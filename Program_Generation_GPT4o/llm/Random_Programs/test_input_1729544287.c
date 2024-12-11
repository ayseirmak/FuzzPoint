
#include <stdio.h>
#include <math.h>

// Constants for the simulation
#define GRAVITY 9.81 // Acceleration due to gravity in m/s^2
#define TIME_STEP 0.1 // Time step in seconds

// Function to calculate projectile trajectory
void calculate_trajectory(double initial_velocity, double launch_angle, double total_time) {
    double velocity_x = initial_velocity * cos(launch_angle);
    double velocity_y = initial_velocity * sin(launch_angle);
    double position_x = 0.0;
    double position_y = 0.0;

    printf("Time(s)   Position X(m)   Position Y(m)\n");
    printf("---------------------------------------\n");

    for (double time = 0.0; time <= total_time; time += TIME_STEP) {
        // Update positions using current velocities
        position_x += velocity_x * TIME_STEP;
        position_y += velocity_y * TIME_STEP - 0.5 * GRAVITY * TIME_STEP * TIME_STEP;
        
        // Update y-velocity due to gravity
        velocity_y -= GRAVITY * TIME_STEP;

        printf("%6.2f     %10.2f       %10.2f\n", time, position_x, position_y);

        // Break simulation if projectile hits the ground
        if (position_y <= 0.0) {
            break;
        }
    }
}

int main() {
    double initial_velocity = 100.0; // Initial velocity in meters per second
    double launch_angle = M_PI / 4;  // Launch angle in radians (45 degrees)
    double total_time = 20.0;        // Total simulation time in seconds

    // Calculate and print the projectile trajectory
    calculate_trajectory(initial_velocity, launch_angle, total_time);

    return 0;
}
