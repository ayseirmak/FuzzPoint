
#include <stdio.h>
#include <math.h>

// Define constants for the simulation
#define REACTION_RATE 0.1    // Reaction rate constant (s^-1)
#define TIME_STEP 0.05       // Time step for the simulation (seconds)
#define TOTAL_TIME 5.0       // Total time for the simulation (seconds)

// Function to simulate the reaction process
void simulate_reaction(double *concentration_A, double *concentration_B, double k, double dt, double total_time) {
    int num_steps = (int)(total_time / dt);
    for (int i = 0; i < num_steps; i++) {
        double dA_dt = -k * (*concentration_A);        // Rate of change of reactant A
        double dB_dt = k * (*concentration_A);         // Rate of change of product B
        
        // Update concentrations
        *concentration_A += dA_dt * dt;
        *concentration_B += dB_dt * dt;
    }
}

int main() {
    // Initial concentrations (mol/L)
    double concentration_A = 1.0;  // Concentration of A at t=0
    double concentration_B = 0.0;  // Concentration of B at t=0

    // Simulate the reaction
    simulate_reaction(&concentration_A, &concentration_B, REACTION_RATE, TIME_STEP, TOTAL_TIME);

    // Output the final concentrations
    printf("Chemical Reaction Simulation:\n");
    printf("Final Concentration of A: %.6f mol/L\n", concentration_A);
    printf("Final Concentration of B: %.6f mol/L\n", concentration_B);

    return 0;
}
