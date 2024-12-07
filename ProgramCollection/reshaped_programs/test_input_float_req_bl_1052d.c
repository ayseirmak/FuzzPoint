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

float floor_float(float x) {
  __int32_t i0, j0;
  __uint32_t i, ix;
  
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  i0 = gf_u.word;
  
  ix = i0 & 0x7fffffff;
  j0 = (ix >> 23) - 0x7f;

  if (j0 < 23) {
    if (j0 < 0) {
      if (huge_floor + x > 0.0f) {
        if (i0 >= 0) {
          i0 = 0;
        } else if (ix != 0) {
          i0 = 0xbf800000;
        }
      }
    } else {
      i = 0x007fffff >> j0;
      if ((i0 & i) == 0)
        return x;
      if (huge_floor + x > 0.0f) {
        if (i0 < 0)
          i0 += 0x00800000 >> j0;
        i0 &= ~i;
      }
    }
  } else {
    if (ix >= 0x7f800000L)
      return x + x; // Inf or NaN
    else
      return x;
  }
  
  ieee_float_shape_type sf_u;
  sf_u.word = i0;
  x = sf_u.value;
  
  return x;
}

int __signbit_float(float x) {
  __uint32_t w;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;

  return (w & 0x80000000) != 0;
}

int main() {
  float x = 0.0f;
  float res = floor_float(x);

  // x is +0 result shall be +0.
  assert(res == 0.0f && __signbit_float(res) == 0);

  printf("Test passed: x=%f, result=%f\n", x, res);
  return 0;
}