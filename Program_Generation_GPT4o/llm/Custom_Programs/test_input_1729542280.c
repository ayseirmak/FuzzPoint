
#include <stdio.h>
#include <fenv.h>
#include <math.h>

// Function to simulate buoyant force calculation in marine environments
void calculate_buoyant_forces(double *volumes, double *densities, double *buoyant_forces, int size) {
    const double g = 9.81;  // Acceleration due to gravity

    // Vectorizable loop to compute buoyant forces
    #pragma GCC ivdep 
    for (int i = 0; i < size; i++) {
        // Buoyant force = volume * density * gravity
        buoyant_forces[i] = volumes[i] * densities[i] * g;

        // Handling potential floating-point exceptions
        if (isnan(buoyant_forces[i]) || isinf(buoyant_forces[i])) {
            buoyant_forces[i] = 0.0;  // Assign zero force for error cases
        }
    }
}

// Function to perform calculations with potential floating-point exceptions
void floating_point_exception_demo() {
    volatile double large_value = 1.0e308;
    volatile double overflow_result = large_value * large_value;  // Causes overflow

    if (isinf(overflow_result)) {
        printf("Overflow detected, result set to maximum: %e\n", DBL_MAX);
        overflow_result = DBL_MAX;
    }
}

int main() {
    // Enable floating-point exceptions for debugging
    feenableexcept(FE_OVERFLOW | FE_DIVBYZERO);

    // Fixed arrays to simulate varying objects in water
    double volumes[5] = {2.0, 4.5, 3.1, 0.0, 5.3};  // Volumes in cubic meters
    double densities[5] = {1000.0, 950.0, 1025.0, 0.0, 980.0};  // Densities in kg/m^3
    
    double buoyant_forces[5];

    // Calculate buoyant forces using vectorized operations
    calculate_buoyant_forces(volumes, densities, buoyant_forces, 5);

    // Display the calculated buoyant forces
    for (int i = 0; i < 5; i++) {
        printf("Buoyant Force[%d]: %f N\n", i, buoyant_forces[i]);
    }

    // Demo floating-point exception handling
    floating_point_exception_demo();

    return 0;
}
