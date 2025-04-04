#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Initialize the floating-point variable
    float f = -3.5; // Example value; adjust as necessary for different tests

    // Compute result as the negative of f
    float result = -f;

    // Check the sign bit and apply assertions as necessary
    if (signbit(f)) {
        assert(!signbit(result)); // If f is negative, result should be non-negative
    } else {
        if (!isnan(f)) {
            assert(signbit(result)); // If f is positive and not NaN, result should be negative
        }
    }
    
    // Indicate successful execution
    return 0;
}