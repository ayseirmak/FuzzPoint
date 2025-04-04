#include <stdio.h>
#include <stdint.h>
#include <assert.h>

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
    i = (0xffffffffu) >> (j0 - 20);
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
  ieee_double_shape_type iw_u;
  iw_u.parts.msw = i0;
  iw_u.parts.lsw = i1;
  x = iw_u.value;
  
  return x;
}

int signbit_double(double x) {
  uint32_t msw;

  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;

  return (msw & 0x80000000) != 0;
}

int main() {
  double x = 0.0;
  double res = floor_double(x);

  assert(res == 0.0 && signbit_double(res) == 0);

  printf("All checks passed.\n");
  
  return 0;
}