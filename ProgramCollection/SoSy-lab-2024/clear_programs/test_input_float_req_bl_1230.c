#include <stdio.h>
#include <stdint.h>
#include <assert.h>

// Function to replace reach_error
void reach_error() {
    assert(0 && "reach_error");
}

// Define the union for float representation
typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

// Function to classify the type of a floating point number
int __fpclassify_float(float x) {
  uint32_t w;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;

  if (w == 0x00000000 || w == 0x80000000) {
    return 2; // zero
  } else if ((w >= 0x00800000 && w <= 0x7f7fffff) ||
             (w >= 0x80800000 && w <= 0xff7fffff)) {
    return 4; // normal
  } else if ((w >= 0x00000001 && w <= 0x007fffff) ||
             (w >= 0x80000001 && w <= 0x807fffff)) {
    return 3; // subnormal
  } else if (w == 0x7f800000 || w == 0xff800000) {
    return 1; // infinity
  } else {
    return 0; // NaN
  }
}

// Function to find the minimum of two floats
float fmin_float(float x, float y) {
  if (__fpclassify_float(x) == 0) {
    return y;
  }
  if (__fpclassify_float(y) == 0) {
    return x;
  }

  return x < y ? x : y;
}

// Check if a float is NaN
int isnan_float(float x) {
  return x != x;
}

// Main function
int main() {
  // Fixed values for NaN
  float x = 0.0f / 0.0f; // NaN
  float y = 0.0f / 0.0f; // NaN

  // Call the fmin_float function
  float res = fmin_float(x, y);

  // Check if result is NaN
  if (!isnan_float(res)) {
    reach_error();
    return 1;
  }

  return 0;
}