
#include <stdio.h>
#include <math.h>

// Define a structure to represent a 2D point
typedef struct {
    double x, y;
} Point;

// Function to perform Fused Multiply-Add (FMA)
double fma_optimized(double a, double b, double c) {
    // FMA: a * b + c
    return fma(a, b, c);
}

// Function to perform rotation of a point around origin
Point rotate_point(Point p, double angle) {
    double cos_theta = cos(angle);
    double sin_theta = sin(angle);
    
    Point rotated;
    
    // Utilize FMA for rotation to optimize
    rotated.x = fma_optimized(p.x, cos_theta, -p.y * sin_theta);
    rotated.y = fma_optimized(p.x, sin_theta, p.y * cos_theta);
    
    return rotated;
}

// Function to scale a point
Point scale_point(Point p, double scale_x, double scale_y) {
    Point scaled;
    scaled.x = p.x * scale_x;
    scaled.y = p.y * scale_y;
    return scaled;
}

// Example of various floating-point operations
double perform_operations(double a, double b) {
    double addition = a + b;
    double subtraction = a - b;
    double multiplication = a * b;
    double division = b != 0 ? a / b : 0;
    double modulus = fmod(a, b);

    // Print operations
    printf("Addition: %f\n", addition);
    printf("Subtraction: %f\n", subtraction);
    printf("Multiplication: %f\n", multiplication);
    printf("Division: %f\n", division);
    printf("Modulus: %f\n", modulus);
    
    return addition + subtraction + multiplication + division + modulus;
}

int main() {
    // Fixed values for points
    Point p = {2.0, 3.0};
    
    // Define rotation angle in radians (e.g., 45 degrees)
    double angle = M_PI / 4;
    
    // Rotate point
    Point rotated_point = rotate_point(p, angle);
    printf("Rotated Point: (x: %f, y: %f)\n", rotated_point.x, rotated_point.y);
    
    // Scale point
    Point scaled_point = scale_point(p, 2.0, 0.5);
    printf("Scaled Point: (x: %f, y: %f)\n", scaled_point.x, scaled_point.y);
    
    // Perform complex floating-point operations
    double result = perform_operations(7.5, 2.3);
    printf("Result of all floating-point operations: %f\n", result);
    
    return 0;
}
