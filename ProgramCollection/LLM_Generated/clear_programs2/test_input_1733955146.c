
#include <stdio.h>
#include <math.h>

// Constants for the simulation
#define GRAVITY 9.81                 // Gravity constant (m/s^2)
#define DRAG_COEFFICIENT 0.1         // Test coefficient of air resistance
#define MASS 1.0                     // Mass of the projectile (kg)
#define TIME_STEP 0.01               // Time step size for the simulation (seconds)
#define SIMULATION_TIME 5.0          // Total simulation duration (seconds)

// Function to calculate acceleration with drag
void calculate_acceleration(double vx, double vy, double *ax, double *ay) {
    double v = sqrt(vx * vx + vy * vy);  // Magnitude of velocity
    *ax = -(DRAG_COEFFICIENT / MASS) * v * vx;
    *ay = -GRAVITY - (DRAG_COEFFICIENT / MASS) * v * vy;
}

// Function to simulate the projectile motion
void simulate_projectile(double initial_velocity, double launch_angle) {
    double vx = initial_velocity * cos(launch_angle); // Initial velocity in x-direction
    double vy = initial_velocity * sin(launch_angle); // Initial velocity in y-direction
    double x = 0, y = 0; // Initial position

    printf("Time(s)\tX(m)\tY(m)\n"); // Output header
    for(double t = 0; t <= SIMULATION_TIME; t += TIME_STEP) {
        double ax, ay;
        calculate_acceleration(vx, vy, &ax, &ay);

        // Update velocity
        vx += ax * TIME_STEP;
        vy += ay * TIME_STEP;

        // Update position
        x += vx * TIME_STEP;
        y += vy * TIME_STEP;

        if (y < 0) // Stop if the projectile hits the ground
            break;

        if (fmod(t, 0.1) < TIME_STEP) // Print output every 0.1 seconds
            printf("%.2f\t%.2f\t%.2f\n", t, x, y);
    }
}

int main() {
    // Define the initial conditions
    double initial_velocity = 50.0; // Initial speed in m/s
    double launch_angle = M_PI / 4; // Launch angle in radians (45 degrees)

    // Run the projectile simulation
    simulate_projectile(initial_velocity, launch_angle);

    return 0;
}
