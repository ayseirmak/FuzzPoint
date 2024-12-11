
#include <stdio.h>
#include <math.h>
#include <float.h>

// Macro to define a safe maximum speed constant
#define MAX_SAFE_SPEED 250.0

// Structure to represent a vehicle speed control system
typedef struct {
    double current_speed; // Current vehicle speed in km/h
    double target_speed;  // Target speed in km/h
    double throttle;      // Throttle level as a percentage
} SpeedControlSystem;

// Function to adjust the throttle based on the speed feedback loop
void adjust_throttle(SpeedControlSystem* system, int iterations) {
    const double adjustment_factor = 0.05; // Throttle adjustment factor

    for (int i = 0; i < iterations; i++) {
        // Calculate speed error
        double speed_error = system->target_speed - system->current_speed;

        // Handle catastrophic cancellation
        double precise_adjustment = (speed_error - sin(speed_error)) / (1.0 + fabs(speed_error));

        // Update the throttle using speed error and adjustment factor
        system->throttle += adjustment_factor * precise_adjustment;

        // Representation of -0.0 handling
        if (system->throttle == -0.0) {
            system->throttle = 0.0;
        }

        // Update current speed based on throttle
        system->current_speed += system->throttle * cos(system->throttle);

        // Check for overflow
        if (system->current_speed > DBL_MAX) {
            system->current_speed = DBL_MAX; // Cap speed to maximum double value
        }

        // Logarithmic damping to simulate drag
        if (system->current_speed > MAX_SAFE_SPEED) {
            system->current_speed -= log(system->current_speed) * 0.1;
        }
    }
}

int main() {
    // Initialize speed control system with given starting values
    SpeedControlSystem system = {
        50.0,   // Current speed (initial)
        120.0,  // Target speed
        0.0     // Initial throttle
    };

    // Perform throttle adjustment over a number of iterations
    adjust_throttle(&system, 100);

    // Final check to determine if the vehicle reached a stable high speed
    int result = (system.current_speed > 100.0) ? 1 : 0;

    return result;
}
