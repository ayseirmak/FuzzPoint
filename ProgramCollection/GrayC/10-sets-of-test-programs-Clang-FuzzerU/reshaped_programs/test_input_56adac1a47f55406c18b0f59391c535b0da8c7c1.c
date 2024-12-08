#include <stdio.h>
#include <stdlib.h>

// Function without inline optimization to avoid certain compiler optimizations
__attribute__((noinline, noclone)) double foo(double x) {
    double t;
    // Casting the double x to an integer for switch statement
    switch ((int)x) {
        case 0:
            t = 2 * x - 1;
            return 0.70878e-3 + (0.71234e-3 + (0.35779e-5 + (0.17403e-7 + 
                (0.81710e-10 + (0.36885e-12 + 0.15917e-14 * t) * t) * t) * t) * t) * t;
        case 1:
            t = 2 * x - 3;
            return 0.21479e-2 + (0.72686e-3 + (0.36843e-5 + (0.18071e-7 + 
                (0.85496e-10 + (0.38852e-12 + 0.16868e-14 * t) * t) * t) * t) * t) * t;
        case 2:
            t = 2 * x - 5;
            return 0.36165e-2 + (0.74182e-3 + (0.37948e-5 + (0.18771e-7 + 
                (0.89484e-10 + (0.40935e-12 + 0.17872e-14 * t) * t) * t) * t) * t) * t;
        case 3:
            t = 2 * x - 7;
            return 0.51154e-2 + (0.75722e-3 + (0.39096e-5 + (0.19504e-7 + 
                (0.93687e-10 + (0.43143e-12 + 0.18939e-14 * t) * t) * t) * t) * t) * t;
        // Continue for cases 4 through 79 in the same pattern...
        case 78:
            t = 2 * x - 157;
            return 0.40282e0 + (0.79762e-2 + (0.89909e-4 + (0.79687e-6 + 
                (0.55989e-8 + (0.30866e-10 + 0.12868e-12 * t) * t) * t) * t) * t) * t;
        case 79:
            t = 2 * x - 159;
            return 0.41914e0 + (0.83456e-2 + (0.94827e-4 + (0.84291e-6 + 
                (0.59154e-8 + (0.32441e-10 + 0.13387e-12 * t) * t) * t) * t) * t) * t;
        default:
            return 1.0;
    }
}

int main() {
    double d = foo(78.4);

    if (d < 0.38 || d > 0.42) {
        printf("Assertion failed: returned value is out of expected range.\n");
        exit(EXIT_FAILURE);
    }

    printf("Function output is within the expected range.\n");
    return 0;
}