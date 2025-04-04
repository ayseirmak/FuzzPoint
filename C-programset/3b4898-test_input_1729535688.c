
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>

// Define a structure for a 3D point
typedef struct {
    float x;
    float y;
    float z;
} Point3D;

// Function to apply a transformation using sine and cosine
void transform_point(Point3D* point, float angle) {
    float rad_angle = angle * (float)(M_PI / 180.0);
    float new_x = point->x * cosf(rad_angle) - point->y * sinf(rad_angle);
    float new_y = point->x * sinf(rad_angle) + point->y * cosf(rad_angle);
    point->x = new_x;
    point->y = new_y;
}

// Recursive function that applies transformations and processes floating-point numbers
void recursive_transform(Point3D* point, int depth) {
    if (depth <= 0) return;

    transform_point(point, 10.0f);  // Apply a small rotation
    point->z = sqrtf(fabsf(point->z));  // Apply sqrt for transformation

    recursive_transform(point, depth - 1);
}

// Function to demonstrate floating-point edge cases
void floating_point_edge_cases() {
    // Underflow handling
    float small_value = 1.0e-40f; 
    float underflow_result = small_value / 2.0f;
    printf("Underflow handling result: %.7e\n", underflow_result);

    // NaN demonstration
    float signaling_nan = 0.0f / 0.0f;  // Resulting in NaN
    float quiet_nan = NAN;
    printf("Signaling NaN: %f, Quiet NaN: %f\n", signaling_nan, quiet_nan);

    // Different rounding modes
    float value_to_round = 2.75f;

    fesetround(FE_TONEAREST);
    printf("Round to nearest: %.1f\n", roundf(value_to_round));

    fesetround(FE_TOWARDZERO);
    printf("Round toward zero: %.1f\n", truncf(value_to_round));

    fesetround(FE_UPWARD);
    printf("Round toward infinity: %.1f\n", ceilf(value_to_round));
}

int main() {
    Point3D point = {1.0f, 1.0f, 1.0f};

    printf("Initial Point3D: (%f, %f, %f)\n", point.x, point.y, point.z);
    recursive_transform(&point, 5); // Perform recursive transformation
    printf("Transformed Point3D: (%f, %f, %f)\n", point.x, point.y, point.z);

    floating_point_edge_cases();

    return 0;
}
