#include <stdio.h>
#include <math.h>
#include <assert.h>

static inline int testf(float b)
{
    float c = 1.01f * b;
    return isinf(c);
}

static inline int test(double b)
{
    double c = 1.01 * b;
    return isinf(c);
}

static inline int testl(long double b)
{
    long double c = 1.01L * b;
    return isinf(c);
}

int main()
{
    // Using typical edge case values close to maximum representable floating point numbers
    float testFloat = 3.4e+38f; // approx close to __FLT_MAX__
    double testDouble = 1.7e+308; // approx close to __DBL_MAX__
    long double testLongDouble = 1.1e+4932L; // approx close to __LDBL_MAX__ (platform dependent)

    assert(testf(testFloat) == 1);
    assert(test(testDouble) == 1);
    assert(testl(testLongDouble) == 1);

    printf("All tests passed successfully.\n");

    return 0;
}