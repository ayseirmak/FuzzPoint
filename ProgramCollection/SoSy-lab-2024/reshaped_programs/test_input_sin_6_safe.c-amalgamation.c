#include <math.h>
#include <stdio.h>
#include <assert.h>

#define SIN_CHECK_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062f
#define SIN_CHECK_ERROR 1e-2f

int main() {
    // Fixed value for x within the given range
    float x = 0.5f;  // This value was chosen arbitrarily within the permissible range

    // Check the range as mentioned in the original code
    if (isgreaterequal(x, -SIN_CHECK_PI / 2.0f) && islessequal(x, SIN_CHECK_PI / 2.0f)) {
        float y = asinf(sinf(x));
        float z = fabsf(x - y);

        // Replace __VERIFIER_assert with standard assert
        assert(islessequal(z, SIN_CHECK_ERROR));

        // Log output for verification
        printf("Assert passed: |x - y| = %f is less than or equal to %f\n", z, SIN_CHECK_ERROR);
    } else {
        printf("Value of x is out of range.\n");
    }

    return 0;
}