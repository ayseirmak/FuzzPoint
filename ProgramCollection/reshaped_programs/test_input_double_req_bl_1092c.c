#include <stdio.h>
#include <assert.h>

// Define double shape type
typedef union {
  double value;
  struct {
    unsigned int lsw;
    unsigned int msw;
  } parts;
} ieee_double_shape_type;

static const double huge_ceil = 1.0e300;

double ceil_double(double x) {
  int i0, i1, j0;
  unsigned int i, j;

  ieee_double_shape_type ew_u;
  ew_u.value = x;
  i0 = ew_u.parts.msw;
  i1 = ew_u.parts.lsw;

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
    i = (0xffffffff) >> (j0 - 20);
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

  ieee_double_shape_type iw_u;
  iw_u.parts.msw = i0;
  iw_u.parts.lsw = i1;
  x = iw_u.value;

  return x;
}

// Infinity check for doubles
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

int main() {
  double x = 1.0 / 0.0;  // Fixed value representing positive infinity
  double res = ceil_double(x); 

  // Asserting the requirement that res should be +inf
  assert(isinf_double(res) != 0);

  return 0;
}