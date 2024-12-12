
#include <stdio.h>
#include <math.h>

// PID Controller structure
typedef struct {
    double kp; // Proportional gain
    double ki; // Integral gain
    double kd; // Derivative gain
    double previous_error;
    double integral;
    double setpoint;  // Desired setpoint
} PIDController;

// Function to initialize a PID controller
void initialize_pid(PIDController *pid, double kp, double ki, double kd, double setpoint) {
    pid->kp = kp;
    pid->ki = ki;
    pid->kd = kd;
    pid->previous_error = 0.0;
    pid->integral = 0.0;
    pid->setpoint = setpoint;
}

// Function to calculate the PID control output
double calculate_pid_output(PIDController *pid, double current_value, double dt) {
    double error = pid->setpoint - current_value;
    pid->integral += error * dt;
    double derivative = (error - pid->previous_error) / dt;
    pid->previous_error = error;
    
    return (pid->kp * error) + (pid->ki * pid->integral) + (pid->kd * derivative);
}

// Simulate a system response to the PID controller
void simulate_pid(PIDController *pid, double initial_value, double dt, int steps) {
    double current_value = initial_value;
    printf("Time Step | Current Value | PID Output\n");
    for (int i = 0; i < steps; i++) {
        double pid_output = calculate_pid_output(pid, current_value, dt);
        // Simulate process model update (assuming a simple model for demonstration purposes)
        current_value += pid_output * dt; // Integrate to get next value
        printf("%9d | %13.4f | %10.4f\n", i, current_value, pid_output);
    }
}

int main() {
    // Create a PID Controller
    PIDController pid;
    initialize_pid(&pid, 1.0, 0.1, 0.01, 1.0); // Set gains and setpoint

    // Initial system value and step configurations
    double initial_value = 0.0;
    double time_step = 0.1; // Time step duration
    int total_steps = 100;  // Total simulation steps
    
    // Simulate the PID control system
    simulate_pid(&pid, initial_value, time_step, total_steps);

    return 0;
}
