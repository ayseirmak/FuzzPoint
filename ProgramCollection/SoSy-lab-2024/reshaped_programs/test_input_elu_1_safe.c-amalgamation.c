#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

// Function definition for Exponential Linear Unit
float elu(float x) {
    if (x >= 0.0f)
        return x;
    else
        return expm1f(x);
}

// Replacement for __VERIFIER_assume
void assume(bool condition) {
    assert(condition);
}

int main() {
    // Deterministic, fixed value for testing
    float x = 1.0f; // Example value, you can choose any constant to test

    // Enforcing the condition that x should not be NaN
    assume(!isnan(x));

    float y = elu(x);

    // Verifying that the result is as expected
    assert(isgreaterequal(y, x));

    printf("Test passed: Function behavior is correct.\n");

    return 0;
}