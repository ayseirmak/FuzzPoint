#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    float x = 1.0; // Example of a normal float
    // Check if x is a normal float
    if (isnormal(x)) {
        assert(isnormal(x));
        printf("The value is a normal floating-point number.\n");
    } else {
        // It could be 0, NaN, Inf, subnormal
        assert(!isnormal(x));
        printf("The value is not a normal floating-point number.\n");
    }

    x = 0.0; // Example of zero to demonstrate other paths
    if (isnormal(x)) {
        assert(isnormal(x));
        printf("The value is a normal floating-point number.\n");
    } else {
        assert(!isnormal(x));
        printf("The value is not a normal floating-point number.\n");
    }

    x = INFINITY; // Example to demonstrate Infinity handling
    if (isnormal(x)) {
        assert(isnormal(x));
        printf("The value is a normal floating-point number.\n");
    } else {
        assert(!isnormal(x));
        printf("The value is not a normal floating-point number.\n");
    }

    x = NAN; // Example to demonstrate NaN handling
    if (isnormal(x)) {
        assert(isnormal(x));
        printf("The value is a normal floating-point number.\n");
    } else {
        assert(!isnormal(x));
        printf("The value is not a normal floating-point number.\n");
    }

    return 0;
}