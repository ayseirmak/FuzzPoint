
#include <stdio.h>
#include <math.h>
#include <complex.h>

// Constants for the signal
#define SIGNAL_LENGTH 8  // Length of the signal (must be a power of 2)

// Function for computing the FFT using the Cooley-Tukey algorithm
void fft(complex double *X, int N) {
    if(N <= 1) return; // Base case

    // Divide
    complex double even[N/2];
    complex double odd[N/2];
    for(int i = 0; i < N/2; i++) {
        even[i] = X[i*2];
        odd[i] = X[i*2 + 1];
    }

    // Conquer
    fft(even, N/2);
    fft(odd, N/2);

    // Combine
    for(int k = 0; k < N/2; k++) {
        complex double t = cexp(-2.0 * I * M_PI * k / N) * odd[k];
        X[k] = even[k] + t;
        X[k + N/2] = even[k] - t;
    }
}

int main() {
    // Define a simple signal with length = SIGNAL_LENGTH
    complex double signal[SIGNAL_LENGTH] = {1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0};

    // Perform FFT
    fft(signal, SIGNAL_LENGTH);

    // Output the FFT results
    printf("Signal Processing Simulation - FFT Output:\n");
    printf("Frequency Component | Magnitude\n");
    for(int i = 0; i < SIGNAL_LENGTH; i++) {
        printf("%17d | %9.4f\n", i, cabs(signal[i]));
    }

    return 0;
}
