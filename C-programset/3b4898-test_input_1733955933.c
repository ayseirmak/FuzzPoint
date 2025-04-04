
#include <stdio.h>
#include <math.h>

// Define the length of the input signal and filter
#define SIGNAL_LEN 8
#define FILTER_LEN 3

// Function to apply a simple low-pass filter to an input signal
void low_pass_filter(const float* input_signal, float* output_signal, const float* filter_coefficients) {
    for (int i = 0; i < SIGNAL_LEN; i++) {
        float filtered_value = 0.0;
        for (int j = 0; j < FILTER_LEN; j++) {
            if (i-j >= 0) { // Check boundary condition
                filtered_value += input_signal[i-j] * filter_coefficients[j];
            }
        }
        output_signal[i] = filtered_value;
    }
}

int main() {
    // Define a sample signal (e.g., a sine wave or any arbitrary waveform)
    float input_signal[SIGNAL_LEN] = {0.0, 0.707, 1.0, 0.707, 0.0, -0.707, -1.0, -0.707};
    float output_signal[SIGNAL_LEN] = {0}; // Initialize the output array

    // Define a simple low-pass filter (moving average filter)
    float filter_coefficients[FILTER_LEN] = {0.333, 0.333, 0.333};

    // Apply the low-pass filter to the input signal
    low_pass_filter(input_signal, output_signal, filter_coefficients);

    // Calculate a simple checksum to ensure output is deterministic
    float checksum = 0.0;
    for (int i = 0; i < SIGNAL_LEN; i++) {
        checksum += output_signal[i] * (i+1);
    }

    // Print deterministic output: 0 for even checksum, 1 for odd checksum
    printf("%d\n", ((int)checksum) % 2);

    return 0;
}
