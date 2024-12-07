#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    double value;
    struct {
        __uint32_t lsw;
        __uint32_t msw;
    } parts;
} ieee_double_shape_type;

// NaN check for doubles
int isnan_double(double x) {
    return x != x;
}

/*
 * __fpclassify_double categorizes floating-point value arg into the following
 * categories: zero, subnormal, normal, infinite, NaN, or implementation-defined category.
 * Returns one of FP_INFINITE, FP_NAN, FP_NORMAL, FP_SUBNORMAL, FP_ZERO or
 * implementation-defined type, specifying the category of arg.
 */
int __fpclassify_double(double x) {
    __uint32_t msw, lsw;
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    msw = ew_u.parts.msw;
    lsw = ew_u.parts.lsw;

    if ((msw == 0x00000000 && lsw == 0x00000000) || (msw == 0x80000000 && lsw == 0x00000000))
        return 2;  // Zero
    else if ((msw >= 0x00100000 && msw <= 0x7fefffff) || (msw >= 0x80100000 && msw <= 0xffefffff))
        return 4;  // Normal
    else if ((msw <= 0x000fffff) || (msw >= 0x80000000 && msw <= 0x800fffff))
        return 3;  // Subnormal
    else if ((msw == 0x7ff00000 && lsw == 0x00000000) || (msw == 0xfff00000 && lsw == 0x00000000))
        return 1;  // Infinite
    else
        return 0;  // NaN
}

double fmax_double(double x, double y) {
    if (__fpclassify_double(x) == 0)  // NaN
        return y;
    if (__fpclassify_double(y) == 0)  // NaN
        return x;
    return x > y ? x : y;
}

int main() {
    // REQ-BL-1250: The fmax and fmaxf procedures shall return NaN if the arguments x and y are NaN.
    double x = 0.0 / 0.0;  // NaN
    double y = 0.0 / 0.0;  // NaN
    double res = fmax_double(x, y);

    if (!isnan_double(res)) {
        fprintf(stderr, "Error: Expected NaN but got a different value\n");
        return 1;
    }
    printf("Test Passed: Result is NaN as expected\n");
    return 0;
}