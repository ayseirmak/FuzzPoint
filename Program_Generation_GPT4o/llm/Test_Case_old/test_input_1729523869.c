
#include <stdio.h>
#include <math.h>
#include <float.h>

// Simple 3D vector struct
typedef struct {
    double x, y, z;
} Vec3;

// Function to compute dot product of two vectors
double dot_product(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// Normalize a vector
Vec3 normalize(Vec3 v) {
    double mag = sqrt(dot_product(v, v));
    return (Vec3) {v.x / mag, v.y / mag, v.z / mag};
}

// Function to trace a ray and determine color
Vec3 ray_trace(Vec3 ray_origin, Vec3 ray_direction) {
    // Sphere centered at origin with radius 1
    Vec3 sphere_center = {0.0, 0.0, -5.0};
    double sphere_radius = 1.0;
    
    // Compute quadratic terms
    Vec3 oc = {ray_origin.x - sphere_center.x, ray_origin.y - sphere_center.y, ray_origin.z - sphere_center.z};
    double a = dot_product(ray_direction, ray_direction);
    double b = 2.0 * dot_product(oc, ray_direction);
    double c = dot_product(oc, oc) - sphere_radius * sphere_radius;
    
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // No intersection, return background color
        return (Vec3) {0.0, 0.0, 0.0};
    } else {
        // Intersection, calculate color
        double t = (-b - sqrt(discriminant)) / (2.0 * a);
        if (t < 0) t = (-b + sqrt(discriminant)) / (2.0 * a);

        Vec3 hit_point = {ray_origin.x + t * ray_direction.x,
                          ray_origin.y + t * ray_direction.y,
                          ray_origin.z + t * ray_direction.z};

        Vec3 normal = {hit_point.x - sphere_center.x, hit_point.y - sphere_center.y, hit_point.z - sphere_center.z};
        normal = normalize(normal);

        // Simple shading based on the normal vector
        double intensity = dot_product(normal, (Vec3) {0.0, 0.0, 1.0});
        if (intensity < 0) intensity = 0;
        
        return (Vec3) {intensity, intensity, intensity};
    }
}

int main() {
    // Define a ray origin and direction
    Vec3 ray_origin = {0.0, 0.0, 0.0};
    Vec3 ray_direction = normalize((Vec3) {0.0, 0.0, -1.0});

    // Trace ray
    Vec3 color = ray_trace(ray_origin, ray_direction);
    printf("Ray color: R=%.3f G=%.3f B=%.3f\n", color.x, color.y, color.z);

    // Floating-point edge cases
    double zero = 0.0;
    double inf = 1.0 / zero;  // Infinity
    double nan = sqrt(-1.0);  // Not-a-Number (NaN)
    double neg_inf = -1.0 / zero; // Negative Infinity
    double tiny = DBL_MIN / 2.0;  // Underflow example

    printf("Infinity: %f\n", inf);
    printf("NaN: %f\n", nan);
    printf("Negative Infinity: %f\n", neg_inf);
    printf("Underflow (tiny number): %e\n", tiny);

    // Handling denormalized numbers
    double denorm = tiny / 2.0;
    printf("Denormalized number: %e\n", denorm);

    // Handling rounding behavior
    double rounded_value = rint(2.6);
    printf("Rounding 2.6: %f\n", rounded_value);

    // Large numbers that can cause overflow
    double large1 = 1.0e308;
    double large2 = 1.0e308;
    double result = large1 * large2; // This should overflow
    printf("Overflow example: %f\n", result);

    return 0;
}
