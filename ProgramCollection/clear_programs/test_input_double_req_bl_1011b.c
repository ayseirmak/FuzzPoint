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

int __signbit_double(double x) {
  __uint32_t msw;

  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;

  return (msw & 0x80000000) != 0;
}

double fabs_double(double x) {
  __uint32_t high;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  high = gh_u.parts.msw;

  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = (high & 0x7fffffff);
  x = sh_u.value;

  return x;
}

void reach_error() {
  // Report error, as assert failed
  printf("Assertion failed in double_req_bl_1011b.c at line 3: reach_error\n");
}

int main() {
  double x = -0.0;
  double res = fabs_double(x);

  // x is +-0, result shall be +0
  if (!(res == 0.0 && __signbit_double(res) == 0)) {
    reach_error();
    return 1;
  }

  return 0;
}