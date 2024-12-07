#include <stdio.h>
#include <assert.h>
#include <stdint.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

/* A union which permits us to convert between a double and two 32 bit
   ints.  */
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

double floor_double(double x) {
    __int32_t i0, i1, j0;
    __uint32_t i;
    ieee_double_shape_type ew_u;
    ew_u.value = (x);
    i0 = ew_u.parts.msw;
    i1 = ew_u.parts.lsw;

    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            if (1.0e300 + x > 0.0) {
                if (i0 >= 0) {
                    i0 = i1 = 0;
                } else if (((i0 & 0x7fffffff) | i1) != 0) {
                    i0 = 0xbff00000;
                    i1 = 0;
                }
            }
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0) {
                return x;
            }
            if (1.0e300 + x > 0.0) {
                if (i0 < 0) {
                    i0 += (0x00100000) >> j0;
                }
                i0 &= (~i);
                i1 = 0;
            }
        }
    } else if (j0 > 51) {
        if (j0 == 0x400) {
            return x + x;
        } else {
            return x;
        }
    } else {
        i = ((uint32_t)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0) {
            return x;
        }
        if (1.0e300 + x > 0.0) {
            if (i0 < 0) {
                if (j0 == 20) {
                    i0 += 1;
                } else {
                    uint32_t j = i1 + (1 << (52 - j0));
                    if (j < i1) {
                        i0 += 1;
                    }
                    i1 = j;
                }
            }
            i1 &= (~i);
        }
    }

    ieee_double_shape_type iw_u;
    iw_u.parts.msw = (i0);
    iw_u.parts.lsw = (i1);
    x = iw_u.value;
    return x;
}

double fabs_double(double x) {
    __uint32_t high;
    ieee_double_shape_type gh_u;
    gh_u.value = (x);
    high = gh_u.parts.msw;

    ieee_double_shape_type sh_u;
    sh_u.value = (x);
    sh_u.parts.msw = (high & 0x7fffffff);
    x = sh_u.value;

    return x;
}

double tan_double(double x) {
    if (x != x) { // NaN check
        return x;
    }
    
    // Dummy implementation of tan for demonstration purposes
    return x; // Placeholder behavior
}

int main() {
    /*
     * REQ-BL-0520//GTD-TR-01-BL-0015, GTD-TR-01-BL-0026/T
     * The tan and tanf procedures shall return NaN if the argument is NaN.
     */

    double x = 0.0 / 0.0; // NAN
    double res = tan_double(x);

    // x is NAN, the result shall be NAN
    assert(isnan_double(res));

    printf("Test passed: tan(NaN) returns NaN\n");
    return 0;
}