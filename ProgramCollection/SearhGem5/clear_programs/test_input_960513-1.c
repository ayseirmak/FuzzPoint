#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long double f(long double d, int i) {
    long double e;

    d = -d;
    e = d;
    if (i == 1)
        d *= 2;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    d -= e * d;
    return d;
}

int main() {
    // Initialize variables with fixed values.
    long double d = 1.0; // Example value
    int i = 2;  // Example value

    // Instead of abort, we use assert to ensure the condition is met.
    assert((int)(f(d, i)) != 0);

    printf("Assertion passed.\n");
    return 0;
}