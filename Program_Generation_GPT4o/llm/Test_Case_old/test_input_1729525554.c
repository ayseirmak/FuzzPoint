
#include <stdio.h>
#include <math.h>
#include <float.h>

#define PI 3.14159265358979323846

// Function to simulate acoustic wave intensity
long double acoustic_wave_intensity(long double frequency, long double amplitude, long double phase_shift) {
    // Calculate wave intensity using trigonometric operations
    long double intensity = amplitude * sinl(2 * PI * frequency + phase_shift);

    // Handling edge cases
    if (intensity != intensity) { // Check for NaN
        printf("Error: Intensity is NaN\n");
        return 0;
    }
    if (isinf(intensity)) { // Check for Infinity
        printf("Error: Intensity is Infinite\n");
        return 0;
    }
    if (fabsl(intensity) < LDBL_MIN) { // Check for underflow
        printf("Warning: Intensity underflow\n");
        intensity = 0;
    }

    return intensity;
}

int main() {
    // Sample fixed values for acoustic wave simulation
    long double frequency = 1000.0L; // 1 KHz
    long double amplitude = 1.0e-320L; // Small amplitude (denormalized number)
    long double phase_shift = 0.0L;

    // Calculate wave intensity
    long double intensity = acoustic_wave_intensity(frequency, amplitude, phase_shift);

    // Calculate intensity for edge case scenarios
    long double extreme_amplitude = 1.0e308L; // Large amplitude to test overflow
    long double extreme_intensity = acoustic_wave_intensity(frequency, extreme_amplitude, phase_shift);

    // Output results to test floating-point behavior
    printf("Acoustic wave intensity: %.15Le\n", intensity);
    printf("Extreme acoustic wave intensity: %.15Le\n", extreme_intensity);

    // Analyze rounding behavior
    long double value = 0.1L + 0.2L;
    printf("0.1 + 0.2 = %.20Le (expected 0.3)\n", value);

    return 0;
}
