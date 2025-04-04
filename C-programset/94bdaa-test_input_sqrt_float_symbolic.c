#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
    // Initialize the test values for x covering typical edge cases
    float test_values[] = {-1.0f, 0.0f, -0.0f, 1.0f, INFINITY, NAN};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++) {
        float x = test_values[i];
        float result = sqrtf(x);

        if (isnan(x)) {
            assert(isnan(result));
            printf("Test %d passed: sqrt(NaN) is NaN\n", i);
            continue;
        }

        if (x < 0.0f) {
            assert(isnan(result));
            printf("Test %d passed: sqrt(negative) is NaN\n", i);
            continue;
        }

        if (isinf(x)) {
            assert(isinf(result) == 1);
            printf("Test %d passed: sqrt(inf) is inf\n", i);
            continue;
        }

        if (x == 0.0f) {
            assert(result == 0.0f);
            // check sign bit sqrt(-0.0) == -0.0
            if (signbit(x)) {
                assert(signbit(result));
            }
            printf("Test %d passed: sqrt(0.0) or sqrt(-0.0) is 0.0 or -0.0\n", i);
            continue;
        }

        assert(x > 0.0f);
        printf("Test %d passed: sqrt(positive number)\n", i);
    }

    return 0;
}