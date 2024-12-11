
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define a structure for a control system state
typedef struct {
    double setpoint;
    double process_variable;
    double control_output;
} ControlSystem;

// Function to simulate a feedback control loop
void simulate_control_loop(ControlSystem* system, int iterations) {
    const double kp = 1.0; // Proportional gain
    for (int i = 0; i < iterations; ++i) {
        double error = system->setpoint - system->process_variable;

        // Handling potential NaN and infinity in control system responses
        if (isnan(error)) {
            printf("NaN error detected at iteration %d!\n", i);
            system->control_output = 0; // Reset output
        } else if (isinf(error)) {
            printf("Infinity error detected at iteration %d!\n", i);
            system->control_output = 0; // Reset output
        } else {
            // Calculate a new control output based on proportional control
            system->control_output = kp * error;
        }

        // Nested loop to simulate precision loss in floating-point calculations
        for (int j = 0; j < 1000; ++j) {
            system->process_variable += system->control_output * 0.001;
        }

        printf("Iteration %d: error = %.4f, control_output = %.4f, process_variable = %.4f\n",
               i, error, system->control_output, system->process_variable);
    }
}

// Function to demonstrate floating-point edge cases
void floating_point_edge_cases() {
    // Infinity arithmetic
    double pos_inf = DBL_MAX * 2.0; // Positive infinity
    double neg_inf = -DBL_MAX * 2.0; // Negative infinity
    double result = pos_inf + neg_inf; // NaN is expected

    // Signaling NaN
    double signaling_nan = sqrt(-1.0);

    // Quiet NaN (standard NaN definition)
    double quiet_nan = NAN;

    printf("Infinity arithmetic result (inf + -inf): %f\n", result);
    printf("Signaling NaN example: %f\n", signaling_nan);
    printf("Quiet NaN example: %f\n", quiet_nan);
}

int main() {
    ControlSystem system = {100.0, 50.0, 0.0}; // Initial setpoint, process variable
    int iterations = 10;

    printf("Starting control loop simulation...\n");
    simulate_control_loop(&system, iterations);

    printf("Exploring floating-point edge cases...\n");
    floating_point_edge_cases();

    return 0;
}
