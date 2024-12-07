#include <stdio.h>
#include <stdint.h>

// Union to manipulate float bit-level representation
typedef union {
    float value;
    uint32_t word;
} ieee_float_shape_type;

// Constants for mathematical calculations
static const float one_sqrt = 1.0, tiny_sqrt = 1.0e-30;

// Function to compute the square root of a float
float __ieee754_sqrtf(float x) {
    float z;
    uint32_t r, hx;
    int32_t ix, s, q, m, t, i;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;

    hx = ix & 0x7fffffff;
    if (!(hx < 0x7f800000L))
        return x * x + x;

    if (hx == 0)
        return x;
    if (ix < 0)
        return (x - x) / (x - x);

    m = (ix >> 23);
    if (hx < 0x00800000L) {
        for (i = 0; (ix & 0x00800000L) == 0; i++)
            ix <<= 1;
        m -= i - 1;
    }
    m -= 127;
    ix = (ix & 0x007fffffL) | 0x00800000L;
    if (m & 1)
        ix += ix;
    m >>= 1;

    ix += ix;
    q = s = 0;
    r = 0x01000000L;

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
            q += (z > one_sqrt) ? 2 : (q & 1);
        }
    }
    ix = (q >> 1) + 0x3f000000L;
    ix += (m << 23);

    ieee_float_shape_type sf_u;
    sf_u.word = ix;
    z = sf_u.value;
    return z;
}

// Function to compute the hypotenuse using float values
float __ieee754_hypotf(float x, float y) {
    float a = x, b = y, t1, t2, y1, y2, w;
    int32_t ha, hb, j, k;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ha = gf_u.word & 0x7fffffff;
    gf_u.value = y;
    hb = gf_u.word & 0x7fffffff;

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

    if ((ha - hb) > 0xf000000L) {
        return a + b;
    }
    k = 0;
    if (ha > 0x58800000L) {
        if (!(ha < 0x7f800000L)) {
            w = a + b;
            if (ha == 0x7f800000L) w = a;
            if (hb == 0x7f800000L) w = b;
            return w;
        }
        ha = ha - 0x22000000L;
        hb = hb - 0x22000000L;
        k += 68;
        sf_u.word = ha;
        a = sf_u.value;
        sf_u.word = hb;
        b = sf_u.value;
    }
    if (hb < 0x26800000L) {
        if (hb == 0) {
            return a;
        } else if (hb < 0x00800000L) {
            sf_u.word = 0x7e800000L;
            t1 = sf_u.value;
            b *= t1;
            a *= t1;
            k -= 126;
        } else {
            ha += 0x22000000;
            hb += 0x22000000;
            k -= 68;
            sf_u.word = ha;
            a = sf_u.value;
            sf_u.word = hb;
            b = sf_u.value;
        }
    }

    w = a - b;
    if (w > b) {
        sf_u.word = ha & 0xfffff000L;
        t1 = sf_u.value;
        t2 = a - t1;
        w = __ieee754_sqrtf(t1 * t1 - (b * (-b) - t2 * (a + t1)));
    } else {
        a = a + a;
        sf_u.word = hb & 0xfffff000L;
        y1 = sf_u.value;
        y2 = b - y1;
        sf_u.word = ha + 0x00800000L;
        t1 = sf_u.value;
        t2 = a - t1;
        w = __ieee754_sqrtf(t1 * y1 - (w * (-w) - (t1 * y2 + t2 * b)));
    }
    if (k != 0) {
        sf_u.word = 0x3f800000L + (k << 23);
        t1 = sf_u.value;
        return t1 * w;
    } else {
        return w;
    }
}

// Function to check if a float is infinity
int isinf_float(float x) {
    int32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffff;
    return (ix == 0x7f800000L);
}

int main() {
    float x = 3.14f; // Set a fixed value for x for deterministic behavior
    float y = 1.0f / 0.0f; // Positive infinity

    float res = __ieee754_hypotf(x, y);
    if (!isinf_float(res)) {
        printf("Error: Result is not infinity!\n");
        return 1;
    }

    printf("Result is infinity as expected.\n");
    return 0;
}