#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float huge_floor = 1.0e30;

float floor_float(float x) {
  __int32_t i0, j0;
  __uint32_t i, ix;
  ieee_float_shape_type gf_u;
  gf_u.value = (x);
  i0 = gf_u.word;

  ix = (i0 & 0x7fffffff);
  j0 = (ix >> 23) - 0x7f;
  if (j0 < 23) {
    if (j0 < 0) {
      if (huge_floor + x > (float)0.0) {
        if (i0 >= 0) {
          i0 = 0;
        } else if ((ix) != 0) {
          i0 = 0xbf800000;
        }
      }
    } else {
      i = (0x007fffff) >> j0;
      if ((i0 & i) == 0)
        return x;
      if (huge_floor + x > (float)0.0) {
        if (i0 < 0)
          i0 += (0x00800000) >> j0;
        i0 &= (~i);
      }
    }
  } else {
    if ((ix) >= 0x7f800000L)
      return x + x;
    else
      return x;
  }

  ieee_float_shape_type sf_u;
  sf_u.word = (i0);
  x = sf_u.value;
  return x;
}

// NaN check for floats
int isnan_float(float x) {
  return x != x;
}

float copysign_float(float x, float y) {
  __uint32_t ix, iy;

  ieee_float_shape_type gf_u;
  gf_u.value = (x);
  ix = gf_u.word;

  gf_u.value = (y);
  iy = gf_u.word;

  ieee_float_shape_type sf_u;
  sf_u.word = ((ix & 0x7fffffff) | (iy & 0x80000000));
  x = sf_u.value;
  return x;
}

static const float two25_scalbn = 3.355443200e+07,
                   twom25_scalbn = 2.9802322388e-08,
                   huge_scalbn = 1.0e+30,
                   tiny_scalbn = 1.0e-30;

float scalbn_float(float x, int n) {
  __int32_t k, ix;
  __uint32_t hx;

  ieee_float_shape_type gf_u;
  gf_u.value = (x);
  ix = gf_u.word;

  hx = ix & 0x7fffffff;
  k = hx >> 23;
  if ((hx) == 0)
    return x;
  if ((hx) >= 0x7f800000L)
    return x + x;

  if ((hx) < 0x00800000L) {
    x *= two25_scalbn;
    gf_u.value = (x);
    ix = gf_u.word;

    k = ((ix & 0x7f800000) >> 23) - 25;
    if (n < -50000)
      return tiny_scalbn * x;
  }

  k = k + n;
  if (k > (0x7f7fffffL >> 23))
    return huge_scalbn * copysign_float(huge_scalbn, x);
  if (k > 0) {
    ieee_float_shape_type sf_u;
    sf_u.word = ((ix & 0x807fffff) | (k << 23));
    x = sf_u.value;
    return x;
  }
  if (k < -22) {
    if (n > 50000)
      return huge_scalbn * copysign_float(huge_scalbn, x);
    else
      return tiny_scalbn * copysign_float(tiny_scalbn, x);
  }

  k += 25;
  ieee_float_shape_type sf_u;
  sf_u.word = ((ix & 0x807fffff) | (k << 23));
  x = sf_u.value;
  return x * twom25_scalbn;
}

float fabs_float(float x) {
  __uint32_t ix;

  ieee_float_shape_type gf_u;
  gf_u.value = (x);
  ix = gf_u.word;

  ieee_float_shape_type sf_u;
  sf_u.word = (ix & 0x7fffffff);
  x = sf_u.value;
  return x;
}

static const float half_ksin = 5.0000000000e-01,
                   S1_ksin = -1.6666667163e-01,
                   S2_ksin = 8.3333337680e-03, 
                   S3_ksin = -1.9841270114e-04,
                   S4_ksin = 2.7557314297e-06,
                   S5_ksin = -2.5050759689e-08,
                   S6_ksin = 1.5896910177e-10;

float __kernel_sinf(float x, float y, int iy) {
  float z, r, v;
  __int32_t ix;

  ieee_float_shape_type gf_u;
  gf_u.value = (x);
  ix = gf_u.word;

  ix &= 0x7fffffff;
  if (ix < 0x32000000) {
    if ((int)x == 0)
      return x;
  }
  z = x * x;
  v = z * x;
  r = S2_ksin + z * (S3_ksin + z * (S4_ksin + z * (S5_ksin + z * S6_ksin)));
  if (iy == 0)
    return x + v * (S1_ksin + z * r);
  else
    return x - ((z * (half_ksin * y - v * r) - y) - v * S1_ksin);
}

static const float one_kcos = 1.0000000000e+00,
                   C1_kcos = 4.1666667908e-02,
                   C2_kcos = -1.3888889225e-03, 
                   C3_kcos = 2.4801587642e-05,
                   C4_kcos = -2.7557314297e-07, 
                   C5_kcos = 2.0875723372e-09,
                   C6_kcos = -1.1359647598e-11;

float __kernel_cosf(float x, float y) {
  float a, hz, z, r, qx;
  __int32_t ix;

  ieee_float_shape_type gf_u;
  gf_u.value = (x);
  ix = gf_u.word;

  ix &= 0x7fffffff;
  if (ix < 0x32000000) {
    if (((int)x) == 0)
      return one_kcos;
  }
  z = x * x;
  r = z * (C1_kcos +
           z * (C2_kcos +
                z * (C3_kcos + z * (C4_kcos + z * (C5_kcos + z * C6_kcos)))));
  if (ix < 0x3e99999a)
    return one_kcos - ((float)0.5 * z - (z * r - x * y));
  else {
    if (ix > 0x3f480000) {
      qx = (float)0.28125;
    } else {
      ieee_float_shape_type sf_u;
      sf_u.word = (ix - 0x01000000);
      qx = sf_u.value;
    }
    hz = (float)0.5 * z - qx;
    a = one_kcos - qx;
    return a - (hz - (z * r - x * y));
  }
}

static const float one_cos = 1.0;

float cos_float(float x) {
  float y[2], z = 0.0;
  __int32_t n, ix;

  ieee_float_shape_type gf_u;
  gf_u.value = (x);
  ix = gf_u.word;

  ix &= 0x7fffffff;
  if (ix <= 0x3f490fd8)
    return __kernel_cosf(x, z);

  else if (!(ix < 0x7f800000L))
    return x - x;

  else {
    n = __ieee754_rem_pio2f(x, y);
    switch (n & 3) {
    case 0:
      return __kernel_cosf(y[0], y[1]);
    case 1:
      return -__kernel_sinf(y[0], y[1], 1);
    case 2:
      return -__kernel_cosf(y[0], y[1]);
    default:
      return __kernel_sinf(y[0], y[1], 1);
    }
  }
}

int main() {
  // Setting a fixed input value
  float x = 0.0f;
  float res = cos_float(x);

  // x is +-0, the result shall be 1.0
  if (res != 1.0f) {
    assert(0 && "reach_error");
    return 1;
  }

  printf("cos(0.0) = %.6f\n", res);  // Output the result for verification
  return 0;
}