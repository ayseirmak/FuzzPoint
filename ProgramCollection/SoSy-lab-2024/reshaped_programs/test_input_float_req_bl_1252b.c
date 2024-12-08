#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef uint32_t __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

int __fpclassify_float(float x) {
  __uint32_t w;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;
  
  if (w == 0x00000000 || w == 0x80000000)
    return 2; // FP_ZERO
  else if ((w >= 0x00800000 && w <= 0x7f7fffff) ||
           (w >= 0x80800000 && w <= 0xff7fffff))
    return 4; // FP_NORMAL
  else if ((w >= 0x00000001 && w <= 0x007fffff) ||
           (w >= 0x80000001 && w <= 0x807fffff))
    return 3; // FP_SUBNORMAL
  else if (w == 0x7f800000 || w == 0xff800000)
    return 1; // FP_INFINITE
  else
    return 0; // FP_NAN
}

float fmax_float(float x, float y) {
  if (__fpclassify_float(x) == 0) {
    return y;
  }
  if (__fpclassify_float(y) == 0) {
    return x;
  }
  return x > y ? x : y;
}

int __signbit_float(float x) {
  __uint32_t w;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;
  
  return (w & 0x80000000) != 0;
}

void reach_error() {
  printf("Error reached: Result does not match the expected +0 with a positive sign bit.\n");
}

int main() {
  float x = 0.0f;  // Fixed deterministic value
  float y = -0.0f; // Fixed deterministic value
  float res = fmax_float(x, y);

  // y is -0 and x is +0, the result shall be +0
  if (!(res == 0.0f && __signbit_float(res) == 0)) {
    reach_error();
    return 1;
  }

  printf("Test passed: Result is +0 as expected.\n");
  return 0;
}