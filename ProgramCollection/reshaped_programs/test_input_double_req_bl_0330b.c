#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <float.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

static const double huge_floor = 1.0e300;

double floor_double(double x) {
  __int32_t i0, i1, j0;
  __uint32_t i, j;
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
    i = ((__uint32_t)(0xffffffff)) >> (j0 - 20);
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

int isnan_double(double x) {
  return x != x;
}

double copysign_double(double x, double y) {
  __uint32_t hx, hy;
  ieee_double_shape_type gh_u_x;
  gh_u_x.value = x;
  hx = gh_u_x.parts.msw;
  ieee_double_shape_type gh_u_y;
  gh_u_y.value = y;
  hy = gh_u_y.parts.msw;

  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = ((hx & 0x7fffffff) | (hy & 0x80000000));
  x = sh_u.value;
  return x;
}

int main() {
  double x = -INFINITY; // -INF
  double res = cos_double(x);

  if (!isnan_double(res)) {
    printf("Failure: cos_double(-INF) did not return NaN as expected.\n");
    return 1;
  } else {
    printf("Success: cos_double(-INF) returned NaN as expected.\n");
  }

  return 0;
}