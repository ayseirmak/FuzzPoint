#include <stdio.h>
#include <math.h>
#include <assert.h>

#define SQRT_CHECK_NEXT 1e-2f
#define SQRT_CHECK_RANGE 1e1f

int main() {
    // Fixed value for deterministic behavior
    float x1 = SQRT_CHECK_RANGE + 1.0f;  // Ensure x1 satisfies the condition used in the original code
    float x2 = x1 + SQRT_CHECK_NEXT;

    // Check conditions as per original logic
    if (!(isgreaterequal(x1, SQRT_CHECK_RANGE) && !isinf(x1))) {
        fprintf(stderr, "Initial assumptions do not hold.\n");
        return 1;
    }

    float y1 = sqrtf(x1);
    float y2 = sqrtf(x2);
    float derivative = (y2 - y1) / SQRT_CHECK_NEXT;

    float d1 = 1.0f / (2.0f * y1);  // Analytical derivative of sqrt(x) at x = x1

    // Replacing __VERIFIER_assert with standard assertion
    assert(isgreaterequal(derivative, d1));

    printf("Derivative: %f, Analytical: %f\n", derivative, d1);

    return 0;
}