#include <stdio.h>
#include <math.h>
#include <assert.h>

#define SIN_CHECK_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062f
#define SIN_CHECK_ERROR 1e-6f

int main() /* check_inverse */
{
    // Using a fixed value for x within the specified range [-PI/2, PI/2]
    float x = 0.5f * SIN_CHECK_PI; // deterministic input

    // Calculate sine and arcsine
    float y = asinf(sinf(x));
    float z = fabsf(x - y);

    // Assert that the difference is within the acceptable error range
    assert(z <= SIN_CHECK_ERROR); // Expected result: assertion might fail

    printf("x: %f, y: %f, z (difference): %f\n", x, y, z);

    return 0;
}