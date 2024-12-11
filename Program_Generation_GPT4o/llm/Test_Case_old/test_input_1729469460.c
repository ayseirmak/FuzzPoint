
#include <stdio.h>
#include <math.h>

// Define a structure to represent a 3D vertex
typedef struct {
    double x, y, z;
} Vertex;

// Function to perform scaling on a vertex
Vertex scale_vertex(Vertex v, double scale_x, double scale_y, double scale_z) {
    Vertex scaled;
    scaled.x = v.x * scale_x;
    scaled.y = v.y * scale_y;
    scaled.z = v.z * scale_z;
    return scaled;
}

// Function to perform rotation around the Z-axis
Vertex rotate_vertex(Vertex v, double angle) {
    double cos_theta = cos(angle);
    double sin_theta = sin(angle);
    
    Vertex rotated;
    rotated.x = cos_theta * v.x - sin_theta * v.y;
    rotated.y = sin_theta * v.x + cos_theta * v.y;
    rotated.z = v.z;
    
    return rotated;
}

// Function to perform translation on a vertex
Vertex translate_vertex(Vertex v, double trans_x, double trans_y, double trans_z) {
    Vertex translated;
    translated.x = v.x + trans_x;
    translated.y = v.y + trans_y;
    translated.z = v.z + trans_z;
    return translated;
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
    // Fixed values for a vertex
    Vertex v = {1.0, 1.0, 1.0};
    
    // Define transformation parameters
    double scale_x = 1.5, scale_y = 0.5, scale_z = 2.0;
    double angle = M_PI / 3; // 60 degrees in radians
    double trans_x = 1.0, trans_y = 2.0, trans_z = -1.0;
    
    // Scale vertex
    Vertex scaled_vertex = scale_vertex(v, scale_x, scale_y, scale_z);
    printf("Scaled Vertex: (x: %f, y: %f, z: %f)\n", scaled_vertex.x, scaled_vertex.y, scaled_vertex.z);
    
    // Rotate vertex
    Vertex rotated_vertex = rotate_vertex(v, angle);
    printf("Rotated Vertex: (x: %f, y: %f, z: %f)\n", rotated_vertex.x, rotated_vertex.y, rotated_vertex.z);
    
    // Translate vertex
    Vertex translated_vertex = translate_vertex(v, trans_x, trans_y, trans_z);
    printf("Translated Vertex: (x: %f, y: %f, z: %f)\n", translated_vertex.x, translated_vertex.y, translated_vertex.z);
    
    // Perform complex floating-point operations
    double result = perform_operations(5.7, 3.2);
    printf("Result of all floating-point operations: %f\n", result);
    
    return 0;
}
