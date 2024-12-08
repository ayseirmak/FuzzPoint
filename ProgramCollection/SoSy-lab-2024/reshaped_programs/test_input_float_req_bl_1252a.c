#include <stdio.h>

// Union to work with IEEE 754 floating-point format
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

// Function to classify the floating-point number
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

// Function to find maximum float, handling -0 and +0 correctly
float fmax_float(float x, float y) {
  if (__fpclassify_float(x) == 0) {
    return y;
  }

  if (__fpclassify_float(y) == 0) {
    return x;
  }
  return x > y ? x : y;
}

// Function to determine the sign bit of the float
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

  float res = fmax_float(x, y);

  // x is -0 and y is +0, the result shall be +0
  if (res == 0.0f && __signbit_float(res) == 0) {
    printf("Test passed: fmax_float returns +0 when one argument is -0 and the other is +0.\n");
  } else {
    printf("Test failed: Result is not +0 as expected.\n");
    return 1;
  }

  return 0;
}