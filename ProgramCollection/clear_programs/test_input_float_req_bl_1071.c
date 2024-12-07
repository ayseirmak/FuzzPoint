#include <stdio.h>
#include <assert.h>

// Typedefs
typedef int __int32_t;
typedef unsigned int __uint32_t;

// Union for floating point manipulation
typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

// Function to truncate float
float trunc_float(float x) {
  __int32_t signbit, w, exponent_less_127;
  
  ieee_float_shape_type gf_u;
  gf_u.value = (x);
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

// Function to check if float is NaN
int isnan_float(float x) {
  return x != x;
}

// Main function
int main() {
  // Set a deterministic value to x as NaN
  float x = 0.0f / 0.0f; // NaN
  float res = trunc_float(x);

  // Assert that the result of truncating NaN is NaN
  assert(isnan_float(res));

  // Output some information for confirmation
  printf("If no assertion failed, the behavior is correct.\n");

  return 0;
}