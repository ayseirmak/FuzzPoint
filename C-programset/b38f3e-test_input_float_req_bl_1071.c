#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

// Custom union to manipulate float bits
typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

// Function to truncate float values
float trunc_float(float x) {
  int32_t signbit, w, exponent_less_127;
  
  // Get the bit representation of the float
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;
  
  signbit = w & 0x80000000;
  exponent_less_127 = (w & 0x7f800000) >> 23; // Extract exponent bits
  exponent_less_127 -= 127; // Adjust exponent
  
  if (exponent_less_127 < 23) {
    if (exponent_less_127 < 0) { 
      // If the exponent suggests the number is between -1 and 1
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
      return x + x; // If exponent is all 1s, it might be INF/NAN
  }
  
  return x;
}

// Function to check if a float is NaN
int isnan_float(float x) {
  return x != x;
}

int main() {
  // Test case for trunc_float with NaN
  float x = 0.0f / 0.0f; // NaN
  float res = trunc_float(x);

  // Verify that result of trunc_float on NaN is still NaN
  assert(isnan_float(res));

  // For visual confirmation if needed (Remove in production)
  printf("Test Passed: Result is NaN as expected\n");

  return 0;
}