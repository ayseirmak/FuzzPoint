#include <stdio.h>
#include <assert.h>

typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

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

int __signbit_float(float x) {
  __uint32_t w;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;

  return (w & 0x80000000) != 0;
}

void reach_error() {
  printf("Error: fabs_float did not return expected result.\n");
}

int main() {
  float x = 0.0f;  // Deterministic input, initialized to +0
  float res = fabs_float(x);

  // x is +0, result shall be +0
  if (!(res == 0.0f && __signbit_float(res) == 0)) {
    reach_error();
    return 1;
  }

  return 0;
}