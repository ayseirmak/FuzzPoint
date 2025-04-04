
#include <stdio.h>
#include <math.h>

#define NUM_MASSES 3

typedef struct {
    double mass[NUM_MASSES];         // Masses of the system
    double stiffness[NUM_MASSES];    // Stiffness constants of the system
    double damping[NUM_MASSES];      // Damping coefficients of the system
} MechanicalSystem;

// Function to compute the vibration response for one simulation step
void compute_vibration_response(MechanicalSystem *system, double *displacement, double *velocity, double dt) {
    for(int i = 0; i < NUM_MASSES; i++) {
        double force = -system->stiffness[i] * displacement[i] - system->damping[i] * velocity[i];
        double acceleration = force / system->mass[i];
        velocity[i] += acceleration * dt;
        displacement[i] += velocity[i] * dt;
    }
}

// Main function to simulate the system over time
int main() { 
    MechanicalSystem system = {
        .mass = {1.0, 2.0, 1.5},           // Masses in kg
        .stiffness = {100.0, 150.0, 120.0}, // Stiffness in N/m
        .damping = {5.0, 10.0, 8.0}        // Damping in Ns/m
    };
    
    double displacement[NUM_MASSES] = {0.1, 0.2, 0.15};  // Initial displacements in meters
    double velocity[NUM_MASSES] = {0.0, 0.0, 0.0};       // Initial velocities in m/s
    double dt = 0.01;            // Time step in seconds
    int num_steps = 1000;        // Number of simulation steps

    // Simulate the vibration response
    for(int step = 0; step < num_steps; ++step) {
        compute_vibration_response(&system, displacement, velocity, dt);
        // Print the displacement of each mass every 200 steps
        if (step % 200 == 0) {
            printf("Time: %.2f s\n", step * dt);
            for(int i = 0; i < NUM_MASSES; i++) {
                printf("  Mass %d: Displacement = %.4f m\n", i + 1, displacement[i]);
            }
        }
    }

    return 0;
}
