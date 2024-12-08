#include <stdio.h>
#include <math.h>
#include <assert.h>

float softplus(float x) {
    return log1pf(expf(x));
}

#define SOFTPLUS_CHECK_LOG2 0.6931471805599453094172321214581765680755001343602552541206800094f
#define SOFTPLUS_CHECK_ERROR 1e-7f

int main() {
    // Deterministic value for x instead of non-deterministic input
    float x = 1.0f;  // Example fixed value; change as needed for testing

    // Assume x is not NaN
    if (isnan(x)) {
        printf("x is NaN, exiting...\n");
        return 0;
    }

    float y = softplus(x);
    float z = 0.5f * x + SOFTPLUS_CHECK_LOG2 - SOFTPLUS_CHECK_ERROR; // Tangent function at x = 0

    // Assert replacement with a standard assert
    assert(isgreaterequal(y, z));
    printf("Assertion passed: y >= z\n");

    return 0;
}