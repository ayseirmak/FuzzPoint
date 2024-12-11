
#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <float.h>

// Define a constant number of vehicles in the fleet
#define NUM_VEHICLES 5

// Function to calculate fuel efficiency using reciprocal transformation
double calculate_fuel_efficiency(double distance_traveled, double fuel_used) {
    // Division by zero exception handling
    if (fuel_used == 0.0) {
        return INFINITY; // Infinite efficiency, unrealistic but handled
    }
    
    // Return the reciprocal of fuel consumption (per 100km for example)
    return distance_traveled / fuel_used;
}

void check_exceptions() {
    // Check for floating-point exceptions
    if (fetestexcept(FE_DIVBYZERO)) {
        printf("Warning: Division by zero encountered.\n");
        feclearexcept(FE_DIVBYZERO);
    }
    if (fetestexcept(FE_OVERFLOW)) {
        printf("Warning: Floating-point overflow occurred.\n");
        feclearexcept(FE_OVERFLOW);
    }
    if (fetestexcept(FE_UNDERFLOW)) {
        printf("Warning: Floating-point underflow occurred.\n");
        feclearexcept(FE_UNDERFLOW);
    }
}

int main() {
    // Initialize data for the fleet of vehicles
    double distances[NUM_VEHICLES] = {100.0, 200.0, 150.0, 120.0, 0.0};
    double fuels[NUM_VEHICLES] = {10.0, 15.0, 0.0, DBL_MIN / 2, 5.0}; // Including zero and denormalized number

    // Handle any potential exceptions to quickly identify issues
    feclearexcept(FE_ALL_EXCEPT);

    printf("Fuel Efficiency (km/l):\n");
    for (int i = 0; i < NUM_VEHICLES; i++) {
        // Calculate fuel efficiency for each vehicle
        double efficiency = calculate_fuel_efficiency(distances[i], fuels[i]);

        // Check for and handle exceptions
        check_exceptions();

        // Safely format and print the result
        if (isinf(efficiency)) {
            printf("Vehicle %d: Infinite (handled division by zero)\n", i + 1);
        } else {
            printf("Vehicle %d: %0.2f\n", i + 1, efficiency);
        }
    }

    return 0;
}
