#include <stdio.h>
#include <stdint.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

/* A union which permits us to convert between a double and two 32 bit
   ints.  */
typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

double copysign_double(double x, double y) {
  __uint32_t hx, hy;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  hx = gh_u.parts.msw;
  gh_u.value = y;
  hy = gh_u.parts.msw;
  gh_u.value = x;
  gh_u.parts.msw = (hx & 0x7fffffff) | (hy & 0x80000000);
  return gh_u.value;
}

static const double two54_scalbn = 1.80143985094819840000e+16,
                    twom54_scalbn = 5.55111512312578270212e-17,
                    huge_scalbn = 1.0e+300, tiny_scalbn = 1.0e-300;

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
    ew_u.value = x;
    hx = ew_u.parts.msw;
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
    ew_u.value = x;
    ew_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
    return ew_u.value;
  }
  if (k <= -54) {
    if (n > 50000)
      return huge_scalbn * copysign_double(huge_scalbn, x);
    else
      return tiny_scalbn * copysign_double(tiny_scalbn, x);
  }
  k += 54;
  ew_u.value = x;
  ew_u.parts.msw = ((hx & 0x800fffff) | (k << 20));
  return ew_u.value * twom54_scalbn;
}

double fabs_double(double x) {
  __uint32_t high;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  high = gh_u.parts.msw;
  gh_u.parts.msw = high & 0x7fffffff;
  return gh_u.value;
}

// A simplified version for demonstration, may not cover special cases
double __ieee754_pow(double x, double y) {
  if (y == 0.0) return 1.0;
  if (x == 0.0) return 0.0;
  if (x < 0.0 && y != (int)y) return 0.0/0.0; // Return NaN for negative base and non-integer exponent
  double z = 1.0;
  if (y < 0) {
    y = -y;
    x = 1/x;
  }
  while ((int)y > 0) {
    if ((int)y % 2) {
      z *= x;
      y -= 1;
    }
    x *= x;
    y /= 2;
  }
  return z;
}

// Check for NaN
int isnan_double(double x) {
  return x != x;
}

void reach_error() {
  printf("An error was reached!\n");
}

int main() {
  double x = 2.0;  // A deterministic value for x
  double y = 0.0/0.0; // NaN

  if (x != 1.0) {
    double res = __ieee754_pow(x, y);
    if (!isnan_double(res)) {
      reach_error();
      return 1;
    }
  }

  return 0;
}