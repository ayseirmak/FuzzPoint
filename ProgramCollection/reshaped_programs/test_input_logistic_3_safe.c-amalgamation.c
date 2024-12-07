#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function to calculate the logistic value
float logistic(float x) {
    return 0.5f * tanhf(0.5f * x) + 0.5f;
}

#define LOGISTIC_CHECK_NEXT 1e-1f

int main() {
    // Initialize x1 with a fixed, deterministic value
    float x1 = 1.0f; // The choice of 1.0f is arbitrary and serves as a placeholder
    float x2 = x1 + LOGISTIC_CHECK_NEXT;

    // Instead of verifier functions, ensure x1 is valid using standard functions
    assert(!isnan(x1) && !isinf(x1));

    // Calculate logistic values
    float y1 = logistic(x1);
    float y2 = logistic(x2);
    // Calculate the derivative
    float derivative = (y2 - y1) / LOGISTIC_CHECK_NEXT;

    // Use standard assert for verification
    assert(islessequal(derivative, 0.25f));

    // Logging the values and result for better visibility
    printf("x1: %f, x2: %f\n", x1, x2);
    printf("y1: %f, y2: %f\n", y1, y2);
    printf("Derivative: %f\n", derivative);
    printf("Assertion passed, derivative is within expected bounds\n");

    return 0;
}