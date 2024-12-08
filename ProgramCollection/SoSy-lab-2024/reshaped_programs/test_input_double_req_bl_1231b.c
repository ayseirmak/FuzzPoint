#include <stdio.h>
#include <math.h> // For NAN definition

typedef int __int32_t;
typedef unsigned int __uint32_t;

// Union to represent a double and its parts
typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

// Function to check NaN for doubles
int isnan_double(double x) { 
  return x != x; 
}

// Classifies the type of double
int __fpclassify_double(double x) {
  __uint32_t msw, lsw;
  ieee_double_shape_type ew_u;
  ew_u.value = x;
  msw = ew_u.parts.msw;
  lsw = ew_u.parts.lsw;

  if ((msw == 0x00000000 && lsw == 0x00000000) ||
      (msw == 0x80000000 && lsw == 0x00000000))
    return 2; // Zero
  else if ((msw >= 0x00100000 && msw <= 0x7fefffff) ||
           (msw >= 0x80100000 && msw <= 0xffefffff))
    return 4; // Normal number
  else if ((msw <= 0x000fffff) ||
           (msw >= 0x80000000 && msw <= 0x800fffff))
    return 3; // Subnormal number
  else if ((msw == 0x7ff00000 && lsw == 0x00000000) ||
           (msw == 0xfff00000 && lsw == 0x00000000))
    return 1; // Infinity
  else
    return 0; // NaN
}

// Finds minimum of two doubles
double fmin_double(double x, double y) {
  if (__fpclassify_double(x) == 0)
    return y;
  if (__fpclassify_double(y) == 0)
    return x;

  return x < y ? x : y;
}

int main() {
  double x = 1.23; // Fixed value for x (could be any specific value)
  double y = NAN;  // Define y as NaN

  if (!isnan_double(x)) {
    double res = fmin_double(x, y);

    // Check if result is as expected: res should be x
    if (res != x) {
      printf("Error: Expected %f but got %f\n", x, res);
      return 1;
    }
  }

  printf("Test passed: x is %f, result is %f\n", x, x);
  return 0;
}