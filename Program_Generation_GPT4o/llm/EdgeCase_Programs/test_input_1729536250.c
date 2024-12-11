
#include <stdio.h>
#include <math.h>
#include <float.h>

// Constants for fuel calculations
#define FUEL_CONSUMPTION_BASE 3.5   // Base fuel consumption in liters per 100 km

// Structure representing vehicle's fuel efficiency parameters
typedef struct {
    double distance;  // Distance traveled in kilometers
    double fuel_used; // Fuel used in liters
} Vehicle;

// Recursive function for extended fuel calculations demonstrating precision handling
double recursive_fuel_efficiency(Vehicle* vehicle, int iterations) {
    if (iterations <= 0) {
        return 0.0;
    }

    // Adjustment factor using catastrophic cancellation example
    long double adjustment = (long double)(vehicle->distance - 1000.0 + 1000.0);

    // Compute efficiency with recursive call
    double current_efficiency = vehicle->fuel_used / adjustment;
    double next_efficiency = recursive_fuel_efficiency(vehicle, iterations - 1);

    // Handle representation of -0.0
    if (current_efficiency == -0.0) {
        current_efficiency = 0.0;
    }

    // Sum efficiencies and handle potential NaN results
    long double total_efficiency = current_efficiency + next_efficiency;
    if (isnan(total_efficiency)) {
        total_efficiency = DBL_MAX;  // Assign maximum double value if NaN
    }

    return (double)total_efficiency;
}

// Function to perform efficiency calculations
double calculate_efficiency(Vehicle* vehicle) {
    double fuel_per_km = FUEL_CONSUMPTION_BASE;

    // Casting in loops between floating-point precisions and handling values
    for (int i = 0; i < 10; i++) {
        long long fuel_int = (long long)(fuel_per_km * 100.0);
        fuel_per_km = (double)((float)fuel_int / 100.0);
    }

    // Initiate recursive efficiency computation over 10 steps
    double computed_efficiency = recursive_fuel_efficiency(vehicle, 10);

    return computed_efficiency * fuel_per_km;
}

int main() {
    // Define vehicle parameters with 1000 km distance and 70 liters of fuel used
    Vehicle myCar = {
        1000.0,  // Distance in km
        70.0     // Fuel used in liters
    };

    // Calculate efficiency
    double efficiency = calculate_efficiency(&myCar);

    // Determine if the efficiency calculation succeeded without triggering NaN
    int result = isnan(efficiency) ? 0 : 1;

    return result;
}
