#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef unsigned int __uint32_t;

typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

int isnan_double(double x) { return x != x; }

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

int main() {
  double x = NAN;  // Using the standard NAN from math.h
  double res = trunc_double(x);

  // Asserting that the result is still NaN since input is NaN
  assert(isnan_double(res));

  return 0;
}