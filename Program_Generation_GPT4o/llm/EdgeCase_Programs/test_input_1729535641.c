
#include <stdio.h>
#include <math.h>
#include <float.h>

// Define macros for mathematical constants if not defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#ifndef M_E
#define M_E 2.71828182845904523536
#endif

typedef struct {
    long double amplitude;
    long double frequency;
    long double phase;
} ACSignal;

// Function to compute signal value at a given time using different floating types
long double compute_signal_long_double(ACSignal signal, long double time) {
    return signal.amplitude * sinl(2.0 * M_PI * signal.frequency * time + signal.phase);
}

double compute_signal_double(ACSignal signal, double time) {
    return (double)signal.amplitude * sin(2.0 * M_PI * (double)signal.frequency * time + (double)signal.phase);
}

float compute_signal_float(ACSignal signal, float time) {
    return (float)signal.amplitude * sinf(2.0f * (float)M_PI * (float)signal.frequency * time + (float)signal.phase);
}

// Function to recursively process floating-point operations
long double recursive_process(ACSignal signal, long long iterations) {
    if (iterations <= 0) return 0.0L;
    long double value = compute_signal_long_double(signal, (long double)iterations / 100.0L);
    return value / iterations + recursive_process(signal, iterations - 1);
}

// Function to explore floating-point edge cases
void explore_edge_cases() {
    // NaN and Infinity handling
    float qnan = NAN; // Quiet NaN
    float snan = (0.0f / 0.0f); // Signaling NaN from arithmetic operation
    float infinity_value = 1.0f / 0.0f; // Positive infinity

    printf("NaN behavior (Quiet NaN): %s\n", isnan(qnan) ? "is NaN" : "is not NaN");
    printf("NaN behavior (Signaling NaN): %s\n", isnan(snan) ? "is NaN" : "is not NaN");
    printf("Infinity value: %f\n", infinity_value);
}

int main() {
    ACSignal signal = {1.0L, 60.0L, 0.0L}; // Example: 60Hz AC signal
    long long iterations = 1000LL;

    // Compute signal at various times using different precision
    printf("Signal computation:\n");
    printf("  long double precision: %.15Lf\n", compute_signal_long_double(signal, 0.1L));
    printf("  double precision: %.15f\n", compute_signal_double(signal, 0.1));
    printf("  float precision: %.7f\n", compute_signal_float(signal, 0.1f));

    // Recursive processing
    long double recursive_value = recursive_process(signal, iterations);
    printf("Recursive process result: %.15Lf\n", recursive_value);

    // Explore edge cases
    explore_edge_cases();

    return 0;
}
