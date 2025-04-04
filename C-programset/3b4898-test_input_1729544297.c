
#include <stdio.h>
#include <math.h>

// Function to simulate fuel consumption and range estimation
void simulate_fuel_consumption(double initial_fuel, double fuel_efficiency, double total_distance, double interval) {
    double fuel_remaining = initial_fuel;
    double distance_traveled = 0.0;

    printf("Distance (km)   Fuel Remaining (liters)   Estimated Range (km)\n");
    printf("-------------------------------------------------------------\n");

    while (distance_traveled < total_distance && fuel_remaining > 0) {
        double range = fuel_remaining * fuel_efficiency;
        printf("%12.2f %21.2f %25.2f\n", distance_traveled, fuel_remaining, range);

        distance_traveled += interval;
        fuel_remaining -= interval / fuel_efficiency;
    }

    // Final status update
    if (fuel_remaining <= 0) {
        printf("Ran out of fuel after %.2f kilometers.\n", distance_traveled);
    } else {
        printf("Reached the destination at %.2f kilometers with %.2f liters remaining.\n", distance_traveled, fuel_remaining);
    }
}

int main() {
    double initial_fuel = 50.0; // Initial fuel in liters
    double fuel_efficiency = 15.0; // Fuel efficiency in kilometers per liter (km/L)
    double total_distance = 200.0; // Total distance to travel in kilometers
    double interval = 10.0; // Distance interval for the simulation in kilometers

    // Perform the simulation
    simulate_fuel_consumption(initial_fuel, fuel_efficiency, total_distance, interval);

    return 0;
}
