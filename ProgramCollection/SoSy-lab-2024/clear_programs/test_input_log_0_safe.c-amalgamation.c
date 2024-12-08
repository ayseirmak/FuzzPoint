#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Static value set to a negative number for x to test the logarithm domain.
    float x = -1.0f;
    
    // Check if x is less than 0.0f, the condition is now hardcoded.
    assert(isless(x, 0.0f));
    
    // Compute the logarithm of x. Since x is negative, logf should return NaN.
    float y = logf(x);
    
    // Assert that the result is NaN, which should be true given logf on a negative input.
    assert(isnan(y));

    // Print the result for verification in a real-world scenario.
    printf("Test passed: log(%f) = %f (NaN expected)\n", x, y);

    return 0;
}