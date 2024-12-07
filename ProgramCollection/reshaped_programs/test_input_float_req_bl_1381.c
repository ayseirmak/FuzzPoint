#include <stdio.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

float copysign_float(float x, float y) {
  __uint32_t ix, iy;
  
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  gf_u.value = y;
  iy = gf_u.word;
  
  ieee_float_shape_type sf_u;
  sf_u.word = ((ix & 0x7fffffff) | (iy & 0x80000000));
  x = sf_u.value;

  return x;
}

// nan check for floats
int isnan_float(float x) { return x != x; }

int main() {
  /*
   * REQ-BL-1381:
   * The copysign and copysignf procedures shall return NaN if the argument x is
   * NaN .
   */

  float x = 0.0f / 0.0f; // NAN
  float y = 3.5f;        // Fixed value, deterministic
  float res = copysign_float(x, y);

  // x is nan, y is a fixed value, the result shall be NAN
  if (!isnan_float(res)) {
    // Using assert for reach error
    assert(0 && "reach_error");
  }

  return 0;
}