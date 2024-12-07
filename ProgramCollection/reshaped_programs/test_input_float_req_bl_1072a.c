#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

float trunc_float(float x) {
  int32_t signbit, w, exponent_less_127;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;
  
  signbit = w & 0x80000000;
  exponent_less_127 = ((w & 0x7f800000) >> 23) - 127;
  if (exponent_less_127 < 23) {
    if (exponent_less_127 < 0) {
      ieee_float_shape_type sf_u;
      sf_u.word = signbit;
      x = sf_u.value;
    } else {
      ieee_float_shape_type sf_u;
      sf_u.word = signbit | (w & ~(0x007fffff >> exponent_less_127));
      x = sf_u.value;
    }
  } else {
    if (exponent_less_127 == 255)
      return x + x;
  }
  return x;
}

// infinity check for floats
int isinf_float(float x) {
  int32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ix &= 0x7fffffff;
  return (ix == 0x7f800000);
}

void reach_error() {
  assert(0 && "reach_error: An error was reached.");
}

int main() {
  // Replace non-deterministic input with a fixed value representing infinity
  float x = 1.0f / 0.0f;  // Set x to positive infinity
  float res = trunc_float(x);

  // Check if the result is infinity
  if (!isinf_float(res)) {
    reach_error();
    return 1;
  }

  printf("Test passed: res is infinity as expected.\n");
  return 0;
}