#include <stdio.h>
#include <math.h>
#include <assert.h>

#define TANH_CHECK_RANGE 5.0f
#define TANH_CHECK_ERROR 1e-6f

int main() {
    // Fixed deterministic value within the range [-TANH_CHECK_RANGE, TANH_CHECK_RANGE]
    float x = 1.0f;  // Example value chosen within the allowed range

    // Compute the inverse hyperbolic tangent of the hyperbolic tangent of x
    float y = atanhf(tanhf(x));
    float z = fabsf(x - y);

    // Assert that the result z should not exceed the error tolerance
    assert(z <= TANH_CHECK_ERROR);

    if (z <= TANH_CHECK_ERROR) {
        printf("Assertion passed: |x - atanhf(tanhf(x))| <= %f\n", TANH_CHECK_ERROR);
    } else {
        printf("Assertion failed: |x - atanhf(tanhf(x))| > %f\n", TANH_CHECK_ERROR);
    }

    return 0;
}