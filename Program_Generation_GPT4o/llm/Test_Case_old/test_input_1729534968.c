
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>

#define EARTH_RADIUS 6371.0 // Earth's radius in kilometers

typedef struct {
    long double latitude;
    long double longitude;
} GeoPoint;

// Function to convert degrees to radians
long double degrees_to_radians(long double degrees) {
    return degrees * M_PI / 180.0;
}

// Function to compute the haversine distance between two geospatial points
long double compute_haversine_distance(GeoPoint p1, GeoPoint p2) {
    long double lat1 = degrees_to_radians(p1.latitude);
    long double lon1 = degrees_to_radians(p1.longitude);
    long double lat2 = degrees_to_radians(p2.latitude);
    long double lon2 = degrees_to_radians(p2.longitude);

    long double dlat = lat2 - lat1;
    long double dlon = lon2 - lon1;

    long double a = powl(sinl(dlat / 2), 2) + cosl(lat1) * cosl(lat2) * powl(sinl(dlon / 2), 2);
    long double c = 2 * atan2l(sqrtl(a), sqrtl(1 - a));

    return EARTH_RADIUS * c;
}

// Function demonstrating various edge case floating-point operations
void demonstrate_floating_point_operations() {
    double nan_value = NAN;
    double infinity_value = INFINITY;
    double negative_infinity = -INFINITY;
    double subnormal = DBL_MIN / 2;

    printf("NaN + 1: %f\n", nan_value + 1);
    printf("Infinity + 1: %f\n", infinity_value + 1);
    printf("Negative Infinity * 2: %f\n", negative_infinity * 2);
    printf("Subnormal * 1e-300: %e\n", subnormal * 1e-300);
}

// Function to showcase precision differences between float, double, and long double
void show_precision() {
    float e_float = M_E;
    double e_double = M_E;
    long double e_long_double = M_E;

    printf("Precision of Euler's number:\n");
    printf("Float: %.10f\n", e_float);
    printf("Double: %.10lf\n", e_double);
    printf("Long Double: %.10Lf\n", e_long_double);
}

int main() {
    // Define geospatial points
    GeoPoint pointA = {52.5200, 13.4050}; // Berlin
    GeoPoint pointB = {48.8566, 2.3522};  // Paris

    // Compute distance
    long double distance = compute_haversine_distance(pointA, pointB);
    printf("Haversine distance between Point A and Point B: %.10Lf km\n", distance);

    // Demonstrate floating-point operations
    demonstrate_floating_point_operations();

    // Show precision differences
    show_precision();

    // Check for specific conditions
    double zero_check = 0.0;
    printf("Zero check for 1.0 / 0.0: %f\n", 1.0 / zero_check); // Should output infinity

    return 0;
}
