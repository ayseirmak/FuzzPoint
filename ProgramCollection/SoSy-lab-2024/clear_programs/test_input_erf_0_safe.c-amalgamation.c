#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() /* check_lower_bound */
{
    // Since nondeterministic input is not allowed, we define a fixed value.
    // For this example, let's choose a specific value for x.
    float x = 0.5f; // You can change this fixed value as needed.

    // Ensure x is not NaN (Not a Number)
    // Since we assign a deterministic value to x, there's no need to check for NaN.
    assert(!isnan(x));

    // Calculate the error function of x
    float y = erff(x);

    // Assert that the result is greater than or equal to -1.0f
    assert(isgreaterequal(y, -1.0f)); /* Expected result: verification successful */

    // Output the results for verification
    printf("x = %f, erff(x) = %f\n", x, y);

    return 0;
}