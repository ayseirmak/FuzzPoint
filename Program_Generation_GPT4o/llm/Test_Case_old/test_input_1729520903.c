
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define structure for a renewable energy plant
typedef struct {
    long double efficiency_perc;
    double power_generated_MW;
    double max_power_MW;
} RenewablePlant;

// Function to calculate adjusted power output considering efficiency and some edge cases
double calculate_power_output(RenewablePlant *plant) {
    if (isnan(plant->efficiency_perc) || isnan(plant->power_generated_MW)) {
        return NAN;
    }
    if (isinf(plant->efficiency_perc) || isinf(plant->power_generated_MW)) {
        return INFINITY;
    }
    
    // Compute power factoring in efficiency
    long double effective_efficiency = fminl(plant->efficiency_perc / 100.0, 1.0L);
    double actual_power_output = effective_efficiency * plant->power_generated_MW;

    // Rounding behavior handling
    if (actual_power_output > plant->max_power_MW) {
        actual_power_output = plant->max_power_MW;
    }

    // Underflow condition
    if (actual_power_output < DBL_MIN) {
        actual_power_output = 0.0;
    }
    
    return actual_power_output;
}

int main() {
    // Define fixed values for renewable plants
    RenewablePlant solar_plant = {99.999L, 50.0, 60.0};
    RenewablePlant wind_plant = {85.555L, 70.0, 100.0};
    RenewablePlant water_plant = {120.0L, NAN, 80.0};   // Intentionally using NaN
    RenewablePlant over_plant = {50.0L, INFINITY, 200.0}; // Intentionally using Infinity

    RenewablePlant plants[] = {solar_plant, wind_plant, water_plant, over_plant};
    int num_plants = sizeof(plants) / sizeof(plants[0]);

    for (int i = 0; i < num_plants; ++i) {
        double output = calculate_power_output(&plants[i]);
        printf("Plant %d adjusted power output: %f MW\n", i+1, output);
    }

    return 0;
}
