#include <stdio.h>
#include <assert.h>

// Typedef integers to match the original code
typedef int __int32_t;
typedef unsigned int __uint32_t;

// Define the union to manipulate IEEE double-precision floating-point numbers
typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

// Function to determine the sign bit of a double
int __signbit_double(double x) {
  __uint32_t msw;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;
  return (msw & 0x80000000) != 0;
}

// Replacement for the fabs function for doubles
double fabs_double(double x) {
  __uint32_t high;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  high = gh_u.parts.msw;

  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = (high & 0x7fffffff);
  x = sh_u.value;

  return x;
}

int main() {
  double x = 0.0;  // Fixed input as deterministic value
  double res = fabs_double(x);

  // Assert to verify the requirement
  assert(res == 0.0 && __signbit_double(res) == 0);

  printf("Test passed: fabs_double(0.0) = %.1f\n", res);
  
  return 0;
}