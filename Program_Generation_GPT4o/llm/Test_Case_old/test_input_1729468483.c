
#include <stdio.h>
#include <math.h>
#include <float.h>

// Function to simulate a simple signal processing routine
void process_signal(double *signal, int length) {
    for (int i = 0; i < length; i++) {
        // Simulate processing: apply a transformation and handle special cases
        signal[i] = sqrt(fabs(signal[i])); // Square root approximation and handling negative values

        // Handling NaN
        if (isnan(signal[i])) {
            printf("Found NaN in the signal at index %d.\n", i);
            signal[i] = 0.0; // Replace NaN with zero
        }

        // Handle denormalized numbers by checking against minimum positive normal value
        if (fabs(signal[i]) < DBL_MIN) {
            printf("Denormalized number at index %d, approximate to zero.\n", i);
            signal[i] = 0.0; // Approximate denormalized numbers to zero
        }
        
        // Handle infinities
        if (isinf(signal[i])) {
            printf("Found infinity in the signal at index %d.\n", i);
            signal[i] = 0.0; // Replace infinity with zero
        }
    }
}

int main() {
    // Define a signal with edge cases
    double signal[] = {
        4.0, -2.0, 0.0, DBL_MIN / 2, NAN, INFINITY, 9.0
    };
    int length = sizeof(signal) / sizeof(signal[0]);

    printf("Original signal:\n");
    for (int i = 0; i < length; i++) {
        printf("signal[%d] = %f\n", i, signal[i]);
    }

    // Process the signal
    process_signal(signal, length);

    printf("\nProcessed signal:\n");
    for (int i = 0; i < length; i++) {
        printf("signal[%d] = %f\n", i, signal[i]);
    }

    return 0;
}
