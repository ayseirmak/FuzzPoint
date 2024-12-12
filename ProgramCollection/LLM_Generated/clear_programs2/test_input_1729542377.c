
#include <stdio.h>
#include <math.h>

// Function to compute sound pressure level changes with distance using the inverse square law
void compute_sound_pressure_levels(double *initial_pressures, double *distances, double *pressure_levels, int size) {
    const double reference_distance = 1.0;  // Reference distance in meters

    for (int i = 0; i < size; i++) {
        // Check for zero distance to prevent division by zero
        if (distances[i] <= 0.0) {
            printf("Invalid distance[%d], set to reference distance.\n", i);
            distances[i] = reference_distance;
        }

        // Calculate the change in sound pressure level
        double pressure_decrease = initial_pressures[i] / (distances[i] * distances[i]);
        
        // Convert pressure to decibel scale using dB = 20 * log10(p/p0), with p0 = reference pressure
        double reference_pressure = 20.0e-6;  // Reference pressure in Pascals
        pressure_levels[i] = 20.0 * log10(fabs(pressure_decrease) / reference_pressure);

        // Ensure pressure levels are within reasonable limits
        if (isnan(pressure_levels[i]) || isinf(pressure_levels[i])) {
            printf("Anomaly in pressure level[%d], reset to zero.\n", i);
            pressure_levels[i] = 0.0;
        }

        // Conditional checks for specific decibel thresholds
        if (pressure_levels[i] > 100.0) {
            printf("Pressure level[%d] exceeds 100 dB: %.2f dB\n", i, pressure_levels[i]);
        } else if (pressure_levels[i] < 30.0) {
            pressure_levels[i] += 10.0;  // Apply gain for low-pressure areas
            printf("Low pressure level[%d] adjusted to: %.2f dB\n", i, pressure_levels[i]);
        }
    }
}

int main() {
    // Fixed initial pressures and distances for the simulation
    double initial_pressures[] = {0.02, 0.015, 0.03, 0.01};  // Initial pressures in Pascals
    double distances[] = {10.0, 0.0, 5.0, 15.0};  // Distances in meters
    int num_sources = sizeof(initial_pressures) / sizeof(initial_pressures[0]);
    double pressure_levels[num_sources];

    // Compute sound pressure levels
    compute_sound_pressure_levels(initial_pressures, distances, pressure_levels, num_sources);

    return 0;
}
