#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

int isnan_float(float x) {
  return x != x;
}

float fabs_float(float x) {
  uint32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  ieee_float_shape_type sf_u;
  sf_u.word = ix & 0x7fffffff;
  x = sf_u.value;

  return x;
}

int main() {
  // Assigning NAN to x
  float x = 0.0f / 0.0f;
  float res = fabs_float(x);

  // Assert that if x is NaN, result should also be NaN
  assert(isnan_float(res));

  // If the assertion fails, print an error message
  if (!isnan_float(res)) {
    printf("Error: Result is not NaN as expected.\n");
    return 1;
  }

  return 0;
}