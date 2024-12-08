#include <stdio.h>
#include <stdlib.h>

// The function foo performs a series of computations based on a switch statement
__attribute__((noinline, noclone)) double foo(double x) {
    double t;
    switch ((int)x) {
        case 0:
            t = 2 * x - 1;
            return 0.70878e-3 + (0.71234e-3 + (0.35779e-5 + (0.17403e-7 + (0.81710e-10 + (0.36885e-12 + 0.15917e-14 * t) * t) * t) * t) * t) * t;
        case 1:
            t = 2 * x - 3;
            return 0.21479e-2 + (0.72686e-3 + (0.36843e-5 + (0.18071e-7 + (0.85496e-10 + (0.38852e-12 + 0.16868e-14 * t) * t) * t) * t) * t) * t;
        case 2:
            t = 2 * x - 5;
            return 0.36165e-2 + (0.74182e-3 + (0.37948e-5 + (0.18771e-7 + (0.89484e-10 + (0.40935e-12 + 0.17872e-14 * t) * t) * t) * t) * t) * t;
        case 10:
            t = 2 * x - 21;
            return 0.16540e-1 + (0.87928e-3 + (0.48520e-5 + (0.25711e-7 + (0.13030e-9 + (0.62820e-12 + 0.28612e-14 * t) * t) * t) * t) * t) * t;
        case 30:
            t = 2 * x - 79;
            return 0.90908e-1 + (0.18544e-2 + (0.13903e-4 + (0.95549e-7 + (0.59752e-9 + (0.33656e-11 + 0.16815e-13 * t) * t) * t) * t) * t) * t;
        case 40:
            t = 2 * x - 99;
            return 0.13443e0 + (0.25474e-2 + (0.21385e-4 + (0.15996e-6 + (0.10585e-8 + (0.61258e-11 + 0.30412e-13 * t) * t) * t) * t) * t) * t;
        case 50:
            t = 2 * x - 119;
            return 0.19540e0 + (0.36342e-2 + (0.34096e-4 + (0.27479e-6 + (0.18934e-8 + (0.11021e-10 + 0.52931e-13 * t) * t) * t) * t) * t) * t;
        case 78:
            t = 2 * x - 157;
            return 0.40282e0 + (0.79762e-2 + (0.89909e-4 + (0.79687e-6 + (0.55989e-8 + (0.30866e-10 + 0.12868e-12 * t) * t) * t) * t) * t) * t;
        case 85:
            t = 2 * x - 171;
            return 0.53453e0 + (0.11030e-1 + (0.13088e-3 + (0.11784e-5 + (0.81743e-8 + (0.43252e-10 + 0.16692e-12 * t) * t) * t) * t) * t) * t;
        case 87:
            t = 2 * x - 175;
            return 0.58082e0 + (0.12135e-1 + (0.14584e-3 + (0.13164e-5 + (0.90803e-8 + (0.47397e-10 + 0.17850e-12 * t) * t) * t) * t) * t) * t;
        default:
            return 1.0;
    }
}

int main() {
    double d = foo(78.4);  // Fixed input value
    if (d < 0.38 || d > 0.42) {
        printf("Result is out of expected range. Exiting.\n");
        return EXIT_FAILURE;  // Use standard failure return
    }
    printf("Computation successful with result: %f\n", d);
    return EXIT_SUCCESS;  // Use standard success return
}