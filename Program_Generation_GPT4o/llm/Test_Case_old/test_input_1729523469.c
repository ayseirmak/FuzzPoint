
#include <stdio.h>
#include <math.h>

// Define a structure to represent an atom in 3D space
typedef struct {
    double x, y, z;   // Coordinates of the atom
    double epsilon;   // Depth of the potential well
    double sigma;     // Finite distance at which the potential is zero
} Atom;

// Function to compute the Lennard-Jones potential between two atoms
double lennard_jones_potential(Atom a1, Atom a2) {
    double r2 = pow(a1.x - a2.x, 2) + pow(a1.y - a2.y, 2) + pow(a1.z - a2.z, 2);
    if (r2 == 0.0) return INFINITY; // Return an infinite potential if atoms overlap
    double inv_r6 = pow(a1.sigma * a2.sigma / sqrt(r2), 6);
    return 4 * a1.epsilon * a2.epsilon * (inv_r6 * inv_r6 - inv_r6);
}

// Recursive function to compute the total potential energy of a molecule
double compute_total_potential(Atom* molecule, int num_atoms, int i, int j) {
    if (i == num_atoms - 1) return 0.0; // Base case: no more atoms to compute
    if (j == num_atoms) return compute_total_potential(molecule, num_atoms, i + 1, i + 2);
    return lennard_jones_potential(molecule[i], molecule[j]) + compute_total_potential(molecule, num_atoms, i, j + 1);
}

// Recursive function to calculate factorial demonstrating floating-point range analysis
long double factorial_recursive(int n) {
    if (n <= 1) return 1.0;
    return n * factorial_recursive(n - 1);
}

int main() {
    Atom molecule[] = {
        {0.0, 0.0, 0.0, 0.2, 0.3},  // Atom 1
        {0.5, 0.5, 0.0, 0.2, 0.3}, // Atom 2
        {1.0, 0.0, 0.0, 0.2, 0.3},  // Atom 3
        {0.0, 1.0, 0.0, 0.2, 0.3}   // Atom 4
    };
    
    int num_atoms = sizeof(molecule) / sizeof(molecule[0]);

    double total_potential = compute_total_potential(molecule, num_atoms, 0, 1);

    printf("Total Lennard-Jones potential energy: %f\n", total_potential);

    // Edge case calculations
    double nan_value = sqrt(-1);
    double inf_value = 1.0 / 0.0;
    double denormal_value = pow(2, -1022);

    printf("Factorial of 20: %Lf\n", factorial_recursive(20));
    printf("NaN value: %f\n", nan_value);
    printf("Inf value: %f\n", inf_value);
    printf("Denormalized value: %e\n", denormal_value);
    
    return total_potential > 0 ? 1 : 0;
}
