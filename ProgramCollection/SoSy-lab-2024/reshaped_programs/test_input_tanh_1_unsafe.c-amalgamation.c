#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() /* check_upper_bound */
{
    // Fixed deterministic input value for x
    float x = 0.5f;  // Example input within range

    // Ensure x is not NaN, since it's a fixed value we've set it should never be NaN
    assert(!isnan(x));

    float y = tanhf(x);

    // Assert fails if y is not greater than or equal to 1.0f; it will not fail for this input
    // as tanh values range between -1 and 1; hence this assertion is incorrect by design
    assert(isgreaterequal(y, 1.0f)); /* Expected result: verification failure */

    return 0;
}