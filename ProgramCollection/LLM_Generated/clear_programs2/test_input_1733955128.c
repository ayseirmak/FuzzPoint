
#include <stdio.h>
#include <math.h>

// Constants for the beam and load
#define BEAM_LENGTH 10.0    // Length of the beam in meters
#define LOAD_INTENSITY 1000.0 // Load intensity in Newton/meter
#define MODULUS_OF_ELASTICITY 210e9 // Modulus of elasticity in Pascals (e.g., for steel)
#define MOMENT_OF_INERTIA 8.333e-6 // Moment of inertia in meter^4 for the beam cross-section

// Function to calculate deflection at a given position x on the beam
double calculate_deflection(double x, double length, double load, double elasticity, double inertia) {
    double part1 = (load / (24 * elasticity * inertia));
    double part2 = x * (pow(length, 3) - 2 * length * pow(x, 2) + pow(x, 3));
    return part1 * part2;
}

int main() {
    double step = BEAM_LENGTH / 10; // Calculate deflection at 10 points along the beam

    // Simulate the deflection
    printf("Structural Engineering Simulation - Beam Deflection:\n");
    printf("Position (m) | Deflection (mm)\n");
    for (double x = 0; x <= BEAM_LENGTH; x += step) {
        double deflection = calculate_deflection(x, BEAM_LENGTH, LOAD_INTENSITY, MODULUS_OF_ELASTICITY, MOMENT_OF_INERTIA);
        printf("%12.2f | %14.4f\n", x, deflection * 1e3); // Convert deflection to millimeters for display
    }

    return 0;
}
