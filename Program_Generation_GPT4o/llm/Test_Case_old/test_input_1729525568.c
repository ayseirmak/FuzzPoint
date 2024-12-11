
#include <stdio.h>
#include <math.h>
#include <float.h>

#define PI 3.14159265358979323846
#define EPSILON 1e-8  // A small constant for edge cases

// Function to compute force between protein and ligand using Lennard-Jones potential
long double compute_interaction_force(long double distance, long double epsilon, long double sigma) {
    // Compute Lennard-Jones potential energy
    long double sigma_over_distance = sigma / distance;
    long double sigma_over_distance_6 = powl(sigma_over_distance, 6);
    long double potential_energy = 4 * epsilon * (sigma_over_distance_6 * (sigma_over_distance_6 - 1));

    // Compute force using derivative of the Lennard-Jones potential
    long double force_magnitude = 24 * epsilon * (2 * powl(sigma_over_distance, 12) - powl(sigma_over_distance, 6)) / distance;

    // Handle edge cases
    if (distance < EPSILON) {
        printf("Warning: Distance is too small, resulting in potential singularities.\n");
        return LDBL_MAX;  // Indicate a large repulsive force
    }
    if (!isfinite(force_magnitude)) {
        printf("Error: Force magnitude is non-finite, possibly due to overflow.\n");
        return 0;
    }
    if (force_magnitude != force_magnitude) {
        printf("Error: Force magnitude is NaN.\n");
        return 0;
    }
    if (fabsl(force_magnitude) < LDBL_MIN) {
        printf("Warning: Force magnitude underflow.\n");
        return 0;  // Treat as zero force
    }

    return force_magnitude;
}

int main() {
    // Fixed values for protein-ligand pair
    long double distance = 0.5L;    // Distance between protein and ligand
    long double epsilon = 0.1L;    // Depth of the potential well
    long double sigma = 1.0L;      // Finite distance at which the inter-particle potential is zero

    // Compute interaction force
    long double force = compute_interaction_force(distance, epsilon, sigma);

    // Simulate edge-case distance
    long double extreme_distance = 0.0L;  // Edge case for zero distance
    long double extreme_force = compute_interaction_force(extreme_distance, epsilon, sigma);

    // Output interaction force results
    printf("Interaction force: %.15Le\n", force);
    printf("Extreme interaction force: %.15Le\n", extreme_force);

    // Other floating-point edge cases
    long double small_value = 1e-320L;  // Testing with denormalized small numbers
    long double large_value = 1e308L;   // Testing for overflow
    long double edge_force_1 = compute_interaction_force(small_value, epsilon, sigma);
    long double edge_force_2 = compute_interaction_force(large_value, epsilon, sigma);

    printf("Edge force with small distance: %.15Le\n", edge_force_1);
    printf("Edge force with large distance: %.15Le\n", edge_force_2);

    return 0;
}
