#include <stdio.h>
#include <math.h>
#include <assert.h>

float logistic(float x) {
    return 0.5f * tanhf(0.5f * x) + 0.5f;
}

int main() {
    // Use a fixed value for x, as nondeterministic inputs are not allowed.
    float x = 1.0f;  // Replace this value with any specific test value you want to observe.

    // There is no need for __VERIFIER_assume since we're setting x directly. Ensure x >= 0.
    if (x >= 0.0f) {
        float y = logistic(x);
        float z = 1.0f - logistic(-x);

        // Use standard assert instead of __VERIFIER_assert
        printf("y: %.6f, z: %.6f\n", y, z);
        assert(y == z);  // Since this is expected to possibly fail, it will trigger the assert if not equal.
    } else {
        // Log a message if x is not valid; though this shouldn't happen due to our fixed choice.
        printf("Chosen x is not suitable, please ensure x >= 0.0f\n");
    }

    return 0;
}