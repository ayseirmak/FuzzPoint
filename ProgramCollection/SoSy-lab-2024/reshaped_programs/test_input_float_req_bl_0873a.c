#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float one_fmod = 1.0, Zero_fmod[] = { 0.0, -0.0 };

float fmod_float(float x, float y) {
  __int32_t n, hx, hy, hz, ix, iy, sx, i;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  hx = gf_u.word;

  gf_u.value = y;
  hy = gf_u.word;

  sx = hx & 0x80000000;
  hx ^= sx;
  hy &= 0x7fffffff;

  if (((hy) == 0) || !((hx) < 0x7f800000L) || ((hy) > 0x7f800000L))
    return (x * y) / (x * y);
  if (hx < hy)
    return x;
  if (hx == hy)
    return Zero_fmod[(__uint32_t)sx >> 31];
  if (((hx) < 0x00800000L)) {
    for (ix = -126, i = (hx << 8); i > 0; i <<= 1)
      ix -= 1;
  } else
    ix = (hx >> 23) - 127;

  if (((hy) < 0x00800000L)) {
    for (iy = -126, i = (hy << 8); i >= 0; i <<= 1)
      iy -= 1;
  } else
    iy = (hy >> 23) - 127;

  if (ix >= -126)
    hx = 0x00800000 | (0x007fffff & hx);
  else {
    n = -126 - ix;
    hx = hx << n;
  }
  if (iy >= -126)
    hy = 0x00800000 | (0x007fffff & hy);
  else {
    n = -126 - iy;
    hy = hy << n;
  }
  n = ix - iy;
  while (n--) {
    hz = hx - hy;
    if (hz < 0) {
      hx = hx + hx;
    } else {
      if (hz == 0)
        return Zero_fmod[(__uint32_t)sx >> 31];
      hx = hz + hz;
    }
  }
  hz = hx - hy;
  if (hz >= 0) {
    hx = hz;
  }

  if (hx == 0)
    return Zero_fmod[(__uint32_t)sx >> 31];
  while (hx < 0x00800000) {
    hx = hx + hx;
    iy -= 1;
  }
  if (iy >= -126) {
    hx = ((hx - 0x00800000) | ((iy + 127) << 23));
    ieee_float_shape_type sf_u;
    sf_u.word = (hx | sx);
    x = sf_u.value;
  } else {
    n = -126 - iy;
    hx >>= n;
    ieee_float_shape_type sf_u;
    sf_u.word = (hx | sx);
    x = sf_u.value;
    x *= one_fmod;
  }
  return x;
}

static const float one_sqrt = 1.0, tiny_sqrt = 1.0e-30;

float __ieee754_sqrtf(float x) {
  float z;
  __uint32_t r, hx;
  __int32_t ix, s, q, m, t, i;

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

float copysign_float(float x, float y) {
  __uint32_t ix, iy;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  gf_u.value = y;
  iy = gf_u.word;
  ieee_float_shape_type sf_u;
  sf_u.word = (ix & 0x7fffffff) | (iy & 0x80000000);
  return sf_u.value;
}

static const float two25_scalbn = 3.355443200e+07,
                   twom25_scalbn = 2.9802322388e-08,
                   huge_scalbn = 1.0e+30,
                   tiny_scalbn = 1.0e-30;

float scalbn_float(float x, int n) {
  __int32_t k, ix;
  __uint32_t hx;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;

  hx = ix & 0x7fffffff;
  k = hx >> 23;
  if (((hx) == 0))
    return x;
  if (!((hx) < 0x7f800000L))
    return x + x;
  if (((hx) < 0x00800000L)) {
    x *= two25_scalbn;
    gf_u.value = x;
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
    sf_u.word = (ix & 0x807fffff) | (k << 23);
    return sf_u.value;
  }
  if (k < -22) {
    if (n > 50000)
      return huge_scalbn * copysign_float(huge_scalbn, x);
    else
      return tiny_scalbn * copysign_float(tiny_scalbn, x);
  }
  k += 25;
  ieee_float_shape_type sf_u;
  sf_u.word = (ix & 0x807fffff) | (k << 23);
  return sf_u.value * twom25_scalbn;
}

float fabs_float(float x) {
  __uint32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ieee_float_shape_type sf_u;
  sf_u.word = ix & 0x7fffffff;
  return sf_u.value;
}

static const float bp_pow[] = { 1.0, 1.5 },
                   dp_h_pow[] = { 0.0, 5.84960938e-01 },
                   dp_l_pow[] = { 0.0, 1.56322085e-06 },
                   zero_pow = 0.0, one_pow = 1.0, two_pow = 2.0,
                   two24_pow = 16777216.0, huge_pow = 1.0e30,
                   tiny_pow = 1.0e-30, L1_pow = 6.0000002384e-01,
                   L2_pow = 4.2857143283e-01, L3_pow = 3.3333334327e-01,
                   L4_pow = 2.7272811532e-01, L5_pow = 2.3066075146e-01,
                   L6_pow = 2.0697501302e-01, P1_pow = 1.6666667163e-01,
                   P2_pow = -2.7777778450e-03, P3_pow = 6.6137559770e-05,
                   P4_pow = -1.6533901999e-06, P5_pow = 4.1381369442e-08,
                   lg2_pow = 6.9314718246e-01, lg2_h_pow = 6.93145752e-01,
                   lg2_l_pow = 1.42860654e-06, ovt_pow = 4.2995665694e-08,
                   cp = 9.6179670095e-01, cp_h_pow = 9.6179199219e-01,
                   cp_l_pow = 4.7017383622e-06, ivln2_pow = 1.4426950216e+00,
                   ivln2_h_pow = 1.4426879883e+00,
                   ivln2_l_pow = 7.0526075433e-06;

float __ieee754_powf(float x, float y) {
  float z, ax, z_h, z_l, p_h, p_l;
  float y1, t1, t2, r, s, t, u, v, w;
  __int32_t i, j, k, yisint, n;
  __int32_t hx, hy, ix, iy, is;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  hx = gf_u.word;

  gf_u.value = y;
  hy = gf_u.word;

  ix = hx & 0x7fffffff;
  iy = hy & 0x7fffffff;

  if (((iy) == 0))
    return one_pow;

  if (((ix) > 0x7f800000L) || ((iy) > 0x7f800000L)) {
    if (ix == 0x3f800000)
      return one_pow;
    else
      return __builtin_nanf("");
  }
  yisint = 0;
  if (hx < 0) {
    if (iy >= 0x4b800000)
      yisint = 2;
    else if (iy >= 0x3f800000) {
      k = (iy >> 23) - 0x7f;
      j = iy >> (23 - k);
      if ((j << (23 - k)) == iy)
        yisint = 2 - (j & 1);
    }
  }

  if (((iy) == 0x7f800000L)) {
    if (ix == 0x3f800000)
      return one_pow;
    else if (ix > 0x3f800000)
      return (hy >= 0) ? y : zero_pow;
    else
      return (hy < 0) ? -y : zero_pow;
  }
  if (iy == 0x3f800000) {
    if (hy < 0)
      return one_pow / x;
    else
      return x;
  }
  if (hy == 0x40000000)
    return x * x;
  if (hy == 0x3f000000) {
    if (hx >= 0)
      return __ieee754_sqrtf(x);
  }

  ax = fabs_float(x);

  if (((ix) == 0x7f800000L) || ((ix) == 0) || ix == 0x3f800000) {
    z = ax;
    if (hy < 0)
      z = one_pow / z;
    if (hx < 0) {
      if (((ix - 0x3f800000) | yisint) == 0) {
        z = (z - z) / (z - z);
      } else if (yisint == 1)
        z = -z;
    }
    return z;
  }

  if (((((__uint32_t)hx >> 31) - 1) | yisint) == 0)
    return (x - x) / (x - x);
  if (iy > 0x4d000000) {
    if (ix < 0x3f7ffff8)
      return (hy < 0) ? huge_pow * huge_pow : tiny_pow * tiny_pow;
    if (ix > 0x3f800007)
      return (hy > 0) ? huge_pow * huge_pow : tiny_pow * tiny_pow;

    t = ax - 1;
    w = (t * t) * ((float)0.5 - t * ((float)0.333333333333 - t * (float)0.25));
    u = ivln2_h_pow * t;
    v = t * ivln2_l_pow - w * ivln2_pow;
    t1 = u + v;
    ieee_float_shape_type gf_u_local;
    gf_u_local.value = t1;
    is = gf_u_local.word;
    ieee_float_shape_type sf_u;
    sf_u.word = is & 0xfffff000;
    t1 = sf_u.value;
    t2 = v - (t1 - u);
  } else {
    float s2, s_h, s_l, t_h, t_l;
    n = 0;

    if (((ix) < 0x00800000L)) {
      ax *= two24_pow;
      n -= 24;
      ieee_float_shape_type gf_u_local;
      gf_u_local.value = ax;
      ix = gf_u_local.word;
    }
    n += (ix >> 23) - 0x7f;
    j = ix & 0x007fffff;

    ix = j | 0x3f800000;
    if (j <= 0x1cc471)
      k = 0;
    else if (j < 0x5db3d7)
      k = 1;
    else {
      k = 0;
      n += 1;
      ix -= 0x00800000;
    }
    ieee_float_shape_type sf_u_local;
    sf_u_local.word = ix;
    ax = sf_u_local.value;
    u = ax - bp_pow[k];
    v = one_pow / (ax + bp_pow[k]);
    s = u * v;
    s_h = s;
    ieee_float_shape_type gf_u_local;
    gf_u_local.value = s_h;
    is = gf_u_local.word;
    sf_u_local.word = is & 0xfffff000;
    s_h = sf_u_local.value;
    sf_u_local.word = ((ix >> 1) | 0x20000000) + 0x0040000 + (k << 21);
    t_h = sf_u_local.value;
    t_l = ax - (t_h - bp_pow[k]);
    s_l = v * ((u - s_h * t_h) - s_h * t_l);
    s2 = s * s;
    r = s2 * s2 *
        (L1_pow +
         s2 * (L2_pow +
               s2 * (L3_pow + s2 * (L4_pow + s2 * (L5_pow + s2 * L6_pow)))));
    r += s_l * (s_h + s);
    s2 = s_h * s_h;
    t_h = (float)3.0 + s2 + r;
    gf_u_local.value = t_h;
    is = gf_u_local.word;
    sf_u_local.word = is & 0xfffff000;
    t_h = sf_u_local.value;
    t_l = r - ((t_h - (float)3.0) - s2);
    u = s_h * t_h;
    v = s_l * t_h + t_l * s;
    p_h = u + v;
    gf_u_local.value = p_h;
    is = gf_u_local.word;
    sf_u_local.word = is & 0xfffff000;
    p_h = sf_u_local.value;
    p_l = v - (p_h - u);
    z_h = cp_h_pow * p_h;
    z_l = cp_l_pow * p_h + p_l * cp + dp_l_pow[k];

    t = (float)n;
    t1 = ((z_h + z_l) + dp_h_pow[k]) + t;
    gf_u_local.value = t1;
    is = gf_u_local.word;
    sf_u_local.word = is & 0xfffff000;
    t1 = sf_u_local.value;
    t2 = z_l - ((t1 - t) - dp_h_pow[k] + z_h);
  }

  s = one_pow;
  if (((((__uint32_t)hx >> 31) - 1) | (yisint - 1)) == 0)
    s = -one_pow;
  
  ieee_float_shape_type gf_u_local;
  gf_u_local.value = y;
  is = gf_u_local.word;
  
  ieee_float_shape_type sf_u_local;
  sf_u_local.word = is & 0xfffff000;
  y1 = sf_u_local.value;
  
  p_l = (y - y1) * t1 + y * t2;
  p_h = y1 * t1;
  z = p_l + p_h;
  
  gf_u_local.value = z;
  j = gf_u_local.word;
  
  i = j & 0x7fffffff;
  
  if (j > 0) {
    if (i > 0x43000000)
      return s * huge_pow * huge_pow;
    else if (i == 0x43000000)
      if (p_l + ovt_pow > z - p_h)
        return s * huge_pow * huge_pow;
  } else {
    if (i > 0x43160000)
      return s * tiny_pow * tiny_pow;
    else if (i == 0x43160000)
      if (p_l <= z - p_h)
        return s * tiny_pow * tiny_pow;
  }

  k = (i >> 23) - 0x7f;
  n = 0;
  if (i > 0x3f000000) {
    n = j + (0x00800000 >> (k + 1));
    k = ((n & 0x7fffffff) >> 23) - 0x7f;
    sf_u_local.word = n & ~(0x007fffff >> k);
    t = sf_u_local.value;
    n = ((n & 0x007fffff) | 0x00800000) >> (23 - k);
    if (j < 0)
      n = -n;
    p_h -= t;
  }
  t = p_l + p_h;
  gf_u_local.value = t;
  is = gf_u_local.word;
  sf_u_local.word = is & 0xfffff000;
  t = sf_u_local.value;
  
  u = t * lg2_h_pow;
  v = (p_l - (t - p_h)) * lg2_pow + t * lg2_l_pow;
  z = u + v;
  w = v - (z - u);
  
  t = z * z;
  t1 = z -
       t * (P1_pow + t * (P2_pow + t * (P3_pow + t * (P4_pow + t * P5_pow))));
  
  r = (z * t1) / (t1 - two_pow) - (w + z * w);
  z = one_pow - (r - z);
  
  gf_u_local.value = z;
  j = gf_u_local.word;
  
  j += (n << 23);
  
  if ((j >> 23) <= 0)
    z = scalbn_float(z, (int)n);
  else {
    sf_u_local.word = j;
    z = sf_u_local.value;
  }
  
  return s * z;
}

int main() {
  // Given conditions: x == -1 and y == +inf
  float x = -1.0f;
  float y = INFINITY; // positive infinity
  float res = __ieee754_powf(x, y);

  // result should be 1.0
  assert(res == 1.0f);

  printf("Test passed, result: %.1f\n", res);

  return 0;
}