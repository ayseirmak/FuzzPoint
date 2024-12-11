
#include <stdio.h>
#include <math.h>
#include <float.h>

#define NUM_CYCLES 100
#define DECAY_FACTOR 0.9999

// Structure to simulate an electrical circuit's voltage behavior
typedef struct {
    float voltage_float;
    double voltage_double;
    long double voltage_long_double;
} CircuitState;

// Function to simulate voltage decay over time
void simulate_voltage_decay(CircuitState *circuit) {
    for (int cycle = 0; cycle < NUM_CYCLES; ++cycle) {
        circuit->voltage_float *= DECAY_FACTOR;
        circuit->voltage_double *= DECAY_FACTOR;
        circuit->voltage_long_double *= DECAY_FACTOR;
    }
}

// Demonstrate catastrophic cancellation
void demonstrate_catastrophic_cancellation() {
    double large_value = 1e10;
    double small_value = 1e-10;
    double result = (large_value + small_value) - large_value;
    
    printf("Result of catastrophic cancellation: %.10f\n", result);
}

// Demonstrate handling of NaNs
void demonstrate_nan_handling() {
    double signaling_nan = NAN; // NaN initialization
    double quiet_nan_operation = signaling_nan + 1.0; // Quiet NaN
    
    // Check if result is NaN
    if (isnan(quiet_nan_operation)) {
        printf("Operation resulted in NaN.\n");
    } else {
        printf("Result: %f\n", quiet_nan_operation);
    }
}

// Function to use extreme values with mathematical constants
void use_extreme_values() {
    double large_value = 1e308;
    double extreme_value = cos(M_PI * large_value);

    printf("Extreme cos operation with large input: %f\n", extreme_value);

    extreme_value = log(M_E * large_value);
    printf("Extreme log operation: %f\n", extreme_value);
}

// Main function
int main() {
    CircuitState circuit = {1.0f, 1.0, 1.0L};

    // Simulate voltage decay
    simulate_voltage_decay(&circuit);

    // Display voltage levels
    printf("Final float voltage: %.10f\n", circuit.voltage_float);
    printf("Final double voltage: %.10lf\n", circuit.voltage_double);
    printf("Final long double voltage: %.10Lf\n", circuit.voltage_long_double);

    // Demonstrate floating-point issues
    demonstrate_catastrophic_cancellation();
    demonstrate_nan_handling();
    use_extreme_values();

    return 0;
}
