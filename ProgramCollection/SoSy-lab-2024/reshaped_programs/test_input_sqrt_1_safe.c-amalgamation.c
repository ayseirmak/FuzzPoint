#include <assert.h>
#include <stdio.h>
#include <math.h>

int main() {
    // Set a fixed positive value for x to ensure a deterministic output
    float x = 9.0f;  // Example of a hard-coded non-negative number

    // Calculate the square root of x
    float y = sqrtf(x);

    // Use an assertion to verify y is non-negative
    assert(y >= 0.0f);

    // Print values for debugging and verification purposes
    printf("Value of x: %f\n", x);
    printf("Square root of x: %f\n", y);

    return 0;
}