#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <assert.h>

__complex__ double f(__complex__ double x, __complex__ double y) {
    x += y;
    return x;
}

int main() {
    __complex__ double ag = 1.0 + 1.0i;
    __complex__ double bg = -2.0 + 2.0i;
    __complex__ double a, b, c;

    a = ag;
    b = bg;
    c = f(a, b);

    // Asserting the conditions based on initial fixed inputs
    assert(a == (1.0 + 1.0i));
    assert(b == (-2.0 + 2.0i));
    assert(c == (-1.0 + 3.0i));

    printf("All assertions passed.\n");
    return 0;
}