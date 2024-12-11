#include <stdio.h>

typedef float fftw_real;

void complex_transpose(fftw_real *rA, fftw_real *iA, int n, int is, int js) {
    int i, j;

    for (i = 1; i < n; ++i) {
        for (j = 0; j < i; ++j) {
            fftw_real ar, ai, br, bi;

            ar = rA[i * is + j * js];
            ai = iA[i * is + j * js];
            br = rA[j * is + i * js];
            bi = iA[j * is + i * js];

            rA[j * is + i * js] = ar;
            iA[j * is + i * js] = ai;
            rA[i * is + j * js] = br;
            iA[i * is + j * js] = bi;
        }
    }
}

int main() {
    fftw_real A[2048];
    int i;
    fftw_real sum = 0.0;

    for (i = 0; i < 2048; ++i) {
        A[i] = (fftw_real)i;
        sum += A[i];
    }
    printf("Checksum before = %f\n", sum);

    for (i = 0; i < 10; ++i) {
        // Pass the correct offsets for iA to ensure valid transposition.
        complex_transpose(A, A+1, 32, 2, 64);
    }

    sum = 0.0;  // Reset sum for reuse.
    for (i = 0; i < 2048; ++i) {
        sum += A[i];
    }
    printf("Checksum after = %f\n", sum);

    return 0;
}