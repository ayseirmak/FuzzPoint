#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <assert.h>

/* Function to return the first complex argument */
__complex__ double f(__complex__ double x, __complex__ double y) {
    return x;
}

int main() {
    /* Declare and initialize complex variables */
    __complex__ double ag = 1.0 + 1.0 * I;
    __complex__ double bg = -2.0 + 2.0 * I;

    __complex__ double a, b, c;

    /* Assign values to complex numbers and invoke function */
    a = ag;
    b = bg;
    c = f(a, b);

    /* Assertions to verify the expected values */
    assert(a == (1.0 + 1.0 * I));
    assert(b == (-2.0 + 2.0 * I));
    assert(c == (1.0 + 1.0 * I));

    /* Return successful exit status */
    return 0;
}