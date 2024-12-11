
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Prototypes for control system operations
inline float pid_calculate(float setpoint, float actual, float Kp, float Ki, float Kd);
void handle_exceptions();

int main() {
    // Set up control system parameters
    float setpoint = 100.0f; // Desired value
    float actual = 75.0f; // Current value
    float Kp = 3.5f, Ki = 0.8f, Kd = 1.2f; // PID constants

    // Calculate control output using PID controller
    float control_output = pid_calculate(setpoint, actual, Kp, Ki, Kd);
    printf("Control output: %f\n", control_output);

    // Trigger potential floating-point exceptions
    volatile float zero = 0.0f;
    volatile float inf = 1.0f / zero;
    volatile float neg_inf = -1.0f / zero;
    volatile float nan = zero / zero;

    printf("Infinity: %f, Negative Infinity: %f, NaN: %f\n", inf, neg_inf, nan);

    // Demonstrate underflow
    volatile float small_value = 1e-45f;
    small_value /= 2.0f;
    printf("Underflow example: %e\n", small_value);

    // Evaluate exception handling
    handle_exceptions();

    return 0;
}

// Inline function for PID calculation
inline float pid_calculate(float setpoint, float actual, float Kp, float Ki, float Kd) {
    static float integral = 0.0f; // Accumulated integral
    static float prev_error = 0.0f; // Previous error for derivative

    // PID calculations
    float error = setpoint - actual;
    integral += error;
    float derivative = error - prev_error;
    prev_error = error;
    return (Kp * error) + (Ki * integral) + (Kd * derivative);
}

// Exception handling function
void handle_exceptions() {
    // Enable floating-point exceptions
    feclearexcept(FE_ALL_EXCEPT);

    // Example operation that could raise an exception
    volatile double large_num = 1e308;
    volatile double result = large_num * large_num; // Potential overflow

    // Check for floating-point exceptions
    if (fetestexcept(FE_OVERFLOW)) {
        printf("Overflow detected!\n");
    } else if (fetestexcept(FE_UNDERFLOW)) {
        printf("Underflow detected!\n");
    } else if (fetestexcept(FE_DIVBYZERO)) {
        printf("Division by zero detected!\n");
    } else if (fetestexcept(FE_INVALID)) {
        printf("Invalid operation detected!\n");
    } else {
        printf("No exceptions detected.\n");
    }
}
