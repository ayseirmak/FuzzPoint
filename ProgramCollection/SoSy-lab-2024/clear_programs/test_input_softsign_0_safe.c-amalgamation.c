#include <stdio.h>
#include <assert.h>
#include <math.h>

float softsign(float x) {
    return x / (fabsf(x) + 1.0f);
}

int main() {
    // Using a fixed set of test values for x
    float test_values[] = {-10.0f, -1.0f, 0.0f, 1.0f, 10.0f};
    int num_tests = sizeof(test_values) / sizeof(test_values[0]);

    for (int i = 0; i < num_tests; i++) {
        float x = test_values[i];

        // Assume statements replaced with conditions, printed for demonstrative purposes
        if (!isnan(x) && !isinf(x)) {
            float y = softsign(x);

            // Using assert to ensure the postcondition
            assert(isgreaterequal(y, -1.0f));
            printf("Test %d: softsign(%f) = %f, assertion passed.\n", i + 1, x, y);
        } else {
            printf("Test %d: Value is either NaN or Inf, skipped.\n", i + 1);
        }
    }

    return 0;
}