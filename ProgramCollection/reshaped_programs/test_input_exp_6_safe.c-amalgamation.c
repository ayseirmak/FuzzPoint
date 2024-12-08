#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EXP_CHECK_NEXT 1e-2f
#define EXP_CHECK_RANGE 88.0f
#define EXP_CHECK_ERROR 1e-6f

int main() /* check_inverse */
{
    // Instead of using nondeterministic input, we set x to a fixed value within the specified range.
    float x = 1.0f; // Example value within the range -88.0f to 88.0f

    // Ensure x is within the desired range for precision.
    if (isgreaterequal(x, -EXP_CHECK_RANGE) && islessequal(x, EXP_CHECK_RANGE)) {
        float y = logf(expf(x));
        float z = fabsf(x - y);

        // Use standard assert to verify the condition instead of __VERIFIER_assert
        assert(islessequal(z, EXP_CHECK_ERROR));
        printf("Assertion passed. Computed error: %.10f\n", z);
    } else {
        printf("Value of x is out of range.\n");
    }

    return 0;
}