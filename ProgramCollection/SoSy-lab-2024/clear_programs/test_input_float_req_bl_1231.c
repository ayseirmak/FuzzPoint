#include <stdio.h>
#include <assert.h>

typedef int __int32_t;
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
    return 2; // Zero
  else if ((w >= 0x00800000 && w <= 0x7f7fffff) ||
           (w >= 0x80800000 && w <= 0xff7fffff))
    return 4; // Normalized
  else if ((w >= 0x00000001 && w <= 0x007fffff) ||
           (w >= 0x80000001 && w <= 0x807fffff))
    return 3; // Denormalized
  else if (w == 0x7f800000 || w == 0xff800000)
    return 1; // Infinity
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

// NaN check for floats
int isnan_float(float x) {
  return x != x;
}

int main() {

  /* REQ-BL-1231:
   * The fmin and fminf procedures shall return the one argument
   * if only the other argument is NaN.
   */

  // Assign deterministic values to x and y
  float x = 0.0f / 0.0f; // An example NaN value
  float y = 3.5f; // A normal float value

  if ((isnan_float(x) && !isnan_float(y)) ||
      (!isnan_float(x) && isnan_float(y))) {

    float res = fmin_float(x, y);

    // x is NaN and y is not NaN, the result shall be y
    if (isnan_float(x) && !isnan_float(y) && res != y) {
      assert(0 && "x is NaN and res should be y");
      return 1;
    }

    // y is NaN and x is not NaN, the result shall be x
    if (!isnan_float(x) && isnan_float(y) && res != x) {
      assert(0 && "y is NaN and res should be x");
      return 1;
    }
  }

  return 0;
}