#include <stdio.h>
#include <math.h>

// Replace __int32_t and __uint32_t with standard types
typedef int int32_t;
typedef unsigned int uint32_t;

typedef union {
  float value;
  uint32_t word;
} ieee_float_shape_type;

// Helper functions
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
      if (1.0e30f + x > (float)0.0) {
        if (i0 >= 0) i0 = 0; 
        else if (ix != 0) i0 = 0xbf800000;
      }
    } else {
      i = (0x007fffff) >> j0;
      if ((i0 & i) == 0) return x;
      if (1.0e30f + x > (float)0.0) {
        if (i0 < 0) i0 += (0x00800000) >> j0;
        i0 &= (~i);
      }
    }
  } else {
    if (ix >= 0x7f800000L) return x + x;
    else return x; 
  }

  ieee_float_shape_type sf_u;
  sf_u.word = i0;
  x = sf_u.value;

  return x;
}

int isnan_float(float x) { return x != x; }

float copysign_float(float x, float y) {
  uint32_t ix, iy;
  
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

float scalbn_float(float x, int n) {
  int32_t k, ix;
  uint32_t hx;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  hx = ix & 0x7fffffff;
  k = hx >> 23;

  if (hx == 0) return x;
  if (!((hx) < 0x7f800000L)) return x + x;
  
  if ((hx) < 0x00800000L) {
    x *= 3.355443200e+07f;
    gf_u.value = x;
    ix = gf_u.word;
    k = (ix & 0x7f800000) >> 23 - 25;
    if (n < -50000) return 1.0e-30f * x;
  }
  k = k + n;
 
  if (k > (0x7f7fffffL >> 23)) return 1.0e+30 * copysign_float(1.0e+30, x);
  if (k > 0) {
    ieee_float_shape_type sf_u;
    sf_u.word = ((ix & 0x807fffff) | (k << 23));
    x = sf_u.value;
    return x;
  }
  if (k < -22) {
    if (n > 50000) return 1.0e+30 * copysign_float(1.0e+30, x);
    else return 1.0e-30 * copysign_float(1.0e-30, x);
  }
  
  k += 25;

  ieee_float_shape_type sf_u;
  sf_u.word = ((ix & 0x807fffff) | (k << 23));
  x = sf_u.value;

  return x * 2.9802322388e-08;
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

// Functions `__kernel_rem_pio2f`, `__ieee754_rem_pio2f`, `__kernel_sinf`, and `__kernel_cosf` are lengthy
// and have been omitted from this conversion example for succinctness. 

float cos_float(float x) {
  float y[2], z = 0.0;
  int32_t n, ix;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  ix &= 0x7fffffff;
  if (ix <= 0x3f490fd8) return __kernel_cosf(x, z);
  else if (!((ix) < 0x7f800000L)) return x - x;
  else {
    n = __ieee754_rem_pio2f(x, y);
    switch (n & 3) {
      case 0: return __kernel_cosf(y[0], y[1]);
      case 1: return -__kernel_sinf(y[0], y[1], 1);
      case 2: return -__kernel_cosf(y[0], y[1]);
      default: return __kernel_sinf(y[0], y[1], 1);
    }
  }
}

int main() {
  float x = -1.0f / 0.0f; // -INF
  float res = cos_float(x);

  // x is -INF, the result shall be NAN
  if (!isnan_float(res)) {
    printf("Error: Expected NaN, but got a valid number.\n");
    return 1;
  } else {
    printf("Success: Result is NaN as expected.\n");
  }

  return 0;
}