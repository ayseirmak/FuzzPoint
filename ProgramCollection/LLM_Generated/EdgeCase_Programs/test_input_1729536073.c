
#include <stdio.h>
#include <math.h>
#include <float.h>

// Constants for transformations
#define ROTATION_FACTOR M_PI / 180.0
#define SCALE_FACTOR M_E

// Structure to represent a 3D point and color
typedef struct {
    double x, y, z;       // Coordinates in 3D space
    double red, green, blue; // Color values
} Point3D;

// Function to transform and light a 3D point
void transform_and_light(Point3D* point, int iterations) {
    for (int i = 0; i < iterations; i++) {
        // Rotate the point around the origin
        double new_x = point->x * cos(i * ROTATION_FACTOR) - point->y * sin(i * ROTATION_FACTOR);
        double new_y = point->x * sin(i * ROTATION_FACTOR) + point->y * cos(i * ROTATION_FACTOR);

        // Using catastrophic cancellation example: subtract nearly equal values
        point->x = new_x - (point->x / SCALE_FACTOR) + point->x;
        point->y = new_y - (point->y / SCALE_FACTOR) + point->y;

        // Update z with precision loss operation 
        point->z = (point->z * 1e-7) + 0.1 * i;

        // Ensure color values stay within [0, 1]
        point->red = fmin(fmax(point->red, 0.0), 1.0);
        point->green = fmin(fmax(point->green, 0.0), 1.0);
        point->blue = fmin(fmax(point->blue, 0.0), 1.0);

        // Nested loops to amplify precision loss effect
        for (int j = 0; j < 5; j++) {
            point->red += 1e-10;
            point->green -= 1e-10;
            point->blue += 1e-10;
        }

        // Clamp colors to avoid extreme values due to repetitive additions
        if (isnan(point->red) || isinf(point->red)) point->red = 1.0;
        if (isnan(point->green) || isinf(point->green)) point->green = 1.0;
        if (isnan(point->blue) || isinf(point->blue)) point->blue = 1.0;
    }
}

int main() {
    // Initialize a 3D point with coordinates and RGB colors
    Point3D point = {
        1.0, 1.0, 1.0,    // Initial position
        0.5, 0.5, 0.5     // Initial color
    };

    // Perform transformations and lighting calculations
    transform_and_light(&point, 360); // Iterating through 360 degrees

    // Determine if the final color representation is reasonably white
    int result = (point.red > 0.9 && point.green > 0.9 && point.blue > 0.9) ? 1 : 0;

    return result;
}
