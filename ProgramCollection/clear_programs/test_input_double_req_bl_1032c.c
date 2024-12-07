#include <stdio.h>

// Definition for the abort function
extern void abort(void);

// Typedefs for 32-bit integer types
typedef int __int32_t;
typedef unsigned int __uint32_t;

// Union to represent a double in IEEE format
typedef union {
    double value;
    struct {
        __uint32_t lsw;
        __uint32_t msw;
    } parts;
} ieee_double_shape_type;

// Function to perform rounding on a double
double round_double(double x) {
    __int32_t msw, exponent_less_1023;
    __uint32_t lsw;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    msw = ew_u.parts.msw;
    lsw = ew_u.parts.lsw;

    exponent_less_1023 = ((msw & 0x7ff00000) >> 20) - 1023;

    if (exponent_less_1023 < 20) {
        if (exponent_less_1023 < 0) {
            msw &= 0x80000000;
            if (exponent_less_1023 == -1)
                msw |= (1023 << 20);
            lsw = 0;
        } else {
            __uint32_t exponent_mask = 0x000fffff >> exponent_less_1023;
            if ((msw & exponent_mask) == 0 && lsw == 0)
                return x;
            msw += 0x00080000 >> exponent_less_1023;
            msw &= ~exponent_mask;
            lsw = 0;
        }
    } else if (exponent_less_1023 > 51) {
        if (exponent_less_1023 == 1024)
            return x + x;
        else
            return x;
    } else {
        __uint32_t exponent_mask = 0xffffffff >> (exponent_less_1023 - 20);
        __uint32_t tmp;
        if ((lsw & exponent_mask) == 0)
            return x;
        tmp = lsw + (1 << (51 - exponent_less_1023));
        if (tmp < lsw)
            msw += 1;
        lsw = tmp;
        lsw &= ~exponent_mask;
    }

    ieee_double_shape_type iw_u;
    iw_u.parts.msw = msw;
    iw_u.parts.lsw = lsw;
    x = iw_u.value;

    return x;
}

// Function to check if a double is infinite
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

// Main function to test the round_double and isinf_double functions
int main() {
    // Set x to positive infinity
    double x = 1.0 / 0.0; // INF
    double res = round_double(x);

    // Check if the result is infinite
    if (!isinf_double(res)) {
        printf("Error: Result is not infinity.\n");
        return 1; // Indicate an error occurred
    }

    printf("Test passed: Result is infinity.\n");
    return 0; // Indicate success
}