
#include <stdio.h>
#include <float.h>
#include <fenv.h>
#include <math.h>

// Structure to represent automotive sensors data
typedef struct {
    float fuelLevel;       // Fuel level in liters
    double velocity;       // Velocity in m/s
    long double temperature; // Temperature in degrees Celsius
} SensorData;

// Function to demonstrate different floating-point precision
void process_sensor_data(SensorData *sensor) {
    // Operations focusing on precision and catastrophic cancellation
    float velocity_float = sensor->velocity;
    double velocity_double = sensor->velocity + sensor->temperature - sensor->temperature; // Catastrophic cancellation

    printf("Sensor Velocity (Float): %.8e\n", velocity_float);
    printf("Sensor Velocity (Double, with cancellation): %.10e\n", velocity_double);
}

// Function to demonstrate different rounding modes
void test_rounding_modes(double value) {
    const char *rounding_modes[] = {"FE_TONEAREST", "FE_TOWARDZERO", "FE_UPWARD", "FE_DOWNWARD"};
    int modes[] = {FE_TONEAREST, FE_TOWARDZERO, FE_UPWARD, FE_DOWNWARD};

    printf("Original Value: %f\n", value);

    for (int i = 0; i < 4; ++i) {
        fesetround(modes[i]);
        double rounded = nearbyint(value);
        printf("Rounded using %s: %f\n", rounding_modes[i], rounded);
    }
}

// Function to handle special values in long double precision
void handle_special_values(long double value) {
    if (fpclassify(value) == FP_ZERO) {
        printf("Value is zero.\n");
    } else if (isinf(value)) {
        printf("Value is infinite.\n");
    } else if (isnan(value)) {
        printf("Value is NaN.\n");
    } else {
        printf("Value is normal.\n");
    }
}

int main() {
    // Initialize sensor data with arbitrary values
    SensorData sensorData = {50.0F, 120.0, -273.15L};

    printf("Initial Sensor State: Fuel Level: %.2f L, Velocity: %.2f m/s, Temperature: %.2Lf °C\n", 
           sensorData.fuelLevel, sensorData.velocity, sensorData.temperature);

    // Process the sensor data
    process_sensor_data(&sensorData);

    // Demonstrate rounding modes on a sample velocity
    printf("\nTesting Rounding Modes on velocity...\n");
    test_rounding_modes(sensorData.velocity);

    // Handle and check special values
    printf("\nHandling Special Values...\n");
    handle_special_values(sensorData.temperature);

    return 0;
}
