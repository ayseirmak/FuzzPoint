#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float one_modf = 1.0;

float modf_float(float x, float *iptr) {
  __int32_t i0, j0;
  __uint32_t i;
  do {
    ieee_float_shape_type gf_u;
    gf_u.value = (x);
    (i0) = gf_u.word;
  } while (0);
  j0 = ((i0 >> 23) & 0xff) - 0x7f;
  if (j0 < 23) {
    if (j0 < 0) {
      do {
        ieee_float_shape_type sf_u;
        sf_u.word = (i0 & 0x80000000);
        (*iptr) = sf_u.value;
      } while (0);
      return x;
    } else {
      i = (0x007fffff) >> j0;
      if ((i0 & i) == 0) {
        __uint32_t ix;
        *iptr = x;
        do {
          ieee_float_shape_type gf_u;
          gf_u.value = (x);
          (ix) = gf_u.word;
        } while (0);
        do {
          ieee_float_shape_type sf_u;
          sf_u.word = (ix & 0x80000000);
          (x) = sf_u.value;
        } while (0);
        return x;
      } else {
        do {
          ieee_float_shape_type sf_u;
          sf_u.word = (i0 & (~i));
          (*iptr) = sf_u.value;
        } while (0);
        return x - *iptr;
      }
    }
  } else {
    __uint32_t ix;
    *iptr = x * one_modf;
    do {
      ieee_float_shape_type gf_u;
      gf_u.value = (x);
      (ix) = gf_u.word;
    } while (0);
    do {
      ieee_float_shape_type sf_u;
      sf_u.word = (ix & 0x80000000);
      (x) = sf_u.value;
    } while (0);
    return x;
  }
}

int __signbit_float(float x) {
  __uint32_t w;

  do {
    ieee_float_shape_type gf_u;
    gf_u.value = (x);
    (w) = gf_u.word;
  } while (0);

  return (w & 0x80000000) != 0;
}

// infinity check for floats
int isinf_float(float x) {
  __int32_t ix;
  do {
    ieee_float_shape_type gf_u;
    gf_u.value = (x);
    (ix) = gf_u.word;
  } while (0);
  ix &= 0x7fffffff;
  return ((ix) == 0x7f800000L);
}

int main() {
  float x = 1.0f / 0.0f; // Positive Infinity
  float iptr = 0.0f; // Initialized with a default value
  float res = modf_float(x, &iptr);

  // x is inf, *iptr is inf, result should be ±0
  if (isinf_float(iptr) && !(res == 0.0f && __signbit_float(res) == 0)) {
    fprintf(stderr, "Error: condition failed\n");
    return 1;
  }

  printf("Test passed. iptr: %f, res: %f\n", iptr, res);
  return 0;
}