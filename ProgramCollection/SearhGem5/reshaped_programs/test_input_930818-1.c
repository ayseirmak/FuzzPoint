#include <stdio.h>
#include <stdlib.h>

static double one = 1.0;

int f(double one) {
    int colinear;
    colinear = (one == 0.0);
    if (colinear)
        abort();
    return colinear;
}

int main() {
    if (f(one)) abort();
    return 0;
}