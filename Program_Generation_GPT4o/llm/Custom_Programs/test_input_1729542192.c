
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Function to compute aerodynamic drag on an array of velocities
void compute_drag(double *velocities, double *drag_forces, int size, double drag_coefficient, double reference_area) {
    // Vectorized loop for computing drag on each velocity
    #pragma GCC optimize ("tree-vectorize") 
    for (int i = 0; i < size; i++) {
        drag_forces[i] = drag_coefficient * reference_area * 0.5 * velocities[i] * velocities[i];
    }
}

// Function to handle computations with potential denormalized numbers
void denormalized_example() {
    volatile double denormalized_value = 1.0e-308;
    volatile double small_multiplier = 1.0e-10;
    volatile double result;

    // Computation that may cause a denormalized result
    result = denormalized_value * small_multiplier;

    // Output for analysis (minimal)
    printf("Potential Denormalized Result: %e\n", result);
}

int main() {
    // Enable floating-point exceptions for debugging
    feenableexcept(FE_UNDERFLOW | FE_OVERFLOW | FE_DIVBYZERO);

    // Fixed array of velocities in m/s for computation
    double velocities[] = {75.0, 150.0, 225.0, 300.0, 375.0};
    int num_velocities = sizeof(velocities) / sizeof(velocities[0]);

    // Setup aerodynamic parameters
    double drag_coefficient = 0.3;    // Factor representing drag coefficiency
    double reference_area = 10.0;     // Reference area in square meters

    // Calculate drag forces
    double drag_forces[num_velocities];
    compute_drag(velocities, drag_forces, num_velocities, drag_coefficient, reference_area);

    // Output results for analysis
    for (int i = 0; i < num_velocities; i++) {
        printf("Velocity: %f m/s, Drag Force: %f N\n", velocities[i], drag_forces[i]);
    }

    // Perform an example computation involving denormalized numbers
    denormalized_example();

    return 0;
}
