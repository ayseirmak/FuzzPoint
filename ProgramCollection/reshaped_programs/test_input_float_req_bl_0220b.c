#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

// Define the function to replace reach_error
#define reach_error() assert(0)

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

// Use a large constant for floor operations
static const float huge_floor = 1.0e30f;

float floor_float(float x) {
    __int32_t i0, j0;
    __uint32_t i, ix;
    ieee_float_shape_type gf_u;
    gf_u.value = (x);
    i0 = gf_u.word;
    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (huge_floor + x > 0.0f) {
                if (i0 >= 0) {
                    i0 = 0;
                } else if (ix != 0) {
                    i0 = 0xbf800000;
                }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) return x;
            if (huge_floor + x > 0.0f) {
                if (i0 < 0) i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        if (!(ix < 0x7f800000L)) return x + x;
        else return x;
    }
    ieee_float_shape_type sf_u;
    sf_u.word = i0;
    x = sf_u.value;
    return x;
}

int __signbit_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = (x);
    w = gf_u.word;
    return (w & 0x80000000) != 0;
}

float sin_float(float x);

// Copysign function
float copysign_float(float x, float y) {
    __uint32_t ix, iy;
    ieee_float_shape_type gf_u;
    gf_u.value = (x);
    ix = gf_u.word;
    gf_u.value = (y);
    iy = gf_u.word;
    ieee_float_shape_type sf_u;
    sf_u.word = ((ix & 0x7fffffff) | (iy & 0x80000000));
    x = sf_u.value;
    return x;
}

static const float tiny_scalbn = 1.0e-30f;

float scalbn_float(float x, int n) {
    __int32_t k, ix;
    __uint32_t hx;
    ieee_float_shape_type gf_u;
    gf_u.value = (x);
    ix = gf_u.word;
    hx = ix & 0x7fffffff;
    k = hx >> 23;
    if (hx == 0) return x;
    if (!(hx < 0x7f800000L)) return x + x;
    if (hx < 0x00800000L) {
        x *= 3.3554432e+07; // 2^25
        gf_u.value = (x);
        ix = gf_u.word;
        k = ((ix & 0x7f800000) >> 23) - 25;
        if (n < -50000) return tiny_scalbn * x;
    }
    k += n;
    if (k > (0x7f7fffffL >> 23)) return 1.0e+30f * copysign_float(1.0e+30f, x);
    if (k > 0) {
        ieee_float_shape_type sf_u;
        sf_u.word = ((ix & 0x807fffff) | (k << 23));
        x = sf_u.value;
        return x;
    }
    if (k < -22) {
        if (n > 50000) return 1.0e+30f * copysign_float(1.0e+30f, x);
        else return tiny_scalbn * copysign_float(tiny_scalbn, x);
    }
    k += 25;
    ieee_float_shape_type sf_u;
    sf_u.word = ((ix & 0x807fffff) | (k << 23));
    x = sf_u.value;
    return x * 2.9802322388e-08; // 2^-25
}

int main() {
    float x = -0.0f;
    float res = sin_float(x);

    // x is -0, result is -0
    if (!(res == -0.0f && __signbit_float(res) == 1)) {
        reach_error();
        return 1;
    }

    return 0;
}

/*
 * Implement the sin_float function and additional support functions here.
 * The previous C code has shown how to handle inputs and do calculations.
 */