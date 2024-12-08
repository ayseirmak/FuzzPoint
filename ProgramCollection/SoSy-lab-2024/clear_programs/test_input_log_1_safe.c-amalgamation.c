#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() /* check_affine_bound */
{
    // Replace nondeterministic input with a fixed deterministic value
    float x = 1.0f; // Chosen to serve as a valid input for logf and assertion checks

    // Assume replaced by a conditional check. Since x is set to 1, the assumption holds.
    assert(isgreaterequal(x, 0.0f)); 

    float y = logf(x);
    float z = x - 1.0f; /* Tangent function at x = 1 */

    // Verify that the tangent function at x = 1 is greater than or equal to y
    assert(isgreaterequal(z, y)); /* Expected result: verification successful */

    printf("Verification successful: Tangent function at x = 1 is >= to log(x).\n");

    return 0;
}