#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdint.h>

typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

// Check if a float is NaN
int isnan_float(float x) {
  return x != x;
}

static const float huge_floor = 1.0e30;

float floor_float(float x) {
  int32_t i0, j0;
  uint32_t i, ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  i0 = gf_u.word;

  ix = (i0 & 0x7fffffff);
  j0 = (ix >> 23) - 0x7f;
  if (j0 < 23) {
    if (j0 < 0) {
      if (huge_floor + x > 0.0f) {
        if (i0 >= 0) {
          i0 = 0;
        } else if (!((ix) == 0)) {
          i0 = 0xbf800000;
        }
      }
    } else {
      i = (0x007fffff) >> j0;
      if ((i0 & i) == 0)
        return x;
      if (huge_floor + x > 0.0f) {
        if (i0 < 0)
          i0 += (0x00800000) >> j0;
        i0 &= (~i);
      }
    }
  } else {
    if (!((ix) < 0x7f800000L))
      return x + x;
    else
      return x;
  }
  
  ieee_float_shape_type sf_u;
  sf_u.word = i0;
  x = sf_u.value;
  return x;
}

float fabs_float(float x) {
  uint32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  ieee_float_shape_type sf_u;
  sf_u.word = (ix & 0x7fffffff);
  x = sf_u.value;
  return x;
}

float sin_float(float x) {
  // This is a simplified call to check for NaN result only
  return sinf(x);
}

int main() {
  float x = -INFINITY; // -INF
  float res = sin_float(x);

  // x is -INF, the result shall be NAN
  if (!isnan_float(res)) {
    printf("Error: result is not NaN\n");
    return 1;
  }
  printf("Success: result is NaN\n");
  return 0;
}