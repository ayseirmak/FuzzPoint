
#include <stdio.h>
#include <math.h>
#include <float.h>

#define NUM_ITERATIONS 1000000

// Structure to hold flight simulation data
typedef struct {
    double altitude;   // in meters
    double velocity;   // in meters per second
    double thrust;     // in newtons
} FlightData;

// Function to simulate atmospheric conditions impacting a flight path
void simulate_flight_conditions(FlightData *flight) {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        // Simulate changes in thrust and velocity
        flight->thrust = sin(flight->velocity / 300.0) * 5000;
        flight->velocity += flight->thrust * 0.001;

        // Handle edge cases using conditionals
        if (flight->velocity > 400.0) {
            flight->velocity = 400.0;  // Cap velocity
        }

        // Artificially inflate altitude for demonstration
        flight->altitude += sqrt(flight->velocity) * 0.01;

        // Detect overflow and handle it
        if (flight->altitude > 1e5) {
            flight->altitude = 1e5;  // Max altitude
            break;
        }
    }
}

// Demonstrate casting between types
void demonstrate_cast_operations() {
    double value = 123456789.123456;
    float casted_float = (float)value;
    long double casted_long_double = (long double)value;
    long long int casted_long_long = (long long)value;

    printf("Double to float: %.6f\n", casted_float);
    printf("Double to long double: %.10Lf\n", casted_long_double);
    printf("Double to long long: %lld\n", casted_long_long);
}

// Function to show floating-point precision loss
void show_precision_loss() {
    double large_value = 1e308;
    double small_increment = 1e-10;

    for (int i = 0; i < 10; ++i) {
        large_value += small_increment;
    }

    printf("Result after repeated small add: %.10e\n", large_value);
}

// Using a switch statement based on range to simulate actions based on altitude
void handle_altitude_actions(double altitude) {
    switch ((int)(altitude / 10000)) {
        case 0:
            printf("Altitude < 10 km: Climbing phase\n");
            break;
        case 1:
            printf("10 km <= Altitude < 20 km: Cruising phase\n");
            break;
        default:
            printf("Altitude >= 20 km: Transition to descent\n");
    }
}

int main() {
    FlightData simulation = {1000.0, 340.0, 10000.0};

    // Simulate flight conditions
    simulate_flight_conditions(&simulation);

    // Print results from simulation
    printf("Final altitude: %f meters\n", simulation.altitude);
    printf("Final velocity: %f m/s\n", simulation.velocity);
    printf("Final thrust: %f N\n", simulation.thrust);

    // Demonstrate type casts
    demonstrate_cast_operations();

    // Show precision loss
    show_precision_loss();

    // Handle different altitude ranges
    handle_altitude_actions(simulation.altitude);

    return 0;
}
