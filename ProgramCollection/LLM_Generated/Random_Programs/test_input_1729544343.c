
#include <stdio.h>

// Constants for the material
#define YOUNG_MODULUS 210e9 // Young's modulus for steel in Pascals (Pa)
#define INITIAL_LENGTH 1.0 // Initial length of the sample in meters
#define CROSS_SECTION_AREA 0.01 // Cross-sectional area in square meters

// Function to simulate stress-strain relationship
void simulate_stress_strain(double max_force, int steps) {
    double force_step = max_force / steps;
    double current_force = 0.0;

    printf("Force (N)   Stress (Pa)   Strain (unitless)\n");
    printf("------------------------------------------\n");

    for (int i = 0; i <= steps; ++i) {
        // Calculate stress
        double stress = current_force / CROSS_SECTION_AREA;
        
        // Calculate strain using Hooke's law: strain = stress / Young's modulus
        double strain = stress / YOUNG_MODULUS;

        printf("%9.2f %13.2f %16.8f\n", current_force, stress, strain);

        current_force += force_step;
    }
}

int main() {
    double max_force = 10000.0; // Maximum force in Newtons (N)
    int steps = 10; // Number of intervals for force application

    // Simulate the stress-strain relationship
    simulate_stress_strain(max_force, steps);

    return 0;
}
