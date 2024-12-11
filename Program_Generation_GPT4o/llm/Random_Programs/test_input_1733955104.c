
#include <stdio.h>
#include <math.h>

// Constants for the simulation
#define SOLAR_PANEL_EFFICIENCY 0.18  // Efficiency of the solar panels (18%)
#define PANEL_AREA 1.5               // Area of a single solar panel in square meters
#define NUM_PANELS 10                // Number of solar panels
#define TIME_STEP (1.0/24.0)         // Time step in hours (one hour intervals)
#define TOTAL_HOURS 12               // Total simulation period in hours (daylight hours)

// Function to simulate solar power generation
double simulate_solar_generation(double efficiency, double area, int num_panels, double total_hours, double time_step) {
    double total_energy = 0.0;
    for (double t = 0; t < total_hours; t += time_step) {
        // Example solar irradiance model: peak at noon (simplified)
        double irradiance = 800 * sin((M_PI / 12.0) * (t + 3)); // Peak irradiance at noon ~ 800 W/m^2
        if (irradiance < 0) irradiance = 0; // No negative irradiance
        // Calculate energy for current time step
        double energy = efficiency * area * num_panels * irradiance * time_step; // kWh
        total_energy += energy;
    }
    return total_energy;
}

int main() {
    // Simulate solar energy generation
    double total_energy_generated = simulate_solar_generation(
        SOLAR_PANEL_EFFICIENCY, PANEL_AREA, NUM_PANELS, TOTAL_HOURS, TIME_STEP);

    // Output the total energy produced
    printf("Renewable Energy Simulation:\n");
    printf("Total Energy Produced: %.2f kWh\n", total_energy_generated);

    return 0;
}
