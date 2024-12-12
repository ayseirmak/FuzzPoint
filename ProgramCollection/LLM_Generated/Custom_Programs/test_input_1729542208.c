
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Simple PI controller function
double pi_controller(double setpoint, double measurement, double kp, double ki, double *integral) {
    double error = setpoint - measurement;
    *integral += error;
    double output = kp * error + ki * *integral;
    
    // Floating-point comparison for saturation
    if (output > 100.0)     // Limit output for control systems to avoid overflow
        output = 100.0;
    else if (output < -100.0)
        output = -100.0;

    return output;
}

// Function demonstrating trapping control and conditionals
void floating_point_conditions_and_trap() {
    volatile double small_value = 1.0e-308;
    volatile double zero = 0.0;
    volatile double result;

    // Example of trapping conditions
    if (small_value < 1.0e-10 && small_value != 0.0) {
        result = small_value / 2.0;
    } else {
        result = small_value * 2.0;
    }

    // Trapping condition: Division by zero will trigger an exception
    result = small_value / zero;
}

int main() {
    // Enable floating-point exceptions for debugging
    feenableexcept(FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);

    // PI controller setup
    double setpoint = 20.0;  // The desired value
    double measurement = 15.0;  // Current system measurement
    double kp = 0.5;     // Proportional gain
    double ki = 0.1;     // Integral gain
    double integral_part = 0.0;  // Integral accumulator for PI controller

    // Compute the control signal
    double control_signal = pi_controller(setpoint, measurement, kp, ki, &integral_part);
    printf("Control Signal: %f\n", control_signal);

    // Perform floating-point operations involving conditionals and exception trapping
    floating_point_conditions_and_trap();

    return 0;
}
