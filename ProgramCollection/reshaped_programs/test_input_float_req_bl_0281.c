#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef unsigned int __uint32_t;

// Union to represent a float as a word (integer)
typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

// Custom implementation of isnan function for float
bool isnan_float(float x) {
  return x != x;
}

float __ieee754_sqrtf(float x) {
  float z;
  __uint32_t r, hx;
  int ix, s, q, m, t;
  int i;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  hx = ix & 0x7fffffff;

  if (!((hx) < 0x7f800000L))
    return x * x + x;

  if (((hx) == 0))
    return x;
  if (ix < 0)
    return (x - x) / (x - x);

  m = (ix >> 23);
  if (((hx) < 0x00800000L)) {
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
    float one_sqrt = 1.0, tiny_sqrt = 1.0e-30;
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

float fabs_float(float x) {
  __uint32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ix &= 0x7fffffff;

  ieee_float_shape_type sf_u;
  sf_u.word = ix;
  x = sf_u.value;
  return x;
}

float __ieee754_asinf(float x) {
  float t, w, p, q, c, r, s;
  int hx, ix;
  
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  hx = gf_u.word;
  ix = hx & 0x7fffffff;

  static const float
    one_asin = 1.0,
    huge_asin = 1.0e+30,
    pio2_hi_asin = 1.57079637050628662109375f,
    pio2_lo_asin = -4.37113900018624283e-8f,
    pio4_hi_asin = 0.785398185253143310546875f,
    pS0_asin = 1.6666667163e-01,
    pS1_asin = -3.2556581497e-01,
    pS2_asin = 2.0121252537e-01,
    pS3_asin = -4.0055535734e-02,
    pS4_asin = 7.9153501429e-04,
    pS5_asin = 3.4793309169e-05,
    qS1_asin = -2.4033949375e+00,
    qS2_asin = 2.0209457874e+00,
    qS3_asin = -6.8828397989e-01,
    qS4_asin = 7.7038154006e-02;

  if (ix == 0x3f800000) {
    return x * pio2_hi_asin + x * pio2_lo_asin;
  } else if (ix > 0x3f800000) {
    return (x - x) / (x - x);
  } else if (ix < 0x3f000000) {
    if (ix < 0x32000000) {
      if (huge_asin + x > one_asin)
        return x;
    } else {
      t = x * x;
      p = t * (pS0_asin + t * (pS1_asin + t * (pS2_asin + t * (pS3_asin + t * (pS4_asin + t * pS5_asin)))));
      q = one_asin + t * (qS1_asin + t * (qS2_asin + t * (qS3_asin + t * qS4_asin)));
      w = p / q;
      return x + x * w;
    }
  }

  w = one_asin - fabs_float(x);
  t = w * 0.5f;
  p = t * (pS0_asin + t * (pS1_asin + t * (pS2_asin + t * (pS3_asin + t * (pS4_asin + t * pS5_asin)))));
  q = one_asin + t * (qS1_asin + t * (qS2_asin + t * (qS3_asin + t * qS4_asin)));
  s = __ieee754_sqrtf(t);

  if (ix >= 0x3F79999A) {
    w = p / q;
    t = pio2_hi_asin - (float)(2.0 * (s + s * w) - pio2_lo_asin);
  } else {
    int iw;
    w = s;
    ieee_float_shape_type gf_w;
    gf_w.value = w;
    iw = gf_w.word;

    ieee_float_shape_type sf_w;
    sf_w.word = (iw & 0xfffff000);
    w = sf_w.value;

    c = (t - w * w) / (s + w);
    r = p / q;
    p = 2.0f * s * r - (pio2_lo_asin - 2.0f * c);
    q = pio4_hi_asin - 2.0f * w;
    t = pio4_hi_asin - (p - q);
  }
  if (hx > 0)
    return t;
  else
    return -t;
}

int main() {
  // Fixed input value for demonstration purposes
  float testValues[] = {-1.5f, 0.5f, 1.5f}; // Sample values
  size_t numTests = sizeof(testValues) / sizeof(testValues[0]);

  for (size_t i = 0; i < numTests; ++i) {
    float x = testValues[i];

    if (x < -1.0f || x > 1.0f) {
      float res = __ieee754_asinf(x);

      // x is not in [-1,1] the result shall be NAN
      if (!isnan_float(res)) {
        printf("Error: Result is not NaN for input x=%.2f\n", x);
        return 1;
      }
    }
  }

  printf("All tests passed.\n");
  return 0;
}