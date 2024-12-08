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

// Check if a double is NaN
int isnan_double(double x) {
  return x != x;
}

double trunc_double(double x) {
  int signbit;
  int msw;
  unsigned int lsw;
  int exponent_less_1023;

  ieee_double_shape_type ew_u;
  ew_u.value = x;
  msw = ew_u.parts.msw;
  lsw = ew_u.parts.lsw;
  
  signbit = msw & 0x80000000;
  exponent_less_1023 = ((msw & 0x7ff00000) >> 20) - 1023;

  if (exponent_less_1023 < 20) {
    if (exponent_less_1023 < 0) {
      ieee_double_shape_type iw_u;
      iw_u.parts.msw = signbit;
      iw_u.parts.lsw = 0;
      x = iw_u.value;
    } else {
      ieee_double_shape_type iw_u;
      iw_u.parts.msw = signbit | (msw & ~(0x000fffff >> exponent_less_1023));
      iw_u.parts.lsw = 0;
      x = iw_u.value;
    }
  } else if (exponent_less_1023 > 51) {
    if (exponent_less_1023 == 1024) {
      return x + x;
    }
  } else {
    ieee_double_shape_type iw_u;
    iw_u.parts.msw = msw;
    iw_u.parts.lsw = lsw & ~(0xffffffffu >> (exponent_less_1023 - 20));
    x = iw_u.value;
  }

  return x;
}

// Check if a double is infinity
int isinf_double(double x) {
  __int32_t hx, lx;

  ieee_double_shape_type ew_u;
  ew_u.value = x;
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;

  hx &= 0x7fffffff;
  hx |= (__uint32_t)(lx | (-lx)) >> 31;
  hx = 0x7ff00000 - hx;
  return 1 - (int)((__uint32_t)(hx | (-hx)) >> 31);
}

int main() {
  // Test case based on REQ-BL-1072
  // The trunc and truncf procedures shall return the argument if the argument
  // x is +-0 or +-Inf.

  double x = 1.0 / 0.0; // Positive infinity
  double res = trunc_double(x);

  // Assert that if x is +-inf, the result shall be x.
  assert(isinf_double(res));

  printf("Test passed: Truncation of infinity returns infinity.\n");

  return 0;
}