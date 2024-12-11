
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define a sample rate and duration for the acoustic wave simulation
#define SAMPLE_RATE 44100
#define DURATION 1  // 1 second

volative double calculate_wave(double frequency, int sample) {
    // Ensure the compiler doesn't optimize this variable's calculations away
    volatile double time = (double)sample / SAMPLE_RATE;
    // Calculate wave using sine function for oscillation (Acoustic wave)
    return sin(2 * M_PI * frequency * time);
}

int main() {
    // Define two acoustic wave frequencies and their initial properties
    double frequencies[] = {440.0, 442.0};  // A4 and slightly detuned
    const int num_samples = SAMPLE_RATE * DURATION;
    
    // Initialize variables to store wave data
    double wave1[num_samples];
    double wave2[num_samples];

    // Calculate waves using different frequencies
    for (int i = 0; i < num_samples; i++) {
        wave1[i] = calculate_wave(frequencies[0], i);
        wave2[i] = calculate_wave(frequencies[1], i);
    }

    // Compute the interference pattern (superposition)
    double interference[num_samples];
    volatile double infinity = INFINITY;

    for (int i = 0; i < num_samples; i++) {
        interference[i] = wave1[i] + wave2[i];

        // Handle edge case for denormalized numbers
        if(fabs(interference[i]) < DBL_MIN) {
            interference[i] = 0.0;  // Considered as an underflow to zero
        }

        // Print only last few results to avoid console overflow
        if (i >= num_samples - 10) {
            printf("Interference[%d]: %0.5f\n", i, interference[i]);
        }
    }

    return 0;
}
