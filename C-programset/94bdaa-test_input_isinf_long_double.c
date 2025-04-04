#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    long double x = INFINITY; // Example value for demonstrating the assertion
    // Initialize x with a typical or edge case value. Replace it according to specific test requirements.

    if (isinf(x)) {
        assert(isinf(x)); // Standard C check for infinity
        printf("x is infinite\n");
    } else {
        assert(!isinf(x)); // Standard C check for non-infinity
        printf("x is not infinite\n");
    }

    return 0;
}