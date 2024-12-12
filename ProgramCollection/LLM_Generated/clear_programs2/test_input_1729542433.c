
#include <stdio.h>
#include <math.h>

// Function to compute reciprocal transformations and perform vectorized operations on engine efficiencies
void calculate_efficiencies(double *rpm_array, double *torque_array, double *efficiencies, int size) {
    const double max_rpm = 7000.0;  // Maximum RPM for efficiency normalization

    // Vectorized loop to compute efficiencies
    for (int i = 0; i < size; i++) {
        // Compute power using torque and RPM: Power = Torque * RPM / 5252 (constant)
        double power = (torque_array[i] * rpm_array[i]) / 5252.0;

        // Normalize RPM with reciprocal transformation
        double normalized_rpm = rpm_array[i] / (max_rpm == 0.0 ? 1.0 : max_rpm);
        double reciprocal_rpm = 1.0 / (normalized_rpm == 0.0 ? 1.0 : normalized_rpm);

        // Calculate efficiency as a function of power and reciprocal RPM
        efficiencies[i] = power * reciprocal_rpm;

        // Edge case handling
        if (isnan(efficiencies[i]) || isinf(efficiencies[i])) {
            printf("Anomaly in efficiency[%d], set to zero.\n", i);
            efficiencies[i] = 0.0;
        }

        // Print each calculated efficiency (minimal output)
        printf("Efficiency[%d]: %.5f\n", i, efficiencies[i]);
    }
}

int main() {
    // Engine data: RPM and Torque vectors
    double rpm_array[] = {2000, 3500, 5000, 6500};  // Engine speed in RPM
    double torque_array[] = {400, 380, 350, 320};   // Torque in Nm
    int num_engines = sizeof(rpm_array) / sizeof(rpm_array[0]);
    double efficiencies[num_engines];

    // Calculate engine efficiencies using vectorized operations
    calculate_efficiencies(rpm_array, torque_array, efficiencies, num_engines);

    return 0;
}
