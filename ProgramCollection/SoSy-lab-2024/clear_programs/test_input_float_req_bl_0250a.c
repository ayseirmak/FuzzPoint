#include <stdio.h>
#include <math.h>
#include <stdint.h>

typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

static const float huge_floor = 1.0e30;
static const float one_sqrt = 1.0, tiny_sqrt = 1.0e-30;
static const float one_asin = 1.0, huge_asin = 1.0e30,
                   pio2_hi_asin = 1.57079637050628662109375f,
                   pio2_lo_asin = -4.37113900018624283e-8f,
                   pio4_hi_asin = 0.785398185253143310546875f,
                   pS0_asin = 1.6666667163e-01, pS1_asin = -3.2556581497e-01,
                   pS2_asin = 2.0121252537e-01, pS3_asin = -4.0055535734e-02,
                   pS4_asin = 7.9153501429e-04, pS5_asin = 3.4793309169e-05,
                   qS1_asin = -2.4033949375e+00, qS2_asin = 2.0209457874e+00,
                   qS3_asin = -6.8828397989e-01, qS4_asin = 7.7038154006e-02;

// Nan check for floats
int isnan_float(float x) {
  return x != x;
}

float floor_float(float x) {
  int32_t i0, j0;
  uint32_t i, ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  i0 = gf_u.word;
  
  ix = (i0 & 0x7fffffff);
  j0 = (ix >> 23) - 0x7f;
  if (j0 < 23) {
    if (j0 < 0) {
      if (huge_floor + x > 0.0) {
        if (i0 >= 0) {
          i0 = 0;
        } else if (!(ix == 0)) {
          i0 = 0xbf800000;
        }
      }
    } else {
      i = (0x007fffff) >> j0;
      if ((i0 & i) == 0)
        return x;
      if (huge_floor + x > 0.0) {
        if (i0 < 0)
          i0 += (0x00800000) >> j0;
        i0 &= (~i);
      }
    }
  } else {
    if (!(ix < 0x7f800000L))
      return x + x;
    else
      return x;
  }

  ieee_float_shape_type sf_u;
  sf_u.word = (i0);
  x = sf_u.value;

  return x;
}

float __ieee754_sqrtf(float x) {
  float z;
  uint32_t r, hx;
  int32_t ix, s, q, m, t, i;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  
  hx = ix & 0x7fffffff;
  if (!(hx < 0x7f800000L))
    return x * x + x;
  if (hx == 0)
    return x;
  if (ix < 0)
    return (x - x) / (x - x);

  m = (ix >> 23);
  if (hx < 0x00800000L) {
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
  sf_u.word = (ix);
  z = sf_u.value;
  
  return z;
}

float fabs_float(float x) {
  uint32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  
  ieee_float_shape_type sf_u;
  sf_u.word = (ix & 0x7fffffff);
  x = sf_u.value;
  
  return x;
}

float __ieee754_asinf(float x) {
  float t, w, p, q, c, r, s;
  int32_t hx, ix;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  hx = gf_u.word;
  
  ix = hx & 0x7fffffff;
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
      p = t * (pS0_asin +
               t * (pS1_asin +
                    t * (pS2_asin +
                         t * (pS3_asin + t * (pS4_asin + t * pS5_asin)))));
      q = one_asin +
          t * (qS1_asin + t * (qS2_asin + t * (qS3_asin + t * qS4_asin)));
      w = p / q;
      return x + x * w;
    }
  }

  w = one_asin - fabs_float(x);
  t = w * 0.5f;
  p = t *
      (pS0_asin +
       t * (pS1_asin +
            t * (pS2_asin + t * (pS3_asin + t * (pS4_asin + t * pS5_asin)))));
  q = one_asin +
      t * (qS1_asin + t * (qS2_asin + t * (qS3_asin + t * qS4_asin)));
  s = __ieee754_sqrtf(t);
  if (ix >= 0x3F79999A) {
    w = p / q;
    t = pio2_hi_asin - (2.0f * (s + s * w) - pio2_lo_asin);
  } else {
    int32_t iw;
    w = s;
    
    ieee_float_shape_type gf_u;
    gf_u.value = w;
    iw = gf_u.word;
    
    ieee_float_shape_type sf_u;
    sf_u.word = (iw & 0xfffff000);
    w = sf_u.value;
    
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
  // Fixed value: positive infinity
  float x = INFINITY;
  float res = __ieee754_asinf(x);

  // x is +inf, the result shall be NAN
  if (!isnan_float(res)) {
    printf("Error: asin(inf) should be NaN\n");
    return 1;
  }

  printf("The output is NaN as expected.\n");
  return 0;
}