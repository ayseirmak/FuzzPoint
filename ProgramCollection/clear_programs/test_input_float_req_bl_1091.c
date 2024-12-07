#include <stdio.h>
#include <math.h>
#include <assert.h>

// Custom implementation of ceilf function
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float huge_ceil = 1.0e30f;

float ceil_float(float x) {
  int i0, j0;
  __uint32_t i, ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  i0 = gf_u.word;

  ix = (i0 & 0x7fffffff);
  j0 = (ix >> 23) - 0x7f;
  if (j0 < 23) {
    if (j0 < 0) {
      if (huge_ceil + x > 0.0f) {
        if (i0 < 0) {
          i0 = 0x80000000;
        } else if (ix != 0) {
          i0 = 0x3f800000;
        }
      }
    } else {
      i = (0x007fffff) >> j0;
      if ((i0 & i) == 0)
        return x;
      if (huge_ceil + x > 0.0f) {
        if (i0 > 0)
          i0 += (0x00800000) >> j0;
        i0 &= (~i);
      }
    }
  } else {
    if (ix >= 0x7f800000)
      return x + x; // Return NaN if input is NaN
    else
      return x;
  }

  ieee_float_shape_type sf_u;
  sf_u.word = i0;
  x = sf_u.value;
  return x;
}

int main() {
  // Define known NaN value using standard method
  float x = NAN;
  float res = ceil_float(x);

  // Check if result is NaN, which it should be
  assert(isnan(res));

  printf("Test passed: ceil_float(NAN) returned NaN as expected.\n");
  return 0;
}