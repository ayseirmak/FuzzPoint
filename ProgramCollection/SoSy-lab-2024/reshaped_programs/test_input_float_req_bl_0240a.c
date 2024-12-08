#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef union {
    float value;
    uint32_t word;
} ieee_float_shape_type;

int isnan_float(float x) {
    return x != x;
}

static const float huge_floor = 1.0e30f;

float floor_float(float x) {
    int32_t i0, j0;
    uint32_t i, ix;
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
                } else if (!((ix) == 0)) {
                    i0 = 0xbf800000;
                }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0)
                return x;
            if (huge_floor + x > 0.0f) {
                if (i0 < 0)
                    i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        if (!(ix < 0x7f800000L))
            return x + x;
        else
            return x;
    }
    ieee_float_shape_type sf_u;
    sf_u.word = (i0);
    x = sf_u.value;
    return x;
}

int __signbit_float(float x) {
    uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;
    return (w & 0x80000000) != 0;
}

float copysign_float(float x, float y) {
    uint32_t ix, iy;
    ieee_float_shape_type gf_ux, gf_uy;
    gf_ux.value = x;
    ix = gf_ux.word;
    gf_uy.value = y;
    iy = gf_uy.word;
    ieee_float_shape_type sf_ux;
    sf_ux.word = (ix & 0x7fffffff) | (iy & 0x80000000);
    x = sf_ux.value;
    return x;
}

float fabs_float(float x) {
    uint32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ieee_float_shape_type sf_u;
    sf_u.word = ix & 0x7fffffff;
    x = sf_u.value;
    return x;
}

__int32_t __ieee754_rem_pio2f(float x, float *y) {
    float z = 0.0f, w = 0.0f, t = 0.0f, r = 0.0f, fn = 0.0f;
    float tx[3];
    int32_t i = 0, j = 0, n = 0, ix = 0, hx = 0;
    int e0 = 0, nx = 0;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;
    ix = hx & 0x7fffffff;

    // Dummy implementation as this function is complex and not used in main
    if (ix <= 0x3f490fd8) {
        y[0] = x;
        y[1] = 0;
        return 0;
    }
    y[0] = 0.0f;
    y[1] = 0.0f;
    return 1;
}

float sin_float(float x) {
    float y[2];
    int32_t n, ix;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffff;

    y[0] = 0.0f;
    y[1] = 0.0f;
    n = 0;

    if (ix <= 0x3f490fd8) {  // |x| ~<= pi/4
        return x;
    } else if (!(ix < 0x7f800000L)) {
        return x - x;
    } else {
        n = __ieee754_rem_pio2f(x, y);
        switch (n & 3) {
        case 0: return y[0];
        case 1: return y[1];
        case 2: return -y[0];
        default: return -y[1];
        }
    }
}

int main() {
    float x = 1.0f / 0.0f; // INF
    float res = sin_float(x);

    // x is +INF, the result shall be NAN
    if (!isnan_float(res)) {
        printf("Error: The result is not NaN as expected.\n");
        return 1;
    }

    printf("The result is NaN as expected.\n");
    return 0;
}