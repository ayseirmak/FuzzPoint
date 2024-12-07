#include <stdio.h>   // For the printf function
#include <math.h>    // For expf, log1pf, islessequal, isgreaterequal
#include <assert.h>  // For the assert macro

float softplus(float x) {
    return log1pf(expf(x));
}

#define SOFTPLUS_CHECK_RANGE 88.0f
#define SOFTPLUS_CHECK_NEXT 1e-5f

int main() {
    // Fixed deterministic value within the specified range.
    float x1 = 50.0f;  // Example chosen within the acceptable range
    float x2 = x1 + SOFTPLUS_CHECK_NEXT;

    // Ensure `x1` is less or equal to `SOFTPLUS_CHECK_RANGE`.
    assert(islessequal(x1, SOFTPLUS_CHECK_RANGE));

    float y1 = softplus(x1);
    float y2 = softplus(x2);
    float derivative = (y2 - y1) / SOFTPLUS_CHECK_NEXT;

    // Ensure the derivative is non-negative as softplus is a non-decreasing function.
    assert(isgreaterequal(derivative, 0.0f));

    // Output the results for verification.
    printf("x1: %f, x2: %f, y1: %f, y2: %f, derivative: %f\n", x1, x2, y1, y2, derivative);
    
    return 0;
}