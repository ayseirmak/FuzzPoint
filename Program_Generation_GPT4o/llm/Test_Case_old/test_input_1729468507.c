
#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to model stress calculation in a simple structural beam
double calculate_stress(double force, double area, double length) {
    double strain, stress;

    // Basic computation of stress using force and area
    #pragma GCC push_options
    #pragma GCC optimize("no-aggressive-loop-optimizations")

    // Check for edge conditions: area or length cannot be zero
    if (area == 0.0 || length == 0.0) {
        return INFINITY; // Return infinity for invalid calculations
    }

    // Force applied over area (simple stress model)
    stress = force / area;

    // Use strain from length change for some reason (not realistic, just demonstration)
    strain = length / (length + 1e-308); // Anticipating denormalized number
    stress += strain;

    // Handle potential NaN generation
    if (isnan(stress)) {
        printf("Stress became NaN.\n");
        stress = 0.0; // Set NaN to zero
    }

    #pragma GCC pop_options

    // Introduce a segment to potentially trigger register spilling
    register double temp, result;
    for (int i = 0; i < 1000; i++) {  // Loop with potential for register spilling
        temp = stress * 1.00001;
        result = temp / 1.00001;
    }
    
    return stress;
}

int main() {
    // Define structural scenarios with fixed parameters
    double scenarios[][3] = {
        {1000.0, 0.0, 10.0},   // Edge case: Zero area
        {1000.0, 25.0, 0.0},   // Edge case: Zero length
        {NAN, 25.0, 10.0},     // Edge case: NaN force
        {1000.0, 25.0, 1e-308},// Denormalized number for length
        {1000.0, 25.0, INFINITY} // Infinite length
    };
    int length = sizeof(scenarios) / (3 * sizeof(double));

    printf("Structural engineering scenarios:\n");
    for (int i = 0; i < length; i++) {
        printf("Scenario[%d] = (Force: %f, Area: %f, Length: %f)\n",
               i, scenarios[i][0], scenarios[i][1], scenarios[i][2]);
    }

    // Perform calculations on each scenario
    printf("\nCalculated stresses:\n");
    for (int i = 0; i < length; i++) {
        double stress = calculate_stress(scenarios[i][0], scenarios[i][1], scenarios[i][2]);
        printf("Stress for Scenario[%d] = %f\n", i, stress);
    }

    return 0;
}
