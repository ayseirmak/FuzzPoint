#include <stdio.h>
#include <math.h>
#include <assert.h>

#define SIN_CHECK_RANGE 32.0f
#define SIN_CHECK_ERROR 1e-3f
#define SIN_CHECK_NEXT 1e-2f

int main() {
    // Fixed and deterministic input for 'x1'
    float x1 = 1.0f; // Choosing a value within the defined range

    // Ensure 'x1' is within the specified range using simple assertions
    assert(x1 >= -SIN_CHECK_RANGE && x1 <= SIN_CHECK_RANGE);
    assert(x1 >= 0.0f); // Additional condition check

    float x2 = x1 + SIN_CHECK_NEXT;
    float y1 = sinf(x1);
    float y2 = sinf(x2);
    float derivative = (y2 - y1) / SIN_CHECK_NEXT;

    float dref = cosf(x1 / 2.0f + x2 / 2.0f); // Average analytical derivative of sin(x) at midpoint
    float error = fabsf(derivative - dref);

    assert(error <= SIN_CHECK_ERROR); // Validation of the calculated derivative

    printf("The calculated derivative error is: %f\n", error);

    return 0;
}