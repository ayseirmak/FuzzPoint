#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Initialize x to a fixed deterministic value
    float x = 1.0f;  // As an example, use x = 1.0. You can choose any non-negative value.

    // No need for __VERIFIER_assume as we've set x directly to a non-negative number.
    // Calculate y and z
    float y = sqrtf(x);
    float z = 0.5f * x + 0.5f;

    // Use standard assert to check the condition
    assert(y <= z);

    // Output for verification purposes
    printf("Assertion passed. y: %f, z: %f\n", y, z);

    return 0;
}