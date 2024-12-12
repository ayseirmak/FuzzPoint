
#include <stdio.h>

#define GRAVITY -9.81 // Gravity acceleration in m/s^2
#define TIME_STEP 0.01 // Time step in seconds
#define DAMPING 0.9 // Energy loss factor upon bouncing

// Function to simulate the bouncing ball
void simulate_bouncing_ball(double initial_height, double initial_velocity, double total_time) {
    double height = initial_height;
    double velocity = initial_velocity;
    double time = 0.0;

    printf("Time (s)   Height (m)   Velocity (m/s)\n");
    printf("--------------------------------------\n");

    while (time <= total_time) {
        // Update velocity and height
        velocity += GRAVITY * TIME_STEP;
        height += velocity * TIME_STEP;

        // Bounce the ball if it hits the ground
        if (height <= 0) {
            height = 0;
            velocity = -velocity * DAMPING;
        }

        printf("%7.2f %11.2f %14.2f\n", time, height, velocity);

        time += TIME_STEP;
    }
}

int main() {
    double initial_height = 2.0; // Initial height in meters
    double initial_velocity = 0.0; // Initial velocity in m/s
    double total_time = 5.0; // Total simulation time in seconds

    // Simulate the bouncing ball
    simulate_bouncing_ball(initial_height, initial_velocity, total_time);

    return 0;
}
