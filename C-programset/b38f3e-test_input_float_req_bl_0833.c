#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

typedef int32_t __int32_t;
typedef uint32_t __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float one_exp = 1.0,
                   halF_exp[2] = {
                       0.5,
                       -0.5,
                   },
                   huge_exp = 1.0e+30, twom100_exp = 7.8886090522e-31,
                   ln2HI_exp[2] = {
                       6.9313812256e-01,
                       -6.9313812256e-01,
                   },
                   ln2LO_exp[2] = {
                       9.0580006145e-06,
                       -9.0580006145e-06,
                   },
                   invln2_exp = 1.4426950216e+00, P1_exp = 1.6666667163e-01,
                   P2_exp = -2.7777778450e-03, P3_exp = 6.6137559770e-05,
                   P4_exp = -1.6533901999e-06, P5_exp = 4.1381369442e-08;

float __ieee754_expf(float x) {
  float y, hi, lo, c, t;
  __int32_t k = 0, xsb, sx;
  __uint32_t hx;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  sx = gf_u.word;

  xsb = (sx >> 31) & 1;
  hx = sx & 0x7fffffff;

  if (hx > 0x7f800000L)
    return x + x;
  if (hx == 0x7f800000L)
    return (xsb == 0) ? x : 0.0;
  if (sx > 0x42b17217)
    return huge_exp * huge_exp;
  if (sx < 0 && hx > 0x42cff1b5)
    return twom100_exp * twom100_exp;

  if (hx > 0x3eb17218) {
    if (hx < 0x3F851592) {
      hi = x - ln2HI_exp[xsb];
      lo = ln2LO_exp[xsb];
      k = 1 - xsb - xsb;
    } else {
      k = invln2_exp * x + halF_exp[xsb];
      t = k;
      hi = x - t * ln2HI_exp[0];
      lo = t * ln2LO_exp[0];
    }
    x = hi - lo;
  } else if (hx < 0x31800000) {
    if (huge_exp + x > one_exp)
      return one_exp + x;
  }

  t = x * x;
  c = x - t * (P1_exp + t * (P2_exp + t * (P3_exp + t * (P4_exp + t * P5_exp))));

  if (k == 0)
    return one_exp - ((x * c) / (c - (float)2.0) - x);
  else 
    y = one_exp - ((lo - (x * c) / ((float)2.0 - c)) - hi);

  if (k >= -125) {
    __uint32_t hy;
    ieee_float_shape_type gf_u;
    gf_u.value = y;
    hy = gf_u.word;

    ieee_float_shape_type sf_u;
    sf_u.word = hy + (k << 23);
    y = sf_u.value;
    return y;
  } else {
    __uint32_t hy;
    ieee_float_shape_type gf_u;
    gf_u.value = y;
    hy = gf_u.word;

    ieee_float_shape_type sf_u;
    sf_u.word = hy + ((k + 100) << 23);
    y = sf_u.value;
    return y * twom100_exp;
  }
}

int __signbit_float(float x) {
  __uint32_t w;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  w = gf_u.word;

  return (w & 0x80000000) != 0;
}

int main() {
  float x = -INFINITY; // -INF
  float res = __ieee754_expf(x);

  // Check if result is +0 with no sign bit
  assert(res == 0.0f && __signbit_float(res) == 0);

  printf("Test passed: expf(-INF) == +0\n");
  return 0;
}