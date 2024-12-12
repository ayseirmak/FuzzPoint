
#include <stdio.h>
#include <math.h>

// Constants for the material
#define COEFFICIENT_OF_EXPANSION 1.2e-5  // Coefficient of linear expansion (1/°C) for a typical metal
#define INITIAL_LENGTH 1.0               // Initial length of the rod (meters)
#define INITIAL_TEMPERATURE 20.0         // Initial temperature (°C)
#define FINAL_TEMPERATURE 100.0          // Final temperature (°C)

// Function to calculate the change in length due to temperature change
double calculate_thermal_expansion(double initial_length, double delta_temperature, double expansion_coeff) {
    return initial_length * expansion_coeff * delta_temperature;
}

int main() {
    // Calculate temperature change
    double delta_temperature = FINAL_TEMPERATURE - INITIAL_TEMPERATURE;

    // Calculate change in length
    double length_change = calculate_thermal_expansion(INITIAL_LENGTH, delta_temperature, COEFFICIENT_OF_EXPANSION);

    // Calculate final length
    double final_length = INITIAL_LENGTH + length_change;

    // Output the results
    printf("Material Science Simulation - Thermal Expansion:\n");
    printf("Initial Length: %.3f meters\n", INITIAL_LENGTH);
    printf("Change in Length: %.6f meters\n", length_change);
    printf("Final Length: %.6f meters\n", final_length);

    return 0;
}
