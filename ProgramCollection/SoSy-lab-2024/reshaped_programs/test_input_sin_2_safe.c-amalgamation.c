#include <stdio.h>
#include <math.h>
#include <assert.h>

#define SIN_CHECK_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062f
#define SIN_CHECK_RANGE 200.0f
#define SIN_CHECK_ERROR 1e-4f

int main() /* check_periodic */ {
    float x1 = 10.0f; // Fixed test value within the valid range
    
    // Replace __VERIFIER_assume with a simple range check
    if (x1 < -SIN_CHECK_RANGE || x1 > SIN_CHECK_RANGE) {
        printf("x1 is out of range, adjust the value to be within [-%f, %f]\n", SIN_CHECK_RANGE, SIN_CHECK_RANGE);
        return -1;
    }

    float x2 = x1 + 2.0f * SIN_CHECK_PI; /* Next period */
    float error = fabsf(sinf(x1) - sinf(x2));
    
    // Replace __VERIFIER_assert with standard assert
    assert(error <= SIN_CHECK_ERROR);

    printf("Test passed: error %f is within the acceptable range\n", error);

    return 0;
}