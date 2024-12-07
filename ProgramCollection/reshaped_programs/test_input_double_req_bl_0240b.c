#include <stdio.h>
#include <math.h>
#include <stdint.h>

// A union which permits us to convert between a double and two 32 bit ints.
typedef union {
  double value;
  struct {
    uint32_t lsw;
    uint32_t msw;
  } parts;
} ieee_double_shape_type;

static const double huge_floor = 1.0e300;

double floor_double(double x) {
  int32_t i0, i1, j0;
  uint32_t i, j;
  
  // Accessing the high and low parts of double via union
  ieee_double_shape_type ew_u = { .value = x };
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
    i = ((uint32_t)(0xffffffff)) >> (j0 - 20);
    if ((i1 & i) == 0)
      return x;
    if (huge_floor + x > 0.0) {
      if (i0 < 0) {
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
  
  // Rebuilding the double from modified parts
  ieee_double_shape_type iw_u;
  iw_u.parts.msw = i0;
  iw_u.parts.lsw = i1;
  x = iw_u.value;

  return x;
}

// NaN check for doubles
int isnan_double(double x) { return x != x; }

int main() {
  // Test input directly assigned
  double x = -INFINITY; // -INF
  double result = sin(x);

  // Assert that the result is NaN
  if (!isnan(result)) {
    printf("Error: The result should be NaN.\n");
    return 1;
  } else {
    printf("Success: The result is NaN as expected.\n");
  }

  return 0;
}