
#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371.0 // Earth's radius in kilometers

// Function to convert degrees to radians
double degrees_to_radians(double degrees) {
    return degrees * (M_PI / 180.0);
}

// Function to calculate the Haversine distance between two points
double haversine_distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = degrees_to_radians(lat2 - lat1);
    double dlon = degrees_to_radians(lon2 - lon1);

    double a = sin(dlat / 2) * sin(dlat / 2) +
               cos(degrees_to_radians(lat1)) * cos(degrees_to_radians(lat2)) *
               sin(dlon / 2) * sin(dlon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}

int main() {
    // Example coordinates: New York City (latitude, longitude) and London
    double nyc_lat = 40.7128;
    double nyc_lon = -74.0060;
    double london_lat = 51.5074;
    double london_lon = -0.1278;

    // Calculate the distance using the Haversine formula
    double distance = haversine_distance(nyc_lat, nyc_lon, london_lat, london_lon);

    // Print the result
    printf("Distance from New York City to London: %.2f kilometers\n", distance);

    return 0;
}
