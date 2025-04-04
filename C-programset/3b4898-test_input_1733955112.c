
#include <stdio.h>
#include <math.h>

// Define constants for the control system
#define MASS 1.0        // Mass of the object (kg)
#define DAMPING 0.5     // Damping coefficient (Ns/m)
#define SPRING_CONST 2.0 // Spring constant (N/m)
#define TIME_STEP 0.01  // Time step for the simulation (seconds)
#define SIMULATION_TIME 10.0 // Total simulation duration (seconds)

// Function to simulate the state-space representation of a mass-spring-damper system
void simulate_mass_spring_damper(double mass, double damping, double spring_const, double time_step, double total_time) {
    double state[2] = {1.0, 0.0}; // Initial conditions: [position, velocity]
    double a = -(damping / mass); // First derivative coefficient
    double b = -(spring_const / mass); // Second derivative coefficient

    printf("Time(s) Position(m) Velocity(m/s)\n");
    for (double t = 0.0; t <= total_time; t += time_step) {
        // Update states using a basic Euler integration method
        double position = state[0];
        double velocity = state[1];
        double acceleration = a * velocity + b * position;
        
        state[0] += time_step * velocity;
        state[1] += time_step * acceleration;

        if (fmod(t, 1.0) < time_step) // Print output per second for brevity
            printf("%8.2f %11.5f %13.5f\n", t, state[0], state[1]);
    }
}

int main() {
    // Run the simulation for the mass-spring-damper system
    simulate_mass_spring_damper(MASS, DAMPING, SPRING_CONST, TIME_STEP, SIMULATION_TIME);
    return 0;
}
