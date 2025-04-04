#include <stdio.h>
#include <math.h>
#include <assert.h>

#define COS_CHECK_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062f
#define COS_CHECK_ERROR 1e-2f

int main() /* check_inverse */
{
    // Initialize x with a deterministic value within the valid range [0, PI]
    float x = COS_CHECK_PI / 4.0f; // Example deterministic value: PI/4

    // Safeguard against assumptions (which are removed here)
    assert(isgreaterequal(x, 0.0f) && islessequal(x, COS_CHECK_PI));

    // Proceed with calculations
    float y = acosf(cosf(x));
    float z = fabsf(x - y);

    // Replace custom assertion function with the standard assert
    assert(islessequal(z, COS_CHECK_ERROR)); /* Expected result: verification successful */

    printf("Assertion passed for x = %.5f, y = %.5f, and z = %.5f\n", x, y, z);

    return 0;
}