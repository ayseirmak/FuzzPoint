
#include <stdio.h>
#include <math.h>
#include <float.h>

// Inline function to calculate seismic wave propagation speed
inline double calculate_wave_speed(double density, double elasticity) {
    return sqrt(elasticity / density);
}

// Inline function to model attenuation over distance
inline double calculate_attenuation(double distance, double frequency) {
    const double attenuation_coefficient = 0.025; // Example coefficient
    return exp(-attenuation_coefficient * distance * frequency);
}

// Function to analyze seismic data with volatile floating-point operation
void analyze_seismic_data(volatile double *densities, volatile double *elasticities, int size) {
    for (int i = 0; i < size; i++) {
        // Calculate wave speed using inline function
        volatile double wave_speed = calculate_wave_speed(densities[i], elasticities[i]);

        // Simulate further geophysical analysis using calculated wave speed
        volatile double frequency = 1.0; // Assume a constant frequency for the wave
        
        // Calculate attenuation using inline function and volatile variable
        volatile double attenuation = calculate_attenuation(100.0, frequency); // 100.0 is the distance

        // Perform combined computation
        volatile double effective_speed = wave_speed * attenuation;
        
        // Handle edge cases with potential floating-point anomalies
        if (isnan(effective_speed) || isinf(effective_speed)) {
            printf("Anomaly detected in effective speed[%d], reset to zero.\n", i);
            effective_speed = 0.0;
        }
        
        // Print the effective speed for minimal output
        printf("Effective Wave Speed[%d]: %.5f m/s\n", i, effective_speed);
    }
}

int main() {
    // Sample data for geophysical analysis
    double densities[] = {2200.0, 2500.0, 2700.0, 2900.0};  // Densities in kg/m^3
    double elasticities[] = {5.0e9, 6.0e9, 7.5e9, 8.0e9};   // Elastic moduli in Pascals
    int num_samples = sizeof(densities) / sizeof(densities[0]);

    // Perform seismic analysis
    analyze_seismic_data(densities, elasticities, num_samples);

    return 0;
}
