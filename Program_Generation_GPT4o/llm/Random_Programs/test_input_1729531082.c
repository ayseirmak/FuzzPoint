
#include <stdio.h>
#include <math.h>

// Structure to represent a beam in structural engineering
typedef struct {
    double length;       // Length of the beam in meters
    double width;        // Width of the beam in meters
    double depth;        // Depth of the beam in meters
    double density;      // Material density in kg/m^3
} Beam;

// Function to compute the volume of the beam
double compute_volume(Beam beam) {
    return beam.length * beam.width * beam.depth;
}

// Function to compute the mass of the beam
double compute_mass(Beam beam) {
    double volume = compute_volume(beam);
    return volume * beam.density;
}

// Function to compute the moment of inertia of a rectangular section beam
double compute_moment_of_inertia(Beam beam) {
    return (beam.width * pow(beam.depth, 3)) / 12.0;
}

// Main function to perform structural calculations
int main() {
    // Define a beam with fixed dimensions and properties
    Beam beam = { 5.0, 0.3, 0.5, 2500.0 }; // length: 5m, width: 0.3m, depth: 0.5m, density: 2500kg/m^3

    // Compute the mass of the beam
    double mass = compute_mass(beam);

    // Compute the moment of inertia of the beam
    double moment_of_inertia = compute_moment_of_inertia(beam);

    // Fixed deterministic outputs related to beam properties
    if (mass > 0 && moment_of_inertia > 0) {
        printf("Output: 1\n"); // both mass and moment of inertia are positive
    } else {
        printf("Output: 0\n");
    }

    return 0;
}
