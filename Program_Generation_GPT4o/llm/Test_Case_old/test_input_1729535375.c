
#include <stdio.h>
#include <math.h>
#include <float.h>

// Structure to represent a geospatial point
typedef struct {
    long double latitude;
    long double longitude;
    long double elevation;
} GeoPoint;

// Function to calculate distances between geospatial points
long double calculate_distance(GeoPoint p1, GeoPoint p2) {
    long double delta_lat = p1.latitude - p2.latitude;
    long double delta_lon = p1.longitude - p2.longitude;

    // Simple Euclidean distance with potential for catastrophic cancellation
    long double distance = sqrtl(delta_lat * delta_lat + delta_lon * delta_lon);

    if (isnan(distance)) {
        printf("Computation resulted in NaN\n");
        return 0.0L;
    }

    if (isinf(distance)) {
        printf("Computation resulted in %s infinity\n", (distance > 0) ? "positive" : "negative");
        return (distance > 0) ? LDBL_MAX : -LDBL_MAX;
    }

    return distance;
}

// Function to analyze precision across different floating-point types
void precision_analysis() {
    float f_lat = FLT_MAX;
    double d_lat = DBL_MAX;
    long double ld_lat = LDBL_MAX;

    for (int i = 0; i < 5; ++i) {
        f_lat /= 10.0F;
        d_lat /= 10.0;
        ld_lat /= 10.0L;

        printf("Iteration %d, float: %.8e, double: %.8e, long double: %.8Le\n", i, f_lat, d_lat, ld_lat);
    }
}

// Geospatial data operation demonstrating edge cases
void geospatial_operations() {
    // Define geospatial points with potential edge case values
    GeoPoint location1 = {90.0L, 180.0L, 0.0L};
    GeoPoint location2 = {90.0L + 1.0e-20L, 180.0L + 1.0e-20L, 0.0L};  // Minimal difference can cause cancellation

    printf("Calculating distance between two geospatial points...\n");
    long double distance = calculate_distance(location1, location2);
    printf("Computed Distance: %.10Le\n", distance);

    precision_analysis();
}

int main() {
    geospatial_operations();
    return 0;
}
