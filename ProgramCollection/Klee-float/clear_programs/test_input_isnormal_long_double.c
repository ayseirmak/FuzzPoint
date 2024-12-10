#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Initialize x to a typical value, e.g., a normal floating-point number
    long double x = 1.0L;

    // Simulate the check for a normal floating-point number
    if (isnormal(x)) {
        assert(isnormal(x));
    } else {
        // These conditions happen if x is 0, NaN, Inf, or subnormal
        assert(!isnormal(x));
    }

    // Simulating potential other values for x, depending on the intent of the original program:
    x = 0.0L;
    assert(!isnormal(x));

    x = NAN;
    assert(!isnormal(x));

    x = INFINITY;
    assert(!isnormal(x));

    x = 1e-5000L;  // for subnormal/very small number example
    assert(!isnormal(x));

    printf("All checks passed.\n");
    return 0;
}