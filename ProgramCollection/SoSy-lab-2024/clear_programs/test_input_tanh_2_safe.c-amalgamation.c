#include <stdio.h>
#include <math.h>
#include <assert.h>

#define TANH_CHECK_NEXT 1e-5f

int main() /* check_non_decreasing */
{
    // Initialize x1 to a fixed, deterministic value
    float x1 = 0.5f;  // Example fixed value

    // Calculate x2 as a deterministic increment
    float x2 = x1 + TANH_CHECK_NEXT;

    // No need for assume as we have eliminated non-determinism
    // Calculate tanh for both x1 and x2
    float y1 = tanhf(x1);
    float y2 = tanhf(x2);

    // Use assert to check the assumption that y1 is less than or equal to y2
    assert(islessequal(y1, y2)); /* Expected result: verification successful */

    // Print the result for verification
    printf("tanh(%f) <= tanh(%f): %d\n", x1, x2, islessequal(y1, y2));

    return 0;
}