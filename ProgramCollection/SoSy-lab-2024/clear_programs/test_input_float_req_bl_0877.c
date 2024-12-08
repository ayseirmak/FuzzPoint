#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

static const float one_fmod = 1.0, Zero_fmod[] = {0.0, -0.0};
static const float one_sqrt = 1.0, tiny_sqrt = 1.0e-30;
static const float two25_scalbn = 3.355443200e+07, twom25_scalbn = 2.9802322388e-08;
static const float huge_scalbn = 1.0e+30, tiny_scalbn = 1.0e-30;
static const float bp_pow[] = {1.0, 1.5};
static const float zero_pow = 0.0, one_pow = 1.0, two_pow = 2.0;
static const float two24_pow = 16777216.0, huge_pow = 1.0e30, tiny_pow = 1.0e-30;
static const float L1_pow = 6.0000002384e-01, L2_pow = 4.2857143283e-01;
static const float L3_pow = 3.3333334327e-01, L4_pow = 2.7272811532e-01;
static const float L5_pow = 2.3066075146e-01, L6_pow = 2.0697501302e-01;
static const float P1_pow = 1.6666667163e-01, P2_pow = -2.7777778450e-03;
static const float P3_pow = 6.6137559770e-05, P4_pow = -1.6533901999e-06;
static const float P5_pow = 4.1381369442e-08;
static const float lg2_pow = 6.9314718246e-01, lg2_h_pow = 6.93145752e-01;
static const float lg2_l_pow = 1.42860654e-06, ovt_pow = 4.2995665694e-08;
static const float cp = 9.6179670095e-01, cp_h_pow = 9.6179199219e-01;
static const float cp_l_pow = 4.7017383622e-06, ivln2_pow = 1.4426950216e+00;
static const float ivln2_h_pow = 1.4426879883e+00, ivln2_l_pow = 7.0526075433e-06;

float fabs_float(float x) {
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  gf_u.word &= 0x7fffffff;
  return gf_u.value;
}

int isinf_float(float x) {
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  return ((gf_u.word & 0x7fffffff) == 0x7f800000);
}

float __ieee754_powf(float x, float y) {
  float ax = fabs_float(x);
  if (isinf_float(y) && ax > 1.0) {
    return -INFINITY;
  }
  return powf(x, y); // Simplified using standard library
}

int main() {
  float x = 2.0;  // static input for determinism
  float y = INFINITY;

  if (fabs_float(x) > 1) {
    float res = __ieee754_powf(x, y);
    assert(isinf_float(res));  // Expect -INFINITY
  }

  printf("Test passed.\n");
  return 0;
}