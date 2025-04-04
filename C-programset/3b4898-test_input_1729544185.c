
#include <stdio.h>
#include <math.h>

// Constants for the climate model
#define SOLAR_CONSTANT 1361.0 // Solar constant in W/m^2
#define ALBEDO 0.3 // Average planetary albedo
#define STEFAN_BOLTZMANN 5.67e-8 // Stefan-Boltzmann constant in W/m^2K^4
#define INITIAL_GHG_CONCENTRATION 400.0 // Initial greenhouse gas concentration in ppm
#define CLIMATE_SENSITIVITY 0.01 // Temperature change per unit change in GHG concentration

// Function to calculate equilibrium temperature increase due to GHG
double compute_temperature_increase(double ghg_concentration) {
    double absorbed_solar_radiation = (1 - ALBEDO) * SOLAR_CONSTANT / 4; // Averaged over the Earth
    double radiative_forcing = CLIMATE_SENSITIVITY * (ghg_concentration - INITIAL_GHG_CONCENTRATION);
    double effective_temperature = pow(absorbed_solar_radiation / (STEFAN_BOLTZMANN + radiative_forcing), 0.25) - 273.15; // Convert from Kelvin to Celsius
    return effective_temperature;
}

int main() {
    double ghg_concentrations[] = {420.0, 440.0, 460.0, 480.0, 500.0};
    int num_scenarios = sizeof(ghg_concentrations) / sizeof(ghg_concentrations[0]);

    printf("Predicted Global Temperature Increase:\n");

    for (int i = 0; i < num_scenarios; ++i) {
        double temp_increase = compute_temperature_increase(ghg_concentrations[i]);
        printf("  GHG Concentration: %.1f ppm -> Temperature Increase: %.2f°C\n", ghg_concentrations[i], temp_increase);
    }

    return 0;
}
