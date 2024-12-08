#include <stdio.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

// nan check for floats
int isnan_float(float x) {
  return x != x;
}

static const float one_sqrt = 1.0, tiny_sqrt = 1.0e-30f;

float __ieee754_sqrtf(float x) {
  float z;
  __uint32_t r, hx;
  __int32_t ix, s, q, m, t, i;

  // extract the word representation of the float
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  
  hx = ix & 0x7fffffff;

  if (hx >= 0x7f800000) // check for NaN or infinity
    return x * x + x;

  if (hx == 0) // check for zero
    return x;

  if (ix < 0) // check for negative number
    return (x - x) / (x - x);

  m = (ix >> 23);
  if (hx < 0x00800000L) { // subnormal number
    for (i = 0; (ix & 0x00800000L) == 0; i++)
      ix <<= 1;
    m -= i - 1;
  }
  m -= 127;
  ix = (ix & 0x007fffffL) | 0x00800000L;

  if (m & 1)
    ix += ix;
  
  m >>= 1;
  ix += ix;
  q = s = 0;
  r = 0x01000000L;

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
  ix = (q >> 1) + 0x3f000000L;
  ix += (m << 23);

  ieee_float_shape_type sf_u;
  sf_u.word = ix;
  z = sf_u.value;

  return z;
}

void test_sqrt_nan() {
  float x = 0.0f / 0.0f; // NAN
  float res = __ieee754_sqrtf(x);

  // Assert that the result should be NaN
  assert(isnan_float(res));
}

int main() {
  test_sqrt_nan();
  printf("All tests passed successfully.\n");
  return 0;
}