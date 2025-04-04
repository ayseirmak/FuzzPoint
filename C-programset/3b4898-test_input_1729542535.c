
#include <stdio.h>
#include <math.h>

// Function to simulate engine dynamics and efficiency calculations
void simulate_engine_performance(volatile double *speed_rpm, volatile double *torque_nm, volatile double *efficiency, int size) {
    const double pi = 3.141592653589793;
    const double max_rpm = 7000.0;  // Max RPM for normalization

    for (int i = 0; i < size; i++) {
        // Normalize speed with possible denormalization
        volatile double normalized_speed = speed_rpm[i] / (max_rpm == 0.0 ? 1.0 : max_rpm);

        // Compute power using both speed and torque
        volatile double power_kw = (torque_nm[i] * speed_rpm[i]) / 9549.0;  // Power in kilowatts formula

        // Optimization with math library call for sine to simulate load fluctuations
        volatile double load_fluctuation = sin(normalized_speed * pi);
        double adjustment_factor = fabs(load_fluctuation) / (1 + power_kw);
        
        // Calculate engine efficiency
        efficiency[i] = power_kw * adjustment_factor;
        
        // Handle any floating-point anomalies
        if (isnan(efficiency[i]) || isinf(efficiency[i])) {
            printf("Anomaly in efficiency[%d], reset to zero.\n", i);
            efficiency[i] = 0.0;
        }

        // Minimal output for the efficiency result
        printf("Efficiency[%d]: %.5f\n", i, efficiency[i]);
    }
}

int main() {
    // Fixed RPM and torque data for engine simulation
    volatile double speed_rpm[] = {2000.0, 3500.0, 5000.0, 6000.0};  // RPM values
    volatile double torque_nm[] = {300.0, 320.0, 340.0, 350.0};    // Torque in Nm
    int num_entries = sizeof(speed_rpm) / sizeof(speed_rpm[0]);
    double efficiency[num_entries];

    // Simulate engine performance
    simulate_engine_performance(speed_rpm, torque_nm, efficiency, num_entries);

    return 0;
}
