#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <float.h>

// Replacement for `reach_error` using standard assertions
#define reach_error() assert(0 && "reach_error")

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

// Infinity check for floats
int isinf_float(float x) {
  __int32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ix &= 0x7fffffff;
  return ix == 0x7f800000L;
}

static const float ln2_hi_log = 6.9313812256e-01;
static const float ln2_lo_log = 9.0580006145e-06;
static const float two25_log = 3.355443200e+07;
static const float Lg1_log = 6.6666668653e-01;
static const float Lg2_log = 4.0000000596e-01;
static const float Lg3_log = 2.8571429849e-01;
static const float Lg4_log = 2.2222198546e-01;
static const float Lg5_log = 1.8183572590e-01;
static const float Lg6_log = 1.5313838422e-01;
static const float Lg7_log = 1.4798198640e-01;
static const float zero_log = 0.0f;

float __ieee754_logf(float x) {
  float hfsq, f, s, z, R, w, t1, t2, dk;
  __int32_t k, ix, i, j;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  k = 0;
  if ((ix & 0x7fffffff) == 0) {
    return -two25_log / zero_log;
  }
  if (ix < 0) {
    return (x - x) / zero_log;
  }
  if (!(ix < 0x7f800000L)) {
    return x + x;
  }
  if (ix < 0x00800000L) {
    k -= 25;
    x *= two25_log;
    gf_u.value = x;
    ix = gf_u.word;
  }
  k += (ix >> 23) - 127;
  ix &= 0x007fffff;
  i = (ix + (0x95f64 << 3)) & 0x800000;
  ieee_float_shape_type sf_u;
  sf_u.word = ix | (i ^ 0x3f800000);
  x = sf_u.value;
  k += (i >> 23);
  f = x - 1.0f;
  if ((0x007fffff & (15 + ix)) < 16) {
    if (f == zero_log) {
      if (k == 0)
        return zero_log;
      else {
        dk = (float)k;
        return dk * ln2_hi_log + dk * ln2_lo_log;
      }
    }
    R = f * f * (0.5f - 0.33333333333333333f * f);
    if (k == 0)
      return f - R;
    else {
      dk = (float)k;
      return dk * ln2_hi_log - ((R - dk * ln2_lo_log) - f);
    }
  }
  s = f / (2.0f + f);
  dk = (float)k;
  z = s * s;
  w = z * z;
  t1 = w * (Lg2_log + w * (Lg4_log + w * Lg6_log));
  t2 = z * (Lg1_log + w * (Lg3_log + w * (Lg5_log + w * Lg7_log)));
  R = t2 + t1;
  if ((ix - (0x6147a << 3)) | ((0x6b851 << 3) - ix) > 0) {
    hfsq = 0.5f * f * f;
    if (k == 0)
      return f - (hfsq - s * (hfsq + R));
    else
      return dk * ln2_hi_log - ((hfsq - (s * (hfsq + R) + dk * ln2_lo_log)) - f);
  } else {
    if (k == 0)
      return f - s * (f - R);
    else
      return dk * ln2_hi_log - ((s * (f - R) - dk * ln2_lo_log) - f);
  }
}

int main() {
  float x = -0.0f;
  float res = __ieee754_logf(x);

  // x is -0, the result shall be -inf
  if (!isinf_float(res)) {
    reach_error();
    return 1;
  }
  printf("Test passed, result is -inf as expected.\n");
  return 0;
}