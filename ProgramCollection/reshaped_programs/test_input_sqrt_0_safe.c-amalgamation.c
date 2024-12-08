#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Fixed float value for demonstration
    float x = -1.0f; // Ensure x is less than 0 to trigger the sqrt domain issue

    // Square root calculation
    float y = sqrtf(x);

    // Assertion to check if y is NaN
    assert(isnan(y));

    // Log output for verification
    printf("x: %f, y: %f, y is NaN: %s\n", x, y, isnan(y) ? "true" : "false");

    return 0;
}