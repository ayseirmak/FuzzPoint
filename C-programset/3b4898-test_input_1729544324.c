
#include <stdio.h>
#include <math.h>

// Constants
#define INITIAL_LENGTH 1.0 // Initial length of the rod in meters
#define ALPHA 11.7e-6 // Coefficient of linear expansion for steel in 1/°C
#define NUM_INTERVALS 10 // Number of temperature intervals for the simulation

// Function to simulate thermal expansion
void simulate_thermal_expansion(double initial_temperature, double final_temperature) {
    double delta_temperature = (final_temperature - initial_temperature) / NUM_INTERVALS;
    double current_length = INITIAL_LENGTH;
    double current_temperature = initial_temperature;

    printf("Temperature (°C)   Length (m)\n");
    printf("-----------------------------\n");

    for (int i = 0; i <= NUM_INTERVALS; ++i) {
        printf("%15.2f %12.6f\n", current_temperature, current_length);

        // Update length based on thermal expansion
        current_length += ALPHA * current_length * delta_temperature;
        current_temperature += delta_temperature;
    }
}

int main() {
    double initial_temperature = 20.0; // Initial temperature in °C
    double final_temperature = 100.0; // Final temperature in °C

    // Perform the simulation
    simulate_thermal_expansion(initial_temperature, final_temperature);

    return 0;
}
