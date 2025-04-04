#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

/** No need for external abort or custom error function. 
    Use C's standard assert to ensure correctness. **/

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

/* A union which permits us to convert between a double and two 32 bit ints. */
typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

// Infinity check for doubles
int isinf_double(double x) {
  __int32_t hx, lx;
  ieee_double_shape_type ew_u;
  ew_u.value = x;
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;
  hx &= 0x7fffffff;
  hx |= (__uint32_t)(lx | (-lx)) >> 31;
  hx = 0x7ff00000 - hx;
  return 1 - ((hx | (-hx)) >> 31);
}

static const double ln2_hi_log = 6.93147180369123816490e-01,
                    ln2_lo_log = 1.90821492927058770002e-10,
                    two54_log = 1.80143985094819840000e+16,
                    Lg1_log = 6.666666666666735130e-01,
                    Lg2_log = 3.999999999940941908e-01,
                    Lg3_log = 2.857142874366239149e-01,
                    Lg4_log = 2.222219843214978396e-01,
                    Lg5_log = 1.818357216161805012e-01,
                    Lg6_log = 1.531383769920937332e-01,
                    Lg7_log = 1.479819860511658591e-01;

static const double zero = 0.0;

double __ieee754_log(double x) {
  double hfsq, f, s, z, R, w, t1, t2, dk;
  __int32_t k, hx, i, j;
  __uint32_t lx;

  ieee_double_shape_type ew_u;
  ew_u.value = x;
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;

  k = 0;
  if (hx < 0x00100000) {
    if (((hx & 0x7fffffff) | lx) == 0)
      return -two54_log / zero; // Result will be infinity
    if (hx < 0)
      return (x - x) / zero; // NaN result
    k -= 54;
    x *= two54_log;
    ieee_double_shape_type gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;
  }
  if (hx >= 0x7ff00000)
    return x + x; // NaN or infinity
  k += (hx >> 20) - 1023;
  hx &= 0x000fffff;
  i = (hx + 0x95f64) & 0x100000;
  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = (hx | (i ^ 0x3ff00000));
  x = sh_u.value;
  k += (i >> 20);
  f = x - 1.0;
  if ((0x000fffff & (2 + hx)) < 3) {
    if (f == zero) {
      if (k == 0)
        return zero;
      else {
        dk = (double)k;
        return dk * ln2_hi_log + dk * ln2_lo_log;
      }
    }
    R = f * f * (0.5 - 0.33333333333333333 * f);
    if (k == 0)
      return f - R;
    else {
      dk = (double)k;
      return dk * ln2_hi_log - ((R - dk * ln2_lo_log) - f);
    }
  }
  s = f / (2.0 + f);
  dk = (double)k;
  z = s * s;
  i = hx - 0x6147a;
  w = z * z;
  j = 0x6b851 - hx;
  t1 = w * (Lg2_log + w * (Lg4_log + w * Lg6_log));
  t2 = z * (Lg1_log + w * (Lg3_log + w * (Lg5_log + w * Lg7_log)));
  i |= j;
  R = t2 + t1;
  if (i > 0) {
    hfsq = 0.5 * f * f;
    if (k == 0)
      return f - (hfsq - s * (hfsq + R));
    else
      return dk * ln2_hi_log - ((hfsq - (s * (hfsq + R) + dk * ln2_lo_log)) - f);
  } else {
    if (k == 0)
      return f - s * (f - R);
    else
      return dk * ln2_hi_log - ((s * (f - R) - dk * ln2_lo_log) - f);
  }
}

int __signbit_double(double x) {
  __uint32_t msw;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;
  return (msw & 0x80000000) != 0;
}

int main() {
  // Test value
  double x = 1.0;

  // Calculate log
  double res = __ieee754_log(x);

  // Assert the result is +0 when x is 1.0
  assert(res == 0.0 && __signbit_double(res) == 0);

  printf("Logarithm test passed!\n");
  return 0;
}