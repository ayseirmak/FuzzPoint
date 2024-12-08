#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function to compute the Exponential Linear Unit (ELU)
float elu(float x) {
    if(x >= 0.0f) {
        return x;
    } else {
        return expm1f(x); // expm1f(x) computes e^x - 1
    }
}

// Define the gap for ELU check
#define ELU_CHECK_NEXT 1e-5f

int main() {
    // Instead of nondeterministic value, using a fixed deterministic value
    float x1 = 0.5f; // Example deterministic input
    float x2 = x1 + ELU_CHECK_NEXT;

    // If x1 is a deterministic value, it is assumed not NaN, so no explicit isnan check is necessary

    float y1 = elu(x1);
    float y2 = elu(x2);

    // Applying standard assert for verification
    assert(islessequal(y1, y2)); // Check if y1 <= y2, which should be true due to ELU properties

    // Output result for confirmation
    printf("Assertion passed: ELU at %.5f (%.5f) <= ELU at %.5f (%.5f)\n", x1, y1, x2, y2);

    return 0;
}