#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

static const float huge_ceil = 1.0e30;

float ceil_float(float x) {
    __uint32_t i, ix;
    int j0;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    __uint32_t i0 = gf_u.word;

    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;

    if (j0 < 23) {
        if (j0 < 0) {
            if (huge_ceil + x > (float)0.0) {
                if (i0 < 0) {
                    i0 = 0x80000000;
                } else if (!((ix) == 0)) {
                    i0 = 0x3f800000;
                }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0)
                return x;
            if (huge_ceil + x > (float)0.0) {
                if (i0 > 0)
                    i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        if (!((ix) < 0x7f800000L))
            return x + x;
        else
            return x;
    }

    ieee_float_shape_type sf_u;
    sf_u.word = i0;
    x = sf_u.value;

    return x;
}

// Infinity check for floats
int isinf_float(float x) {
    __uint32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffff;
    return ((ix) == 0x7f800000L);
}

int main() {
    // Define a fixed input: negative infinity
    float x = -INFINITY; 
    float res = ceil_float(x);

    // Check the result for negative infinity
    if (!isinf_float(res)) {
        printf("Error: Expected -inf, got %f\n", res);
        return 1;
    }

    printf("Test passed: Result is -inf as expected.\n");
    return 0;
}