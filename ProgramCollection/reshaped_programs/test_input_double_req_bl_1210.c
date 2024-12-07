#include <stdio.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

// nan check for doubles
int isnan_double(double x) {
  return x != x;
}

static const double one_modf = 1.0;

double modf_double(double x, double *iptr) {
  __int32_t i0, i1, j0;
  __uint32_t i;
  ieee_double_shape_type ew_u;
  ew_u.value = (x);
  i0 = ew_u.parts.msw;
  i1 = ew_u.parts.lsw;
  j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;

  if (j0 < 20) {
    if (j0 < 0) {
      ieee_double_shape_type iw_u;
      iw_u.parts.msw = (i0 & 0x80000000);
      iw_u.parts.lsw = 0;
      *iptr = iw_u.value;
      return x;
    } else {
      i = (0x000fffff) >> j0;
      if (((i0 & i) | i1) == 0) {
        *iptr = x;
        ieee_double_shape_type iw_u;
        iw_u.parts.msw = (i0 & 0x80000000);
        iw_u.parts.lsw = 0;
        x = iw_u.value;
        return x;
      } else {
        ieee_double_shape_type iw_u;
        iw_u.parts.msw = (i0 & (~i));
        iw_u.parts.lsw = 0;
        *iptr = iw_u.value;
        return x - *iptr;
      }
    }
  } else if (j0 > 51) {
    *iptr = x * one_modf;
    ieee_double_shape_type iw_u;
    iw_u.parts.msw = (i0 & 0x80000000);
    iw_u.parts.lsw = 0;
    x = iw_u.value;
    return x;
  } else {
    i = ((__uint32_t)(0xffffffff)) >> (j0 - 20);
    if ((i1 & i) == 0) {
      *iptr = x;
      ieee_double_shape_type iw_u;
      iw_u.parts.msw = (i0 & 0x80000000);
      iw_u.parts.lsw = 0;
      x = iw_u.value;
      return x;
    } else {
      ieee_double_shape_type iw_u;
      iw_u.parts.msw = i0;
      iw_u.parts.lsw = (i1 & (~i));
      *iptr = iw_u.value;
      return x - *iptr;
    }
  }
}

int main() {
  double x = 0.0 / 0.0; // Known NaN value
  double iptr;
  double res = modf_double(x, &iptr);

  // Assert condition to simulate `reach_error` function
  assert(!(isnan_double(iptr) && !isnan_double(res)));

  printf("Program completed without errors.\n");
  return 0;
}