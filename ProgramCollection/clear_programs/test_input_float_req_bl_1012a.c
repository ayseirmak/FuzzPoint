#include <stdio.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

float fabs_float(float x) {
  __uint32_t ix;
  ieee_float_shape_type temp_union;
  temp_union.value = x;
  ix = temp_union.word;
  
  temp_union.word = (ix & 0x7fffffff);
  x = temp_union.value;
  
  return x;
}

// infinity check for floats
int isinf_float(float x) {
  __int32_t ix;
  ieee_float_shape_type temp_union;
  temp_union.value = x;
  ix = temp_union.word;

  ix &= 0x7fffffff;
  return (ix == 0x7f800000L);
}

int main() {
  // Deterministically set x to infinity using IEEE 754 representation for +Inf
  float x = 1.0f / 0.0f; // This represents +Infinity
  float res = fabs_float(x);

  // x is +inf, result shall be +inf
  assert(isinf_float(res) && "Error: Expected result to be +Infinity");

  printf("Test passed: fabs_float(Inf) returned +Inf as expected.\n");
  return 0;
}