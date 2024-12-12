
#include <stdio.h>

// Structure to represent a PID controller
typedef struct {
    double kp;      // Proportional gain
    double ki;      // Integral gain
    double kd;      // Derivative gain
    double prev_error;  // Previous error term
    double integral;    // Integral accumulator
} PIDController;

// Function to update the PID controller output
double update_pid(PIDController *pid, double setpoint, double measurement, double dt) {
    double error = setpoint - measurement;
    pid->integral += error * dt;
    double derivative = (error - pid->prev_error) / dt;
    double output = pid->kp * error + pid->ki * pid->integral + pid->kd * derivative;
    pid->prev_error = error;
    return output;
}

int main() {
    PIDController pid = {1.0, 0.1, 0.05, 0.0, 0.0}; // PID gains

    double setpoint = 10.0;    // Desired setpoint
    double position = 0.0;     // Initial position
    double dt = 0.1;           // Time step in seconds

    // Simulate for 20 seconds
    int num_steps = 200;
    for (int i = 0; i < num_steps; ++i) {
        double control_signal = update_pid(&pid, setpoint, position, dt);
        // Simulate the system's response to the control signal (simple model)
        position += control_signal * dt;

        // Print the position every 20 steps
        if (i % 20 == 0) {
            printf("Time: %.1f s, Position: %.2f\n", i * dt, position);
        }
    }

    return 0;
}
