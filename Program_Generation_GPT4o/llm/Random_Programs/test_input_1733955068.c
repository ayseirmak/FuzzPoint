
#include <stdio.h>
#include <math.h>

// Define constants for the simulation
#define SPACE_SIZE 10        // Size of the spatial grid
#define DIFFUSION_COEFF 0.1  // Diffusion coefficient (arbitrary units)
#define TIME_STEP 0.01       // Time step size
#define TOTAL_TIME 1.0       // Total simulation time

// Function to perform diffusion simulation
void simulate_diffusion(double *concentration, int size, double diffusion_coeff, double time_step, double total_time) {
    int num_steps = (int)(total_time / time_step);
    double new_concentration[SPACE_SIZE];

    for (int step = 0; step < num_steps; step++) {
        // Apply diffusion equation
        for (int i = 1; i < size - 1; i++) {
            new_concentration[i] = concentration[i] + diffusion_coeff * time_step *
                                   (concentration[i + 1] - 2 * concentration[i] + concentration[i - 1]);
        }
        // Update concentrations
        for (int i = 1; i < size - 1; i++) {
            concentration[i] = new_concentration[i];
        }
    }
}

int main() {
    // Initialize concentrations with an initial peak at the center
    double concentration[SPACE_SIZE] = {0};
    concentration[SPACE_SIZE / 2] = 1.0;  // Initial high concentration at the center

    // Run the diffusion simulation
    simulate_diffusion(concentration, SPACE_SIZE, DIFFUSION_COEFF, TIME_STEP, TOTAL_TIME);

    // Output the final concentration distribution
    printf("Final Concentration Distribution:\n");
    for (int i = 0; i < SPACE_SIZE; i++) {
        printf("Position %d: %.5f\n", i, concentration[i]);
    }

    return 0;
}
