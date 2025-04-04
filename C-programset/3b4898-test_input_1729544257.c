
#include <stdio.h>
#include <math.h>

// Function to simulate vehicle kinematics
void simulate_kinematics(double initial_velocity, double acceleration, double time_step, double total_time) {
    double position = 0.0;
    double velocity = initial_velocity;

    printf("Time(s)   Position(m)   Velocity(m/s)\n");
    printf("-------------------------------------\n");

    for (double time = 0.0; time <= total_time; time += time_step) {
        // Update position and velocity using kinematic equations
        position += velocity * time_step + 0.5 * acceleration * time_step * time_step;
        velocity += acceleration * time_step;

        printf("%6.2f     %10.2f       %10.2f\n", time, position, velocity);
    }
}

int main() {
    // Initial conditions and constants
    double initial_velocity = 20.0; // Initial velocity in meters per second (m/s)
    double acceleration = 2.5;      // Constant acceleration in meters per second squared (m/s^2)
    double time_step = 0.5;         // Time step in seconds
    double total_time = 10.0;       // Total time in seconds

    // Simulate the vehicle motion
    simulate_kinematics(initial_velocity, acceleration, time_step, total_time);

    return 0;
}
