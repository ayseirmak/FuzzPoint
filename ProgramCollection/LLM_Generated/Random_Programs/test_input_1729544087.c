
#include <stdio.h>
#include <math.h>

// Structure to represent a mass-spring-damper system
typedef struct {
    double mass;       // Mass of the object
    double spring_constant;  // Spring constant (stiffness)
    double damping_coefficient; // Damping coefficient
} MassSpringDamper;

// Function to calculate the net force on the mass
double calculate_force(MassSpringDamper msd, double displacement, double velocity) {
    double spring_force = -msd.spring_constant * displacement;
    double damping_force = -msd.damping_coefficient * velocity;
    return spring_force + damping_force;
}

// Function to update the displacement and velocity of the system
void update_system(MassSpringDamper msd, double *displacement, double *velocity, double dt) {
    double force = calculate_force(msd, *displacement, *velocity);
    double acceleration = force / msd.mass;
    *velocity += acceleration * dt;
    *displacement += *velocity * dt;
}

int main() {
    MassSpringDamper system = {1.0, 10.0, 1.0}; // mass=1kg, spring constant=10N/m, damping=1Ns/m

    double displacement = 1.0; // Initial displacement in meters
    double velocity = 0.0;     // Initial velocity in meters per second
    double dt = 0.01;          // Time step in seconds

    // Simulate for 10 seconds
    int num_steps = 1000;
    for (int i = 0; i < num_steps; ++i) {
        update_system(system, &displacement, &velocity, dt);
        // Print the displacement every 100 steps
        if (i % 100 == 0) {
            printf("Time: %.2f s, Displacement: %.4f m\n", i * dt, displacement);
        }
    }

    return 0;
}
