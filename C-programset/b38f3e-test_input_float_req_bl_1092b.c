#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef unsigned int __uint32_t;
typedef int __int32_t;

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
        if (ix < 0x7f800000)
            return x;
        else
            return x + x;
    }
    
    ieee_float_shape_type sf_u;
    sf_u.word = i0;
    x = sf_u.value;
    
    return x;
}

int __signbit_float(float x) {
    __uint32_t w;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    return (w & 0x80000000) != 0;
}

int main() {
    float x = 0.0f;
    float res = ceil_float(x);

    // x is +0, the result should be 0
    assert(res == 0.0f && __signbit_float(res) == 0);

    printf("Test passed: +0 input gives +0 output without sign bit.\n");
    return 0;
}