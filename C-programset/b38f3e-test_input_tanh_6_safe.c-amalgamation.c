#include <stdio.h>
#include <math.h>
#include <assert.h>

#define TANH_CHECK_RANGE 5.0f
#define TANH_CHECK_ERROR 1e-2f

int main() /* check_inverse */
{
    // Deterministic input value within given range [-TANH_CHECK_RANGE, TANH_CHECK_RANGE]
    float x = 2.0f;  // Instead of nondeterministic choice, we use a fixed value example

    // Ensure x is within the specified range
    assert(isgreaterequal(x, -TANH_CHECK_RANGE) && islessequal(x, TANH_CHECK_RANGE));

    float y = atanhf(tanhf(x));
    float z = fabsf(x - y);

    // Check that the error is within the specified limit
    assert(islessequal(z, TANH_CHECK_ERROR)); /* Expected result: verification successful */

    printf("Verification successful with x = %f, y = %f, z = %f\n", x, y, z);

    return 0;
}