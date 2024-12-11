
#include <stdio.h>
#include <math.h>
#include <float.h>

// Macros for climatic constants
#define TEMPERATURE_VARIATION 0.000001L
#define PRECIPITATION_CONSTANT 1.0e-308L
#define RADIAN_CONVERSION (M_PI / 180.0L)

// Structure to represent a climatic data point
typedef struct {
    long double temperature; // in Celsius
    long double precipitation; // in mm
    long double latitude; // in degrees
} ClimateDataPoint;

// Function to simulate changes in the climate data point
void climate_variation_simulation(ClimateDataPoint *data) {
    // Simulate change using trigonometric and logarithmic functions
    long double adjusted_temp, adjusted_precip;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            adjusted_temp = data->temperature * sinl(data->latitude * RADIAN_CONVERSION + i);
            adjusted_precip = data->precipitation * PRECIPITATION_CONSTANT * logl(fabsl(data->latitude) + 1.0L);

            adjusted_temp -= adjusted_precip / 1000.0L; // Fine adjustment

            if (fpclassify(adjusted_temp) == FP_SUBNORMAL) {
                printf("Adjusted temperature became subnormal at iteration (%d, %d): %.10Le\n", i, j, adjusted_temp);
            } else if (adjusted_temp == -0.0L) {
                printf("Adjusted temperature represented as -0.0 at iteration (%d, %d)\n", i, j);
            }
        }
    }
}

// Demonstrating mathematical operations that can incur gradual underflow
void process_climate_data(ClimateDataPoint *data) {
    printf("Processing climate data for latitude: %.10Le degrees\n", data->latitude);

    // Simulate a time series forecast using nested loops
    for (int year = 0; year < 5; year++) {
        data->temperature += TEMPERATURE_VARIATION;

        climate_variation_simulation(data);

        printf("Year %d: Temperature: %.10Le, Precipitation: %.10Le\n", year, data->temperature, data->precipitation);
    }
}

int main() {
    // Initialize a climate data point with arbitrary values
    ClimateDataPoint data = {15.0L, PRECIPITATION_CONSTANT, 45.0L};

    printf("Initial Climate State: (Temperature: %.10Le °C, Precipitation: %.10Le mm, Latitude: %.10Le degrees)\n", 
           data.temperature, data.precipitation, data.latitude);

    // Process the climate data
    process_climate_data(&data);

    return 0;
}
