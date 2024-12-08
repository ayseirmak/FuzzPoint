#include <stdio.h>
#include <math.h>
#include <assert.h>

// Softsign function implementation
float softsign(float x) {
    return x / (fabsf(x) + 1.0f);
}

#define SOFTSIGN_CHECK_NEXT 1e-1f

int main() {
    // Using a fixed value for x1 instead of nondeterministic input
    float x1 = 0.5f; // You can change this value as needed for testing
    float x2 = x1 + SOFTSIGN_CHECK_NEXT;

    // Assuming x1 is a valid finite number: not NaN or infinity
    if (isnan(x1) || isinf(x1)) {
        printf("Error: x1 should not be NaN or infinity.\n");
        return 1;
    }

    float y1 = softsign(x1);
    float y2 = softsign(x2);
    float derivative = (y2 - y1) / SOFTSIGN_CHECK_NEXT;

    // Asserting that the derivative is less than or equal to 1.0f
    assert(derivative <= 1.0f);

    // Adding a message to indicate completion
    printf("The derivative check is successful.\n");

    return 0;
}