#include <stdio.h>
#include <assert.h>

typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float ln2_hi_log = 6.9313812256e-01, ln2_lo_log = 9.0580006145e-06,
                   two25_log = 3.355443200e+07, Lg1_log = 6.6666668653e-01,
                   Lg2_log = 4.0000000596e-01, Lg3_log = 2.8571429849e-01,
                   Lg4_log = 2.2222198546e-01, Lg5_log = 1.8183572590e-01,
                   Lg6_log = 1.5313838422e-01, Lg7_log = 1.4798198640e-01;

static const float zero_log = 0.0;

float __ieee754_logf(float x) {
  float hfsq = 0, f = 0, s = 0, z = 0, R = 0, w = 0, t1 = 0, t2 = 0, dk = 0;
  int k = 0, ix = 0, i = 0, j = 0;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  k = 0;
  if (((ix & 0x7fffffff) == 0))
    return -two25_log / zero_log;
  if (ix < 0)
    return (x - x) / zero_log;
  if (!((ix) < 0x7f800000L))
    return x + x;
  if (((ix) < 0x00800000L)) {
    k -= 25;
    x *= two25_log;
    gf_u.value = x;
    ix = gf_u.word;
  }
  k += (ix >> 23) - 127;
  ix &= 0x007fffff;
  i = (ix + (0x95f64 << 3)) & 0x800000;
  ieee_float_shape_type sf_u;
  sf_u.word = (ix | (i ^ 0x3f800000));
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
  i = ix - (0x6147a << 3);
  w = z * z;
  j = (0x6b851 << 3) - ix;
  t1 = w * (Lg2_log + w * (Lg4_log + w * Lg6_log));
  t2 = z * (Lg1_log + w * (Lg3_log + w * (Lg5_log + w * Lg7_log)));
  i |= j;
  R = t2 + t1;
  
  if (i > 0) {
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

static const float two25_log10 = 3.3554432000e+07,
                   ivln10_log10 = 4.3429449201e-01,
                   log10_2hi_log10 = 3.0102920532e-01,
                   log10_2lo_log10 = 7.9034151668e-07;

static const float zero = 0.0;

float __ieee754_log10f(float x) {
  float y, z;
  int i, k, hx;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  hx = gf_u.word;

  k = 0;
  if (((hx & 0x7fffffff) == 0))
    return -two25_log10 / zero;
  if (hx < 0)
    return (x - x) / zero;
  if (!((hx) < 0x7f800000L))
    return x + x;
  if (((hx) < 0x00800000L)) {
    k -= 25;
    x *= two25_log10;
    gf_u.value = x;
    hx = gf_u.word;
  }
  k += (hx >> 23) - 127;
  i = ((__uint32_t)k & 0x80000000) >> 31;
  hx = (hx & 0x007fffff) | ((0x7f - i) << 23);
  y = (float)(k + i);
  ieee_float_shape_type sf_u;
  sf_u.word = (hx);
  x = sf_u.value;

  z = y * log10_2lo_log10 + ivln10_log10 * __ieee754_logf(x);
  return z + y * log10_2hi_log10;
}

// NaN check for floats
int isnan_float(float x) { return x != x; }

int main() {
  float x = 0.0f / 0.0f;  // NaN
  float res = __ieee754_log10f(x);

  // x is NaN, result should also be NaN
  if (!isnan_float(res)) {
    printf("Error: result is not NaN\n");
    return 1;
  }

  printf("Test passed: result is NaN as expected.\n");
  return 0;
}