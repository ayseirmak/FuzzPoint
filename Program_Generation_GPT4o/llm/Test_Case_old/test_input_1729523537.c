
#include <stdio.h>
#include <math.h>
#include <complex.h>

// Signal Processing Example: Convolution with Complex Numbers
#define N 4
#define M 3
#define EPSILON 0.0001

// Function to perform convolution with complex numbers
void convolve_complex(double complex *signal, int signal_length, double complex *kernel, int kernel_length, double complex *result) {
    int n, k;
    for (n = 0; n < signal_length + kernel_length - 1; ++n) {
        result[n] = 0 + 0*I;
        for (k = 0; k < kernel_length; ++k) {
            if (n - k >= 0 && n - k < signal_length) {
                result[n] += signal[n - k] * kernel[k];
            }
        }
    }
}

// Function to compare two complex numbers with a given epsilon
int complex_compare(double complex a, double complex b, double epsilon) {
    return (cabs(a - b) < epsilon) ? 1 : 0;
}

int main() {
    // Fixed signal and kernel values
    double complex signal[N] = {1.0 + 2.0*I, 2.0 + 1.0*I, 0.5 + 0.5*I, -1.0 + 0.5*I};
    double complex kernel[M] = {0.5 + 0.0*I, -0.5 + 0.5*I, 1.0 - 1.0*I};
    double complex result[N + M - 1];

    // Perform convolution
    convolve_complex(signal, N, kernel, M, result);

    // Print results
    printf("Convolution result (real and imaginary parts):\n");
    for (int i = 0; i < N + M - 1; ++i) {
        printf("Result[%d]: %.3f + %.3fi\n", i, creal(result[i]), cimag(result[i]));
    }

    // Example floating-point comparison with epsilon
    double complex a = 1.0001 + 2.0*I;
    double complex b = 1.0000 + 2.0*I;

    if (complex_compare(a, b, EPSILON)) {
        printf("The complex numbers a and b are considered equal within an epsilon of %.4f\n", EPSILON);
    } else {
        printf("The complex numbers a and b are different beyond an epsilon of %.4f\n", EPSILON);
    }

    return 0;
}
