#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function to compute the logistic function for a given value x
float logistic(float x) {
    return 0.5f * tanhf(0.5f * x) + 0.5f;
}

#define LOGISTIC_CHECK_RANGE 10.0f
#define LOGISTIC_CHECK_ERROR 1e-6f

int main() {
    // Fixed value for x within the specified range [-10, 10]
    float x = 0.0f;  // Set this to any deterministic value within [-10.0f, 10.0f]

    // Calculating y using the logistic function
    float y = 2.0f * atanhf(2.0f * logistic(x) - 1.0f);

    // Calculate the absolute difference
    float z = fabsf(x - y);

    // Assert that checks for the precision error threshold
    assert(z <= LOGISTIC_CHECK_ERROR);  // Expected to fail if the precision error is too large

    // Log output for demonstration purpose
    printf("x: %f, y: %f, z (error): %f\n", x, y, z);

    return 0;
}