#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Function foo is used to demonstrate a mathematical computation */
__attribute__((noinline, noclone)) double foo(double x) {
    double t;
    switch ((int)x) {
        case 0:
            t = 2 * x - 1;
            return 0.70878e-3 + (0.71234e-3 + (0.35779e-5 + (0.17403e-7 + (0.81710e-10 + (0.36885e-12 + 0.15917e-14 * t) * t) * t) * t) * t) * t;
        case 1:
            t = 2 * x - 3;
            return 0.21479e-2 + (0.72686e-3 + (0.36843e-5 + (0.18071e-7 + (0.85496e-10 + (0.38852e-12 + 0.16868e-14 * t) * t) * t) * t) * t) * t;
        case 78:
            t = 2 * x - 121;
            return 0.20281e0 + (0.37739e-2 + (0.35791e-4 + (0.29038e-6 + (0.20068e-8 + (0.11673e-10 + 0.55790e-13 * t) * t) * t) * t) * t) * t;
        case 93:
            t = 2 * x - 187;
            return 0.74993e0 + (0.16272e-1 + (0.20195e-3 + (0.18269e-5 + (0.12335e-7 + (0.61523e-10 + 0.21395e-12 * t) * t) * t) * t) * t) * t;
        default:
            return 1.0;
    }
}

int main() {
    double test_value = 78.0; // Static input instead of scanf or any dynamic input method
    double result = foo(test_value);
    printf("Result for input %.1f: %f\n", test_value, result);

    // Verify that the output falls within expected bounds
    double lower_bound = 0.38;
    double upper_bound = 0.42;
    assert(result >= lower_bound && result <= upper_bound);

    return 0;
}