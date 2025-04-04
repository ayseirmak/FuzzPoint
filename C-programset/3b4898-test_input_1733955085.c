
#include <stdio.h>
#include <math.h>

// Constants for the material
#define YOUNG_MODULUS 200e9  // Young's modulus in Pascals (example value for steel)
#define POISSON_RATIO 0.3    // Poisson's ratio for the material

// Function to calculate axial strain using Hooke's Law
double calculate_axial_strain(double stress) {
    return stress / YOUNG_MODULUS;
}

// Function to calculate lateral strain using Poisson's ratio
double calculate_lateral_strain(double axial_strain) {
    return -POISSON_RATIO * axial_strain;
}

// Function to calculate volume change fraction
double calculate_volume_change(double axial_strain, double lateral_strain) {
    return (1 + axial_strain) * pow(1 + lateral_strain, 2) - 1;
}

int main() {
    // Define applied stress in Pascals
    double applied_stress = 100e6;  // 100 MPa

    // Calculate strains
    double axial_strain = calculate_axial_strain(applied_stress);
    double lateral_strain = calculate_lateral_strain(axial_strain);

    // Calculate volume change
    double volume_change = calculate_volume_change(axial_strain, lateral_strain);

    printf("Material Science Simulation:\n");
    printf("Applied Stress: %.2e Pa\n", applied_stress);
    printf("Axial Strain: %.6e\n", axial_strain);
    printf("Lateral Strain: %.6e\n", lateral_strain);
    printf("Volume Change Fraction: %.6e\n", volume_change);

    return 0;
}
