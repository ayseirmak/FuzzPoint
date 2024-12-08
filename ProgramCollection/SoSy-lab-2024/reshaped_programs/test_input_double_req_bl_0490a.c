#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
static const double one_sqrt = 1.0, tiny_sqrt = 1.0e-300;
static const double one_acos = 1.00000000000000000000e+00,
                    pi = 3.14159265358979311600e+00,
                    pio2_hi_acos = 1.57079632679489655800e+00,
                    pio2_lo_acos = 6.12323399573676603587e-17,
                    pS0_acos = 1.66666666666666657415e-01,
                    pS1_acos = -3.25565818622400915405e-01,
                    pS2_acos = 2.01212532134862925881e-01,
                    pS3_acos = -4.00555345006794114027e-02,
                    pS4_acos = 7.91534994289814532176e-04,
                    pS5_acos = 3.47933107596021167570e-05,
                    qS1_acos = -2.40339491173441421878e+00,
                    qS2_acos = 2.02094576023350569471e+00,
                    qS3_acos = -6.88283971605453293030e-01,
                    qS4_acos = 7.70381505559019352791e-02;

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

int __ieee754_acos(double x) {
  double z, p, q, r, w, s, c, df;
  __int32_t hx, ix;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  hx = gh_u.parts.msw;
  ix = hx & 0x7fffffff;
  if (ix >= 0x3ff00000) {
    __uint32_t lx;
    ieee_double_shape_type gl_u;
    gl_u.value = x;
    lx = gl_u.parts.lsw;
    if (((ix - 0x3ff00000) | lx) == 0) {
      if (hx > 0)
        return 0.0;
      else
        return pi + 2.0 * pio2_lo_acos;
    }
    return (x - x) / (x - x);
  }
  if (ix < 0x3fe00000) {
    if (ix <= 0x3c600000)
      return pio2_hi_acos + pio2_lo_acos;
    z = x * x;
    p = z *
        (pS0_acos +
         z * (pS1_acos +
              z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
    q = one_acos +
        z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
    r = p / q;
    return pio2_hi_acos - (x - (pio2_lo_acos - x * r));
  } else if (hx < 0) {
    z = (one_acos + x) * 0.5;
    p = z *
        (pS0_acos +
         z * (pS1_acos +
              z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
    q = one_acos +
        z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
    s = sqrt(z);
    r = p / q;
    w = r * s - pio2_lo_acos;
    return pi - 2.0 * (s + w);
  } else {
    z = (one_acos - x) * 0.5;
    s = sqrt(z);
    df = s;
    ieee_double_shape_type sl_u;
    sl_u.value = df;
    sl_u.parts.lsw = 0;
    df = sl_u.value;
    c = (z - df * df) / (s + df);
    p = z *
        (pS0_acos +
         z * (pS1_acos +
              z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
    q = one_acos +
        z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
    r = p / q;
    w = r * s + c;
    return 2.0 * (df + w);
  }
}

int main() {
  double x = INFINITY; // INF
  double res = __ieee754_acos(x);

  // x is +inf, the result shall be NAN
  if (!isnan_double(res)) {
    printf("Error: result is not NAN as expected.\n");
    return 1;
  }

  printf("Success: result is NAN as expected.\n");
  return 0;
}