#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <float.h>

int main() {
    // Initialize x with a specific value
    float x = -4.0f; // Example negative value to simulate sqrt for negative numbers

    // Calculate the square root
    float result = sqrtf(x); // Use standard sqrtf function

    // Check for NaN input
    if (isnan(x)) {
        assert(isnan(result));
        return 0;
    }

    // Check for negative input
    if (x < 0.0f) {
        assert(isnan(result));
        printf("Result is NaN for negative input as expected.\n");
        return 0;
    }

    // Check for positive infinity
    if (isinf(x)) {
        assert(isinf(result) == 1);
        printf("Result is infinity for infinity input as expected.\n");
        return 0;
    }

    // Check for zero input
    if (x == 0.0f) {
        assert(result == 0.0f);
        // Check sign bit (sqrt(-0.0) == -0.0)
        if (signbit(x)) {
            assert(signbit(result));
            printf("Result maintains negative zero sign as expected.\n");
        } else {
            printf("Result is zero for zero input as expected.\n");
        }
        return 0;
    }

    // Ensure x is positive
    assert(x > 0.0f);
    printf("Result is calculated for positive input as expected.\n");

    return 0;
}