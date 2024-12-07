#include <stdio.h>
#include <math.h>
#include <assert.h>

// Constants defining the range and error for cosine derivative check
#define COS_CHECK_RANGE 32.0f
#define COS_CHECK_ERROR 1e-6f
#define COS_CHECK_NEXT 1e-2f

int main() {
    // Fixed value for x1 instead of nondeterministic input
    float x1 = 1.0f;  // choose any value within [-COS_CHECK_RANGE, COS_CHECK_RANGE]

    // Ensure x1 is within the desired range and non-negative as per the original assumptions
    assert(isgreaterequal(x1, -COS_CHECK_RANGE) && islessequal(x1, COS_CHECK_RANGE));
    assert(isgreaterequal(x1, 0.0f));

    // Calculate x2 based on x1
    float x2 = x1 + COS_CHECK_NEXT;

    // Calculate the cosine values and derivative based on x1 and x2
    float y1 = cosf(x1);
    float y2 = cosf(x2);
    float derivative = (y2 - y1) / COS_CHECK_NEXT;

    // Calculate the reference derivative and the error
    float dref = -sinf(x1 / 2.0f + x2 / 2.0f); /* analytical derivative of cos(x) at the midpoint between x1 and x2 */
    float error = fabsf(derivative - dref);

    // Assert to verify if the computed error is within acceptable limits
    assert(islessequal(error, COS_CHECK_ERROR));

    // Print the results for diagnostic purposes
    printf("x1: %f, x2: %f, y1: %f, y2: %f, derivative: %f, dref: %f, error: %f\n", x1, x2, y1, y2, derivative, dref, error);

    return 0;
}