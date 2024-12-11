
#include <stdio.h>
#include <math.h>
#include <float.h>

#define DEG_TO_RAD(deg) ((deg) * (M_PI / 180.0))
#define EARTH_RADIUS_KM 6371.0

// Function to calculate the Haversine distance between two points on the Earth's surface
long double haversine_distance(long double lat1, long double lon1, long double lat2, long double lon2) {
    long double dlat = DEG_TO_RAD(lat2 - lat1);
    long double dlon = DEG_TO_RAD(lon2 - lon1);
    long double a = sinl(dlat / 2.0L) * sinl(dlat / 2.0L) +
                    cosl(DEG_TO_RAD(lat1)) * cosl(DEG_TO_RAD(lat2)) *
                    sinl(dlon / 2.0L) * sinl(dlon / 2.0L);
    long double c = 2.0L * atan2l(sqrtl(a), sqrtl(1.0L - a));
    return EARTH_RADIUS_KM * c;
}

int main() {
    // Example points (latitude and longitude in degrees)
    long double lat1 = 90.0L;   // North Pole, edge case
    long double lon1 = 0.0L;
    long double lat2 = 0.0L;   // Equator
    long double lon2 = 0.0L;
    
    // Calculate geospatial Haversine distance
    long double distance = haversine_distance(lat1, lon1, lat2, lon2);
    printf("Distance between North Pole and Equator: %Lf km\n", distance);
    
    // Use edge cases for floating-point numbers
    long double min_value = LDBL_MIN;  // Smallest positive normalized long double
    long double max_value = LDBL_MAX;  // Largest positive long double
    long double nearly_zero = 1.0e-307L;  // A value close to zero for denormalization

    // Compute with potential overflow scenario
    long double overflow_example = max_value * 2.0L;
    if (isinf(overflow_example)) {
        printf("Overflow occurred, result is Infinite\n");
    }
    
    // Compute with potential underflow scenario
    long double underflow_example = nearly_zero / 2.0L;
    if (underflow_example == 0.0L) {
        printf("Underflow occurred, result is Zero\n");
    }

    // Compute with denormalized value
    long double denorm_result = sinl(nearly_zero);
    printf("Sin of a denormalized number: %Lf\n", denorm_result);

    // Check behavior with NaN
    long double nan_example = sqrtl(-1.0L);
    if (isnan(nan_example)) {
        printf("Operation resulted in NaN\n");
    }
    
    return 0;
}
