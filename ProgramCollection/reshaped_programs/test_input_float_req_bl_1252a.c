#include <stdio.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

/*
 * __fpclassify Categorizes floating point value arg into the following
 * categories:
 * zero, subnormal, normal, infinite, NAN, or implementation-defined category.
 * Returns One of FP_INFINITE, FP_NAN, FP_NORMAL, FP_SUBNORMAL, FP_ZERO
 * or implementation-defined type, specifying the category of arg.
 */

int __fpclassify_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    if (w == 0x00000000 || w == 0x80000000)
        return 2; // FP_ZERO
    else if ((w >= 0x00800000 && w <= 0x7f7fffff) ||
             (w >= 0x80800000 && w <= 0xff7fffff))
        return 4; // FP_NORMAL
    else if ((w >= 0x00000001 && w <= 0x007fffff) ||
             (w >= 0x80000001 && w <= 0x807fffff))
        return 3; // FP_SUBNORMAL
    else if (w == 0x7f800000 || w == 0xff800000)
        return 1; // FP_INFINITE
    else
        return 0; // FP_NAN
}

float fmax_float(float x, float y) {
    if (__fpclassify_float(x) == 0) {
        return y;
    }

    if (__fpclassify_float(y) == 0) {
        return x;
    }
    return x > y ? x : y;
}

int __signbit_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    return (w & 0x80000000) != 0;
}

int main() {
    // Variables x and y are explicitly declared and initialized with deterministic values.
    float x = -0.0f;
    float y = 0.0f;

    // Calculate the maximum value between x and y.
    float res = fmax_float(x, y);

    /* Check that when x is -0 and y is +0, the result is +0.
     * Use standard assertion for error checking.
     */
    if (!(res == 0.0f && __signbit_float(res) == 0)) {
        printf("Error: The result is not +0\n");
        return 1;
    }

    // Indicate successful execution.
    printf("Success: The result is +0\n");
    return 0;
}