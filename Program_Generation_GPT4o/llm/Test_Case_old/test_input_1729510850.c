
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

// Define a structure to represent a point in 3D space
typedef struct {
    long double x, y, z;  // Coordinates
} Point3D;

// Function to compute the area of a triangle given 3 points
long double compute_area(Point3D a, Point3D b, Point3D c) {
    // Using Heron's formula
    volatile long double ab = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
    volatile long double bc = sqrt((b.x - c.x)*(b.x - c.x) + (b.y - c.y)*(b.y - c.y) + (b.z - c.z)*(b.z - c.z));
    volatile long double ca = sqrt((c.x - a.x)*(c.x - a.x) + (c.y - a.y)*(c.y - a.y) + (c.z - a.z)*(c.z - a.z));
    
    long double s = (ab + bc + ca) / 2.0;
    return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

// Function to deliberately trigger constant folding
long double precompute_value() {
    // Expression will be folded during compile time
    return (1.0e20L + 2.0L) - 1.0e20L;
}

int main() {
    Point3D point1 = {0.0L, 0.0L, 0.0L};
    Point3D point2 = {5.0L, 0.0L, 0.0L};
    Point3D point3 = {0.0L, 5.0L, 0.0L};

    // Display the area of the triangle
    printf("Area of triangle: %Lf\n", compute_area(point1, point2, point3));

    // Display a constant folded value
    printf("Constant folded value: %Lf\n", precompute_value());

    // Demonstrate handling of special floating-point values
    volatile float zero = 0.0f;
    volatile float infinity = 1.0f / zero;
    volatile float neg_infinity = -1.0f / zero;
    volatile float nan_value = zero / zero;

    printf("Infinity: %f, Negative Infinity: %f, NaN: %f\n", infinity, neg_infinity, nan_value);

    // Demonstrate underflow
    volatile float small_value = 1e-45f;
    small_value /= 2.0f;
    printf("Underflow example: %e\n", small_value);

    return (small_value == 0.0f) ? 1 : 0;
}
