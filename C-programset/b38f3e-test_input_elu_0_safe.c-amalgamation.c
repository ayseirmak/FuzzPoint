#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

// Function to emulate __VERIFIER_assume using assert for deterministic conditions
#define ASSUME(cond) assert(cond)

float elu(float x) {
    if (x >= 0.0f)
        return x;
    else
        return expm1f(x);
}

int main() {
    // Using a fixed deterministic value for x
    float x = -0.5f; // Example fixed value for testing
    
    // Ensure x is not NaN (as per original __VERIFIER_assume logic)
    ASSUME(!isnan(x));
    
    float y = elu(x);
    
    // Perform the assertion check using standard assert
    // It checks that y is greater than or equal to -1.0f
    assert(y >= -1.0f);
    
    printf("Assertion passed for x = %f with y = %f\n", x, y);

    return 0;
}