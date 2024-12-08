#include <stdio.h>
#include <assert.h>
#include <stdint.h>

// Custom error handler to mimic reach_error
void reach_error() {
    printf("Error: Assertion failed in function reach_error.\n");
    assert(0);
}

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

// Truncate float to integer value
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

// Check if float x is negative
int __signbit_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;
    return (w & 0x80000000) != 0;
}

int main() {
    float x = -0.0f;  // Deterministic test value
    float res = trunc_float(x);

    // Assert that the result is as expected
    if (!(res == -0.0f && __signbit_float(res) == 1)) {
        reach_error();
        return 1;
    }

    printf("Test passed. Result: %.2f\n", res);
    return 0;
}