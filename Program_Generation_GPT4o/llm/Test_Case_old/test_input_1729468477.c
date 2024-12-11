
#include <stdio.h>
#include <math.h>

// Define a structure for celestial body
typedef struct {
    double mass;    // Mass of the celestial body (in kilograms)
    double radius;  // Radius of the celestial body (in meters)
    double distance; // Distance from another celestial body (in meters)
} CelestialBody;

// Compute gravitational force between two celestial bodies
double compute_gravitational_force(CelestialBody body1, CelestialBody body2) {
    const double G = 6.67430e-11;  // Gravitational constant
    // Compute force using Newton's law of universal gravitation
    double force = G * (body1.mass * body2.mass) / (body1.distance * body1.distance);
    return force;
}

// Calculate gravitational potential energy between two celestial bodies
double compute_gravitational_potential_energy(CelestialBody body1, CelestialBody body2) {
    const double G = 6.67430e-11;  // Gravitational constant
    return -G * (body1.mass * body2.mass) / body1.distance;
}

int main() {
    // Example: Two celestial bodies (e.g., Earth and Moon)
    CelestialBody earth = {5.972e24, 6.371e6, 0.0};       // Earth mass(kg) and radius(m)
    CelestialBody moon = {7.348e22, 1.737e6, 3.844e8};    // Moon mass(kg), radius(m), and distance(m)

    double force = compute_gravitational_force(earth, moon);
    double potential_energy = compute_gravitational_potential_energy(earth, moon);

    // Show results with conditional floating-point comparisons
    printf("Gravitational Force: %e Newtons\n", force);
    if (force > 1e20) {
        printf("The gravitational force is extremely large.\n");
    } else {
        printf("The gravitational force is moderate.\n");
    }

    printf("Gravitational Potential Energy: %e Joules\n", potential_energy);
    if (potential_energy < -1e29) {
        printf("The gravitational potential energy is extremely negative, indicating a strong attraction.\n");
    } else {
        printf("The gravitational potential energy is moderate.\n");
    }

    return 0;
}
