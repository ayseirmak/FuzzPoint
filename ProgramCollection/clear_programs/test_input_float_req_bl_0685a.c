#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

float fabs_float(float x) {
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    __uint32_t ix = gf_u.word;
    gf_u.word = ix & 0x7fffffffu;  // Clear sign bit
    return gf_u.value;
}

static const float atanhi_atan[] = {
    4.6364760399e-01, 7.8539812565e-01, 9.8279368877e-01, 1.5707962513e+00};

static const float atanlo_atan[] = {
    5.0121582440e-09, 3.7748947079e-08, 3.4473217170e-08, 7.5497894159e-08};

static const float aT_atan[] = {
    3.3333334327e-01, -2.0000000298e-01, 1.4285714924e-01, -1.1111110449e-01,
    9.0908870101e-02, -7.6918758452e-02, 6.6610731184e-02, -5.8335702866e-02,
    4.9768779427e-02, -3.6531571299e-02, 1.6285819933e-02};

static const float one_atan = 1.0, huge_atan = 1.0e30,
                   pi_o_4 = 7.8539818525e-01, pi_o_2 = 1.5707963705e+00,
                   pi = 3.1415927410e+00;

float atan_float(float x) {
    float w, s1, s2, z;
    __int32_t ix, hx;
    ieee_float_shape_type gf_u;
    
    gf_u.value = x;
    hx = gf_u.word;
    ix = hx & 0x7fffffff;
    if (ix >= 0x50800000) {
        if (ix > 0x7f800000L)
            return x + x; // NaN
        return hx > 0 ? atanhi_atan[3] + atanlo_atan[3] : -atanhi_atan[3] - atanlo_atan[3];
    }

    if (ix < 0x3ee00000) {
        if (ix < 0x31000000 && huge_atan + x > one_atan)
            return x;
        return x - x * (s1 + s2);
    }

    // Argument reduction.
    int id;
    if (ix < 0x3f980000) {
        if (ix < 0x3f300000) {
            id = 0;
            x = (2.0f * x - one_atan) / (2.0f + x);
        } else {
            id = 1;
            x = (x - one_atan) / (x + one_atan);
        }
    } else {
        if (ix < 0x401c0000) {
            id = 2;
            x = (x - 1.5f) / (one_atan + 1.5f * x);
        } else {
            id = 3;
            x = -1.0f / x;
        }
    }

    z = x * x;
    w = z * z;
    s1 = z * (aT_atan[0] + w * (aT_atan[2] + w * (aT_atan[4] + w * (aT_atan[6] + w * (aT_atan[8] + w * aT_atan[10])))));
    s2 = w * (aT_atan[1] + w * (aT_atan[3] + w * (aT_atan[5] + w * (aT_atan[7] + w * aT_atan[9]))));

    z = id < 0 ? x - x * (s1 + s2) : atanhi_atan[id] - ((x * (s1 + s2) - atanlo_atan[id]) - x);
    return (hx < 0) ? -z : z;
}

static const float tiny_atan2 = 1.0e-30, pi_lo_atan2 = -8.7422776573e-08;
static const float zero_atan2 = 0.0;

float __ieee754_atan2f(float y, float x) {
    float z;
    __int32_t hx, hy, ix, iy;
    
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;
    ix = hx & 0x7fffffff;
    
    gf_u.value = y;
    hy = gf_u.word;
    iy = hy & 0x7fffffff;
    
    if (ix > 0x7f800000L || iy > 0x7f800000L)
        return x + y; // NaN

    if (hx == 0x3f800000)
        return atan_float(y); 

    int m = ((hy >> 31) & 1) | ((hx >> 30) & 2);

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
                return 3.0f * pi_o_4 + tiny_atan2;
            case 3:
                return -3.0f * pi_o_4 - tiny_atan2;
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

    int k = (iy - ix) >> 23;
    z = k > 60 ? pi_o_2 + 0.5f * pi_lo_atan2 : atan_float(fabs_float(y / x));
    return m == 0 ? z : (m == 1 ? -z : (m == 2 ? pi - (z - pi_lo_atan2) : (z - pi_lo_atan2) - pi));
}

int main() {
    float x = -INFINITY;
    float y = INFINITY;

    float res = __ieee754_atan2f(y, x);

    // x is -inf, y is +inf, the result shall be +3pi/4
    assert(res == 3 * pi_o_4);

    printf("Test passed!\n");
    return 0;
}