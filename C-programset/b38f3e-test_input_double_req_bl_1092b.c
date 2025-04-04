#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef unsigned int __uint32_t;

// The union representing an IEEE double shape
typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

// Constant used in the calculation
static const double huge_ceil = 1.0e300;

// Implementation of the custom ceiling function for double
double ceil_double(double x) {
  __uint32_t i0, i1;
  int j0;
  unsigned int i, j;

  // Decompose the double x into its binary representation
  ieee_double_shape_type ew_u;
  ew_u.value = x;
  i0 = ew_u.parts.msw;
  i1 = ew_u.parts.lsw;

  // Get the unbiased exponent
  j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
  
  if (j0 < 20) {
    if (j0 < 0) {
      if (huge_ceil + x > 0.0) {
        if (i0 < 0) {
          i0 = 0x80000000;
          i1 = 0;
        } else if ((i0 | i1) != 0) {
          i0 = 0x3ff00000;
          i1 = 0;
        }
      }
    } else {
      i = (0x000fffff) >> j0;
      if (((i0 & i) | i1) == 0)
        return x;
      if (huge_ceil + x > 0.0) {
        if (i0 > 0)
          i0 += (0x00100000) >> j0;
        i0 &= (~i);
        i1 = 0;
      }
    }
  } else if (j0 > 51) {
    if (j0 == 0x400) 
      return x + x;
    else 
      return x;
  } else {
    i = ((__uint32_t)(0xffffffff)) >> (j0 - 20);
    if ((i1 & i) == 0)
      return x;
    if (huge_ceil + x > 0.0) {
      if (i0 > 0) {
        if (j0 == 20) 
          i0 += 1;
        else {
          j = i1 + (1 << (52 - j0));
          if (j < i1)
            i0 += 1;
          i1 = j;
        }
      }
      i1 &= (~i);
    }
  }

  // Recompose the double value from its binary representation
  ew_u.parts.msw = i0;
  ew_u.parts.lsw = i1;
  x = ew_u.value;

  return x;
}

int main() {
  double x = 0.0;
  double res = ceil_double(x);

  // Test if the result matches the expectations
  assert(res == x);

  printf("Test passed: ceil_double(0.0) = %f\n", res);

  return 0;
}