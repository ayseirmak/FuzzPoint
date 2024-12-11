
#include <stdio.h>
#include <math.h>
#include <float.h>

// Macros to define constants used for computations
#define GRAVITY 9.80665L     // Standard gravity in m/s^2
#define AIR_DENSITY 1.225L   // Sea level standard air density in kg/m³

// Structure to represent an aerospace object with its properties
typedef struct {
    long double mass;          // Mass of the object in kg
    long double velocity;      // Velocity of the object in m/s
    long double altitude;      // Current altitude in meters
} AerospaceObject;

// Function handling special floating-point values
void handle_special_values(long double value) {
    switch (fpclassify(value)) {
        case FP_ZERO:
            printf("Value is zero.\n");
            break;
        case FP_INFINITE:
            printf("Value is infinite.\n");
            break;
        case FP_NAN:
            printf("Value is NaN.\n");
            break;
        case FP_SUBNORMAL:
            printf("Value is subnormal.\n");
            break;
        default:
            printf("Value is normal.\n");
            break;
    }
}

// Recursive function to simulate altitude change due to velocity and gravity
long double recursive_altitude_change(AerospaceObject *object, int depth, int maxDepth) {
    if (depth >= maxDepth) {
        return object->altitude;
    }

    long double airResistance = 0.5L * AIR_DENSITY * object->velocity * object->velocity;
    long double acceleration = (object->mass * GRAVITY - airResistance) / object->mass;

    object->altitude += object->velocity + 0.5L * acceleration;
    object->velocity += acceleration;

    // Handle special values by checking each computed value
    handle_special_values(object->altitude);
    return recursive_altitude_change(object, depth + 1, maxDepth);
}

int main() {
    // Initialize the aerospace object with some arbitrary initial values
    AerospaceObject spacecraft = {1000.0L, 250.0L, 10000.0L};

    printf("Initial Conditions: Mass = %.3Lf kg, Velocity = %.3Lf m/s, Altitude = %.3Lf m\n", 
           spacecraft.mass, spacecraft.velocity, spacecraft.altitude);
    
    // Simulate altitude change over time
    printf("Simulating altitude change...\n");
    long double final_altitude = recursive_altitude_change(&spacecraft, 0, 5);
    printf("Final Altitude: %.10Le m\n", final_altitude);
    
    return 0;
}
