#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() /* check_non_negative */
{
    // Initialize the float 'x' with a deterministic value.
    // Since the original program uses a non-deterministic float,
    // select a constant that represents a typical input scenario.
    float x = 1.0f; // Example input value

    // Ensure 'x' is not NaN
    assert(!isnan(x));

    // Calculate y as the exponential of x
    float y = expf(x);

    // Assert that y is greater than or equal to 0.0f
    assert(isgreaterequal(y, 0.0f)); /* Expected result: verification successful */

    // Optionally, print the result for logging purposes
    printf("expf(%f) = %f, assertion passed.\n", x, y);

    return 0;
}