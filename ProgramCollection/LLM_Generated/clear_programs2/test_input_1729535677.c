
#include <stdio.h>
#include <math.h>

// Define mathematical constants if not present
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif

// Define struct for a celestial body
typedef struct {
    long double position;
    long double velocity;
    long double mass;
} CelestialBody;

// Function to simulate gravitational interaction
void simulate_gravity(CelestialBody* body, long long time_steps) {
    const long double G = 6.67430e-11L;  // Gravitational constant
    const long double dt = 0.1L; // Time step
    const long double central_mass = 1.989e30L; // Mass of the central body (e.g., the sun)
    
    for (long long i = 0; i < time_steps; ++i) {
        long double force = -(G * central_mass * body->mass) / (body->position * body->position);
        long double acceleration = force / body->mass;
        body->velocity += acceleration * dt;
        body->position += body->velocity * dt;
    }
    
    // Display the final state
    printf("Final position: %.12Lf\n", body->position);
    printf("Final velocity: %.12Lf\n", body->velocity);
}

// Function to explore floating-point edge cases
void floating_point_edge_cases() {
    // Using mathematical constants
    double area_circle = M_PI * pow(1.0, 2); // Area of circle with radius 1
    printf("Area of unit circle using PI: %.15f\n", area_circle);

    // Infinity arithmetic
    float inf = 1.0f / 0.0f; // Positive infinity
    printf("Infinity plus 1: %f\n", inf + 1.0f);
    
    // Representation of -0.0
    float neg_zero = -0.0f;
    printf("Representation of -0.0f: %.1f\n", neg_zero);
    
    // Check special value using conditionals
    if (inf > 1.0f) {
        printf("Infinity is greater than 1.0f\n");
    } else {
        printf("Infinity handling issue!\n");
    }
}

int main() {
    CelestialBody planet = {1.496e11L, 0.0L, 5.972e24L}; // Initial position, velocity, mass (Earth-like)
    long long time_steps = 1000000LL;

    printf("Starting simulation...\n");
    simulate_gravity(&planet, time_steps);
    
    printf("Exploring floating-point edge cases...\n");
    floating_point_edge_cases();

    return 0;
}
