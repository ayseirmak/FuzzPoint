
#include <stdio.h>
#include <math.h>

#define SIGNAL_LENGTH 5

// Function to compute the Signal-to-Noise Ratio (SNR)
double compute_snr(double signal_power, double noise_power) {
    // Ensure no division by zero
    if (noise_power == 0) return 0;
    return 10.0 * log10(signal_power / noise_power);
}

// Function to simulate signal processing where floating point operations can be contracted
void process_signal(double* signal, double* noise, double* result) {
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        // Floating-point operations
        result[i] = (signal[i] * signal[i] + noise[i] * noise[i]) / (signal[i] - noise[i]);
    }
}

// Function to loop over a structure and simulate unrolling optimization
void adjust_signal(double* signal) {
    for (int i = 0; i < SIGNAL_LENGTH; i+=2) { // Loop unrolling suggestion (manual)
        signal[i] *= 0.9; // Example of simple adjustment
        if (i+1 < SIGNAL_LENGTH) {
            signal[i+1] *= 0.9; // Adjustment in unrolled loop
        }
    }
}

int main() {
    // Fixed input values representing signal and noise power
    double signal[SIGNAL_LENGTH] = {100.0, 105.0, 110.0, 115.0, 120.0};
    double noise[SIGNAL_LENGTH] = {10.0, 8.0, 9.0, 7.0, 6.0};
    double processed_signal[SIGNAL_LENGTH];

    // Process signal to trigger floating-point contraction optimizations
    process_signal(signal, noise, processed_signal);

    printf("Processed Signal Values:\n");
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        printf("Value %d: %f\n", i+1, processed_signal[i]);
    }

    // Compute SNR for each signal-noise pair
    printf("Signal-to-Noise Ratios:\n");
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        double snr = compute_snr(signal[i], noise[i]);
        printf("SNR %d: %f dB\n", i+1, snr);
    }

    // Adjust signal to demonstrate loop unrolling optimization
    adjust_signal(signal);

    printf("Adjusted Signal Values:\n");
    for (int i = 0; i < SIGNAL_LENGTH; i++) {
        printf("Signal Value %d: %f\n", i+1, signal[i]);
    }

    return 0;
}
