
#include <stdio.h>
#include <math.h>
#include <float.h>

// Structure to represent an automotive sensor
typedef struct {
    double speed;    // in km/h
    double temperature; // in Celsius
    double fuel_level;  // in percentage
} SensorData;

// Function to simulate sensor readings with floating-point operations
void simulate_sensor_data(SensorData *sensor) {
    for (int i = 0; i < 100; ++i) {
        sensor->speed += 0.1 * (sensor->speed / 100.0);
        sensor->temperature = sin(sensor->speed) * 20;
        sensor->fuel_level *= 0.99;

        // Handle overflow
        if (sensor->speed > DBL_MAX / 2) {
            sensor->speed = INFINITY;
    }

        // Detect underflow
        if (fabs(sensor->fuel_level) < DBL_MIN) {
            sensor->fuel_level = 0.0;
        }
    }
}

// Demonstrate NaN comparison
void demonstrate_nan_operations() {
    double nan_value = NAN;

    printf("NaN compared with itself: %d\n", nan_value == nan_value);
    printf("NaN compared with 0: %d\n", nan_value == 0.0);
}

// Demonstrate precision loss
void demonstrate_precision_loss() {
    double small_value = 1e-15;
    double large_value = 1.0;

    for (int i = 0; i < 100000; ++i) {
        large_value += small_value;
    }

    printf("Result after causing precision loss: %.15f\n", large_value);
}

// Function to demonstrate casting between different types
void demonstrate_casting_operations() {
    double precise_value = 1000.123456789;
    float casted_value = (float)precise_value;
    long long int_value = (long long)precise_value;

    printf("Double to float casting: %.7f\n", casted_value);
    printf("Double to long long casting: %lld\n", int_value);
}

int main() {
    SensorData sensor = {120.0, 25.0, 75.0};

    // Simulate sensor data processing
    simulate_sensor_data(&sensor);

    printf("Final speed: %.2f km/h\n", sensor.speed);
    printf("Final temperature: %.2f°C\n", sensor.temperature);
    printf("Final fuel level: %.2f%%\n", sensor.fuel_level);

    // Demonstrate NaN comparisons
    demonstrate_nan_operations();

    // Demonstrate precision loss due to floating-point arithmetic
    demonstrate_precision_loss();

    // Demonstrate casting between different types
    demonstrate_casting_operations();

    return 0;
}
