#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
    long double x = 4.0; // Initialized with a positive value for the test case
    long double result = sqrtl(x);

    if (isnan(x)) {
        assert(isnan(result));
    } else if (x < 0.0) {
        assert(isnan(result));
    } else if (isinf(x)) {
        assert(isinf(result) == 1);
    } else if (x == 0.0l) {
        assert(result == 0.0l);
        // check sign bit sqrt(-0.0) == -0.0
        if (signbit(x)) {
            assert(signbit(result));
        }
    } else {
        assert(x > 0.0l);
    }

    return 0; // Indicate successful execution
}