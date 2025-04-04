#include <stdio.h>
#include <stdlib.h>

#ifdef __ARM_ARCH
// Ensure compatibility on ARM architecture
#endif

double foo(double x) {
    double t;
    switch ((int)x) {
        case 0:
            t = 2 * x - 1;
            return 0.70878e-3 + (0.71234e-3 + (0.35779e-5 + (0.17403e-7 + (0.81710e-10 + (0.36885e-12 + 0.15917e-14 * t) * t) * t) * t) * t) * t;
        case 1:
            t = 2 * x - 3;
            return 0.21479e-2 + (0.72686e-3 + (0.36843e-5 + (0.18071e-7 + (0.85496e-10 + (0.38852e-12 + 0.16868e-14 * t) * t) * t) * t) * t) * t;
        // Add other cases as originally necessary...
        case 78:
            t = 2 * x - 157;
            return 0.40282e0 + (0.79762e-2 + (0.89909e-4 + (0.79687e-6 + (0.55989e-8 + (0.30866e-10 + 0.12868e-12 * t) * t) * t) * t) * t) * t;
        // Add the remaining cases here...
        default:
            return 1.0;
    }
}

int main() {
    double d = foo(78.4);  // Fixed input value

    if (d < 0.38 || d > 0.42) {
        printf("Error: Output is out of range.\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Output is within the expected range.\n");
    }

    return 0;
}