#include <stdio.h>
#include <assert.h>
#include <math.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

int __fpclassify_float(float x) {
    __uint32_t w;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    if (w == 0x00000000 || w == 0x80000000)
        return 2; // Zero
    else if ((w >= 0x00800000 && w <= 0x7f7fffff) || (w >= 0x80800000 && w <= 0xff7fffff))
        return 4; // Normal
    else if ((w >= 0x00000001 && w <= 0x007fffff) || (w >= 0x80000001 && w <= 0x807fffff))
        return 3; // Subnormal
    else if (w == 0x7f800000 || w == 0xff800000)
        return 1; // Infinite
    else
        return 0; // NaN
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

// nan check for floats
int isnan_float(float x) {
    return x != x;
}

int main() {
    // Deterministic inputs (fixed values instead of nondeterministic ones)
    float x = NAN;  // Representing scenarios where x might be NaN
    float y = 1.0f; // A normal floating-point number

    if ((isnan_float(x) && !isnan_float(y)) || (!isnan_float(x) && isnan_float(y))) {
        float res = fmax_float(x, y);

        // x is NaN and y is not NaN, the result shall be y
        if (isnan_float(x) && !isnan_float(y) && res != y) {
            printf("Error: x is NaN and result is not y.\n");
            return 1;
        }

        // y is NaN and x is not NaN, the result shall be x
        if (!isnan_float(x) && isnan_float(y) && res != x) {
            printf("Error: y is NaN and result is not x.\n");
            return 1;
        }
    }

    return 0;
}