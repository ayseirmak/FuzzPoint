#include <math.h>
#include <stdio.h>
#include <assert.h>

#define EXP_CHECK_RANGE 88.0f
#define EXP_CHECK_ERROR 1e-9f

int main() {
    // Use a fixed value for x instead of nondeterministic input
    float x = 1.0f; // Example value within the specified range [-EXP_CHECK_RANGE, EXP_CHECK_RANGE]

    // Check if the value of x is within the range; use assert to mimic __VERIFIER_assume
    assert(x >= -EXP_CHECK_RANGE && x <= EXP_CHECK_RANGE);

    float y = logf(expf(x));
    float z = fabsf(x - y);

    // Use assert to mimic __VERIFIER_assert
    assert(z <= EXP_CHECK_ERROR);

    printf("Expression verified for x = %.2f: z = %.10f\n", x, z);

    return 0;
}