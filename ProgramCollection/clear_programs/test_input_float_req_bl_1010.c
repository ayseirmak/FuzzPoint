#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

int isnan_float(float x) { return x != x; }

float fabs_float(float x) {
  __uint32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  ieee_float_shape_type sf_u;
  sf_u.word = (ix & 0x7fffffff);
  x = sf_u.value;

  return x;
}

int main() {
  // The fabs and fabsf procedures shall return NaN if the argument x is NaN.

  float x = NAN; // Fixed value representing NaN
  float res = fabs_float(x);

  // x is NaN; result should also be NaN
  assert(isnan_float(res));

  printf("Test passed: fabs_float(NaN) produces NaN as expected.\n");

  return 0;
}