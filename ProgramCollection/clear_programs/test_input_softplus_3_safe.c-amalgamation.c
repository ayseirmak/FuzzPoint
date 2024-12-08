#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function definition for the softplus activation
float softplus(float x) {
    return log1pf(expf(x));
}

#define SOFTPLUS_CHECK_NEXT 1e-5f

int main() {
    // Initialize variables with fixed values
    float x1 = 1.0f; // Fixed input value
    float x2 = x1 + SOFTPLUS_CHECK_NEXT;
    
    // Check if x1 is not NaN - Assume x1 as a valid number
    assert(!isnan(x1));
    
    // Apply softplus function
    float y1 = softplus(x1);
    float y2 = softplus(x2);
    
    // Assert to check the non-decreasing property of the softplus function
    assert(islessequal(y1, y2));

    // Print results for verification
    printf("Softplus(%f) = %f\n", x1, y1);
    printf("Softplus(%f) = %f\n", x2, y2);
    printf("Assertion passed: Softplus is non-decreasing.\n");

    return 0;
}