#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double foo(double x) {
    double t;
    switch ((int) x) {
    case 0:
        t = 2 * x - 1;
        return 0.70878e-3 + (0.71234e-3 + (0.35779e-5 + (0.17403e-7 + (0.81710e-10 + (0.36885e-12 + 0.15917e-14 * t) * t) * t) * t) * t) * t;
    case 1:
        t = 2 * x - 3;
        return 0.21479e-2 + (0.72686e-3 + (0.36843e-5 + (0.18071e-7 + (0.85496e-10 + (0.38852e-12 + 0.16868e-14 * t) * t) * t) * t) * t) * t;
    case 2:
        t = 2 * x - 5;
        return 0.36165e-2 + (0.74182e-3 + (0.37948e-5 + (0.18771e-7 + (0.89484e-10 + (0.40935e-12 + 0.17872e-14 * t) * t) * t) * t) * t) * t;
    case 3:
        t = 2 * x - 7;
        return 0.51154e-2 + (0.75722e-3 + (0.39096e-5 + (0.19504e-7 + (0.93687e-10 + (0.43143e-12 + 0.18939e-14 * t) * t) * t) * t) * t) * t;
    // (other cases remain unchanged)
    case 92:
        t = 2 * x - 185;
        return 0.71818e0 + (0.15486e-1 + (0.19128e-3 + (0.17307e-5 + (0.11732e-7 + (0.58991e-10 + 0.20803e-12 * t) * t) * t) * t) * t) * t;
    case 93:
        t = 2 * x - 187;
        return 0.74993e0 + (0.16272e-1 + (0.20195e-3 + (0.18269e-5 + (0.12335e-7 + (0.61523e-10 + 0.21395e-12 * t) * t) * t) * t) * t) * t;
    }
    return 1.0;
}

int main() {
    double d = foo(78.4);
    
    if (d < 0.38 || d > 0.42) {
        printf("Aborting due to unexpected function output: %f\n", d);
        abort();
    } else {
        printf("Function output is within expected range: %f\n", d);
    }

    return 0;
}