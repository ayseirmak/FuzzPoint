#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
    double value;
    struct {
        __uint32_t lsw;
        __uint32_t msw;
    } parts;
} ieee_double_shape_type;

// Check if double is NaN
int isnan_double(double x) {
    return x != x;
}

// Check if double is negative
int __signbit_double(double x) {
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    __uint32_t msw = gh_u.parts.msw;
    return (msw & 0x80000000) != 0;
}

// Check if double is infinity
int isinf_double(double x) {
    ieee_double_shape_type ew_u;
    ew_u.value = x;
    __int32_t hx = ew_u.parts.msw;
    __int32_t lx = ew_u.parts.lsw;
    
    hx &= 0x7fffffff;
    hx |= (uint32_t)(lx | (-lx)) >> 31;
    hx = 0x7ff00000 - hx;
    
    return 1 - ((uint32_t)(hx | (-hx)) >> 31);
}

// Absolute value of double
double fabs_double(double x) {
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    __uint32_t high = gh_u.parts.msw;
    
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = (high & 0x7fffffff);
    x = sh_u.value;
    
    return x;
}

int main() {
    double x = 1.0 / 0.0; // Positive infinity
    double res = fabs_double(x);

    // Verify if the result is infinity
    if (!isinf_double(res)) {
        printf("Test failed: Result is not infinity.\n");
        return 1;
    } else {
        printf("Test passed: Result is infinity as expected.\n");
    }

    return 0;
}