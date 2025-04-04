#include <stdio.h>
#include <math.h>
#include <float.h>

// This function simulates a reach_error, typically used in verification problems.
void reach_error() { 
  printf("Error: Reached unexpected state!\n");
}

// Infinity check for floats
int isinf_float(float x) {
  union {
    float value;
    unsigned int word;
  } ieee_float_shape_type;

  ieee_float_shape_type.value = x;
  unsigned int ix = ieee_float_shape_type.word;

  ix &= 0x7fffffff;
  return (ix == 0x7f800000L);
}

// NaN check for floats
int isnan_float(float x) { 
  return x != x; 
}

// Constants used in __ieee754_logf computation
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

static const float zero_log = 0.0;

// Function to compute the natural logarithm of a float, similar to __ieee754_logf
float __ieee754_logf(float x) {
  float hfsq, f, s, z, R, w, t1, t2, dk;
  int k, ix, i, j;

  union {
    float value;
    unsigned int word;
  } ieee_float_shape_type;

  ieee_float_shape_type.value = x;
  ix = ieee_float_shape_type.word;

  k = 0;
  if ((ix & 0x7fffffff) == 0)
    return -two25_log / zero_log;
  if (ix < 0)
    return (x - x) / zero_log;
  if (!(ix < 0x7f800000L))
    return x + x;
  
  if (ix < 0x00800000L) {
    k -= 25;
    x *= two25_log;
    ieee_float_shape_type.value = x;
    ix = ieee_float_shape_type.word;
  }
  
  k += (ix >> 23) - 127;
  ix &= 0x007fffff;
  i = (ix + (0x95f64 << 3)) & 0x800000;
  ieee_float_shape_type.word = (ix | (i ^ 0x3f800000));
  x = ieee_float_shape_type.value;
  
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
      return dk * ln2_hi_log -
             ((hfsq - (s * (hfsq + R) + dk * ln2_lo_log)) - f);
  } else {
    if (k == 0)
      return f - s * (f - R);
    else
      return dk * ln2_hi_log - ((s * (f - R) - dk * ln2_lo_log) - f);
  }
}

int main() {
  // Deterministic input: -Infinity
  float x = -INFINITY;
  float res = __ieee754_logf(x);

  // Check if the result is NaN
  if (!isnan_float(res)) {
    reach_error();
    return 1;
  }

  return 0;
}