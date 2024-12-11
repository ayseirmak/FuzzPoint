
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Structure representing a signal with different aspects
typedef struct {
    float amplitude;
    double frequency;
    long double phase;
} Signal;

// Function to model a simple transformation and casting involving floating-point manipulations
long long calculate_signal_power(Signal signal) {
    // Initialize with a long double precision
    long double power = signal.amplitude * signal.amplitude * (long double)signal.frequency;

    // Cast to a lower precision and back to check for precision loss
    float temp_power = (float)power;
    power = (long double)temp_power;

    // Return as a long long by rounding down
    long long result = (long long)floorl(power);
    return result;
}

// Recursive function to process signal recursively
double recursive_signal_transform(double frequency, int depth) {
    if (depth <= 0) return frequency;
    double new_freq = sqrt(frequency) + 0.5;
    return recursive_signal_transform(new_freq, depth - 1);
}

int main() {
    // Fixed signals defined in the system
    Signal signals[] = {
        {1.5f, 2.71828, 3.141592653589793238L}, // Signal 1
        {2.2f, 3.14159, 2.7182818284590452353602874713527L}  // Signal 2
    };

    int num_signals = sizeof(signals) / sizeof(signals[0]);

    // Set different rounding modes
    fesetround(FE_TOWARDZERO);

    // Process each signal
    for (int i = 0; i < num_signals; i++) {
        long long power = calculate_signal_power(signals[i]);
        printf("Signal %d power: %lld\n", i + 1, power);

        // Recursive computation showcasing potential for catastrophic cancellation
        double altered_freq = recursive_signal_transform(signals[i].frequency, 5);
        printf("Altered frequency of signal %d: %.9f\n", i + 1, altered_freq);
    }

    // Demonstrate NaN and Infinity handling
    double nan_example = sqrt(-1.0);
    double infinity_example = 1.0 / 0.0;

    printf("NaN Example: %f\n", nan_example);
    printf("Infinity Example: %f\n", infinity_example);

    return 0;
}
