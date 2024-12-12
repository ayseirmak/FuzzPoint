
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Define macros for PID controller parameters
#define KP 0.1  // Proportional gain
#define KI 0.01 // Integral gain
#define KD 0.05 // Derivative gain
#define SETPOINT 100.0 // Desired target value
#define TIME_INTERVAL 1.0 // Time interval for loop updates
#define NUM_ITERATIONS 30 // Number of iterations

typedef struct {
    double kp;
    double ki;
    double kd;
    double integral;
    double previous_error;
} PIDController;

// Function to simulate PID controller behavior
double compute_pid_output(PIDController* pid, double current_value) {
    double error = SETPOINT - current_value;
    pid->integral += error * TIME_INTERVAL;
    double derivative = (error - pid->previous_error) / TIME_INTERVAL;
    double output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
    pid->previous_error = error;
    return output;
}

// Function to demonstrate floating-point edge cases
void floating_point_edge_cases() {
    // Different rounding modes demonstration
    float value = 2.5f;

    fesetround(FE_TONEAREST);
    printf("Round to nearest: %.1f\n", roundf(value));

    fesetround(FE_TOWARDZERO);
    printf("Round toward zero: %.1f\n", roundf(value));

    fesetround(FE_UPWARD);
    printf("Round toward infinity: %.1f\n", roundf(value));

    // Representation of -0.0
    float neg_zero = -0.0f;
    printf("Representation of -0.0: %f\n", neg_zero);

    // Overflow handling
    float large_value = FLT_MAX;
    float overflow_result = large_value * 2.0f; // Intentional overflow
    printf("Overflow handling result: %e\n", overflow_result);
}

int main() {
    PIDController pid = {KP, KI, KD, 0.0, 0.0};
    double current_value = 20.0; // Starting value
    double output;
    
    printf("PID Control Loop Simulation:\n");
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        output = compute_pid_output(&pid, current_value);
        current_value += output;
        printf("Iteration %d: Control Output = %.2f, Current Value = %.2f\n", i, output, current_value);
    }
    
    floating_point_edge_cases();

    return 0;
}
