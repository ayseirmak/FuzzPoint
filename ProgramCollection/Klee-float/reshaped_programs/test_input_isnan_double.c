#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    double x = NAN; // Initialize x to NaN for testing

    if (isnan(x)) {
        assert(x != x);
    } else {
        assert(x == x);
    }

    // Additional test case with a typical floating-point value
    x = 1.0; // Change x to a typical value
    if (isnan(x)) {
        assert(x != x);
    } else {
        assert(x == x);
    }

    return 0;
}