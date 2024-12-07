#include <stdio.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

static const float one_fmod = 1.0, Zero_fmod[] = {0.0, -0.0};

float fmod_float(float x, float y) {
    __int32_t n, hx, hy, hz, ix, iy, sx, i;

    // Extract bit representations
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;

    gf_u.value = y;
    hy = gf_u.word;

    sx = hx & 0x80000000;
    hx ^= sx;
    hy &= 0x7fffffff;

    if (hy == 0 || !(hx < 0x7f800000L) || (hy > 0x7f800000L)) {
        return (x * y) / (x * y);
    }
    if (hx < hy) return x;
    if (hx == hy) return Zero_fmod[sx >> 31];

    if (hx < 0x00800000L) {
        for (ix = -126, i = (hx << 8); i > 0; i <<= 1)
            ix -= 1;
    } else {
        ix = (hx >> 23) - 127;
    }

    if (hy < 0x00800000L) {
        for (iy = -126, i = (hy << 8); i >= 0; i <<= 1)
            iy -= 1;
    } else {
        iy = (hy >> 23) - 127;
    }

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
    if (hz >= 0) hx = hz;

    if (hx == 0)
        return Zero_fmod[sx >> 31];
    while (hx < 0x00800000) {
        hx += hx;
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

// NaN check for floats
int isnan_float(float x) {
    return x != x;
}

int main() {
    float x = 42.0f; // arbitrary test value
    float y = -0.0f;
    float res = fmod_float(x, y);

    // Validate the result shall be NaN
    if (!isnan_float(res)) {
        printf("Error: The result is not NaN for y = -0\n");
        return 1;
    }

    printf("Success: The result is NaN as expected.\n");
    return 0;
}