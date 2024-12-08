#include <stdio.h>
#include <math.h>
#include <assert.h>

#define COS_CHECK_RANGE 32.0f
#define COS_CHECK_ERROR 1e-3f
#define COS_CHECK_NEXT 1e-2f

int main() /* check_derivative */
{
    // Define and initialize the fixed value for x1 within the specified range
    float x1 = 10.0f; // Chosen as a representative value within the range

    // Ensure that x1 is within the specified range
    assert(x1 >= -COS_CHECK_RANGE && x1 <= COS_CHECK_RANGE);

    float x2 = x1 + COS_CHECK_NEXT;

    // Assert that x1 is non-negative
    assert(x1 >= 0.0f);

    float y1 = cosf(x1);
    float y2 = cosf(x2);
    float derivative = (y2 - y1) / COS_CHECK_NEXT;

    float dref = -sinf(x1 / 2.0f + x2 / 2.0f); /* Analytical derivative of cos(x) at the midpoint between x1 and x2 */
    float error = fabsf(derivative - dref);

    // Replace the custom verifier assert with standard C assert. Check error is within the acceptable range.
    assert(error <= COS_CHECK_ERROR); /* Expected result: verification successful */

    // Log the results for verification
    printf("x1: %f, x2: %f, y1: %f, y2: %f, derivative: %f, dref: %f, error: %f\n", x1, x2, y1, y2, derivative, dref, error);

    return 0;
}