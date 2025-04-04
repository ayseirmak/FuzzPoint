
#include <stdio.h>
#include <math.h>

// Structure to represent a marine vessel and its properties
typedef struct {
    double mass;        // Mass of the vessel in kilograms
    double drag_coefficient;  // Coefficient of drag
    double lift_coefficient;  // Coefficient of lift
    double cross_sectional_area; // Cross-sectional area in square meters
} MarineVessel;

// Function to calculate the drag force on the vessel
double calculate_drag_force(MarineVessel vessel, double velocity) {
    // Simplified drag force equation: F_drag = 0.5 * Cd * A * rho * v^2
    double water_density = 1025.0; // Density of seawater in kg/m^3
    return 0.5 * vessel.drag_coefficient * vessel.cross_sectional_area * water_density * velocity * velocity;
}

// Function to calculate the lift force on the vessel
double calculate_lift_force(MarineVessel vessel, double velocity) {
    // Simplified lift force equation: F_lift = 0.5 * Cl * A * rho * v^2
    double water_density = 1025.0; // Density of seawater in kg/m^3
    return 0.5 * vessel.lift_coefficient * vessel.cross_sectional_area * water_density * velocity * velocity;
}

// Function to update the position and velocity of the vessel
void update_vessel_position(MarineVessel vessel, double *position, double *velocity, double dt) {
    double drag_force = calculate_drag_force(vessel, *velocity);
    double lift_force = calculate_lift_force(vessel, *velocity);
    double net_force = lift_force - drag_force; // Assuming lift opposes drag for simplicity

    double acceleration = net_force / vessel.mass;
    *velocity += acceleration * dt;
    *position += *velocity * dt;
}

int main() {
    MarineVessel vessel = {5000.0, 0.82, 0.3, 20.0}; // mass=5000kg, Cd=0.82, Cl=0.3, area=20m^2

    double position = 0.0; // Initial position in meters
    double velocity = 5.0; // Initial velocity in m/s (approx. 18 km/h)
    double dt = 0.1;       // Time step in seconds

    // Simulate for 100 seconds
    int num_steps = 1000;
    for (int i = 0; i < num_steps; ++i) {
        update_vessel_position(vessel, &position, &velocity, dt);
        // Print the position every 100 steps
        if (i % 100 == 0) {
            printf("Time: %.1f s, Position: %.2f m, Velocity: %.2f m/s\n", i * dt, position, velocity);
        }
    }

    return 0;
}
