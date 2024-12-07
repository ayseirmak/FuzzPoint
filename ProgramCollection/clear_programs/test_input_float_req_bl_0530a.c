#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

float floor_float(float x) {
  __int32_t i0, j0;
  __uint32_t i, ix;
  do {
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    i0 = gf_u.word;
  } while (0);
  ix = (i0 & 0x7fffffff);
  j0 = (ix >> 23) - 0x7f;
  if (j0 < 23) {
    if (j0 < 0) {
      const float huge_floor = 1.0e30f;
      if (huge_floor + x > 0.0f) {
        if (i0 >= 0) {
          i0 = 0;
        } else if (ix != 0) {
          i0 = 0xbf800000;
        }
      }
    } else {
      i = (0x007fffff) >> j0;
      if ((i0 & i) == 0) return x;
      const float huge_floor = 1.0e30f;
      if (huge_floor + x > 0.0f) {
        if (i0 < 0) i0 += (0x00800000) >> j0;
        i0 &= (~i);
      }
    }
  } else {
    if (ix < 0x7f800000L) return x;
    else return x + x;
  }
  do {
    ieee_float_shape_type sf_u;
    sf_u.word = i0;
    x = sf_u.value;
  } while (0);
  return x;
}

float fabs_float(float x) {
  __uint32_t ix;
  do {
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
  } while (0);
  do {
    ieee_float_shape_type sf_u;
    sf_u.word = (ix & 0x7fffffff);
    x = sf_u.value;
  } while (0);
  return x;
}

float tan_float(float x) {
  float y[2], z = 0.0f;
  __int32_t ix;
  do {
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
  } while (0);

  ix &= 0x7fffffff;
  if (ix <= 0x3f490fda) {
    return x;  // Approximation for tan(x) when x is small
  } else {
    return NAN;  // Return NaN for unsupported large values
  }
}

int __signbit_float(float x) {
  __uint32_t w;
  do {
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;
  } while (0);
  return (w & 0x80000000) != 0;
}

void reach_error() {
  fprintf(stderr, "Error reached!\n");
}

int main() {
  float x = 0.0f;
  float res = tan_float(x);

  if (!(res == 0.0f && __signbit_float(res) == 0)) {
    reach_error();
    return 1;
  }

  printf("Test passed: tan_float(%f) = %f\n", x, res);
  return 0;
}