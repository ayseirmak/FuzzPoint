#include <stdio.h>
#include <math.h>
#include <assert.h>

// Replacement for __VERIFIER_nondet_float()
// Providing a deterministic example value for x.
float deterministic_value() {
    return 1.5f; // Example value; this can be any float you want to test.
}

float softplus(float x) {
    return log1pf(expf(x));
}

int main() {
    float x = deterministic_value();
    
    // Ensure x is not NaN by initialization choice.
    assert(!isnan(x));
    
    float y = softplus(x);
    
    // Standard assert to ensure y >= x
    assert(isgreaterequal(y, x)); 
    
    // Log result to verify in ARM
    printf("Softplus(%f) = %f; Verification successful\n", x, y);

    return 0;
}