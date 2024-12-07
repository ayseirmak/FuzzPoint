#include <stdio.h>       // For standard input/output
#include <stdint.h>      // For standard integer types
#include <math.h>        // For fabs function

typedef uint32_t __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

float fabs_float(float x) {
    __uint32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;

    ieee_float_shape_type sf_u;
    sf_u.word = ix & 0x7fffffff;  // Mask off the sign bit
    x = sf_u.value;

    return x;
}

int __signbit_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    return (w & 0x80000000) != 0;  // Check the sign bit
}

void reach_error() {
    printf("Error: reach_error\n");
}

int main() {
    // Fixed and deterministic input based on the program requirement
    float x = -0.0f;
    float res = fabs_float(x);

    // Check whether res is +0
    if (!(res == 0.0f && __signbit_float(res) == 0)) {
        reach_error();
        return 1;
    }

    printf("Test passed.\n");
    return 0;
}