
#include <stdio.h>
#include <math.h>
#include <float.h>

// Simulation parameters for a simple control system
typedef struct {
    long double setpoint;  // Desired value
    long double current_value;  // Current measurement
    long double kp;  // Proportional gain
    long double ki;  // Integral gain
    long double kd;  // Derivative gain
} PIDController;

// Function to compute the PID controller output
long double compute_pid_output(PIDController *pid, long double error, long double integral, long double derivative) {
    long double output = pid->kp * error + pid->ki * integral + pid->kd * derivative;
    return output;
}

int main() {
    // Define a PID controller with specific gains
    PIDController pid = { 100.0L, 0.0L, 2.0L, 0.5L, 1.0L};
    
    // Simulate a process variable that is very close to zero
    long double process_variable = 1.0e-307L; // Near denormalized numbers
    long double error = pid.setpoint - process_variable;

    // Handle edge cases
    long double integral = 1.0L / INFINITY;  // Example of underflow handling
    long double derivative = NAN;  // Using NaN for invalid state

    // Compute PID output
    long double output = compute_pid_output(&pid, error, integral, derivative);

    // Check for NaN and Infinity
    if (isnan(output)) {
        printf("PID output is NaN (Not-a-Number)\n");
    } else if (isinf(output)) {
        printf("PID output is Infinite\n");
    } else {
        printf("PID output: %Lf\n", output);
    }

    // Check rounding behavior example
    long double rounded_value = roundl(process_variable * powl(10.0L, 35.0L));
    printf("Rounded value: %Lf\n", rounded_value);

    // Check the behavior with a large number
    long double large_number = LDBL_MAX;
    long double large_computation = large_number * 2.0L;  // Overflow example
    if (isinf(large_computation)) {
        printf("Large computation resulted in Infinity\n");
    }

    return 0;
}
