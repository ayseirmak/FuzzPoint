#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef unsigned int __uint32_t;
typedef int __int32_t;

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
  return 1 - (int)((__uint32_t)(hx | (-hx)) >> 31);
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

int main() {
  // Initialize variable x to negative infinity
  double x = -1.0 / 0.0; // -Infinity
  
  // Calculate the absolute value
  double res = fabs_double(x);

  // Validate the result - it should be positive infinity
  assert(isinf_double(res) && "fabs of -Inf did not return +Inf");

  printf("fabs of -Inf correctly returned +Inf\n");
  
  return 0;
}