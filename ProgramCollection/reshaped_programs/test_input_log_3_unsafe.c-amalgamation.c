#include <stdio.h>
#include <math.h>
#include <assert.h>

#define LOG_CHECK_NEXT 1e-2f

int main() {
    // Set a fixed value for x1 since we can't use nondeterministic functions
    float x1 = 1.0f; // Choosing a fixed positive number
    float x2 = x1 + LOG_CHECK_NEXT;

    // Ensure x1 is within the assumptions used in the original code
    assert(isgreaterequal(x1, 0.0f) && !isinf(x1));

    float y1 = logf(x1);
    float y2 = logf(x2);
    float derivative = (y2 - y1) / LOG_CHECK_NEXT;

    float d1 = 1.0f / x1; // Analytical derivative of log(x) at x = x1

    // Replace verification function with standard assertion
    assert(isgreaterequal(derivative, d1));

    // Optional: Print results for verification/debugging
    printf("x1: %f, x2: %f\n", x1, x2);
    printf("y1: %f, y2: %f\n", y1, y2);
    printf("Calculated Derivative: %f\n", derivative);
    printf("Analytical Derivative: %f\n", d1);

    return 0;
}