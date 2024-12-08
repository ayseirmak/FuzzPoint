#include <stdio.h>

// Function to simulate the reaching of an error condition
void reach_error() {
    printf("Reach error called\n");
}

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

static const double one_modf = 1.0;

// Function to handle modf for double values
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
            i = 0x000fffff >> j0;
            if ((i0 & i) | i1) {
                ieee_double_shape_type iw_u;
                iw_u.parts.msw = i0 & ~i;
                iw_u.parts.lsw = 0;
                *iptr = iw_u.value;
                return x - *iptr;
            } else {
                ieee_double_shape_type gh_u;
                gh_u.value = x;
                *iptr = x;
                ieee_double_shape_type iw_u;
                iw_u.parts.msw = gh_u.parts.msw & 0x80000000;
                iw_u.parts.lsw = 0;
                x = iw_u.value;
                return x;
            }
        }
    } else if (j0 > 51) {
        ieee_double_shape_type gh_u;
        gh_u.value = x;
        *iptr = x * one_modf;
        ieee_double_shape_type iw_u;
        iw_u.parts.msw = gh_u.parts.msw & 0x80000000;
        iw_u.parts.lsw = 0;
        x = iw_u.value;
        return x;
    } else {
        i = 0xffffffff >> (j0 - 20);
        if (!(i1 & i)) {
            ieee_double_shape_type gh_u;
            gh_u.value = x;
            *iptr = x;
            ieee_double_shape_type iw_u;
            iw_u.parts.msw = gh_u.parts.msw & 0x80000000;
            iw_u.parts.lsw = 0;
            x = iw_u.value;
            return x;
        } else {
            ieee_double_shape_type iw_u;
            iw_u.parts.msw = i0;
            iw_u.parts.lsw = i1 & ~i;
            *iptr = iw_u.value;
            return x - *iptr;
        }
    }
}

// Check if a double is infinity
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

// Check the sign bit of a double
int __signbit_double(double x) {
    __uint32_t msw;

    ieee_double_shape_type gh_u;
    gh_u.value = x;
    msw = gh_u.parts.msw;
    
    return (msw & 0x80000000) != 0;
}

int main() {
    // Initialize variables
    double x = -1.0 / 0.0; // -INF
    double iptr = 1.0; // Defined deterministic value

    // Execute modf operation
    double res = modf_double(x, &iptr);

    // Check the condition
    if (isinf_double(iptr) && !(res == -0.0 && __signbit_double(res) == 1)) {
        reach_error();
        return 1;
    }

    printf("Test passed successfully\n");
    return 0;
}