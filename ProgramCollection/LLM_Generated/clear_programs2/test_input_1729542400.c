
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>

// Function to simulate a simple physics model, such as a particle moving under gravity
void physics_simulation(double *positions, double *velocities, double *accelerations, int size) {
    const double time_step = 0.01;  // Time step in seconds
    const double gravity = 9.81;    // Acceleration due to gravity in m/s²
    
    // Enable floating-point exceptions in order to handle edge cases like denormalized numbers
    feenableexcept(FE_UNDERFLOW | FE_OVERFLOW);
    
    for (int i = 0; i < size; i++) {
        // Update velocity with potential danger of denormalized number generation
        velocities[i] += accelerations[i] * time_step;
        
        // Update position
        positions[i] += velocities[i] * time_step;
        
        // Simulate an edge case of denormalized number
        double e_tiny = velocities[i] * DBL_MIN;  // Intentional small product leading to tiny result
        
        // Various arithmetic operations
        accelerations[i] = gravity - (positions[i] / (positions[i] == 0.0 ? 1.0 : positions[i]));  // Avoid division by zero
        
        // Adding aimless noise for complexity
        double noise = fmod(e_tiny, 0.001);  // Wraps around a very small modulus
        velocities[i] += noise;  // Affect velocity with noise

        // Handle floating-point anomalies
        if (isnan(positions[i]) || isinf(positions[i]) || isnan(velocities[i]) || isinf(velocities[i])) {
            printf("Anomaly detected for particle[%d], reset to initial values.\n", i);
            positions[i] = 0.0;
            velocities[i] = 0.0;
        }
        
        printf("Particle[%d] - Position: %.5f, Velocity: %.5f\n", i, positions[i], velocities[i]);
    }
}

int main() {
    // Initial conditions for the simulation
    double positions[] = {0.0, 5.0, 10.0, 15.0};  // Initial positions in meters
    double velocities[] = {1.0, 0.0, -1.0, -2.0};  // Initial velocities in m/s
    double accelerations[] = {0.0, 0.0, 0.0, 0.0};  // Initial accelerations in m/s²
    int num_particles = sizeof(positions) / sizeof(positions[0]);

    // Run the physics simulation
    physics_simulation(positions, velocities, accelerations, num_particles);

    return 0;
}
