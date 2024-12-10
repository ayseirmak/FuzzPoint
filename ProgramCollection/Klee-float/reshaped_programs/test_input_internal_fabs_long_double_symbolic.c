#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
    // Initializing `x` with a specific value, change as needed for testing
    long double x = -NAN;  // Example with negative NaN for demonstrative purposes

    // Use `fabsl` to get the absolute value of a long double
    long double result = fabsl(x);

    if (isnan(x)) {
        if (signbit(x)) {
            printf("-ve nan\n");
        } else {
            printf("+ve nan\n");
        }
        assert(!signbit(result));
        assert(isnan(result));
        return 0;
    }

    if (isinf(x)) {
        if (signbit(x)) {
            printf("-ve inf\n");
        } else {
            printf("+ve inf\n");
        }
        assert(!signbit(result));
        assert(isinf(result) == 1);
        return 0;
    }

    if (x == 0.0l) {
        if (signbit(x)) {
            printf("-ve 0.0\n");
        } else {
            printf("+ve 0.0\n");
        }
        assert(!signbit(result));
        assert(result == 0.0l);
        return 0;
    }

    printf("result > 0.0\n");
    assert(result > 0.0l);

    return 0;
}