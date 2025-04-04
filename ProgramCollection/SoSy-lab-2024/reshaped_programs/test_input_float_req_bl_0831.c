#include <stdio.h>
#include <assert.h>
#include <math.h>

// Define constants directly in the program to avoid any external dependencies
typedef union {
  float value;
  unsigned int word;
} ieee_float_shape_type;

// Check for NaN for floats
int isnan_float(float x) { return x != x; }

static const float one_exp = 1.0,
                   halF_exp[2] = {0.5, -0.5},
                   huge_exp = 1.0e+30, twom100_exp = 7.8886090522e-31,
                   ln2HI_exp[2] = {6.9313812256e-01, -6.9313812256e-01},
                   ln2LO_exp[2] = {9.0580006145e-06, -9.0580006145e-06},
                   invln2_exp = 1.4426950216e+00, P1_exp = 1.6666667163e-01,
                   P2_exp = -2.7777778450e-03, P3_exp = 6.6137559770e-05,
                   P4_exp = -1.6533901999e-06, P5_exp = 4.1381369442e-08;

float __ieee754_expf(float x) {
  float y, hi, lo, c, t;
  int k = 0, xsb;
  unsigned int hx, sx;

  ieee_float_shape_type gf_u;
  gf_u.value = x;
  sx = gf_u.word;

  xsb = (sx >> 31) & 1;
  hx = sx & 0x7fffffff;

  if (hx > 0x7f800000L) // x is NaN or Inf
    return x + x;
  if (hx == 0x7f800000L) // x is Inf
    return (xsb == 0) ? x : 0.0;
  if (sx > 0x42b17217) // overflow
    return huge_exp * huge_exp;
  if (sx < 0 && hx > 0x42cff1b5) // underflow
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

  unsigned int hy;
  ieee_float_shape_type sf_u;

  if (k >= -125) {
    gf_u.value = y;
    hy = gf_u.word;
    sf_u.word = hy + (k << 23);
    y = sf_u.value;
    return y;
  } else {
    gf_u.value = y;
    hy = gf_u.word;
    sf_u.word = hy + ((k + 100) << 23);
    y = sf_u.value;
    return y * twom100_exp;
  }
}

int main() {
  float x = NAN; // Explicitly setting NaN as input
  float res = __ieee754_expf(x);

  // Checking if the result is NaN
  if (!isnan_float(res)) {
    // Use standard assert for error handling
    assert(0 && "reach_error");
    return 1;
  }

  printf("Test passed: Result is NaN as expected.\n");
  return 0;
}