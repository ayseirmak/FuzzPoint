
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Function to simulate VR headset positional tracking using complex floating-point arithmetic
#pragma STDC FENV_ACCESS ON // Enable access to the floating-point environment
double process_headset_position(double x, double y, double z) {
    // Enabling strict IEEE 754 mode
    #pragma GCC optimize ("fp-contract=off")
    
    volatile double result = 0.0; // Volatile ensures no optimization removes these computations
    
    // Handle denormalized numbers and NaN
    if (x == 0.0) x = DBL_MIN * 0.5;
    if (y != y) y = 0.0;  // NaN check, setting y to zero
  
    // Compute vector magnitude using strict IEEE 754 compliance
    double magnitude = sqrt(x*x + y*y + z*z);
    
    if (magnitude == INFINITY) magnitude = 0.0; // Handle infinity
    
    result = magnitude;

    // Intentional no-op to demonstrate pragma effects
    #pragma GCC optimize ("fp-contract=fast") // Allow floating-point contraction
    result += 0; // MFLOP no-op to check contract
    return result;
}

int main() {
    // Define fixed positions representing VR headset coordinates
    double positions[][3] = {
        {0.1, 1.0, -1.0},
        {3.0, NAN, 4.0},
        {1e-308, 1.0, 1.0}, // Denormalized edge case
        {INFINITY, 1.0, 1.0},
        {1.0, 1.0, 0.0}
    };
    int length = sizeof(positions) / sizeof(positions[0]);

    // Enable exceptions for floating-point anomalies
    feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW);

    printf("Original VR headset positions:\n");
    for (int i = 0; i < length; i++) {
        printf("Position[%d] = (%f, %f, %f)\n", i, positions[i][0], positions[i][1], positions[i][2]);
    }

    // Process VR headset positional data
    printf("\nProcessed VR headset magnitudes:\n");
    for (int i = 0; i < length; i++) {
        double magnitude = process_headset_position(positions[i][0], positions[i][1], positions[i][2]);
        printf("Magnitude for position[%d] = %f\n", i, magnitude);
    }

    return 0;
}
