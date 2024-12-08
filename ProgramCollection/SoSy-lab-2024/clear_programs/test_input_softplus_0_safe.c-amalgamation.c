#include <stdio.h>
#include <math.h>
#include <assert.h>

float softplus(float x) {
    return log1pf(expf(x));
}

int main() {
    // Fixed deterministic input value for 'x'
    float x = 1.0f; // Example fixed value; it should meet the expected behavior.
    
    // Assuming the input is not NaN, no need for __VERIFIER_assume
    
    // Calculate the softplus function value
    float y = softplus(x);
    
    // Assert that the result is non-negative
    assert(y >= 0.0f);
    
    // Optional: Print the result for better understanding
    printf("softplus(%f) = %f\n", x, y);

    return 0;
}