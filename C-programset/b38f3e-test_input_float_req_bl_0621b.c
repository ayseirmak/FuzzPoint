#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

static const float huge_floor = 1.0e30f;

// NaN check for floats
int isnan_float(float x) {
    return x != x;
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

static const float atanhi_atan[] = {
    4.6364760399e-01f,
    7.8539812565e-01f,
    9.8279368877e-01f,
    1.5707962513e+00f,
};

static const float atanlo_atan[] = {
    5.0121582440e-09f,
    3.7748947079e-08f,
    3.4473217170e-08f,
    7.5497894159e-08f,
};

static const float aT_atan[] = {
    3.3333334327e-01f, -2.0000000298e-01f, 1.4285714924e-01f, -1.1111110449e-01f,
    9.0908870101e-02f, -7.6918758452e-02f, 6.6610731184e-02f, -5.8335702866e-02f,
    4.9768779427e-02f, -3.6531571299e-02f, 1.6285819933e-02f,
};

static const float one_atan = 1.0f, huge_atan = 1.0e30f,
                   pi_o_4 = 7.8539818525e-01f, pi_o_2 = 1.5707963705e+00f,
                   pi = 3.1415927410e+00f;

float atan_float(float x) {
    float w, s1, s2, z;
    __int32_t ix, hx, id;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    hx = gf_u.word;

    ix = hx & 0x7fffffff;
    if (ix >= 0x50800000) {
        if (ix > 0x7f800000)
            return x + x; // NaN
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
    }

    z = x * x;
    w = z * z;

    s1 = z * (aT_atan[0] +
              w * (aT_atan[2] +
                   w * (aT_atan[4] +
                        w * (aT_atan[6] + w * (aT_atan[8] + w * aT_atan[10])))));
    s2 = w *
         (aT_atan[1] +
          w * (aT_atan[3] + w * (aT_atan[5] + w * (aT_atan[7] + w * aT_atan[9]))));
    if (id < 0)
        return x - x * (s1 + s2);
    else {
        z = atanhi_atan[id] - ((x * (s1 + s2) - atanlo_atan[id]) - x);
        return (hx < 0) ? -z : z;
    }
}

int main() {
    float x = -1.0f / 0.0f; // -INF
    float res = atan_float(x);
    assert(res == -pi_o_2);
    printf("Test passed: atan(-INF) = %f\n", res);
    return 0;
}