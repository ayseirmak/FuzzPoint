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

// Check if a double is NaN
int isnan_double(double x) {
    return x != x;
}

// Classify the double value
int __fpclassify_double(double x) {
    __uint32_t msw, lsw;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    msw = ew_u.parts.msw;
    lsw = ew_u.parts.lsw;

    if ((msw == 0x00000000 && lsw == 0x00000000) ||
        (msw == 0x80000000 && lsw == 0x00000000))
        return 2;  // Zero
    else if ((msw >= 0x00100000 && msw <= 0x7fefffff) ||
             (msw >= 0x80100000 && msw <= 0xffefffff))
        return 4;  // Normalized
    else if ((msw <= 0x000fffff) ||
             (msw >= 0x80000000 && msw <= 0x800fffff))
        return 3;  // Denormalized
    else if ((msw == 0x7ff00000 && lsw == 0x00000000) ||
             (msw == 0xfff00000 && lsw == 0x00000000))
        return 1;  // Inf
    else
        return 0;  // NaN
}

// fmin function for doubles
double fmin_double(double x, double y) {
    if (__fpclassify_double(x) == 0)
        return y;
    if (__fpclassify_double(y) == 0)
        return x;

    return x < y ? x : y;
}

int main() {
    // Fixed input: both values are NaN
    double x = 0.0 / 0.0;  // NaN
    double y = 0.0 / 0.0;  // NaN
    double res = fmin_double(x, y);

    // Check if the result is NaN as required
    if (!isnan_double(res)) {
        printf("Error: Result should be NaN.\n");
        return 1;
    }

    printf("Success: The result is NaN as expected.\n");
    return 0;
}