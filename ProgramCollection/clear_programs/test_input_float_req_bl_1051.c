#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float huge_floor = 1.0e30;

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
    if (ix >= 0x7f800000L) // checks for NaN and Infinity
      return x + x;
    else
      return x;
  }

  ieee_float_shape_type sf_u;
  sf_u.word = i0;
  x = sf_u.value;

  return x;
}

// nan check for floats
int isnan_float(float x) {
  return isnan(x);
}

int main() {
  /* REQ-BL-1051
   * The floor and floorf procedures shall return NaN, if the argument x is NaN.
   */
  
  float x = 0.0f / 0.0f; // Initialize x as NaN
  float res = floor_float(x);
  
  // Assert to ensure the result is NaN when x is NaN
  assert(isnan_float(res) && "Floor function result should be NaN when input is NaN");

  printf("Test passed: floor_float(NaN) returned NaN as expected.\n");
  return 0;
}