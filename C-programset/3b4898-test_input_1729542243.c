
#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to perform perspective division in a 3D rendering scenario
void perspective_division(double vertices[][4], int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        // Basic check to prevent division by zero
        if (vertices[i][3] != 0.0) {
            vertices[i][0] /= vertices[i][3];
            vertices[i][1] /= vertices[i][3];
            vertices[i][2] /= vertices[i][3];
        } else {
            // Handle the infinity case by assigning a large number
            vertices[i][0] = vertices[i][1] = vertices[i][2] = DBL_MAX;
        }
        
        // Check for denormalized numbers and assign zero if encountered
        if (fabs(vertices[i][0]) < DBL_MIN) vertices[i][0] = 0.0;
        if (fabs(vertices[i][1]) < DBL_MIN) vertices[i][1] = 0.0;
        if (fabs(vertices[i][2]) < DBL_MIN) vertices[i][2] = 0.0;

        // Handling NaN value propagation
        if (isnan(vertices[i][0]) || isnan(vertices[i][1]) || isnan(vertices[i][2])) {
            printf("NaN encountered in vertex[%d]\n", i);
        }
    }
}

// Function to demonstrate operations with subnormal numbers
void handle_subnormal_numbers() {
    volatile double denormalized_multiplication = 1.0e-308 * 1.0e-308;
    volatile double result = denormalized_multiplication / 1.0e-308;  // Potentially subnormal

    if (fpclassify(result) == FP_SUBNORMAL) {
        printf("Result is subnormal: %e\n", result);
    }
}

int main() {
    // Define a set of vertices with a w coordinate for perspective division
    double vertices[3][4] = {
        {1.0, 2.0, 3.0, 4.0},
        {5.0, 6.0, 7.0, 0.0},  // This will cause an infinity handling
        {8.0, 9.0, NAN, 2.0}   // This contains a NaN
    };
    
    // Perform perspective division and handle special cases
    perspective_division(vertices, 3);

    // Perform operations involving subnormal numbers for mid-end optimizations
    handle_subnormal_numbers();

    return 0;
}
