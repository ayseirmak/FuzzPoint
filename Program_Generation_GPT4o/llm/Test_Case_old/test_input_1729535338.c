
#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX_ITERATIONS 10

typedef struct {
    long double kp;      // Proportional gain
    long double ki;      // Integral gain
    long double kd;      // Derivative gain
    long double setPoint; // Desired value
    long double output;   // Calculated output
} PIDController;

long double calculate_error(long double setPoint, long double currentValue) {
    return setPoint - currentValue;
}

long double recursive_control(PIDController *controller, long double currentValue, int depth) {
    if (depth >= MAX_ITERATIONS) return currentValue;

    long double error = calculate_error(controller->setPoint, currentValue);
    long double correction = (controller->kp * error) + (controller->ki * M_PI * error) + (controller->kd * M_E * error);

    // Simulate saturation by limiting correction output
    if (isnan(correction) || isinf(correction)) {
        correction = (correction > 0) ? LDBL_MAX : -LDBL_MAX;
    }

    currentValue = currentValue + correction / powl(10, depth);
    
    // Recursive call to simulate repeated control adjustments
    return recursive_control(controller, currentValue, depth + 1);
}

void control_system_simulation() {
    PIDController controller = {0.1L, 0.01L, 0.001L, 1000.0L, 0.0L};
    
    // Initial condition with boundary condition numerical limits
    long double currentValue = 0.0L;
    controller.output = recursive_control(&controller, currentValue, 0);
    
    printf("Final Control Output: %.10Lf\n", controller.output);
}

int main() {
    control_system_simulation();
    
    // Additional check with float and double types
    float f_val = 1.0e-38F;
    double d_val = 1.0e-308;
    
    for (int i = 0; i < 5; ++i) {
        float f_multiplied = f_val * 1.0e30F;
        double d_multiplied = d_val * 1.0e290;
        printf("Iteration %d, float: %.10e, double: %.10e\n", i, f_multiplied, d_multiplied);
        f_val *= 10.0F;
        d_val *= 10.0;
    }

    return 0;
}
