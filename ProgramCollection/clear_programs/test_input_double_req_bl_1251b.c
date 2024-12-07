#include <stdio.h>
#include <math.h>

// Instead of using __VERIFIER_nondet_double, we declare a fixed value
double fixed_value = 42.0;

// Union for converting double to its IEEE representation
typedef union {
  double value;
  struct {
    unsigned int lsw;
    unsigned int msw;
  } parts;
} ieee_double_shape_type;

// Function to check if a double is NaN
int isnan_double(double x) {
    return x != x;
}

// Categorizes the floating-point value into different categories like zero, normal, etc.
int __fpclassify_double(double x) {
  unsigned int msw, lsw;

  ieee_double_shape_type ew_u;
  ew_u.value = x;
  msw = ew_u.parts.msw;
  lsw = ew_u.parts.lsw;

  if ((msw == 0x00000000 && lsw == 0x00000000) ||
      (msw == 0x80000000 && lsw == 0x00000000))
    return 2; // Zero
  else if ((msw >= 0x00100000 && msw <= 0x7fefffff) ||
           (msw >= 0x80100000 && msw <= 0xffefffff))
    return 4; // Normal
  else if ((msw <= 0x000fffff) ||
           (msw >= 0x80000000 && msw <= 0x800fffff))
    return 3; // Subnormal
  else if ((msw == 0x7ff00000 && lsw == 0x00000000) ||
           (msw == 0xfff00000 && lsw == 0x00000000))
    return 1; // Infinite
  else
    return 0; // NaN
}

// Function to return the maximum of two double values
double fmax_double(double x, double y) {
  if (__fpclassify_double(x) == 0)
    return y;
  if (__fpclassify_double(y) == 0)
    return x;

  return x > y ? x : y;
}

int main() {
  // Use a fixed value for x instead of nondeterministic input
  double x = fixed_value;
  double y = 0.0 / 0.0; // NaN representation

  // Check and print result to ensure behavior as expected
  if (!isnan_double(x)) {
    double res = fmax_double(x, y);

    // If y is NaN and x is not NaN, the result should be x
    if (res != x) {
      // Use printf to log error
      printf("Error: Expected %f but got %f\n", x, res);
      return 1;
    }
  }

  printf("Test passed successfully.\n");
  return 0;
}