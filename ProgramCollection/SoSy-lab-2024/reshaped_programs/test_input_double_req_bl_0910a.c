#include <stdio.h>
#include <math.h>
#include <assert.h>

// infinity check for doubles
int isinf_double(double x) {
    // Use the standard isnormal function and check for infinity value.
    return isinf(x);
}

static const double ln2_hi_log = 6.93147180369123816490e-01,
                     ln2_lo_log = 1.90821492927058770002e-10,
                     two54_log = 1.80143985094819840000e+16,
                     Lg1_log = 6.666666666666735130e-01,
                     Lg2_log = 3.999999999940941908e-01,
                     Lg3_log = 2.857142874366239149e-01,
                     Lg4_log = 2.222219843214978396e-01,
                     Lg5_log = 1.818357216161805012e-01,
                     Lg6_log = 1.531383769920937332e-01,
                     Lg7_log = 1.479819860511658591e-01;

static const double zero = 0.0;

double __ieee754_log(double x) {
    double hfsq, f, s, z, R, w, t1, t2, dk;
    int k = 0, hx, i, j;
    unsigned int lx;

    union {
        double value;
        struct {
            unsigned int lsw;
            unsigned int msw;
        } parts;
    } ew_u = { .value = x };

    hx = ew_u.parts.msw;
    lx = ew_u.parts.lsw;

    if (hx < 0x00100000) {
        if (((hx & 0x7fffffff) | lx) == 0)
            return -two54_log / zero;
        if (hx < 0)
            return (x - x) / zero;
        k -= 54;
        x *= two54_log;
        ew_u.value = x;
        hx = ew_u.parts.msw;
    }
    if (hx >= 0x7ff00000)
        return x + x;
    k += (hx >> 20) - 1023;
    hx &= 0x000fffff;
    i = (hx + 0x95f64) & 0x100000;
    ew_u.parts.msw = (hx | (i ^ 0x3ff00000));
    x = ew_u.value;
    k += (i >> 20);
    f = x - 1.0;
    if ((0x000fffff & (2 + hx)) < 3) {
        if (f == zero) {
            if (k == 0) return zero;
            else {
                dk = (double) k;
                return dk * ln2_hi_log + dk * ln2_lo_log;
            }
        }
        R = f * f * (0.5 - 0.33333333333333333 * f);
        if (k == 0) return f - R;
        else {
            dk = (double) k;
            return dk * ln2_hi_log - ((R - dk * ln2_lo_log) - f);
        }
    }
    s = f / (2.0 + f);
    dk = (double) k;
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
        if (k == 0) return f - (hfsq - s * (hfsq + R));
        else return dk * ln2_hi_log - ((hfsq - (s * (hfsq + R) + dk * ln2_lo_log)) - f);
    } else {
        if (k == 0) return f - s * (f - R);
        else return dk * ln2_hi_log - ((s * (f - R) - dk * ln2_lo_log) - f);
    }
}

int main() {
    double x = 0.0;
    double res = __ieee754_log(x);

    // x is +-0, the result shall be -inf
    if (!isinf_double(res)) {
        printf("Assertion failed: Result is not -inf for x = %f\n", x);
        return 1;
    }

    printf("Test passed for x = %f\n", x);
    return 0;
}