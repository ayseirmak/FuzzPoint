
#include <stdio.h>

#define LENGTH 10.0      // Length of the beam in meters
#define NUM_POINTS 100   // Number of discrete points along the beam
#define E 210e9          // Young's modulus in Pascals (Pa)
#define I 8.33e-6        // Moment of inertia in m^4
#define LOAD 1000.0      // Uniform load in Newtons/m

// Function to calculate deflection along the beam
void calculate_deflection(double *deflection) {
    double dx = LENGTH / (NUM_POINTS - 1);
    double load_per_node = LOAD * dx;

    // Initialize an array to store bending moments
    double moments[NUM_POINTS] = {0.0};

    // Calculating moments at each point using finite difference method
    for (int i = NUM_POINTS - 2; i >= 0; i--) {
        moments[i] = moments[i + 1] + load_per_node * dx;
    }

    // Calculating deflection using moments
    for (int i = 1; i < NUM_POINTS; i++) {
        deflection[i] = deflection[i - 1] + moments[i] * dx / (E * I);
    }
}

int main() {
    double deflection[NUM_POINTS] = {0.0};

    // Calculate the deflection of the cantilever beam
    calculate_deflection(deflection);

    // Output the deflection at each point
    printf("Position (m)   Deflection (m)\n");
    printf("-------------------------------\n");
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("%12.2f     %14.8f\n", i * (LENGTH / (NUM_POINTS - 1)), deflection[i]);
    }

    return 0;
}
