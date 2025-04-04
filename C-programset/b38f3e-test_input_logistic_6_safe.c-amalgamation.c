#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function simulating logistic behavior
float logistic(float x) {
    return 0.5f * tanhf(0.5f * x) + 0.5f;
}

// Define constants
#define LOGISTIC_CHECK_RANGE 10.0f
#define LOGISTIC_CHECK_ERROR 1e-2f

int main() {
    // Initialize x with a specific test value within the defined range
    float x = 5.0f;  // Example test value; you can change this to any value within [-10.0, 10.0]

    // Check the condition similar to __VERIFIER_assume
    if (!(isgreaterequal(x, -LOGISTIC_CHECK_RANGE) && islessequal(x, LOGISTIC_CHECK_RANGE))) {
        printf("Test value out of range\n");
        return 1;
    }

    float y = 2.0f * atanhf(2.0f * logistic(x) - 1);
    float z = fabsf(x - y);

    // Use an assertion to replace __VERIFIER_assert
    assert(islessequal(z, LOGISTIC_CHECK_ERROR));

    printf("Verification successful: z (%f) is less than or equal to %f\n", z, LOGISTIC_CHECK_ERROR);
    return 0;
}