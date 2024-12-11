
#include <stdio.h>

// Function to simulate a first-order chemical reaction A -> B
void reaction_kinetics(double k, double initial_concentration_A, double total_time, double time_step) {
    double concentration_A = initial_concentration_A;
    double concentration_B = 0.0;
    double time = 0.0;

    printf("Time (s)   [A] (mol/L)   [B] (mol/L)\n");
    printf("-----------------------------------\n");

    while (time <= total_time) {
        printf("%8.2f %15.6f %14.6f\n", time, concentration_A, concentration_B);

        // Calculate rate of reaction
        double rate = -k * concentration_A;

        // Update concentrations using Euler's method
        concentration_A += rate * time_step;
        concentration_B += (-rate) * time_step;

        // Update time
        time += time_step;
    }
}

int main() {
    double k = 0.1; // Reaction rate constant in 1/s
    double initial_concentration_A = 1.0; // Initial concentration of A in mol/L
    double total_time = 50.0; // Total simulation time in seconds
    double time_step = 1.0; // Time step in seconds

    // Simulate the reaction kinetics
    reaction_kinetics(k, initial_concentration_A, total_time, time_step);

    return 0;
}
