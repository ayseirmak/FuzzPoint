#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

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

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;
    
    gf_u.value = y;
    hy = gf_u.word;

    sx = hx & 0x80000000;
    hx ^= sx;
    hy &= 0x7fffffff;

    if (hy == 0 || !((hx) < 0x7f800000L) || (hy > 0x7f800000L))
        return (x * y) / (x * y);
    if (hx < hy)
        return x;
    if (hx == hy)
        return Zero_fmod[sx >> 31];
    if (hx < 0x00800000L) {
        for (ix = -126, i = (hx << 8); i > 0; i <<= 1)
            ix -= 1;
    } else
        ix = (hx >> 23) - 127;

    if (hy < 0x00800000L) {
        for (iy = -126, i = (hy << 8); i >= 0; i <<= 1)
            iy -= 1;
    } else
        iy = (hy >> 23) - 127;

    if (ix >= -126)
        hx = 0x00800000 | (0x007fffff & hx);
    else {
        n = -126 - ix;
        hx <<= n;
    }
    if (iy >= -126)
        hy = 0x00800000 | (0x007fffff & hy);
    else {
        n = -126 - iy;
        hy <<= n;
    }
    n = ix - iy;
    while (n--) {
        hz = hx - hy;
        if (hz < 0) {
            hx += hx;
        } else {
            if (hz == 0)
                return Zero_fmod[sx >> 31];
            hx = hz + hz;
        }
    }
    hz = hx - hy;
    if (hz >= 0) {
        hx = hz;
    }

    if (hx == 0)
        return Zero_fmod[sx >> 31];
    while (hx < 0x00800000) {
        hx += hx;
        iy -= 1;
    }
    if (iy >= -126) {
        hx = ((hx - 0x00800000) | ((iy + 127) << 23));
        gf_u.word = hx | sx;
        x = gf_u.value;
    } else {
        n = -126 - iy;
        hx >>= n;
        gf_u.word = hx | sx;
        x = gf_u.value;
        x *= one_fmod;
    }
    return x;
}

float __ieee754_sqrtf(float x) {
    float z;
    __uint32_t r, hx;
    __int32_t ix, s, q, m, t, i;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    
    hx = ix & 0x7fffffff;

    if (!((hx) < 0x7f800000L))
        return x * x + x;

    if ((hx) == 0)
        return x;
    if (ix < 0)
        return (x - x) / (x - x);

    m = ix >> 23;
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
        z = 1.0 - 1.0e-30;
        if (z >= 1.0) {
            z = 1.0 + 1.0e-30;
            if (z > 1.0)
                q += 2;
            else
                q += (q & 1);
        }
    }
    ix = (q >> 1) + 0x3f000000L;
    ix += (m << 23);
    gf_u.word = ix;
    z = gf_u.value;
    return z;
}

float copysign_float(float x, float y) {
    __uint32_t ix, iy;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    
    gf_u.value = y;
    iy = gf_u.word;

    ieee_float_shape_type sf_u;
    sf_u.word = ((ix & 0x7fffffff) | (iy & 0x80000000));
    x = sf_u.value;
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
    float x = 0.5;  // Fixed dummy value for demonstration
    float y = INFINITY;  // +Infinity

    if (fabsf(x) < 1) {
        float res = powf(x, y);

        // result shall be +0
        assert(res == 0.0f && __signbit_float(res) == 0);
        printf("Test passed!\n");
    }

    return 0;
}