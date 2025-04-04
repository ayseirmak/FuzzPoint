#include <stdio.h>
#include <math.h>
#include <assert.h>

// Definitions for float manipulations
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

// Define constants
static const float one_fmod = 1.0f, Zero_fmod[] = {0.0f, -0.0f};
static const float one_sqrt = 1.0f, tiny_sqrt = 1.0e-30f;
static const float two25_scalbn = 3.355443200e+07f, twom25_scalbn = 2.9802322388e-08f, huge_scalbn = 1.0e+30f, tiny_scalbn = 1.0e-30f;
static const float bp_pow[] = {1.0f, 1.5f}, dp_h_pow[] = {0.0f, 5.84960938e-01f}, dp_l_pow[] = {0.0f, 1.56322085e-06f};
static const float zero_pow = 0.0f, one_pow = 1.0f, two_pow = 2.0f, two24_pow = 16777216.0f, huge_pow = 1.0e30f, tiny_pow = 1.0e-30f;
static const float L1_pow = 6.0000002384e-01f, L2_pow = 4.2857143283e-01f, L3_pow = 3.3333334327e-01f;
static const float L4_pow = 2.7272811532e-01f, L5_pow = 2.3066075146e-01f, L6_pow = 2.0697501302e-01f;
static const float P1_pow = 1.6666667163e-01f, P2_pow = -2.7777778450e-03f, P3_pow = 6.6137559770e-05f;
static const float P4_pow = -1.6533901999e-06f, P5_pow = 4.1381369442e-08f;
static const float lg2_pow = 6.9314718246e-01f, lg2_h_pow = 6.93145752e-01f, lg2_l_pow = 1.42860654e-06f;
static const float ovt_pow = 4.2995665694e-08f, cp = 9.6179670095e-01f, cp_h_pow = 9.6179199219e-01f, cp_l_pow = 4.7017383622e-06f;
static const float ivln2_pow = 1.4426950216e+00f, ivln2_h_pow = 1.4426879883e+00f, ivln2_l_pow = 7.0526075433e-06f;

float fabs_float(float x) {
    __uint32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ieee_float_shape_type sf_u;
    sf_u.word = (ix & 0x7fffffff);
    return sf_u.value;
}

int __signbit_float(float x) {
    __uint32_t w;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;
    return (w & 0x80000000) != 0;
}

float __ieee754_powf(float x, float y) {
    // Simplified implementation for demonstration
    float ax = fabs_float(x);

    if (ax > 1 && y == -INFINITY) {
        return 0.0f; // should return +0.0
    }
    return powf(x, y);
}

int main() {
    float x = 3.14f; // Fixed deterministic value
    float y = -1.0f / 0.0f; // -INF

    if (fabs_float(x) > 1) {
        float res = __ieee754_powf(x, y);

        // Verify result shall be +0
        assert(res == 0.0f && __signbit_float(res) == 0);

        printf("Test passed: Result is +0\n");
    }

    return 0;
}