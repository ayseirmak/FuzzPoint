#include <stdio.h>
#include <assert.h>

// Define constants for infinity
static const double POS_INF = 1.0 / 0.0;
static const double NEG_INF = -1.0 / 0.0;

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    double value;
    struct {
        __uint32_t lsw;
        __uint32_t msw;
    } parts;
} ieee_double_shape_type;

// Function to check if a double is NaN
int isnan_double(double x) { 
    return x != x; 
}

// Function to check if a double is Inf
int isinf_double(double x) {
    __int32_t hx, lx;
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;
    hx &= 0x7fffffff;
    hx |= (__uint32_t)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    return 1 - (int)((__uint32_t)(hx | (-hx)) >> 31);
}

// Function to determine the sign bit of a double
int __signbit_double(double x) {
    __uint32_t msw;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    msw = gh_u.parts.msw;
    return (msw & 0x80000000) != 0;
}

// Function that implements the modf logic for double
double modf_double(double x, double *iptr) {
    __int32_t i0, i1, j0;
    __uint32_t i;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    i0 = ew_u.parts.msw;
    i1 = ew_u.parts.lsw;

    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            ieee_double_shape_type iw_u;
            iw_u.parts.msw = (i0 & 0x80000000);
            iw_u.parts.lsw = 0;
            *iptr = iw_u.value;
            return x;
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0) {
                *iptr = x;
                ieee_double_shape_type iw_u;
                iw_u.parts.msw = (i0 & 0x80000000);
                iw_u.parts.lsw = 0;
                x = iw_u.value;
                return x;
            } else {
                ieee_double_shape_type iw_u;
                iw_u.parts.msw = (i0 & (~i));
                iw_u.parts.lsw = 0;
                *iptr = iw_u.value;
                return x - *iptr;
            }
        }
    } else if (j0 > 51) {
        *iptr = x;
        ieee_double_shape_type iw_u;
        iw_u.parts.msw = (i0 & 0x80000000);
        iw_u.parts.lsw = 0;
        x = iw_u.value;
        return x;
    } else {
        i = (__uint32_t)(0xffffffff) >> (j0 - 20);
        if ((i1 & i) == 0) {
            *iptr = x;
            ieee_double_shape_type iw_u;
            iw_u.parts.msw = (i0 & 0x80000000);
            iw_u.parts.lsw = 0;
            x = iw_u.value;
            return x;
        } else {
            ieee_double_shape_type iw_u;
            iw_u.parts.msw = i0;
            iw_u.parts.lsw = i1 & (~i);
            *iptr = iw_u.value;
            return x - *iptr;
        }
    }
}

int main() {
    double x = POS_INF; // Use predefined constant for INF
    double iptr = 0.0;  // Initialize iptr to a deterministic value
    double res = modf_double(x, &iptr);

    // Check according to the requirement if x is inf, *iptr should be inf, and result should be +0
    assert(isinf_double(iptr) && (res == 0.0 && __signbit_double(res) == 0));

    printf("Test passed successfully.\n");
    return 0;
}