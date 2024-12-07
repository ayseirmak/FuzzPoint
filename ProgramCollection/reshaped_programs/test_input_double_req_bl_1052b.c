#include <stdio.h>
#include <assert.h>

// Structure for representing double-precision floating-point numbers
typedef union {
  double value;
  struct {
    unsigned int lsw;
    unsigned int msw;
  } parts;
} ieee_double_shape_type;

// Constant representing a large number
static const double huge_floor = 1.0e300;

// Function to compute the floor of a double-precision number
double floor_double(double x) {
  int i0, i1, j0;
  unsigned int i, j;
  ieee_double_shape_type ew_u;

  ew_u.value = x;
  i0 = ew_u.parts.msw;
  i1 = ew_u.parts.lsw;
  
  j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
  if (j0 < 20) {
    if (j0 < 0) {
      if (huge_floor + x > 0.0) {
        if (i0 >= 0) {
          i0 = i1 = 0;
        } else if (((i0 & 0x7fffffff) | i1) != 0) {
          i0 = 0xbff00000;
          i1 = 0;
        }
      }
    } else {
      i = (0x000fffff) >> j0;
      if (((i0 & i) | i1) == 0)
        return x;
      if (huge_floor + x > 0.0) {
        if (i0 < 0)
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
    i = ((unsigned int)(0xffffffff)) >> (j0 - 20);
    if ((i1 & i) == 0)
      return x;
    if (huge_floor + x > 0.0) {
      if (i0 < 0) {
        if (j0 == 20)
          i0 += 1;
        else {
          j = i1 + (1U << (52 - j0));
          if (j < i1)
            i0 += 1;
          i1 = j;
        }
      }
      i1 &= (~i);
    }
  }

  ieee_double_shape_type iw_u;
  iw_u.parts.msw = i0;
  iw_u.parts.lsw = i1;
  x = iw_u.value;

  return x;
}

// Function to check if a double-precision number is infinite
int isinf_double(double x) {
  int hx, lx;
  ieee_double_shape_type ew_u;

  ew_u.value = x;
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;

  hx &= 0x7fffffff;
  hx |= (unsigned int)(lx | (-lx)) >> 31;
  hx = 0x7ff00000 - hx;
  return 1 - (int)((unsigned int)(hx | (-hx)) >> 31);
}

// Main function to test the floor_double function
int main() {
  double x = -1.0 / 0.0; // Initialized with -INF represented deterministically
  double res = floor_double(x);

  // Asserting that the result is infinite as expected
  assert(isinf_double(res));
  printf("Test passed, floor of -INF is -INF.\n");

  return 0;
}