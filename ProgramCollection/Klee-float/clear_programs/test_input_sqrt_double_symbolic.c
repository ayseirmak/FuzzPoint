#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
    double x = 0.0; // You can change this to test different scenarios.
    double result = sqrt(x);

    if (isnan(x)) {
        assert(isnan(result));
        return 0;
    }

    if (x < 0.0) {
        assert(isnan(result));
        return 0;
    }

    if (isinf(x)) {
        assert(isinf(result) == 1);
        return 0;
    }

    if (x == 0.0) {
        assert(result == 0.0);
        // Check sign bit: sqrt(-0.0) should be -0.0
        if (signbit(x)) {
            assert(signbit(result));
        }
        return 0;
    }

    assert(x > 0.0); // Ensures that x must be positive at this point
    return 0;
}