#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

static const float one_fmod = 1.0, Zero_fmod[] = {
                                       0.0,
                                       -0.0,
};

float fmod_float(float x, float y) {
    __int32_t n, hx, hy, hz, ix, iy, sx, i;

    ieee_float_shape_type gf_u_x;
    gf_u_x.value = x;
    hx = gf_u_x.word;

    ieee_float_shape_type gf_u_y;
    gf_u_y.value = y;
    hy = gf_u_y.word;

    sx = hx & 0x80000000;
    hx ^= sx;
    hy &= 0x7fffffff;

    if (((hy) == 0) || !((hx) < 0x7f800000L) || ((hy) > 0x7f800000L))
        return (x * y) / (x * y);
    if (hx < hy)
        return x;
    if (hx == hy)
        return Zero_fmod[(__uint32_t)sx >> 31];
    if (((hx) < 0x00800000L)) {
        for (ix = -126, i = (hx << 8); i > 0; i <<= 1)
            ix -= 1;
    } else
        ix = (hx >> 23) - 127;

    if (((hy) < 0x00800000L)) {
        for (iy = -126, i = (hy << 8); i >= 0; i <<= 1)
            iy -= 1;
    } else
        iy = (hy >> 23) - 127;

    if (ix >= -126)
        hx = 0x00800000 | (0x007fffff & hx);
    else {
        n = -126 - ix;
        hx = hx << n;
    }
    if (iy >= -126)
        hy = 0x00800000 | (0x007fffff & hy);
    else {
        n = -126 - iy;
        hy = hy << n;
    }
    n = ix - iy;
    while (n--) {
        hz = hx - hy;
        if (hz < 0) {
            hx = hx + hx;
        } else {
            if (hz == 0)
                return Zero_fmod[(__uint32_t)sx >> 31];
            hx = hz + hz;
        }
    }
    hz = hx - hy;
    if (hz >= 0) {
        hx = hz;
    }

    if (hx == 0)
        return Zero_fmod[(__uint32_t)sx >> 31];
    while (hx < 0x00800000) {
        hx = hx + hx;
        iy -= 1;
    }
    if (iy >= -126) {
        hx = ((hx - 0x00800000) | ((iy + 127) << 23));
        ieee_float_shape_type sf_u;
        sf_u.word = (hx | sx);
        x = sf_u.value;
    } else {
        n = -126 - iy;
        hx >>= n;
        ieee_float_shape_type sf_u;
        sf_u.word = (hx | sx);
        x = sf_u.value;
        x *= one_fmod;
    }
    return x;
}

int __signbit_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;
    return (w & 0x80000000) != 0;
}

int main() {
    // Deterministic input value for y
    float y = 2.0f;  // Replace this with any non-zero constant value you wish to test

    float x = -0.0f;

    if ((y < 0.0f || y > 0.0f)) {
        float res = fmod_float(x, y);

        // x is -0, y is not 0, result shall be -0
        assert(res == -0.0f && __signbit_float(res) == 1);
    }

    return 0;
}