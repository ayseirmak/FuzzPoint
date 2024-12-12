
#include <stdio.h>
#include <math.h>
#include <fenv.h>

// Recursive function to compute a signal power series
double compute_power_series(double base, int exponent, double attenuation) {
    // Base case
    if (exponent == 0) return 1.0;

    double previous_value = compute_power_series(base, exponent - 1, attenuation);
    double result = base * previous_value - attenuation;

    // Ensure no denormalized values
    if (fabs(result) < 1.0e-308) result = 0.0;

    return result;
}

// Signal modulation example
double amplitude_modulation(double carrier_frequency, double modulating_signal) {
    return carrier_frequency * sin(modulating_signal);
}

// Trigger floating-point range optimizations and handle exceptions
void perform_edge_case_operations() {
    volatile double small_value = 1.0e-308;
    volatile double large_value = 1.0e308;
    volatile double zero = 0.0;
    volatile double result;

    // Underflow example
    result = small_value / large_value;

    // Overflow example
    result = large_value * large_value;

    // Division by zero example
    result = small_value / zero;
}

int main() {
    // Enable floating-point exceptions (handling)
    feenableexcept(FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW);

    // Fixed values for signal modulation
    double carrier_frequency = 1000.0;  // Hz
    double modulating_signal = 0.5;

    // Calculate amplitude modulation
    double modulated_signal = amplitude_modulation(carrier_frequency, modulating_signal);
    printf("Modulated Signal: %f\n", modulated_signal);

    // Calculate a power series of type base^exponent with attenuation
    double base = 1.5;
    int exponent = 5;
    double attenuation = 0.1;
    double power_series_value = compute_power_series(base, exponent, attenuation);
    printf("Power Series Value: %f\n", power_series_value);

    // Perform floating-point edge operations
    perform_edge_case_operations();

    return 0;
}
