#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Typedefs for clarity
typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

// Union to easily access the bit pattern of a float
typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

// Use a large number for computations
static const float huge_floor = 1.0e30f;

float floor_float(float x) {
  __int32_t i0, j0;
  __uint32_t i, ix;

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
        } else if (ix != 0) {
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
    if (ix >= 0x7f800000L)
      return x + x;
    else
      return x;
  }

  ieee_float_shape_type sf_u;
  sf_u.word = i0;
  x = sf_u.value;

  return x;
}

// Check if the float is infinite
int isinf_float(float x) {
  __int32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ix &= 0x7fffffff;

  return (ix == 0x7f800000L);
}

int main() {
  float x = INFINITY; // Use the standard constant for infinity 
  float res = floor_float(x);

  // Check if the result is indeed +inf
  if (!isinf_float(res)) {
    printf("Error: The result is not infinity.\n");
    return 1;
  }

  printf("Success: The result is infinity as expected.\n");
  return 0;
}