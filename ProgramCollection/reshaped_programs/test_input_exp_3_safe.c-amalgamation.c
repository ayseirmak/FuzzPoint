#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EXP_CHECK_NEXT 1e-2f
#define EXP_CHECK_RANGE 88.0f

int main() /* check_derivative */
{
    // Fixed deterministic input value within the range [-EXP_CHECK_RANGE, EXP_CHECK_RANGE]
    float x1 = 0.0f;  // Example value within the defined range

    // Ensure x1 is within the specified range (for example and self-documentation)
    assert(isgreaterequal(x1, -EXP_CHECK_RANGE) && islessequal(x1, EXP_CHECK_RANGE));

    // Calculate next point
    float x2 = x1 + EXP_CHECK_NEXT;

    // Calculate exponential values at the two points
    float y1 = expf(x1);
    float y2 = expf(x2);

    // Calculate the numerical derivative
    float derivative = (y2 - y1) / EXP_CHECK_NEXT;

    // Verify that the derivative is greater than or equal to y1
    assert(isgreaterequal(derivative, y1));

    // Print values for verification
    printf("x1: %f\nx2: %f\ny1: %f\ny2: %f\nderivative: %f\n", x1, x2, y1, y2, derivative);

    return 0;
}