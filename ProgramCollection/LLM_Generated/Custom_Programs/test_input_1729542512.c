
#include <stdio.h>
#include <math.h>

// Inline function for calculating reaction rate using Arrhenius equation
inline double calculate_reaction_rate(double A, double E, double R, double T) {
    return A * exp(-E / (R * T));  // Arrhenius equation
}

// Inline function for computing conversion percentage
inline double compute_conversion(double initial_concentration, double final_concentration) {
    return ((initial_concentration - final_concentration) / initial_concentration) * 100.0;
}

// Function to simulate a chemical reactor's conversion and rate calculations
void simulate_reactor(double *temperatures, double *initial_concentrations, double *final_concentrations, double *reaction_rates, int size) {
    const double A = 5e7;  // Pre-exponential factor
    const double E = 80000;  // Activation energy in J/mol
    const double R = 8.314;  // Universal gas constant in J/(mol*K)

    for (int i = 0; i < size; i++) {
        // Calculate reaction rate with inlined function
        double reaction_rate = calculate_reaction_rate(A, E, R, temperatures[i]);
        reaction_rates[i] = reaction_rate;

        // Calculate conversion using various floating-point operations
        double conversion = compute_conversion(initial_concentrations[i], final_concentrations[i]);

        // Arithmetic operations to introduce complexity
        conversion += reaction_rate;
        conversion -= 10.0;
        conversion *= 1.5;
        conversion = fmax(conversion, 0.0);  // Ensure not negative
        conversion = fmod(conversion, 100.0);  // Modulo operation limiting to 100

        // Handle edge cases with printing minimal anomalies
        if (isnan(conversion) || isinf(conversion)) {
            printf("Anomalous conversion[%d] detected, reset to zero.\n", i);
            conversion = 0.0;
        }

        printf("Final Conversion[%d]: %.2f%%, Reaction Rate: %.5e mol/L/s\n", i, conversion, reaction_rate);
    }
}

int main() {
    // Setup reactor simulation parameters
    double temperatures[] = {300.0, 350.0, 400.0, 450.0};  // Temperatures in K
    double initial_concentrations[] = {1.0, 1.0, 1.0, 1.0};  // Initial concentrations in mol/L
    double final_concentrations[] = {0.8, 0.6, 0.4, 0.2};  // Final concentrations in mol/L
    int num_reactions = sizeof(temperatures) / sizeof(temperatures[0]);
    double reaction_rates[num_reactions];

    // Run the reactor simulation
    simulate_reactor(temperatures, initial_concentrations, final_concentrations, reaction_rates, num_reactions);

    return 0;
}
