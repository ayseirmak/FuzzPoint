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

int __signbit_float(float x) {
    __uint32_t w;
    
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    return (w & 0x80000000) != 0;
}

int main() {
    float x = 0.0f;
    float res = trunc_float(x);

    // Assert x is 0, result shall be 0 and not negative
    assert(res == 0.0f && __signbit_float(res) == 0);

    printf("Test passed: trunc_float(0.0f) == 0.0f with positive signbit\n");

    return 0;
}