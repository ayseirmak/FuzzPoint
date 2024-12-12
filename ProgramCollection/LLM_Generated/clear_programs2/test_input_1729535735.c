
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <fenv.h>

// Function to process waveform and demonstrate floating-point operations
void process_waveform(double frequency, double amplitude, int steps) {
    double delta_t = 1.0 / (frequency * steps);
    double time = 0.0;
    double waveform = 0.0;

    printf("Starting acoustic waveform processing...\n");

    for (int i = 0; i < steps; ++i) {
        // Calculate wave value using sinusoidal function
        double wave_value = amplitude * sin(2.0 * M_PI * frequency * time);

        // Adjust wave value and introduce precision loss through nested loops
        for (int j = 0; j < 1000; ++j) {
            waveform += wave_value * 0.0001;
        }

        // Demonstrate different rounding modes
        float rounded_value;

        fesetround(FE_TONEAREST);
        rounded_value = roundf(waveform);
        printf("Round to nearest: %.1f\n", rounded_value);

        fesetround(FE_TOWARDZERO);
        rounded_value = truncf(waveform);
        printf("Round toward zero: %.1f\n", rounded_value);

        fesetround(FE_UPWARD);
        rounded_value = ceilf(waveform);
        printf("Round toward infinity: %.1f\n", rounded_value);

        time += delta_t;

        // Switch case to handle floating-point edge cases
        switch (fpclassify(waveform)) {
            case FP_NAN:
                printf("Signaling NaN detected - Resetting waveform\n");
                waveform = 0.0;
                break;
            case FP_INFINITE:
                printf("Infinity detected - Clamping waveform\n");
                waveform = DBL_MAX;
                break;
            default:
                break;
        }
    }
}

int main() {
    double frequency = 440.0; // Frequency of A4 note, 440 Hz
    double amplitude = 1.0;   // Normalized amplitude

    // Demonstrating representation of -0.0
    double neg_zero = -0.0;
    printf("Representation of -0.0: %.1f\n", neg_zero);

    printf("Acoustic waveform simulation\n");
    process_waveform(frequency, amplitude, 10);

    return 0;
}
