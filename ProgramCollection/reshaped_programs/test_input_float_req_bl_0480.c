#include <stdio.h>
#include <stdint.h>
#include <assert.h>

// Definitions for compatibility
typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

// Union for manipulating float bits
typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

// Constants
static const float one_sqrt = 1.0f, tiny_sqrt = 1.0e-30f;
static const float one_acos = 1.0f;
static const float pi = 3.1415925026e+00f;
static const float pio2_hi_acos = 1.5707962513e+00f;
static const float pio2_lo_acos = 7.5497894159e-08f;
static const float pS0_acos = 1.6666667163e-01f;
static const float pS1_acos = -3.2556581497e-01f;
static const float pS2_acos = 2.0121252537e-01f;
static const float pS3_acos = -4.0055535734e-02f;
static const float pS4_acos = 7.9153501429e-04f;
static const float pS5_acos = 3.4793309169e-05f;
static const float qS1_acos = -2.4033949375e+00f;
static const float qS2_acos = 2.0209457874e+00f;
static const float qS3_acos = -6.8828397989e-01f;
static const float qS4_acos = 7.7038154006e-02f;

// Function for calculating the square root
float __ieee754_sqrtf(float x) {
    float z;
    __uint32_t r, hx;
    __int32_t ix, s, q, m, t, i;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    hx = ix & 0x7fffffff;

    if (!(hx < 0x7f800000))
        return x * x + x;

    if (hx == 0)
        return x;
    if (ix < 0)
        return (x - x) / (x - x);

    m = (ix >> 23);
    if ((hx < 0x00800000)) {
        for (i = 0; (ix & 0x00800000) == 0; i++)
            ix <<= 1;
        m -= i - 1;
    }
    m -= 127;
    ix = (ix & 0x007fffff) | 0x00800000;
    if (m & 1)
        ix += ix;
    m >>= 1;

    ix += ix;
    q = s = 0;
    r = 0x01000000;

    while (r != 0) {
        t = s + r;
        if (t <= ix) {
            s = t + r;
            ix -= t;
            q += r;
        }
        ix += ix;
        r >>= 1;
    }

    if (ix != 0) {
        z = one_sqrt - tiny_sqrt;
        if (z >= one_sqrt) {
            z = one_sqrt + tiny_sqrt;
            if (z > one_sqrt) q += 2;
            else q += (q & 1);
        }
    }
    ix = (q >> 1) + 0x3f000000;
    ix += (m << 23);
    gf_u.word = ix;
    z = gf_u.value;
    return z;
}

// Function for calculating the arc cosine
float __ieee754_acosf(float x) {
    float z, p, q, r, w, s, c, df;
    __int32_t hx, ix;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;
    ix = hx & 0x7fffffff;

    if (ix == 0x3f800000) {
        if (hx > 0)
            return 0.0f;
        else
            return pi + 2.0f * pio2_lo_acos;
    }
    else if (ix > 0x3f800000) {
        return (x - x) / (x - x);
    }
    if (ix < 0x3f000000) {
        if (ix <= 0x23000000)
            return pio2_hi_acos + pio2_lo_acos;
        z = x * x;
        p = z * (pS0_acos + z * (pS1_acos + z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
        q = one_acos + z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
        r = p / q;
        return pio2_hi_acos - (x - (pio2_lo_acos - x * r));
    }
    else if (hx < 0) {
        z = (one_acos + x) * 0.5f;
        p = z * (pS0_acos + z * (pS1_acos + z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
        q = one_acos + z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
        s = __ieee754_sqrtf(z);
        r = p / q;
        w = r * s - pio2_lo_acos;
        return pi - 2.0f * (s + w);
    }
    else {
        int32_t idf;
        z = (one_acos - x) * 0.5f;
        s = __ieee754_sqrtf(z);
        df = s;
        gf_u.value = df;
        idf = gf_u.word;
        gf_u.word = idf & 0xfffff000;
        df = gf_u.value;
        c = (z - df * df) / (s + df);
        p = z * (pS0_acos + z * (pS1_acos + z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
        q = one_acos + z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
        r = p / q;
        w = r * s + c;
        return 2.0f * (df + w);
    }
}

// Function to determine the sign bit of a float
int __signbit_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;
    return (w & 0x80000000) != 0;
}

int main() {
    // Deterministic input defined directly
    float x = 1.0f;
    float res = __ieee754_acosf(x);

    // Check if the result is +0 when the input is +1
    if (!(res == 0.0f && __signbit_float(res) == 0)) {
        printf("Error: The result was not +0 as expected.\n");
        return 1;
    }

    // Successful execution
    printf("Success: The result is +0 as expected.\n");
    return 0;
}