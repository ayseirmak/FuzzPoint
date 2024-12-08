#include <stdio.h>
#include <math.h>
#include <assert.h>

#define ERF_CHECK_NEXT 1e-2f

/* The truncated constant */
#define ERF_CHECK_TWO_OVER_SQRT_PI 1.1283f

int main() /* check_derivative */
{
    // Fixed input variables for deterministic behavior
    float x1 = 0.5f; // Example constant value for x1
    float x2 = x1 + ERF_CHECK_NEXT;

    // Assumption check (not supporting NaNs)
    if (!isnan(x1)) {
        float y1 = erff(x1);
        float y2 = erff(x2);
        float derivative = (y2 - y1) / ERF_CHECK_NEXT;

        // Assert to replace __VERIFIER_assert
        assert(isgreaterequal(derivative, 0.0f));
    } else {
        printf("x1 is NaN, which is unexpected.\n");
    }

    return 0;
}