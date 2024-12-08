#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>

#define GELU_CHECK_SQRT2 1.41421356237309504880168872420969807856967187537694807317667973799f
#define GELU_CHECK_NEXT 1e-5f

float gelu(float x) {
    float cdf = 0.5f * erff(x / GELU_CHECK_SQRT2) + 0.5f; // Express the CDF of the normal distribution in terms of the error function
    return x * cdf;
}

int main() {
    // Fixed value for x1 for this deterministic program
    float x1 = 0.5f; // Choose a fixed value for deterministic analysis
    float x2 = x1 + GELU_CHECK_NEXT;

    // Ensuring x1 is neither NaN nor Infinity for this specific value
    bool safe_value = !isnan(x1) && !isinf(x1);
    assert(safe_value); // Replacing __VERIFIER_assume with assert

    float y1 = gelu(x1);
    float y2 = gelu(x2);
    float derivative = (y2 - y1) / GELU_CHECK_NEXT;

    // Replacing __VERIFIER_assert with assert to ensure standard compliance
    assert(islessequal(derivative, 1.0f)); // Expected result: verification failure

    // Log the derivative for examination
    printf("Derivative at x1 = %.5f is %.5f\n", x1, derivative);

    return 0;
}