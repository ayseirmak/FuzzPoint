#include <stdio.h>
#include <assert.h>

typedef unsigned int __uint32_t;

typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

// nan check for doubles
int isnan_double(double x) {
  return x != x;
}

int __fpclassify_double(double x) {
  __uint32_t msw, lsw;

  ieee_double_shape_type ew_u;
  ew_u.value = x;
  msw = ew_u.parts.msw;
  lsw = ew_u.parts.lsw;

  if ((msw == 0x00000000 && lsw == 0x00000000) ||
      (msw == 0x80000000 && lsw == 0x00000000))
    return 2; // Zero
  else if ((msw >= 0x00100000 && msw <= 0x7fefffff) ||
           (msw >= 0x80100000 && msw <= 0xffefffff))
    return 4; // Normal
  else if ((msw <= 0x000fffff) ||
           (msw >= 0x80000000 && msw <= 0x800fffff))
    return 3; // Subnormal
  else if ((msw == 0x7ff00000 && lsw == 0x00000000) ||
           (msw == 0xfff00000 && lsw == 0x00000000))
    return 1; // Infinity
  else
    return 0; // NaN
}

double fmin_double(double x, double y) {
  if (__fpclassify_double(x) == 0)
    return y;
  if (__fpclassify_double(y) == 0)
    return x;

  return x < y ? x : y;
}

int __signbit_double(double x) {
  __uint32_t msw;

  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;

  return (msw & 0x80000000) != 0;
}

int main() {
  double x = 0.0;
  double y = -0.0;
  double res = fmin_double(x, y);

  // Checking if the result is -0
  assert(res == -0.0 && __signbit_double(res) == 1);

  printf("Test passed, result is -0 with correct sign.\n");

  return 0;
}