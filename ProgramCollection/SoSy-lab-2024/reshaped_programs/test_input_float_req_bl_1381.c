#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

typedef union {
    float value;
    uint32_t word;
} ieee_float_shape_type;

float copysign_float(float x, float y) {
    uint32_t ix, iy;
    do {
        ieee_float_shape_type gf_u;
        gf_u.value = (x);
        (ix) = gf_u.word;
    } while (0);
    do {
        ieee_float_shape_type gf_u;
        gf_u.value = (y);
        (iy) = gf_u.word;
    } while (0);
    do {
        ieee_float_shape_type sf_u;
        sf_u.word = ((ix & 0x7fffffff) | (iy & 0x80000000));
        (x) = sf_u.value;
    } while (0);
    return x;
}

// NaN check for floats
int isnan_float(float x) {
    return x != x;
}

// This function aims at simulating a failure in case of logic error
void reach_error() {
    printf("Reach Error: Result is not NaN as expected.\n");
}

int main() {
    /*
     * REQ-BL-1381:
     * The copysign and copysignf procedures shall return NaN if the argument x is
     * NaN.
     */

    // Initialize x to NaN
    float x = 0.0f / 0.0f; // NaN
    float y = 1.0f; // Any deterministic float value; it could be any value

    // Invocation of the copysign_float function
    float res = copysign_float(x, y);

    // x is NaN, y can be any, the result shall be NaN
    if (!isnan_float(res)) {
        reach_error();
        return 1;
    }

    return 0;
}