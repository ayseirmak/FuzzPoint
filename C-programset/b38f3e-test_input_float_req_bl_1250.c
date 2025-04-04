#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

/*
 * __fpclassify_float categorizes a floating point value `x` into the following
 * categories: zero, subnormal, normal, infinite, NAN, or implementation-defined category.
 * Returns one of FP_INFINITE, FP_NAN, FP_NORMAL, FP_SUBNORMAL, FP_ZERO or
 * implementation-defined type, specifying the category of `x`.
 */

int __fpclassify_float(float x) {
  uint32_t w;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;

  if (w == 0x00000000 || w == 0x80000000)
    return 2;  // FP_ZERO
  else if ((w >= 0x00800000 && w <= 0x7f7fffff) ||
           (w >= 0x80800000 && w <= 0xff7fffff))
    return 4;  // FP_NORMAL
  else if ((w >= 0x00000001 && w <= 0x007fffff) ||
           (w >= 0x80000001 && w <= 0x807fffff))
    return 3;  // FP_SUBNORMAL
  else if (w == 0x7f800000 || w == 0xff800000)
    return 1;  // FP_INFINITE
  else
    return 0;  // FP_NAN
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

// nan check for floats
int isnan_float(float x) { return x != x; }

int main() {
  // Using fixed values to demonstrate functionality

  float x = 0.0f / 0.0f; // Representing NAN
  float y = 0.0f / 0.0f; // Representing NAN
  float res = fmax_float(x, y);

  // Assertion with standard assert to replace reach_error function
  assert(isnan_float(res) && "Result should be NaN when both inputs are NaN");

  printf("Assertion passed: Result is NaN as expected.\n");

  return 0;
}