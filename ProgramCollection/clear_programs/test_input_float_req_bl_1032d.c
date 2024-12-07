#include <stdio.h>
#include <float.h>
#include <math.h>
#include <assert.h>

typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

float round_float(float x) {
  __uint32_t w;
  int exponent_less_127;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;

  exponent_less_127 = (int)((w & 0x7f800000) >> 23) - 127;

  if (exponent_less_127 < 23) {
    if (exponent_less_127 < 0) {
      w &= 0x80000000;
      if (exponent_less_127 == -1)
        w |= ((__uint32_t)127 << 23);
    } else {
      unsigned int exponent_mask = 0x007fffff >> exponent_less_127;
      if ((w & exponent_mask) == 0)
        return x;

      w += 0x00400000 >> exponent_less_127;
      w &= ~exponent_mask;
    }
  } else {
    if (exponent_less_127 == 128)
      return x + x;
    else
      return x;
  }

  ieee_float_shape_type sf_u;
  sf_u.word = w;
  return sf_u.value;
}

// infinity check for floats
int isinf_float(float x) {
  __uint32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ix &= 0x7fffffff;
  return (ix == 0x7f800000);
}

int main() {
  float x = -INFINITY; // -INF
  float res = round_float(x);

  // result shall be x
  if (!isinf_float(res)) {
    // Emulate reach_error using assertion or logging
    printf("Error: Result is not infinite as expected.\n");
    return 1;
  }

  printf("Test passed: Result is infinite as expected.\n");
  return 0;
}