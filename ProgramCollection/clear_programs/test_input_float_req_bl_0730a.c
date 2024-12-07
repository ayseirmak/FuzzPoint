#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>

// Custom function to report a reach error
void reach_error() {
    fprintf(stderr, "reach_error detected\n");
    abort();
}

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

    hx = ix & 0x7fffffff;

    // Return x*x + x if x is NaN or INF
    if (!(hx < 0x7f800000L)) 
        return x * x + x;

    // Return x if x == 0
    if (hx == 0)
        return x;

    // Return NaN if x < 0
    if (ix < 0)
        return (x - x) / (x - x);

    m = (ix >> 23);
    // adjust subnormal numbers
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

    // Generate sqrt(x) bit by bit
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

    // Use rounding tricks for accuracy
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
    ix = (q >> 1) + 0x3f000000L;
    ix += (m << 23);
    ieee_float_shape_type sf_u;
    sf_u.word = ix;
    z = sf_u.value;

    return z;
}

// infinity check for floats
int isinf_float(float x) {
    __int32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffff;
    return (ix == 0x7f800000L);
}

int main() {
    // Deterministic float value for +Infinity
    union { unsigned int i; float f; } infinity_union;
    infinity_union.i = 0x7f800000;
    float x = infinity_union.f;

    float res = __ieee754_sqrtf(x);

    // x +inf the result shall be x
    if (!isinf_float(res)) {
        reach_error();
        return 1;
    }

    printf("Test passed: Result is infinite as expected.\n");
    return 0;
}