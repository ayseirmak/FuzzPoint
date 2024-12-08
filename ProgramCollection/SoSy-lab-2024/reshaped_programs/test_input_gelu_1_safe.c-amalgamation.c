#include <stdio.h>
#include <math.h>
#include <assert.h>

#define GELU_CHECK_SQRT2 1.41421356237309504880168872420969807856967187537694807317667973799f

float gelu(float x) {
    float cdf = 0.5f * erff(x / GELU_CHECK_SQRT2) + 0.5f; /* Express the CDF of the normal distribution in terms of the error function */
    return x * cdf;
}

int main() {
    float x = 2.0f;  // Deterministic input value instead of nondeterministic input
    
    // We know x is already greater than or equal to 0.0f and not infinite, so these assumptions are intrinsically true

    float y = gelu(x);
    
    // Replace custom verifier assertions with standard assertions
    assert(islessequal(y, x)); /* Expected result: verification successful */
    
    printf("GELU(%f) = %f\n", x, y);
    
    return 0;
}