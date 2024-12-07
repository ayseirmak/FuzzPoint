#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// Define union for IEEE float shape
typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

// IEEE 754 isnan
int isnan_float(float x) { return x != x; }

static const float one_sqrt = 1.0f, tiny_sqrt = 1.0e-30f;

float __ieee754_sqrtf(float x) {
  float z;
  uint32_t r, hx;
  int32_t ix, s, q, m, t, i;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  hx = ix & 0x7fffffff;

  if (!(hx < 0x7f800000L))
    return x * x + x; // NaN or infinity check

  if (hx == 0)
    return x; // zero
  if (ix < 0)
    return (x - x) / (x - x); // negative number

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

static const float one_acos = 1.0f, pi = 3.1415925026f,
                   pio2_hi_acos = 1.5707962513f,
                   pio2_lo_acos = 7.5497894159e-08f, pS0_acos = 1.6666667163e-01f,
                   pS1_acos = -3.2556581497e-01f, pS2_acos = 2.0121252537e-01f,
                   pS3_acos = -4.0055535734e-02f, pS4_acos = 7.9153501429e-04f,
                   pS5_acos = 3.4793309169e-05f, qS1_acos = -2.4033949375e+00f,
                   qS2_acos = 2.0209457874e+00f, qS3_acos = -6.8828397989e-01f,
                   qS4_acos = 7.7038154006e-02f;

float __ieee754_acosf(float x) {
  float z, p, q, r, w, s, c, df;
  int32_t hx, ix;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  hx = gf_u.word;

  ix = hx & 0x7fffffff;
  if (ix == 0x3f800000) {
    if (hx > 0)
      return 0.0f;
    else
      return pi + 2.0f * pio2_lo_acos;
  } else if (ix > 0x3f800000) {
    return (x - x) / (x - x);
  }
  if (ix < 0x3f000000) {
    if (ix <= 0x23000000)
      return pio2_hi_acos + pio2_lo_acos;
    z = x * x;
    p = z *
        (pS0_acos +
         z * (pS1_acos +
              z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
    q = one_acos +
        z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
    r = p / q;
    return pio2_hi_acos - (x - (pio2_lo_acos - x * r));
  } else if (hx < 0) {
    z = (one_acos + x) * 0.5f;
    p = z *
        (pS0_acos +
         z * (pS1_acos +
              z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
    q = one_acos +
        z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
    s = __ieee754_sqrtf(z);
    r = p / q;
    w = r * s - pio2_lo_acos;
    return pi - 2.0f * (s + w);
  } else {
    z = (one_acos - x) * 0.5f;
    s = __ieee754_sqrtf(z);
    df = s;
    int32_t idf;
    ieee_float_shape_type df_u;
    df_u.value = df;
    idf = df_u.word;

    ieee_float_shape_type sf_u;
    sf_u.word = (idf & 0xfffff000);
    df = sf_u.value;

    c = (z - df * df) / (s + df);
    p = z *
        (pS0_acos +
         z * (pS1_acos +
              z * (pS2_acos + z * (pS3_acos + z * (pS4_acos + z * pS5_acos)))));
    q = one_acos +
        z * (qS1_acos + z * (qS2_acos + z * (qS3_acos + z * qS4_acos)));
    r = p / q;
    w = r * s + c;
    return 2.0f * (df + w);
  }
}

int main() {

  // REQ-BL-0480: The acos and acosf procedures shall return NAN, if the argument x is +-inf

  // Set a fixed input of inf (using float infinity)
  float x = INFINITY; 
  float res = __ieee754_acosf(x);

  // x is +inf, the result shall be NAN
  if (!isnan_float(res)) {
    printf("Error: Result is not NAN as it should be.\n");
    return 1;
  }

  printf("The result is NAN as expected for +inf input.\n");
  return 0;
}