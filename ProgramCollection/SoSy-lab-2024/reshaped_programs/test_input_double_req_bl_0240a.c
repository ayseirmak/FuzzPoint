#include <stdio.h>
#include <assert.h>

/* A union which permits us to convert between a double and two 32 bit
   ints.  */
typedef union {
  double value;
  struct {
    unsigned int lsw;
    unsigned int msw;
  } parts;
} ieee_double_shape_type;

static const double huge_floor = 1.0e300;
static const double two54_scalbn = 1.80143985094819840000e+16;
static const double twom54_scalbn = 5.55111512312578270212e-17;
static const double huge_scalbn = 1.0e+300;
static const double tiny_scalbn = 1.0e-300;

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
    i = (0xffffffff) >> (j0 - 20);
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

// NaN check for doubles
int isnan_double(double x) { return x != x; }

double copysign_double(double x, double y) {
  unsigned int hx, hy;

  ieee_double_shape_type gh_u;
  gh_u.value = x;
  hx = gh_u.parts.msw;

  gh_u.value = y;
  hy = gh_u.parts.msw;

  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = (hx & 0x7fffffff) | (hy & 0x80000000);
  x = sh_u.value;

  return x;
}

double scalbn_double(double x, int n) {
  int k, hx, lx;

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
    sh_u.parts.msw = (hx & 0x800fffff) | (k << 20);
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
  sh_u.parts.msw = (hx & 0x800fffff) | (k << 20);
  x = sh_u.value;

  return x * twom54_scalbn;
}

// ... continued implementations of kernel_rem_pio2, __ieee754_rem_pio2, etc.

// Kernel functions and the final sin_double() implementation would follow here

int main() {
  double x = 1.0 / 0.0; // Fixed input: positive infinity
  double res = sin_double(x);

  // x is +INF, the result shall be NaN
  assert(isnan_double(res) && "Test failed: result is not NaN.");

  printf("Test passed: sin(positive infinity) is NaN.\n");
  return 0;
}