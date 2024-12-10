#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
    // Initialize the variable x with typical test cases
    long double x_values[] = {NAN, -1.0l, INFINITY, 0.0l, -0.0l, 4.0l};
    int num_tests = sizeof(x_values) / sizeof(x_values[0]);
    for (int i = 0; i < num_tests; ++i) {
        long double x = x_values[i];
        long double result = sqrtl(x);  // Use standard library sqrtl function

        if (isnan(x)) {
            assert(isnan(result));
            continue;
        }

        if (x < 0.0l) {
            assert(isnan(result));
            continue;
        }

        if (isinf(x)) {
            assert(isinf(result) == 1);
            continue;
        }

        if (x == 0.0l) {
            assert(result == 0.0l);
            // Check sign bit sqrt(-0.0) == -0.0
            if (signbit(x)) {
                assert(signbit(result));
            }
            continue;
        }

        assert(x > 0.0l);
        // For x > 0, also ensure results are reasonable
        assert(fabsl(result - sqrtl(x)) < 0.0001l);
    }

    return 0;
}