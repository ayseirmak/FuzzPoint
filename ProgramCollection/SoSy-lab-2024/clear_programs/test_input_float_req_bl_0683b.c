#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

// Union for float and uint32_t conversion
typedef union {
    float value;
    uint32_t word;
} ieee_float_shape_type;

// Function to get absolute value of a float
float fabs_float(float x) {
    uint32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ieee_float_shape_type sf_u;
    sf_u.word = (ix & 0x7fffffff);
    x = sf_u.value;
    return x;
}

// An array of constants used in atan_float function
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

// Function to approximate atan of a float
float atan_float(float x) {
    float w, s1, s2, z;
    int32_t ix, hx, id;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;
    ix = hx & 0x7fffffff;

    if (ix >= 0x50800000) {
        if (ix > 0x7f800000L)
            return x + x;
        if (hx > 0)
            return atanhi_atan[3] + atanlo_atan[3];
        else
            return -atanhi_atan[3] - atanlo_atan[3];
    }

    if (ix < 0x3ee00000) {
        if (ix < 0x31000000) {
            if (huge_atan + x > one_atan)
                return x;
        }
        id = -1;
    } else {
        x = fabs_float(x);
        if (ix < 0x3f980000) {
            if (ix < 0x3f300000) {
                id = 0;
                x = ((float)2.0 * x - one_atan) / ((float)2.0 + x);
            } else {
                id = 1;
                x = (x - one_atan) / (x + one_atan);
            }
        } else {
            if (ix < 0x401c0000) {
                id = 2;
                x = (x - (float)1.5) / (one_atan + (float)1.5 * x);
            } else {
                id = 3;
                x = -(float)1.0 / x;
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
    if (id < 0)
        return x - x * (s1 + s2);
    else {
        z = atanhi_atan[id] - ((x * (s1 + s2) - atanlo_atan[id]) - x);
        return (hx < 0) ? -z : z;
    }
}

// Constants for atan2f and helper functions
static const float tiny_atan2 = 1.0e-30, zero_atan2 = 0.0,
                   pi_lo_atan2 = -8.7422776573e-08;

// Function to calculate atan2f
float __ieee754_atan2f(float y, float x) {
    float z;
    int32_t k, m, hx, hy, ix, iy;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;
    ix = hx & 0x7fffffff;

    gf_u.value = y;
    hy = gf_u.word;
    iy = hy & 0x7fffffff;

    if (ix > 0x7f800000L || iy > 0x7f800000L)
        return x + y;
    if (hx == 0x3f800000)
        return atan_float(y);
    m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

    if (iy == 0) {
        switch (m) {
        case 0:
        case 1:
            return y;
        case 2:
            return pi + tiny_atan2;
        case 3:
            return -pi - tiny_atan2;
        }
    }

    if (ix == 0)
        return (hy < 0) ? -pi_o_2 - tiny_atan2 : pi_o_2 + tiny_atan2;

    if (ix == 0x7f800000L) {
        if (iy == 0x7f800000L) {
            switch (m) {
            case 0:
                return pi_o_4 + tiny_atan2;
            case 1:
                return -pi_o_4 - tiny_atan2;
            case 2:
                return (float)3.0 * pi_o_4 + tiny_atan2;
            case 3:
                return (float)-3.0 * pi_o_4 - tiny_atan2;
            }
        } else {
            switch (m) {
            case 0:
                return zero_atan2;
            case 1:
                return -zero_atan2;
            case 2:
                return pi + tiny_atan2;
            case 3:
                return -pi - tiny_atan2;
            }
        }
    }

    if (iy == 0x7f800000L)
        return (hy < 0) ? -pi_o_2 - tiny_atan2 : pi_o_2 + tiny_atan2;

    k = (iy - ix) >> 23;
    if (k > 60)
        z = pi_o_2 + (float)0.5 * pi_lo_atan2;
    else if (hx < 0 && k < -60)
        z = 0.0;
    else
        z = atan_float(fabs_float(y / x));
    switch (m) {
    case 0:
        return z;
    case 1: {
        uint32_t zh;
        ieee_float_shape_type gf_u;
        gf_u.value = z;
        zh = gf_u.word;
        ieee_float_shape_type sf_u;
        sf_u.word = (zh ^ 0x80000000);
        z = sf_u.value;
    }
        return z;
    case 2:
        return pi - (z - pi_lo_atan2);
    default:
        return (z - pi_lo_atan2) - pi;
    }
}

// Function to check the sign of a float
int __signbit_float(float x) {
    uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;
    return (w & 0x80000000) != 0;
}

// Function to check if float is finite
int isfinite_float(float x) {
    int32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffff;
    return (ix < 0x7f800000L);
}

int main() {
    float x = 1.0f / 0.0f; // INF
    float y = 1.5f; // Chose a fixed non-infinite value

    if (isfinite_float(y) && y > 0.0f) {
        float res = __ieee754_atan2f(y, x);

        // x is +inf, y > 0.0 and y != -inf, the result shall be 0.0
        assert(res == 0.0f && __signbit_float(res) == 0);
    }

    return 0;
}