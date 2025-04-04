#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

// Check if a float is NaN
int isnan_float(float x) {
    return x != x;
}

// Constants required for the exp function
static const float one_exp = 1.0f,
                   halF_exp[2] = {0.5f, -0.5f},
                   huge_exp = 1.0e+30f,
                   twom100_exp = 7.8886090522e-31f,
                   ln2HI_exp[2] = {6.9313812256e-01f, -6.9313812256e-01f},
                   ln2LO_exp[2] = {9.0580006145e-06f, -9.0580006145e-06f},
                   invln2_exp = 1.4426950216e+00f,
                   P1_exp = 1.6666667163e-01f,
                   P2_exp = -2.7777778450e-03f,
                   P3_exp = 6.6137559770e-05f,
                   P4_exp = -1.6533901999e-06f,
                   P5_exp = 4.1381369442e-08f;

// IEEE 754 exp function for floats
float __ieee754_expf(float x) {
    float y, hi, lo, c, t;
    __int32_t k = 0, xsb;
    __uint32_t hx;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    __uint32_t sx = gf_u.word;

    xsb = (sx >> 31) & 1;
    hx = sx & 0x7fffffff;

    if (hx > 0x7f800000L)
        return x + x;
    if (hx == 0x7f800000L)
        return (xsb == 0) ? x : 0.0f;
    if (sx > 0x42b17217)
        return huge_exp * huge_exp;
    if (sx < 0 && hx > 0x42cff1b5)
        return twom100_exp * twom100_exp;

    if (hx > 0x3eb17218) {
        if (hx < 0x3F851592) {
            hi = x - ln2HI_exp[xsb];
            lo = ln2LO_exp[xsb];
            k = 1 - xsb - xsb;
        } else {
            k = invln2_exp * x + halF_exp[xsb];
            t = k;
            hi = x - t * ln2HI_exp[0];
            lo = t * ln2LO_exp[0];
        }
        x = hi - lo;
    } else if (hx < 0x31800000) {
        if (huge_exp + x > one_exp)
            return one_exp + x;
    }

    t = x * x;
    c = x - t * (P1_exp + t * (P2_exp + t * (P3_exp + t * (P4_exp + t * P5_exp))));
    if (k == 0)
        return one_exp - ((x * c) / (c - 2.0f) - x);
    else
        y = one_exp - ((lo - (x * c) / (2.0f - c)) - hi);
    if (k >= -125) {
        __uint32_t hy;
        ieee_float_shape_type sf_u;
        sf_u.word = (gf_u.word + (k << 23));
        y = sf_u.value;
        return y;
    } else {
        ieee_float_shape_type sf_u;
        sf_u.word = (gf_u.word + ((k + 100) << 23));
        y = sf_u.value;
        return y * twom100_exp;
    }
}

// Check if a float is infinity
int isinf_float(float x) {
    __int32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffff;
    return (ix == 0x7f800000L);
}

int main() {
    // The exp and expf procedures shall return the argument if the argument x is +Inf.
    float x = 1.0f / 0.0f; // INF
    float res = __ieee754_expf(x);

    // x is +inf, the result shall be x
    assert(isinf_float(res));

    printf("Test passed: res = %f\n", res);
    return 0;
}