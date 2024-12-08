#include <stdio.h>
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
 * __fpclassify Categorizes floating point value arg into the following
 * categories: zero, subnormal, normal, infinite, NAN, or implementation-defined category.
 * Returns One of FP_INFINITE, FP_NAN, FP_NORMAL, FP_SUBNORMAL, FP_ZERO or
 * implementation-defined type, specifying the category of arg.
 */
int __fpclassify_double(double x) {
    __uint32_t msw, lsw;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    msw = ew_u.parts.msw;
    lsw = ew_u.parts.lsw;

    if ((msw == 0x00000000 && lsw == 0x00000000) ||
        (msw == 0x80000000 && lsw == 0x00000000)) {
        return 2; // FP_ZERO
    } else if ((msw >= 0x00100000 && msw <= 0x7fefffff) ||
               (msw >= 0x80100000 && msw <= 0xffefffff)) {
        return 4; // FP_NORMAL
    } else if ((msw <= 0x000fffff) ||
               (msw >= 0x80000000 && msw <= 0x800fffff)) {
        return 3; // FP_SUBNORMAL
    } else if ((msw == 0x7ff00000 && lsw == 0x00000000) ||
               (msw == 0xfff00000 && lsw == 0x00000000)) {
        return 1; // FP_INFINITE
    } else {
        return 0; // FP_NAN
    }
}

double fmax_double(double x, double y) {
    if (__fpclassify_double(x) == 0) return y;
    if (__fpclassify_double(y) == 0) return x;
    return x > y ? x : y;
}

int main() {
    double x = 1.23; // Fixed double value as an example instead of nondeterministic input
    double y = 0.0 / 0.0; // NaN

    /* REQ-BL-1251:
     * The fmax and fmaxf procedures shall return the one argument
     * if only the other argument is NaN.
     */

    if (!isnan_double(x)) {
        double res = fmax_double(x, y);

        // y is NaN and x is not NaN, the result shall be x
        if (res != x) {
            printf("Error: Expected result to be x\n");
            return 1;
        }
    }

    printf("Test passed successfully.\n");
    return 0;
}