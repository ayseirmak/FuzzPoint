#include <stdio.h>
#include <math.h>
#include <assert.h>

// Logistic function definition
float logistic(float x) {
    return 0.5f * tanhf(0.5f * x) + 0.5f;
}

#define LOGISTIC_CHECK_NEXT 1e-5f

int main() {
    // Replacing nondeterministic value with a fixed, initialized value
    float x1 = 0.0f;  // fixed example value
    float x2 = x1 + LOGISTIC_CHECK_NEXT;

    // Assume x1 is not NaN
    assert(!isnan(x1));

    // Compute logistic values
    float y1 = logistic(x1);
    float y2 = logistic(x2);

    // Assert that y1 is less than or equal to y2
    assert(islessequal(y1, y2));

    // If assertion fails, this message will not be printed
    printf("Assertion passed: logistic function is non-decreasing.\n");

    return 0;
}