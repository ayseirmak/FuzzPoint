#include <stdio.h>
#include <assert.h>
#include <math.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

static const float huge_ceil = 1.0e30f;

float ceil_float(float x) {
    __int32_t i0, j0;
    __uint32_t i, ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    i0 = gf_u.word;

    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;

    if (j0 < 23) {
        if (j0 < 0) {
            if (huge_ceil + x > 0.0f) {
                if (i0 < 0) {
                    i0 = 0x80000000;
                } else if (ix != 0) {
                    i0 = 0x3f800000;
                }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0)
                return x;
            if (huge_ceil + x > 0.0f) {
                if (i0 > 0)
                    i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        if (!(ix < 0x7f800000)) {
            return x + x;
        } else {
            return x;
        }
    }

    ieee_float_shape_type sf_u;
    sf_u.word = i0;
    x = sf_u.value;
    return x;
}

// Infinity check for floats
int isinf_float(float x) {
    __int32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffff;

    return (ix == 0x7f800000);
}

int main() {
    float x = -INFINITY; // fixed input - represents -INF
    float res = ceil_float(x);

    // x is -inf, the result shall be -inf
    if (!isinf_float(res)) {
        printf("Error: Expected result to be -inf, but it was not.\n");
        return 1;
    }

    printf("Test passed: Result is -inf as expected.\n");
    return 0;
}