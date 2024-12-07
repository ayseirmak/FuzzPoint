#include <stdio.h>
#include <assert.h>

// Define types for compatibility
typedef int __int32_t;
typedef unsigned int __uint32_t;

// Union for converting between float and unsigned int
typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

// Function to determine absolute value of a float
float fabs_float(float x) {
  __uint32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ieee_float_shape_type sf_u;
  sf_u.word = ix & 0x7fffffff; // Clear the sign bit
  x = sf_u.value;
  return x;
}

// Function to check if a float is infinite
int isinf_float(float x) {
  __int32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ix &= 0x7fffffff;
  return (ix == 0x7f800000L);
}

int main() {
  // Predefined input value (negative infinity)
  float x = -1.0f / 0.0f; // Using standard expression for -INFINITY
  float res = fabs_float(x);

  // Check if the result is positive infinity
  assert(isinf_float(res) && "The result should be positive infinity.");

  return 0;
}