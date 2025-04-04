#include <stdio.h>
#include <complex.h>    // Required for complex number operations
#include <stdlib.h>     // Required for exit() function
#include <assert.h>     // Required for assert() function

__complex__ double f(__complex__ double x, __complex__ double y) {
    x += y;
    return x;
}

int main() {
    __complex__ double ag = 0.0 + 1.0i;
    __complex__ double bg = -2.0 + 2.0i;

    __complex__ double a, b, c;

    a = ag;
    b = -2.0 + 2.0i;
    c = f(a, b);

    // Replacing aborts and undefined behavior with assertions
    // Ensuring deterministic behavior by having defined values for comparisons
    assert(creal(a) == 0.0 && cimag(a) == 1.0);  // a should be 0.0 + 1.0i
    assert(creal(b) == -2.0 && cimag(b) == 2.0); // b should remain -2.0 + 2.0i
    assert(creal(c) == -2.0 && cimag(c) == 3.0); // c should be -2.0 + 3.0i

    // If all assertions pass, the program exits with 0
    return 0;
}