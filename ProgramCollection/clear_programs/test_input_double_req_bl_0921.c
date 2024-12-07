#include <stdio.h>
#include <stdbool.h>

// Define constants for NaN checking
#define NAN (0.0/0.0)

// Define types to ensure correct sizes on ARM architecture
typedef int __int32_t;
typedef unsigned int __uint32_t;

/* A union to facilitate conversion between a double and two 32-bit integers. */
typedef union {
    double value;
    struct {
        __uint32_t lsw;
        __uint32_t msw;
    } parts;
} ieee_double_shape_type;

// Function to check if a double is infinity
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

// Function to calculate the natural logarithm of a double
double __ieee754_log(double x) {
    double hfsq, f, s, z, R, w, t1, t2, dk;
    __int32_t k, hx, i, j;
    __uint32_t lx;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;

    k = 0;
    if (hx < 0x00100000) {
        if (((hx & 0x7fffffff) | lx) == 0) return -1.80143985094819840000e+16 / (0.0);
        if (hx < 0) return (x - x) / (0.0);
        k -= 54;
        x *= 1.80143985094819840000e+16;
        ieee_double_shape_type gh_u;
        gh_u.value = x;
        hx = gh_u.parts.msw;
    }

    if (hx >= 0x7ff00000) return x + x; // NaN or Infinity

    k += (hx >> 20) - 1023;
    hx &= 0x000fffff;
    i = (hx + 0x95f64) & 0x100000;
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = (hx | (i ^ 0x3ff00000));
    x = sh_u.value;
    k += (i >> 20);
    f = x - 1.0;
    
    static const double zero = 0.0;
    static const double ln2_hi_log = 6.93147180369123816490e-01;
    static const double ln2_lo_log = 1.90821492927058770002e-10;
    static const double Lg1_log = 6.666666666666735130e-01;
    static const double Lg2_log = 3.999999999940941908e-01;
    static const double Lg3_log = 2.857142874366239149e-01;
    static const double Lg4_log = 2.222219843214978396e-01;
    static const double Lg5_log = 1.818357216161805012e-01;
    static const double Lg6_log = 1.531383769920937332e-01;
    static const double Lg7_log = 1.479819860511658591e-01;

    if ((0x000fffff & (2 + hx)) < 3) {
        if (f == zero) {
            if (k == 0) return zero;
            else {
                dk = (double)k;
                return dk * ln2_hi_log + dk * ln2_lo_log;
            }
        }
        R = f * f * (0.5 - 0.33333333333333333 * f);
        if (k == 0)
            return f - R;
        else {
            dk = (double)k;
            return dk * ln2_hi_log - ((R - dk * ln2_lo_log) - f);
        }
    }

    s = f / (2.0 + f);
    dk = (double)k;
    z = s * s;
    i = hx - 0x6147a;
    w = z * z;
    j = 0x6b851 - hx;
    t1 = w * (Lg2_log + w * (Lg4_log + w * Lg6_log));
    t2 = z * (Lg1_log + w * (Lg3_log + w * (Lg5_log + w * Lg7_log)));
    i |= j;
    R = t2 + t1;

    if (i > 0) {
        hfsq = 0.5 * f * f;
        if (k == 0)
            return f - (hfsq - s * (hfsq + R));
        else
            return dk * ln2_hi_log - ((hfsq - (s * (hfsq + R) + dk * ln2_lo_log)) - f);
    } else {
        if (k == 0)
            return f - s * (f - R);
        else
            return dk * ln2_hi_log - ((s * (f - R) - dk * ln2_lo_log) - f);
    }
}

// Function to check if a double is NaN
int isnan_double(double x) {
    return x != x;
}

int main() {
    double x = NAN;  // Use a fixed NaN value
    double res = __ieee754_log(x);

    // Assert that if x is NaN, the result should be NaN
    if (!isnan_double(res)) {
        printf("Error: Result is not NaN when input is NaN.\n");
        return 1;
    }

    return 0;
}