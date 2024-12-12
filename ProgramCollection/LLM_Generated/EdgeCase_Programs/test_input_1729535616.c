
#include <stdio.h>
#include <math.h>
#include <fenv.h> // For controlling rounding modes

// Define macros for constants
#define SPEED_OF_SOUND 343.2L // Speed of sound in air at 20 degrees Celsius in m/s
#define PI 3.14159265358979323846L

typedef struct {
    long double amplitude;
    long double frequency;
    long double phase;
} SoundWave;

// Function to simulate wave propagation and compute the wave value at a given time
long double compute_wave_value(SoundWave wave, float time) {
    return wave.amplitude * sinl(2.0L * PI * wave.frequency * time + wave.phase);
}

// Function to demonstrate floating-point precision
void compare_precision(SoundWave wave, float time) {
    // Calculate using different floating-point types
    long double value_long_double = compute_wave_value(wave, time);
    double value_double = (double)wave.amplitude * sin(2.0 * (double)PI * (double)wave.frequency * (double)time + (double)wave.phase);
    float value_float = (float)wave.amplitude * sinf(2.0f * (float)PI * (float)wave.frequency * (float)time + (float)wave.phase);

    printf("Comparing precision at time %.3f:\n", time);
    printf("  long double: %.15Lf\n", value_long_double);
    printf("  double: %.15f\n", value_double);
    printf("  float: %.7f\n", value_float);
}

// Function to demonstrate edge cases and rounding
void rounding_demo() {
    // Examples of specific edge cases
    float neg_zero1 = -0.0f;
    float neg_zero2 = -1.0f / INFINITY; // Another way to represent -0.0

    printf("Negative zero comparison:\n");
    printf("  -0.0: %f\n", neg_zero1);
    printf("  -1/inf: %f\n", neg_zero2);

    // Set rounding modes and demonstrate calculations
    fesetround(FE_TONEAREST);
    printf("Rounding to nearest: %.1f\n", roundf(2.5f));

    fesetround(FE_TOWARDZERO);
    printf("Rounding toward zero: %.1f\n", roundf(2.5f));

    fesetround(FE_UPWARD);
    printf("Rounding toward infinity: %.1f\n", roundf(2.5f));
}

int main() {
    SoundWave wave = {1.0L, 440.0L, 0.0L}; // A simple sound wave at 440Hz (A4 note)
    float times[] = {0.0f, 0.5f, 1.0f, 1.5f, 2.0f};

    // Simulate wave propagation and observe precision and rounding
    printf("Wave propagation simulation:\n");
    for (int i = 0; i < 5; ++i) {
        compare_precision(wave, times[i]);
    }

    rounding_demo();

    return 0;
}
