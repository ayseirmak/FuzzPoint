
#include <stdio.h>
#include <math.h>

// Gravitational constant (G) in (km^3)/(kg*s^2)
#define GRAVITATIONAL_CONSTANT 6.67430e-20

// Structure to represent a celestial body
typedef struct {
    double x, y, z;  // Position of the body in 3D space (in km)
    double mass;     // Mass of the body (in kg)
} CelestialBody;

// Function to calculate the Euclidean distance between two celestial bodies
double calculate_distance(CelestialBody a, CelestialBody b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

// Function to calculate the gravitational force between two celestial bodies
double calculate_gravitational_force(CelestialBody a, CelestialBody b) {
    double distance = calculate_distance(a, b);
    // Gravitational force formula: (G * m1 * m2) / distance^2
    if (distance == 0) return 0;  // Avoid division by zero
    return (GRAVITATIONAL_CONSTANT * a.mass * b.mass) / (distance * distance);
}

// Function to calculate gravitational potential energy between two celestial bodies
double calculate_potential_energy(CelestialBody a, CelestialBody b) {
    double distance = calculate_distance(a, b);
    // Potential energy formula: -(G * m1 * m2) / distance
    if (distance == 0) return 0;  // Avoid division by zero
    return -(GRAVITATIONAL_CONSTANT * a.mass * b.mass) / distance;
}

int main() {
    // Define celestial bodies with fixed values
    CelestialBody solar_system[] = {
        {0.0, 0.0, 0.0, 1.989e30},  // Sun
        {57.91e6, 0.0, 0.0, 3.285e23},  // Mercury
        {108.2e6, 0.0, 0.0, 4.867e24},  // Venus
        {149.6e6, 0.0, 0.0, 5.972e24},  // Earth
        {227.9e6, 0.0, 0.0, 6.39e23}   // Mars
    };
    
    int num_bodies = sizeof(solar_system) / sizeof(solar_system[0]);

    // Calculate gravitational forces and potential energies between celestial bodies
    printf("Astronomical Calculations:\n");
    for (int i = 0; i < num_bodies; i++) {
        for (int j = i + 1; j < num_bodies; j++) {
            double force = calculate_gravitational_force(solar_system[i], solar_system[j]);
            double energy = calculate_potential_energy(solar_system[i], solar_system[j]);
            printf("Between Body %d and Body %d: Force = %.3e N, Potential Energy = %.3e J\n",
                   i+1, j+1, force, energy);
        }
    }
    
    return 0;
}
