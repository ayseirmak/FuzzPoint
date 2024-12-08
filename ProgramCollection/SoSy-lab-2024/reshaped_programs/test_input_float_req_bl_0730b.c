#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float one_sqrt = 1.0f, tiny_sqrt = 1.0e-30f;

float __ieee754_sqrtf(float x) {
  float z;
  __uint32_t r, hx;
  __int32_t ix, s, q, m, t, i;

  // Extract the bits of the float
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  
  hx = ix & 0x7fffffff;

  // Check for Inf or NaN
  if (!(hx < 0x7f800000))
    return x * x + x;

  // Check for zero
  if (hx == 0)
    return x;
  
  // Check for negative value
  if (ix < 0)
    return (x - x) / (x - x);
  
  m = (ix >> 23);
  
  // Normalize subnormal and adjust m
  if (hx < 0x00800000) {
    for (i = 0; (ix & 0x00800000) == 0; i++) 
      ix <<= 1;
    m -= i - 1;
  }
  m -= 127;
  ix = (ix & 0x007fffff) | 0x00800000;
  if (m & 1)
    ix += ix;
  m >>= 1;
  
  // Calculate sqrt by bit manipulation
  ix += ix;
  q = s = 0;
  r = 0x01000000;
  while (r != 0) {
    t = s + r;
    if (t <= ix) {
      s = t + r;
      ix -= t;
      q += r;
    }
    ix += ix;
    r >>= 1;
  }

  if (ix != 0) {
    z = one_sqrt - tiny_sqrt;
    if (z >= one_sqrt) {
      z = one_sqrt + tiny_sqrt;
      if (z > one_sqrt)
        q += 2;
      else
        q += (q & 1);
    }
  }

  // Pack the result back into a float
  ix = (q >> 1) + 0x3f000000;
  ix += (m << 23);
  ieee_float_shape_type sf_u;
  sf_u.word = ix;
  z = sf_u.value;
  
  return z;
}

int __signbit_float(float x) {
  __uint32_t w;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;

  return (w & 0x80000000) != 0;
}

void reach_error() {
  printf("Error reached\n");
}

int main() {
  float x = 0.0f;
  float res = __ieee754_sqrtf(x);

  // x +0, the result shall be +0
  assert(res == 0.0f && __signbit_float(res) == 0);

  return 0;
}