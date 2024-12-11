
#include <stdio.h>
#include <math.h>
#include <float.h>

// Geospatial point structure
typedef struct {
    double latitude;
    double longitude;
} GeoPoint;

// Function to calculate the great-circle distance between two points on the Earth's surface
double great_circle_distance(GeoPoint p1, GeoPoint p2) {
    const double EARTH_RADIUS = 6371e3; // in meters

    double lat1_rad = p1.latitude * M_PI / 180.0;
    double lat2_rad = p2.latitude * M_PI / 180.0;
    double delta_lat_rad = (p2.latitude - p1.latitude) * M_PI / 180.0;
    double delta_lon_rad = (p2.longitude - p1.longitude) * M_PI / 180.0;

    // Haversine formula for great-circle distance
    double a = sin(delta_lat_rad / 2.0) * sin(delta_lat_rad / 2.0) +
               cos(lat1_rad) * cos(lat2_rad) * sin(delta_lon_rad / 2.0) * sin(delta_lon_rad / 2.0);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

// Function to test edge cases involving floating-point operations
void test_edge_cases() {
    // Handling subnormal numbers
    double subnormal = DBL_MIN / 2.0;
    if (subnormal < DBL_MIN && subnormal > 0.0) {
        printf("Handling Subnormal (Denormalized) Number: %e\n", subnormal);
    } else {
        printf("Number is not subnormal.\n");
    }

    // Conditional statement with floating-point comparisons
    double threshold_distance = 1e-9; // Very small threshold
    GeoPoint point1 = {0.0, 0.0};
    GeoPoint point2 = {0.0, 0.0};

    double calculated_distance = great_circle_distance(point1, point2);
    if (calculated_distance < threshold_distance) {
        printf("Points are effectively coincident.\n");
    } else {
        printf("Points are distinct with distance: %f\n", calculated_distance);
    }
}

int main() {
    // Define fixed geospatial points
    GeoPoint loc1 = {37.7749, -122.4194};  // San Francisco, CA
    GeoPoint loc2 = {34.0522, -118.2437};  // Los Angeles, CA

    // Calculate the great-circle distance
    double distance = great_circle_distance(loc1, loc2);
    printf("Great-circle distance between locations: %.2f meters\n", distance);

    // Test edge cases
    test_edge_cases();

    return 0;
}
