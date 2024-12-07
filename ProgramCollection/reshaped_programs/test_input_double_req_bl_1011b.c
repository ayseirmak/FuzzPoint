#include <stdio.h>
#include <assert.h>

// Structure for interpreting the parts of a double
typedef union {
  double value;
  struct {
    unsigned int lsw;
    unsigned int msw;
  } parts;
} ieee_double_shape_type;

// Function to check if a double is negative
int __signbit_double(double x) {
  unsigned int msw;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;
  
  return (msw & 0x80000000) != 0;
}

// Function to return the absolute value of a double
double fabs_double(double x) {
  unsigned int high;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  high = gh_u.parts.msw;
  
  ieee_double_shape_type sh_u;
  sh_u.value = x;
  sh_u.parts.msw = high & 0x7fffffff;
  x = sh_u.value;
  
  return x;
}

int main() {
  // Deterministic input value
  double x = -0.0;
  double res = fabs_double(x);

  // Requirement: fabs() should return +0 if input is +-0
  assert(res == 0.0 && __signbit_double(res) == 0);

  printf("Test passed: fabs_double(-0.0) = %f\n", res);
  return 0;
}