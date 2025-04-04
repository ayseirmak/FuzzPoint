
#include <stdio.h>
#include <math.h>

// Define the PID Controller structure
typedef struct {
    double kp;      // Proportional gain
    double ki;      // Integral gain
    double kd;      // Derivative gain
    double setpoint; // Desired setpoint
    double integral;
    double previous_error;
} PIDController;

// Initialize the PID controller
void init_pid(PIDController *pid, double kp, double ki, double kd, double setpoint) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->setpoint = setpoint;
    pid->integral = 0.0;
    pid->previous_error = 0.0;
}

// Compute the PID output
double compute_pid(PIDController *pid, double current_value, double dt) {
    double error = pid->setpoint - current_value;
    pid->integral += error * dt;
    double derivative = (error - pid->previous_error) / dt;
    pid->previous_error = error;
    return (pid->kp * error) + (pid->ki * pid->integral) + (pid->kd * derivative);
}

// Simulate a system controlled by PID
void simulate_system(PIDController *pid, double initial_value, double dt, int steps) {
    double current_value = initial_value;
    printf("Step | Current Value | PID Output\n");
    for(int i = 0; i < steps; i++) {
        double pid_output = compute_pid(pid, current_value, dt);
        // Simulate the process update (modify this model as needed to simulate a real system)
        current_value += pid_output * dt; // Example simple integration effect
        printf("%4d | %13.6f | %10.6f\n", i, current_value, pid_output);
    }
}

int main() {
    // Define and initialize PID controller parameters
    PIDController pid;
    init_pid(&pid, 2.0, 0.5, 1.0, 100.0); // Example gains and setpoint

    // Define simulation parameters
    double initial_value = 0.0;
    double time_step = 0.1; // Time step duration
    int total_steps = 50;   // Total simulation steps

    // Simulate the PID-controlled system
    simulate_system(&pid, initial_value, time_step, total_steps);

    return 0;
}
