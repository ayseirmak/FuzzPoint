#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

static const float one_sqrt = 1.0f, tiny_sqrt = 1.0e-30f;

float __ieee754_sqrtf(float x) {
    float z;
    __uint32_t r, hx;
    __int32_t ix, s, q, m, t, i;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    hx = ix & 0x7fffffffU;

    if (!(hx < 0x7f800000U))
        return x * x + x;

    if (hx == 0)
        return x;
    if (ix < 0)
        return (x - x) / (x - x);

    m = ix >> 23;
    if (hx < 0x00800000U) {
        for (i = 0; (ix & 0x00800000U) == 0; i++)
            ix <<= 1;
        m -= i - 1;
    }
    m -= 127;
    ix = (ix & 0x007fffffU) | 0x00800000U;
    if (m & 1)
        ix += ix;
    m >>= 1;

    ix += ix;
    q = s = 0;
    r = 0x01000000U;

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
            if (z > one_sqrt)
                q += 2;
            else
                q += (q & 1);
        }
    }
    ix = (q >> 1) + 0x3f000000U;
    ix += (m << 23);
    ieee_float_shape_type sf_u;
    sf_u.word = ix;
    z = sf_u.value;
    return z;
}

float __ieee754_hypotf(float x, float y) {
    float a = x, b = y, t1, t2, y1, y2, w;
    __int32_t j, k, ha, hb;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ha = gf_u.word;
    ha &= 0x7fffffffU;
    gf_u.value = y;
    hb = gf_u.word;
    hb &= 0x7fffffffU;
    if (hb > ha) {
        a = y;
        b = x;
        j = ha;
        ha = hb;
        hb = j;
    } else {
        a = x;
        b = y;
    }
    ieee_float_shape_type sf_u;
    sf_u.word = ha;
    a = sf_u.value;
    sf_u.word = hb;
    b = sf_u.value;
    if ((ha - hb) > 0xf000000U) {
        return a + b;
    }
    k = 0;
    if (ha > 0x58800000U) {
        if (!(ha < 0x7f800000U)) {
            w = a + b;
            if (ha == 0x7f800000U)
                w = a;
            if (hb == 0x7f800000U)
                w = b;
            return w;
        }
        ha -= 0x22000000U;
        hb -= 0x22000000U;
        k += 68;
        sf_u.word = ha;
        a = sf_u.value;
        sf_u.word = hb;
        b = sf_u.value;
    }
    if (hb < 0x26800000U) {
        if (hb == 0) {
            return a;
        } else if (hb < 0x00800000U) {
            sf_u.word = 0x7e800000U;
            t1 = sf_u.value;
            b *= t1;
            a *= t1;
            k -= 126;
        } else {
            ha += 0x22000000U;
            hb += 0x22000000U;
            k -= 68;
            sf_u.word = ha;
            a = sf_u.value;
            sf_u.word = hb;
            b = sf_u.value;
        }
    }

    w = a - b;
    if (w > b) {
        sf_u.word = ha & 0xfffff000U;
        t1 = sf_u.value;
        t2 = a - t1;
        w = __ieee754_sqrtf(t1 * t1 - (b * (-b) - t2 * (a + t1)));
    } else {
        a = a + a;
        sf_u.word = hb & 0xfffff000U;
        y1 = sf_u.value;
        y2 = b - y1;
        sf_u.word = ha + 0x00800000U;
        t1 = sf_u.value;
        t2 = a - t1;
        w = __ieee754_sqrtf(t1 * y1 - (w * (-w) - (t1 * y2 + t2 * b)));
    }
    if (k != 0) {
        sf_u.word = 0x3f800000U + (k << 23);
        t1 = sf_u.value;
        return t1 * w;
    } else
        return w;
}

// nan check for floats
int isnan_float(float x) { return x != x; }

// check if value is finite
int isfinite_float(float x) {
    __int32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffffU;
    return (ix < 0x7f800000U);
}

int main() {
    // Fixed deterministic inputs
    float x = 0.0f / 0.0f; // NaN
    float y = 1.0f; // Example fixed float input value

    if (isfinite_float(y)) {
        float res = __ieee754_hypotf(x, y);
        if (!isnan_float(res)) {
            printf("Error: Expected NaN result\n");
            return 1;
        }
    }

    printf("Test completed successfully.\n");
    return 0;
}