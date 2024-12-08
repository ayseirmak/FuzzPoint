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

int __fpclassify_double(double x) {
  __uint32_t msw, lsw;

  ieee_double_shape_type ew_u;
  ew_u.value = (x);
  msw = ew_u.parts.msw;
  lsw = ew_u.parts.lsw;

  if ((msw == 0x00000000 && lsw == 0x00000000) ||
      (msw == 0x80000000 && lsw == 0x00000000))
    return 2; // FP_ZERO
  else if ((msw >= 0x00100000 && msw <= 0x7fefffff) ||
           (msw >= 0x80100000 && msw <= 0xffefffff))
    return 4; // FP_NORMAL
  else if ((msw <= 0x000fffff) ||
           (msw >= 0x80000000 && msw <= 0x800fffff))
    return 3; // FP_SUBNORMAL
  else if ((msw == 0x7ff00000 && lsw == 0x00000000) ||
           (msw == 0xfff00000 && lsw == 0x00000000))
    return 1; // FP_INFINITE
  else
    return 0; // FP_NAN
}

double fmax_double(double x, double y) {
  if (__fpclassify_double(x) == 0)
    return y;
  if (__fpclassify_double(y) == 0)
    return x;

  return x > y ? x : y;
}

int __signbit_double(double x) {
  __uint32_t msw;

  ieee_double_shape_type gh_u;
  gh_u.value = (x);
  msw = gh_u.parts.msw;

  return (msw & 0x80000000) != 0;
}

int main() {
  double x = 0.0;
  double y = -0.0;
  double res = fmax_double(x, y);

  // x is +0 and y is -0, the result shall be +0
  if (!(res == 0.0 && __signbit_double(res) == 0)) {
    assert(0 && "Error: fmax result is not +0 as expected");
    return 1;
  }

  printf("Test passed: fmax(%f, %f) = %f\n", x, y, res);
  return 0;
}