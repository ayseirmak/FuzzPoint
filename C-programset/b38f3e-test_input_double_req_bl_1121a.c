#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

typedef union {
  double value;
  struct {
    uint32_t lsw;
    uint32_t msw;
  } parts;
} ieee_double_shape_type;

// Function to check for NaN values for doubles
int isnan_double(double x) {
  return x != x;
}

static const double one_fmod = 1.0;
static const double Zero_fmod[] = {0.0, -0.0};

double fmod_double(double x, double y) {
  int32_t n, hx, hy, hz, ix, iy, sx, i;
  uint32_t lx, ly, lz;

  ieee_double_shape_type ew_u;

  ew_u.value = x;
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;

  ew_u.value = y;
  hy = ew_u.parts.msw;
  ly = ew_u.parts.lsw;

  sx = hx & 0x80000000;
  hx ^= sx;
  hy &= 0x7FFFFFFF;

  if ((hy | ly) == 0 || (hx >= 0x7FF00000) ||
      ((hy | ((ly | -ly) >> 31)) > 0x7FF00000))
    return (x * y) / (x * y);

  if (hx <= hy) {
    if ((hx < hy) || (lx < ly))
      return x;
    if (lx == ly)
      return Zero_fmod[(uint32_t)sx >> 31];
  }

  if (hx < 0x00100000) {
    if (hx == 0) {
      for (ix = -1043, i = lx; i > 0; i <<= 1)
        ix -= 1;
    } else {
      for (ix = -1022, i = (hx << 11); i > 0; i <<= 1)
        ix -= 1;
    }
  } else {
    ix = (hx >> 20) - 1023;
  }

  if (hy < 0x00100000) {
    if (hy == 0) {
      for (iy = -1043, i = ly; i > 0; i <<= 1)
        iy -= 1;
    } else {
      for (iy = -1022, i = (hy << 11); i > 0; i <<= 1)
        iy -= 1;
    }
  } else {
    iy = (hy >> 20) - 1023;
  }

  // Normalize x
  if (ix >= -1022)
    hx = 0x00100000 | (0x000FFFFF & hx);
  else {
    n = -1022 - ix;
    if (n <= 31) {
      hx = (hx << n) | (lx >> (32 - n));
      lx <<= n;
    } else {
      hx = lx << (n - 32);
      lx = 0;
    }
  }

  // Normalize y
  if (iy >= -1022)
    hy = 0x00100000 | (0x000FFFFF & hy);
  else {
    n = -1022 - iy;
    if (n <= 31) {
      hy = (hy << n) | (ly >> (32 - n));
      ly <<= n;
    } else {
      hy = ly << (n - 32);
      ly = 0;
    }
  }

  // x mod y
  n = ix - iy;
  while (n--) {
    hz = hx - hy;
    lz = lx - ly;
    if (lx < ly)
      hz -= 1;
    if (hz < 0) {
      hx = hx + hx + (lx >> 31);
      lx = lx + lx;
    } else {
      if ((hz | lz) == 0)
        return Zero_fmod[(uint32_t)sx >> 31];
      hx = hz + hz + (lz >> 31);
      lx = lz + lz;
    }
  }
  hz = hx - hy;
  lz = lx - ly;
  if (lx < ly)
    hz -= 1;
  if (hz >= 0) {
    hx = hz;
    lx = lz;
  }

  // Convert back to floating-point
  if ((hx | lx) == 0)
    return Zero_fmod[(uint32_t)sx >> 31];
  while (hx < 0x00100000) {
    hx = hx + hx + (lx >> 31);
    lx = lx + lx;
    iy -= 1;
  }
  if (iy >= -1022) {
    hx = ((hx - 0x00100000) | ((iy + 1023) << 20));
    ew_u.parts.msw = (hx | sx);
    ew_u.parts.lsw = lx;
    x = ew_u.value;
  } else {
    n = -1022 - iy;
    if (n <= 20) {
      lx = (lx >> n) | ((uint32_t)hx << (32 - n));
      hx >>= n;
    } else if (n <= 31) {
      lx = (hx << (32 - n)) | (lx >> n);
      hx = sx;
    } else {
      lx = hx >> (n - 32);
      hx = sx;
    }
    ew_u.parts.msw = (hx | sx);
    ew_u.parts.lsw = lx;
    x = ew_u.value;
    x *= one_fmod;
  }
  return x;
}

int main() {
  double x = 5.0;  // Set a fixed value for deterministic behavior
  double y = 0.0;  // Fixed value, specifically testing division by zero
  double res = fmod_double(x, y);

  // Assert that the result is NaN
  if (!isnan_double(res)) {
    printf("Error: Result is not NaN when y is zero.\n");
    return 1;
  }

  printf("Test passed: Result is NaN when y is zero.\n");
  return 0;
}