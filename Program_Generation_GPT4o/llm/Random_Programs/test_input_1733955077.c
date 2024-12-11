
#include <stdio.h>
#include <math.h>

// Define constants for the simulation
#define GRID_SIZE 100            // Size of the spatial grid
#define TIME_STEP 0.001          // Time step size
#define TOTAL_TIME 1.0           // Total simulation time
#define WAVE_SPEED 500.0         // Wave speed (m/s) - arbitrary units
#define DAMPING_FACTOR 0.99      // Damping factor for wave attenuation

// Function to simulate seismic wave propagation
void simulate_wave_propagation(double *u, double *v, int size, double wave_speed, double time_step, double total_time, double damping) {
    int num_steps = (int)(total_time / time_step);
    double u_new[GRID_SIZE];

    for (int step = 0; step < num_steps; step++) {
        for (int i = 1; i < size - 1; i++) {
            // Update wave field using central difference approximation
            u_new[i] = 2 * u[i] - v[i] + wave_speed * wave_speed * time_step * time_step *
                      (u[i + 1] - 2 * u[i] + u[i - 1]);
        }

        // Implement damping and swap buffers
        for (int i = 1; i < size - 1; i++) {
            v[i] = u[i] * damping;
            u[i] = u_new[i];
        }
    }
}

int main() {
    // Initialize the wave field and previous wave field arrays
    double u[GRID_SIZE] = {0};
    double v[GRID_SIZE] = {0};
    
    // Create an initial disturbance (e.g., simulating a seismic event at the center)
    u[GRID_SIZE / 2] = 1.0;

    // Run the wave propagation simulation
    simulate_wave_propagation(u, v, GRID_SIZE, WAVE_SPEED, TIME_STEP, TOTAL_TIME, DAMPING_FACTOR);

    // Output the final state of the wave field
    printf("Final Wave Field:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        printf("Position %d: %.5f\n", i, u[i]);
    }

    return 0;
}
