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

// Replacement for fabs_float
float fabs_float(float x) {
    ieee_float_shape_type u;
    u.value = x;
    u.word &= 0x7FFFFFFF; // Clear the sign bit
    return u.value;
}

// All the constants as they are
static const float atanhi_atan[] = {
    4.6364760399e-01,
    7.8539812565e-01,
    9.8279368877e-01,
    1.5707962513e+00,
};

static const float atanlo_atan[] = {
    5.0121582440e-09,
    3.7748947079e-08,
    3.4473217170e-08,
    7.5497894159e-08,
};

static const float aT_atan[] = {
    3.3333334327e-01, -2.0000000298e-01, 1.4285714924e-01, -1.1111110449e-01,
    9.0908870101e-02, -7.6918758452e-02, 6.6610731184e-02, -5.8335702866e-02,
    4.9768779427e-02, -3.6531571299e-02, 1.6285819933e-02,
};

static const float one_atan = 1.0, huge_atan = 1.0e30,
                   pi_o_4 = 7.8539818525e-01, pi_o_2 = 1.5707963705e+00,
                   pi = 3.1415927410e+00;

// Reimplement atan_float
float atan_float(float x) {
    float w, s1, s2, z;
    __int32_t ix, hx, id;

    ieee_float_shape_type u;
    u.value = x;
    hx = u.word;
    ix = hx & 0x7FFFFFFF;

    if (ix >= 0x50800000) {
        return ((ix > 0x7F800000L) || (hx < 0)) ? -(atanhi_atan[3] + atanlo_atan[3]) : (atanhi_atan[3] + atanlo_atan[3]);
    }

    if (ix < 0x3EE00000) {
        if (ix < 0x31000000) {
            return x;
        }
        id = -1;
    } else {
        x = fabs_float(x);
        if (ix < 0x3F980000) {
            if (ix < 0x3F300000) {
                id = 0;
                x = (2.0f * x - one_atan) / (2.0f + x);
            } else {
                id = 1;
                x = (x - one_atan) / (x + one_atan);
            }
        } else {
            if (ix < 0x401C0000) {
                id = 2;
                x = (x - 1.5f) / (one_atan + 1.5f * x);
            } else {
                id = 3;
                x = -1.0f / x;
            }
        }
    }

    z = x * x;
    w = z * z;

    s1 = z * (aT_atan[0] +
              w * (aT_atan[2] +
                   w * (aT_atan[4] +
                        w * (aT_atan[6] + w * (aT_atan[8] + w * aT_atan[10])))));
    s2 =
        w *
        (aT_atan[1] +
         w * (aT_atan[3] + w * (aT_atan[5] + w * (aT_atan[7] + w * aT_atan[9]))));

    if (id < 0) {
        return x - x * (s1 + s2);
    } else {
        z = atanhi_atan[id] - ((x * (s1 + s2) - atanlo_atan[id]) - x);
        return (hx < 0) ? -z : z;
    }
}

// isfinite function in C
int isfinite_float(float x) {
    return isfinite(x);
}

// Reimplement atan2
float __ieee754_atan2f(float y, float x) {
    float z;
    __int32_t k, m, hx, hy, ix, iy;

    // Extract high words of each argument
    ieee_float_shape_type u_x, u_y;
    u_x.value = x;
    hx = u_x.word;
    ix = hx & 0x7FFFFFFF;
    u_y.value = y;
    hy = u_y.word;
    iy = hy & 0x7FFFFFFF;

    if (((ix) > 0x7f800000L) || ((iy) > 0x7f800000L)) return x + y;
    if (hx == 0x3f800000) return atan_float(y);

    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

    if (iy == 0) {
        if (m == 0 || m == 1) return y;
        return m == 2 ? pi + 1.0e-30f : -pi - 1.0e-30f;
    }

    if (ix == 0) return hy < 0 ? -pi_o_2 - 1.0e-30f : pi_o_2 + 1.0e-30f;

    if (ix == 0x7f800000L) {
        if (iy == 0x7f800000L) {
            switch (m) {
                case 0: return pi_o_4 + 1.0e-30f;
                case 1: return -pi_o_4 - 1.0e-30f;
                case 2: return 3.0f * pi_o_4 + 1.0e-30f;
                case 3: return -3.0f * pi_o_4 - 1.0e-30f;
            }
        } else {
            return m == 0 ? 0.0f : m == 1 ? -0.0f : m == 2 ? pi + 1.0e-30f : -pi - 1.0e-30f;
        }
    }

    if (iy == 0x7f800000L) return hy < 0 ? -pi_o_2 - 1.0e-30f : pi_o_2 + 1.0e-30f;

    k = (iy - ix) >> 23;
    if (k > 60) z = pi_o_2 + 0.5f * (-8.7422776573e-08f);
    else if (hx < 0 && k < -60) z = 0.0f;
    else z = atan_float(fabs_float(y / x));

    switch (m) {
        case 0: return z;
        case 1: {
            ieee_float_shape_type gf_u;
            gf_u.value = z;
            gf_u.word ^= 0x80000000;
            return gf_u.value;
        }
        case 2: return pi - (z - -8.7422776573e-08f);
        default: return (z - -8.7422776573e-08f) - pi;
    }
}

int main() {
    float x = -INFINITY; // -INF
    float y = -10.0f;    // Finite and less than 0

    // Assert if the result is not as expected
    if (isfinite_float(y) && y < 0.0f) {
        float res = __ieee754_atan2f(y, x);

        // x is -inf, y < 0.0 and y is finite, the result shall be -pi
        assert(res == -pi && "The result was expected to be -pi.");
    }

    return 0;
}