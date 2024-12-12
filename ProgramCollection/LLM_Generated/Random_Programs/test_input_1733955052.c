
#include <stdio.h>
#include <math.h>

// Define a vector in 3D space
typedef struct {
    double x, y, z;
} Vector3;

// Function to normalize a vector
Vector3 normalize(Vector3 v) {
    double magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    if (magnitude == 0) return (Vector3) {0, 0, 0};  // Avoid division by zero
    return (Vector3) {v.x / magnitude, v.y / magnitude, v.z / magnitude};
}

// Function to calculate the dot product of two vectors
double dot_product(Vector3 a, Vector3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Function to calculate the cross product of two vectors
Vector3 cross_product(Vector3 a, Vector3 b) {
    return (Vector3) {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

// Function to calculate the reflection vector from a light source
Vector3 reflect(Vector3 light_dir, Vector3 normal) {
    double dot = dot_product(light_dir, normal);
    return (Vector3) {
        light_dir.x - 2 * dot * normal.x,
        light_dir.y - 2 * dot * normal.y,
        light_dir.z - 2 * dot * normal.z
    };
}

// Function to simulate lighting effect
double calculate_lighting(Vector3 normal, Vector3 light_dir, Vector3 view_dir) {
    Vector3 reflect_dir = reflect(normalize(light_dir), normalize(normal));
    double specular_strength = 0.5;
    double specular = pow(fmax(dot_product(reflect_dir, normalize(view_dir)), 0.0), 32);
    return specular_strength * specular;
}

int main() {
    // Define the normal vector at a surface point (e.g., VR object)
    Vector3 normal = {0.0, 0.0, 1.0};

    // Define a light source direction
    Vector3 light_dir = {0.0, -1.0, -1.0};

    // Define the direction of the viewer
    Vector3 view_dir = {0.0, 0.0, -1.0};

    // Calculate lighting effect
    double lighting = calculate_lighting(normal, light_dir, view_dir);

    printf("Lighting Simulation in VR:\n");
    printf("Specular Lighting Intensity: %.6f\n", lighting);

    return 0;
}
