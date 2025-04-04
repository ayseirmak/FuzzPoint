#include <stdio.h>
#include <assert.h>

// Define constants for the program
typedef int __int32_t;
typedef unsigned int __uint32_t;

// Union to interpret the float as an integer
typedef union {
  float value;
  __uint32_t word;
} ieee_float_shape_type;

static const float one_fmod = 1.0f;
static const float Zero_fmod[] = { 0.0f, -0.0f };

// Function to calculate the floating-point modulus
float fmod_float(float x, float y) {
  __int32_t n, hx, hy, hz, ix, iy, sx, i;

  // Extract words from floating point numbers
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  hx = gf_u.word;

  gf_u.value = y;
  hy = gf_u.word;

  sx = hx & 0x80000000;
  hx ^= sx;
  hy &= 0x7fffffff;

  if ((hy == 0) || !(hx < 0x7f800000L) || (hy > 0x7f800000L)) {
    return (x * y) / (x * y);
  }
  if (hx < hy) return x;
  if (hx == hy) return Zero_fmod[(unsigned int)sx >> 31];
  if (hx < 0x00800000L) {
    for (ix = -126, i = (hx << 8); i > 0; i <<= 1) ix -= 1;
  } else ix = (hx >> 23) - 127;

  if (hy < 0x00800000L) {
    for (iy = -126, i = (hy << 8); i >= 0; i <<= 1) iy -= 1;
  } else iy = (hy >> 23) - 127;

  if (ix >= -126) hx = 0x00800000 | (0x007fffff & hx);
  else {
    n = -126 - ix;
    hx = hx << n;
  }
  if (iy >= -126) hy = 0x00800000 | (0x007fffff & hy);
  else {
    n = -126 - iy;
    hy = hy << n;
  }
  n = ix - iy;
  while (n--) {
    hz = hx - hy;
    if (hz < 0) {
      hx += hx;
    } else {
      if (hz == 0) return Zero_fmod[(unsigned int)sx >> 31];
      hx = hz + hz;
    }
  }
  hz = hx - hy;
  if (hz >= 0) {
    hx = hz;
  }

  if (hx == 0) return Zero_fmod[(unsigned int)sx >> 31];
  while (hx < 0x00800000) {
    hx += hx;
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

// Check if the float is finite
int isfinite_float(float x) {
  __int32_t ix;
  ieee_float_shape_type gf_u;
  gf_u.value = x;
  ix = gf_u.word;
  ix &= 0x7fffffff;
  return (ix < 0x7f800000L);
}

int main() {
  float x = 3.14f;  // Example deterministic float value
  float y = -1.0f / 0.0f; // -INF

  if (isfinite_float(x)) {
    float res = fmod_float(x, y);

    // Assert that the result is equal to x
    assert(res == x);
  }

  printf("Test passed.\n");
  return 0;
}