#include <stdio.h>
#include <math.h>
#include <assert.h>

float logistic(float x) {
    return 0.5f * tanhf(0.5f * x) + 0.5f;
}

int main() {
    // Fixed deterministic input
    float x = 2.0f; // Example deterministic value

    // Check for NaN is redundant since x is predefined as a valid number and cannot be NaN
    float y = logistic(x);

    // Using standard assert to check the condition, replacing __VERIFIER_assert
    assert(islessequal(y, 1.0f));
    
    // If using logging
    if (islessequal(y, 1.0f)) {
        printf("Assertion passed: y <= 1.0 is true.\n");
    } else {
        printf("Assertion failed: y <= 1.0 is false.\n");
    }

    return 0;
}