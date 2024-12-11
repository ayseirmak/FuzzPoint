
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define a structure for seismic waves in geophysics
typedef struct {
    long double amplitude;
    double frequency;
} SeismicWave;

// Function to perform computation on seismic waves
double compute_seismic_activity(SeismicWave waves[], int count) {
    double total_energy = 0.0;

    // Perform computations on waves, optimized for potential loop unrolling
    for (int i = 0; i < count; ++i) {
        long double omega = 2.0L * M_PI * waves[i].frequency;
        long double energy = waves[i].amplitude * waves[i].amplitude * omega;
        total_energy += (double)energy;

        // Extended precision edge case
        if (isinf(waves[i].amplitude) || isinf(waves[i].frequency)) {
            total_energy = INFINITY;
            break;
        }

        // Handle denormalized number
        if (fabs(waves[i].amplitude) < DBL_MIN) {
            // Underflow
            printf("Detected underflow with amplitude: %Le\n", waves[i].amplitude);
        }
    }
    
    return total_energy;
}

int main() {
    // Define seismic waves with fixed values
    SeismicWave waves[] = {
        {1.0L, 1.5},
        {3.6L, 0.8},
        {0.000000000001L, 0.5},  // Potential denormalized value
        {INFINITY, 5.0},         // Intentionally using Infinity
    };
    
    int num_waves = sizeof(waves) / sizeof(waves[0]);
    
    // Compute total seismic activity
    double total_activity = compute_seismic_activity(waves, num_waves);
    printf("Total seismic activity energy: %f\n", total_activity);
    
    return 0;
}
