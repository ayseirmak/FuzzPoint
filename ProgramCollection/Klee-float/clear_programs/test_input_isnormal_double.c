#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Initialize x with a normal floating-point number and other edge cases
    double normalSamples[] = {1.0, 2.5, -3.0}; // Normal numbers
    double edgeCases[] = {0.0, INFINITY, NAN, pow(2, -1022) / 2}; // Edge cases: 0, Inf, NaN, Subnormal
    
    // Testing normal numbers
    for (int i = 0; i < 3; i++) {
        double x = normalSamples[i];
        if (isnormal(x)) {
            assert(isnormal(x));
            printf("x = %f is a normal number\n", x);
        }
    }
    
    // Testing edge cases
    for (int i = 0; i < 4; i++) {
        double x = edgeCases[i];
        if (!isnormal(x)) {
            assert(!isnormal(x));
            printf("x = %f is not a normal number\n", x);
        }
    }
    
    return 0;
}