
#include <stdio.h>
#include <math.h>

// Inline function to compute hydrodynamic drag force
inline double compute_drag_force(double drag_coefficient, double area, double velocity) {
    return 0.5 * drag_coefficient * area * velocity * velocity;
}

// Inline function to compute buoyancy force
inline double compute_buoyancy_force(double density_fluid, double volume_submerged) {
    const double g = 9.81; // Acceleration due to gravity in m/s²
    return density_fluid * volume_submerged * g;
}

// Function to perform marine engineering computations
void marine_engineering_analysis(volatile double *drag_coefficients, volatile double *areas, volatile double *velocities, double *volumes, double density_fluid, int size) {
    for (int i = 0; i < size; i++) {
        // Perform hydrodynamic drag force calculation
        volatile double drag_force = compute_drag_force(drag_coefficients[i], areas[i], velocities[i]);

        // Perform buoyancy force calculation
        volatile double buoyancy_force = compute_buoyancy_force(density_fluid, volumes[i]);

        // Effective net force analysis
        volatile double net_force = buoyancy_force - drag_force;

        // Handle edge cases in floating-point calculations
        if (isnan(net_force) || isinf(net_force)) {
            printf("Anomaly detected in net force[%d], reset to zero.\n", i);
            net_force = 0.0;
        }
        
        // Print the net force for each computation
        printf("Net Force[%d]: %.5f N\n", i, net_force);
    }
}

int main() {
    // Fixed input data for marine engineering analysis
    double drag_coefficients[] = {0.8, 1.0, 0.6, 1.2}; // Example drag coefficients
    double areas[] = {2.0, 1.5, 2.5, 3.0}; // Cross-sectional areas in m²
    double velocities[] = {3.0, 5.0, 4.0, 2.5}; // Velocities in m/s
    double volumes[] = {1.0, 1.5, 2.0, 2.5}; // Submerged volumes in m³
    double density_fluid = 1025; // Seawater density in kg/m³
    int num_samples = sizeof(drag_coefficients) / sizeof(drag_coefficients[0]);

    // Perform the analysis
    marine_engineering_analysis(drag_coefficients, areas, velocities, volumes, density_fluid, num_samples);

    return 0;
}
