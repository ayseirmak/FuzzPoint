#include <stdio.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

float trunc_float(float x) {
    __int32_t signbit, w, exponent_less_127;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;
    
    signbit = w & 0x80000000;
    exponent_less_127 = ((w & 0x7f800000) >> 23) - 127;
    if (exponent_less_127 < 23) {
        if (exponent_less_127 < 0) {
            ieee_float_shape_type sf_u;
            sf_u.word = signbit;
            x = sf_u.value;
        } else {
            ieee_float_shape_type sf_u;
            sf_u.word = signbit | (w & ~(0x007fffff >> exponent_less_127));
            x = sf_u.value;
        }
    } else {
        if (exponent_less_127 == 255) {
            return x + x;
        }
    }
    return x;
}

// Infinity check for floats
int isinf_float(float x) {
    __int32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    
    ix &= 0x7fffffff;
    return ix == 0x7f800000L;
}

int main() {
    float x = -1.0f / 0.0f; // -INF
    float res = trunc_float(x);

    // Assert that x being -inf results in -inf
    if (!isinf_float(res)) {
        fprintf(stderr, "Error: Expected infinity.\n");
        return 1;
    }

    printf("Test passed: trunc_float return value is infinity as expected.\n");
    return 0;
}