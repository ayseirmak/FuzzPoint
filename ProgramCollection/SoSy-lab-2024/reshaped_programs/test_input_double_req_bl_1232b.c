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

// Check if the double value is NaN
int isnan_double(double x) {
    return x != x;
}

// Classify double value according to IEEE 754
int __fpclassify_double(double x) {
    __uint32_t msw, lsw;
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    msw = ew_u.parts.msw;
    lsw = ew_u.parts.lsw;

    if ((msw == 0x00000000 && lsw == 0x00000000) ||
        (msw == 0x80000000 && lsw == 0x00000000)) {
        return 2; // zero
    } else if ((msw >= 0x00100000 && msw <= 0x7fefffff) ||
               (msw >= 0x80100000 && msw <= 0xffefffff)) {
        return 4; // normal
    } else if ((msw <= 0x000fffff) ||
               (msw >= 0x80000000 && msw <= 0x800fffff)) {
        return 3; // subnormal
    } else if ((msw == 0x7ff00000 && lsw == 0x00000000) ||
               (msw == 0xfff00000 && lsw == 0x00000000)) {
        return 1; // infinity
    } else {
        return 0; // NaN
    }
}

// Minimum function for double with special cases
double fmin_double(double x, double y) {
    if (__fpclassify_double(x) == 0) return y;
    if (__fpclassify_double(y) == 0) return x;
    return x < y ? x : y;
}

// Detects the sign bit of a double value
int __signbit_double(double x) {
    __uint32_t msw;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    msw = gh_u.parts.msw;

    return (msw & 0x80000000) != 0;
}

int main() {
    // Pre-defined deterministic inputs
    double x = -0.0;
    double y = 0.0;
    double res = fmin_double(x, y);

    // Check condition: if x is -0 and y is +0, the result shall be -0
    if (!(res == -0.0 && __signbit_double(res) == 1)) {
        // Trigger an error for assertion
        assert(0 && "Error: Result is not -0 with the correct sign bit.");
        return 1;
    }

    return 0;
}