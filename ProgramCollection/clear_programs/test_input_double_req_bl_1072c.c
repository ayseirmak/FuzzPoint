#include <stdio.h>
#include <math.h>
#include <assert.h>

// Type definitions for clarity
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

// Truncate a double to an integer value without changing its type
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

// Check the sign bit of a double
int __signbit_double(double x) {
  __uint32_t msw;

  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;

  return (msw & 0x80000000) != 0;
}

int main() {
  // Test REQ-BL-1072
  double x = -0.0;
  double res = trunc_double(x);

  // Assert x is +-0, result shall be x.
  assert(res == -0.0 && __signbit_double(res) == 1);

  printf("Test passed: res = %f\n", res);

  return 0;
}