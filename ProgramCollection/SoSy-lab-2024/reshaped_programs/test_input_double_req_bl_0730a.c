#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

// NaN check for doubles
int isnan_double(double x) {
  return x != x;
}

static const double one_sqrt = 1.0, tiny_sqrt = 1.0e-300;

double __ieee754_sqrt(double x) {
  double z;
  __int32_t sign = 0x80000000;
  __uint32_t r, t1, s1, ix1, q1;
  __int32_t ix0, s0, q, m, t, i;

  ieee_double_shape_type ew_u;
  ew_u.value = x;
  ix0 = ew_u.parts.msw;
  ix1 = ew_u.parts.lsw;

  if ((ix0 & 0x7ff00000) == 0x7ff00000) {
    return x * x + x;
  }

  if (ix0 <= 0) {
    if (((ix0 & (~sign)) | ix1) == 0)
      return x;
    else if (ix0 < 0)
      return (x - x) / (x - x);
  }

  m = (ix0 >> 20);
  if (m == 0) {
    while (ix0 == 0) {
      m -= 21;
      ix0 |= (ix1 >> 11);
      ix1 <<= 21;
    }
    for (i = 0; (ix0 & 0x00100000) == 0; i++)
      ix0 <<= 1;
    m -= i - 1;
    ix0 |= (ix1 >> (32 - i));
    ix1 <<= i;
  }
  m -= 1023;
  ix0 = (ix0 & 0x000fffff) | 0x00100000;
  if (m & 1) {
    ix0 += ix0 + ((ix1 & sign) >> 31);
    ix1 += ix1;
  }
  m >>= 1;

  ix0 += ix0 + ((ix1 & sign) >> 31);
  ix1 += ix1;
  q = q1 = s0 = s1 = 0;
  r = 0x00200000;

  while (r != 0) {
    t = s0 + r;
    if (t <= ix0) {
      s0 = t + r;
      ix0 -= t;
      q += r;
    }
    ix0 += ix0 + ((ix1 & sign) >> 31);
    ix1 += ix1;
    r >>= 1;
  }

  r = sign;
  while (r != 0) {
    t1 = s1 + r;
    t = s0;
    if ((t < ix0) || ((t == ix0) && (t1 <= ix1))) {
      s1 = t1 + r;
      if (((t1 & sign) == sign) && (s1 & sign) == 0)
        s0 += 1;
      ix0 -= t;
      if (ix1 < t1)
        ix0 -= 1;
      ix1 -= t1;
      q1 += r;
    }
    ix0 += ix0 + ((ix1 & sign) >> 31);
    ix1 += ix1;
    r >>= 1;
  }

  if ((ix0 | ix1) != 0) {
    z = one_sqrt - tiny_sqrt;
    if (z >= one_sqrt) {
      z = one_sqrt + tiny_sqrt;
      if (q1 == (__uint32_t)0xffffffff) {
        q1 = 0;
        q += 1;
      } else if (z > one_sqrt) {
        if (q1 == (__uint32_t)0xfffffffe)
          q += 1;
        q1 += 2;
      } else
        q1 += (q1 & 1);
    }
  }
  ix0 = (q >> 1) + 0x3fe00000;
  ix1 = q1 >> 1;
  if ((q & 1) == 1)
    ix1 |= sign;
  ix0 += (m << 20);

  ieee_double_shape_type iw_u;
  iw_u.parts.msw = ix0;
  iw_u.parts.lsw = ix1;
  z = iw_u.value;

  return z;
}

// Infinity check for doubles
int isinf_double(double x) {
  return isinf(x);
}

int main() {
  // Fixed input: +Infinity
  double x = INFINITY;
  double res = __ieee754_sqrt(x);

  // Check if the result is +Infinity
  assert(isinf_double(res) && "Error: Result is not +Infinity");

  printf("Test passed for input +Infinity.\n");

  return 0;
}