
#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to simulate an acoustics calculation for sound pressure levels
double calculate_sound_pressure(double amplitude, double frequency, double distance) {
    volatile double intensity; // Volatile prevents CSE on this variable
    double pressure;

    // Check for edge conditions
    if (amplitude <= 0.0) {
        amplitude = DBL_MIN; // Replace zero or negative amplitude with denormalized min value
    }
    
    // Basic formula for sound pressure using amplitude, frequency, and distance
    double factor = amplitude * frequency; // Subexpression for demonstrating CSE
    intensity = factor / (4.0 * M_PI * distance * distance);

    // Handle cases for special floating-point values
    pressure = sqrt(intensity);
    if (pressure != pressure || isinf(pressure)) {
        printf("Invalid pressure computed: %f\n", pressure);
        pressure = 0.0; // Set pressure to zero if NaN or infinity
    }

    return pressure;
}

int main() {
    // Define scenarios with predefined acoustic parameters
    double scenarios[][3] = {
        {0.0, 440.0, 3.0},      // Zero amplitude, typical frequency (A4), normal distance
        {1.0, NAN, 10.0},       // NaN frequency
        {1.0, 440.0, INFINITY}, // Infinite distance
        {1.0, 880.0, 1e-308},   // Very small distance causing denormalized number
        {1.0, 440.0, 5.0}       // Normal parameters
    };
    int length = sizeof(scenarios) / (3 * sizeof(double));

    printf("Acoustic scenarios:\n");
    for (int i = 0; i < length; i++) {
        printf("Scenario[%d] = (Amplitude: %f, Frequency: %f, Distance: %f)\n",
               i, scenarios[i][0], scenarios[i][1], scenarios[i][2]);
    }

    // Calculate sound pressure for each scenario
    printf("\nCalculated sound pressures:\n");
    for (int i = 0; i < length; i++) {
        double pressure = calculate_sound_pressure(scenarios[i][0], scenarios[i][1], scenarios[i][2]);
        printf("Sound pressure for Scenario[%d] = %f\n", i, pressure);
    }

    return 0;
}
