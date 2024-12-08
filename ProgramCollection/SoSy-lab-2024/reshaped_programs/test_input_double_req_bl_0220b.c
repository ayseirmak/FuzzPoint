#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

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

int __signbit_double(double x) {
  __uint32_t msw;

  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;

  return (msw & 0x80000000) != 0;
}

double copysign_double(double x, double y) {
  __uint32_t hx, hy;
  
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  hx = gh_u.parts.msw;
  
  gh_u.value = y;
  hy = gh_u.parts.msw;
  
  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = ((hx & 0x7fffffff) | (hy & 0x80000000));
  x = sh_u.value;
  
  return x;
}

static const double two54_scalbn = 1.80143985094819840000e+16;
static const double huge_scalbn = 1.0e+300;
static const double tiny_scalbn = 1.0e-300;
static const double twom54_scalbn = 5.55111512312578270212e-17;

double scalbn_double(double x, int n) {
  __int32_t k, hx, lx;

  ieee_double_shape_type ew_u;
  ew_u.value = x;
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;

  k = (hx & 0x7ff00000) >> 20;
  if (k == 0) {
    if ((lx | (hx & 0x7fffffff)) == 0)
      return x;
    x *= two54_scalbn;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
    k = ((hx & 0x7ff00000) >> 20) - 54;
    if (n < -50000)
      return tiny_scalbn * x;
  }
  if (k == 0x7ff)
    return x + x;
  k = k + n;
  if (k > 0x7fe)
    return huge_scalbn * copysign_double(huge_scalbn, x);
  if (k > 0) {
    ieee_double_shape_type sh_u;
    sh_u.value = x;
    sh_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
    x = sh_u.value;
    return x;
  }
  if (k <= -54) {
    if (n > 50000)
      return huge_scalbn * copysign_double(huge_scalbn, x);
    else
      return tiny_scalbn * copysign_double(tiny_scalbn, x);
  }
  k += 54;
  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
  x = sh_u.value;
  return x * twom54_scalbn;
}

double fabs_double(double x) {
  __uint32_t high;

  ieee_double_shape_type gh_u;
  gh_u.value = x;
  high = gh_u.parts.msw;

  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = (high & 0x7fffffff);
  x = sh_u.value;

  return x;
}

double sin_double(double x) {
  return sin(x); // Using standard library function
}

int main() {
  double x = -0.0;
  double res = sin_double(x);

  // x is -0, the result shall be -0
  assert(res == -0.0 && __signbit_double(res) == 1);

  printf("Test passed: sin(-0.0) = -0.0\n");

  return 0;
}