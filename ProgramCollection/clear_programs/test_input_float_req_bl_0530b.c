#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

static const float huge_floor = 1.0e30f;
static const float two25_scalbn = 3.355443200e+07f, twom25_scalbn = 2.9802322388e-08f;
static const float tiny_scalbn = 1.0e-30f;
static const float zero_krempio = 0.0f, one_krempio = 1.0f;
static const float invpio2_rempio = 6.3661980629e-01f;
static const float pio2_1_rempio = 1.5707855225e+00f;
static const float pio2_1t_rempio = 1.0804334124e-05f;
static const float two8_rempio = 2.5600000000e+02f;

float floor_float(float x) {
    __int32_t i0, j0;
    __uint32_t i, ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
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
        if (ix < 0x7f800000L) return x;
        else return x + x;
    }
    
    ieee_float_shape_type sf_u;
    sf_u.word = i0;
    x = sf_u.value;
    
    return x;
}

float fabs_float(float x) {
    __uint32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    
    ieee_float_shape_type sf_u;
    sf_u.word = (ix & 0x7fffffff);
    x = sf_u.value;
    
    return x;
}

__int32_t __ieee754_rem_pio2f(float x, float *y) {
    float z, t;
    __int32_t n, ix, hx;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;
    
    ix = hx & 0x7fffffff;
    if (ix <= 0x3f490fd8) {  // |x| ~<= pi/4
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    
    if (ix < 0x4016cbe4) {  // |x| < 3pi/4
        if (hx > 0) {
            z = x - pio2_1_rempio;
            y[0] = z - pio2_1t_rempio;
            y[1] = (z - y[0]) - pio2_1t_rempio;
            return 1;
        } else {
            z = x + pio2_1_rempio;
            y[0] = z + pio2_1t_rempio;
            y[1] = (z - y[0]) + pio2_1t_rempio;
            return -1;
        }
    }
    
    t = fabs_float(x);
    n = (__int32_t)(t * invpio2_rempio + 0.5f);
    return n;
}

float __kernel_tanf(float x, float y, int iy) {
    // simplified for clarity
    return x;  // naive implementation for illustration purposes
}

float tan_float(float x) {
    float y[2], z = 0.0f;
    __int32_t n, ix;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;

    ix &= 0x7fffffff;
    if (ix <= 0x3f490fda)
        return __kernel_tanf(x, z, 1);

    n = __ieee754_rem_pio2f(x, y);
    return __kernel_tanf(y[0], y[1], 1 - ((n & 1) << 1));
}

int __signbit_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    return (w & 0x80000000) != 0;
}

int main() {
    float x = -0.0f;
    float res = tan_float(x);

    assert(res == -0.0f && __signbit_float(res) == 1);

    printf("Test passed!\n");
    return 0;
}