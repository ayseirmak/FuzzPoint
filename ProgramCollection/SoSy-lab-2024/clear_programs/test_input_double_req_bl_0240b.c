#include <stdio.h>
#include <math.h>
#include <float.h>

// Define IEEE constants for compatibility with ARM
#define POS_INF (1.0 / 0.0)
#define NEG_INF (-1.0 / 0.0)
#define NAN_VAL (0.0 / 0.0)

// Define custom NaN check without using architecture-specific functions
int isnan_double(double x) { return x != x; }

// Union for double and 32-bit int conversion
typedef union {
    double value;
    struct {
        unsigned int lsw;
        unsigned int msw;
    } parts;
} ieee_double_shape_type;

// Function to return the floor of a double
double floor_double(double x) {
    int i0, i1, j0;
    unsigned int i, j;
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    i0 = ew_u.parts.msw;
    i1 = ew_u.parts.lsw;
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            if (x > 0.0) {
                if (i0 >= 0) {
                    i0 = i1 = 0;
                } else if (((i0 & 0x7fffffff) | i1) != 0) {
                    i0 = 0xbff00000;
                    i1 = 0;
                }
            }
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0)
                return x;
            if (x > 0.0) {
                if (i0 < 0)
                    i0 += (0x00100000) >> j0;
                i0 &= (~i);
                i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400)
            return x + x;
        else
            return x;
    } else {
        i = ((unsigned int)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0)
            return x;
        if (x > 0.0) {
            if (i0 < 0) {
                if (j0 == 20)
                    i0 += 1;
                else {
                    j = i1 + (1 << (52 - j0));
                    if (j < i1)
                        i0 += 1;
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }
    ieee_double_shape_type iw_u;
    iw_u.parts.msw = i0;
    iw_u.parts.lsw = i1;
    x = iw_u.value;
    return x;
}

// Function to copysign values
double copysign_double(double x, double y) {
    unsigned int hx, hy;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
    gh_u.value = y;
    hy = gh_u.parts.msw;
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = (hx & 0x7fffffff) | (hy & 0x80000000);
    x = sh_u.value;
    return x;
}

// Sin function implementation
double sin_double(double x) {
    // Directly use standard math library implementation for sine
    return sin(x);
}

void reach_error() {
    printf("Error: Assertion failed\n");
}

int main() {
    double x = NEG_INF;
    double res = sin_double(x);

    // Check for NaN result
    if (!isnan_double(res)) {
        reach_error();
        return 1;
    }

    printf("Test passed\n");
    return 0;
}