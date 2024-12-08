#include <stdio.h>
#include <math.h>
#include <assert.h>

#define SQRT_CHECK_NEXT 1e1f
#define SQRT_CHECK_DIFF 1e-2f

int main() {
    // Replacing nondeterministic input with a fixed value
    float x1 = 4.0f;  // Explicitly initialize with a non-negative value
    float x2 = x1 + SQRT_CHECK_NEXT;

    // Assumptions are now handled by setting the initial value appropriately.
    assert(x1 >= 0.0f && !isinf(x1));

    float y1 = sqrtf(x1);
    float y2 = sqrtf(x2);
    float derivative = (y2 - y1) / SQRT_CHECK_NEXT;

    float d2 = 1.0f / (2.0f * y2); // Analytical derivative of sqrt(x) at x = x2
    float diff = derivative - d2;

    // Replace custom verifier assert with standard assert
    assert(diff >= -SQRT_CHECK_DIFF);

    printf("Verification successful: derivative approximation is within acceptable range.\n");

    return 0;
}