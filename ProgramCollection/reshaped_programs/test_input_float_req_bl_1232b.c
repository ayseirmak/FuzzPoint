#include <stdio.h>
#include <assert.h>

typedef unsigned int __uint32_t;

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
    return 2; // zero
  else if ((w >= 0x00800000 && w <= 0x7f7fffff) ||
           (w >= 0x80800000 && w <= 0xff7fffff))
    return 4; // normal
  else if ((w >= 0x00000001 && w <= 0x007fffff) ||
           (w >= 0x80000001 && w <= 0x807fffff))
    return 3; // subnormal
  else if (w == 0x7f800000 || w == 0xff800000)
    return 1; // infinite
  else
    return 0; // NaN
}

float fmin_float(float x, float y) {
  if (__fpclassify_float(x) == 0)
    return y;
  if (__fpclassify_float(y) == 0)
    return x;

  return x < y ? x : y;
}

int __signbit_float(float x) {
  __uint32_t w;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;

  return (w & 0x80000000) != 0;
}

int main() {

  float x = -0.0f;
  float y = 0.0f;
  float res = fmin_float(x, y);

  // Assert: x is -0 and y is +0, the result should be -0
  assert(res == -0.0f && __signbit_float(res) == 1);

  printf("Test passed successfully: fmin(-0.0, 0.0) = -0.0\n");

  return 0;
}