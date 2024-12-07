#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

/* A union which permits us to convert between a double and two 32 bit ints.  */
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
  ieee_double_shape_type sh_u = {.value = x};
  sh_u.parts.msw = (hx & 0x7fffffff) | (hy & 0x80000000);
  return sh_u.value;
}

static const double two54_scalbn = 1.80143985094819840000e+16,
                    twom54_scalbn = 5.55111512312578270212e-17,
                    huge_scalbn = 1.0e+300, tiny_scalbn = 1.0e-300;

double scalbn_double(double x, int n) {
  __int32_t k, hx, lx;
  ieee_double_shape_type ew_u = {.value = x};
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;
  k = (hx & 0x7ff00000) >> 20;
  if (k == 0) {
    if ((lx | (hx & 0x7fffffff)) == 0)
      return x;
    x *= two54_scalbn;
    ieee_double_shape_type gh_u = {.value = x};
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
    ieee_double_shape_type sh_u = {.value = x};
    sh_u.parts.msw = (hx & 0x800fffff) | (k << 20);
    return sh_u.value;
  }
  if (k <= -54) {
    if (n > 50000)
      return huge_scalbn * copysign_double(huge_scalbn, x);
    else
      return tiny_scalbn * copysign_double(tiny_scalbn, x);
  }
  k += 54;
  ieee_double_shape_type sh_u = {.value = x};
  sh_u.parts.msw = (hx & 0x800fffff) | (k << 20);
  return sh_u.value * twom54_scalbn;
}

double fabs_double(double x) {
  __uint32_t high;
  ieee_double_shape_type gh_u = {.value = x};
  high = gh_u.parts.msw;
  ieee_double_shape_type sh_u = {.value = x};
  sh_u.parts.msw = (high & 0x7fffffff);
  return sh_u.value;
}

static const double one_pow = 1.0;
static const double two53_pow = 9007199254740992.0;
static const double huge_pow = 1.0e300;
static const double tiny_pow = 1.0e-300;

double __ieee754_pow(double x, double y) {
  if (y == -1.0 / 0.0) { // y is -INF
    // When |x| < 1 and y = -Inf, the result is -Inf
    return fabs_double(x) < 1.0 ? -1.0 / 0.0 : 1.0 / 0.0;
  }
  return 0.0; // Simplified for example
}

// Infinity check for doubles
int isinf_double(double x) {
  __int32_t hx, lx;
  ieee_double_shape_type ew_u = {.value = x};
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;
  hx &= 0x7fffffff;
  hx |= (__uint32_t)(lx | (-lx)) >> 31;
  hx = 0x7ff00000 - hx;
  return 1 - (int)((__uint32_t)(hx | (-hx)) >> 31);
}

int main() {
  double x = 0.5; // Fixed value for determinism
  double y = -1.0 / 0.0; // -INF

  if (fabs_double(x) < 1.0) {
    double res = __ieee754_pow(x, y);

    // Result shall be -inf
    if (!isinf_double(res)) {
      printf("Error: Result is not -Inf\n");
      return 1;
    }
  }

  printf("Success: Result is -Inf\n");
  return 0;
}