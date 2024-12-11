
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define N 8 // Number of samples, which should be a power of 2 for FFT

typedef struct {
    double real;
    double imag;
} Complex;

// Function to perform the FFT
void fft(Complex *x) {
    unsigned int N = 8; // Number of samples should be power of two
    unsigned int k = N, n;
    double thetaT = 3.14159265358979328346L / N;
    Complex phiT = {cos(thetaT), -sin(thetaT)}, T;
    while (k > 1) {
        n = k;
        k >>= 1;
        phiT.real = cos(thetaT);
        phiT.imag = -sin(thetaT);
        T.real = 1.0;
        T.imag = 0.0;
        for (unsigned int l = 0; l < k; l++) {
            for (unsigned int a = l; a < N; a += (k << 1)) {
                Complex t, q;
                t.real = T.real * x[a + k].real - T.imag * x[a + k].imag;
                t.imag = T.real * x[a + k].imag + T.imag * x[a + k].real;
                q.real = x[a].real - t.real;
                q.imag = x[a].imag - t.imag;
                x[a].real += t.real;
                x[a].imag += t.imag;
                x[a + k].real = q.real;
                x[a + k].imag = q.imag;
            }
            double tmpReal = T.real;
            T.real = tmpReal * phiT.real - T.imag * phiT.imag;
            T.imag = tmpReal * phiT.imag + T.imag * phiT.real;
        }
    }
    unsigned int m = (unsigned int)log2(N);
    for (unsigned int a = 0; a < N; a++) {
        unsigned int b = a;
        b = ((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1);
        b = ((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2);
        b = ((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4);
        b = ((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8);
        b = (b >> 16) | (b << 16);
        b >>= 32 - m;
        if (b > a) {
            Complex tmp = x[a];
            x[a] = x[b];
            x[b] = tmp;
        }
    }
}

// Function to print the FFT results
void print_fft_result(Complex *x) {
    printf("FFT Result:\n");
    for (int i = 0; i < N; i++) {
        printf("%2d: %8.3f + %8.3fi\n", i, x[i].real, x[i].imag);
    }
}

int main() {
    // Example input signal (real part only, imaginary part is zero)
    Complex signal[N] = {
        {1.0, 0.0}, {1.0, 0.0}, {1.0, 0.0}, {1.0, 0.0},
        {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}
    };

    // Perform FFT
    fft(signal);

    // Print FFT results
    print_fft_result(signal);

    return 0;
}
