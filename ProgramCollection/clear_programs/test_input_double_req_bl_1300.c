#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
  double value;
  struct {
    __uint32_t lsw;
    __uint32_t msw;
  } parts;
} ieee_double_shape_type;

// Infinity check for doubles
int isinf_double(double x) {
  __int32_t hx, lx;
  ieee_double_shape_type ew_u;
  ew_u.value = x;
  hx = ew_u.parts.msw;
  lx = ew_u.parts.lsw;
  
  hx &= 0x7fffffff;
  hx |= (__uint32_t)(lx | (-lx)) >> 31;
  hx = 0x7ff00000 - hx;
  return 1 - (int)((__uint32_t)(hx | (-hx)) >> 31);
}

// NaN check for doubles
int isnan_double(double x) { 
  return x != x; 
}

int isfinite_double(double x) {
  __int32_t hx;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  hx = gh_u.parts.msw;
  return (int)((__uint32_t)((hx & 0x7fffffff) - 0x7ff00000) >> 31);
}

void reach_error() { 
  // Assert fail replacement with a simple print statement
  printf("Error: reach_error executed\n");
}

int main() {    
  // Replace nondeterministic values with a fixed set of values
  double test_values[] = {0.0, 1.0, -1.0, 1e300, -1e300, 0.0/0.0, 1.0/0.0}; // Includes NaN, Inf, finite and non-finite
  int num_tests = sizeof(test_values) / sizeof(test_values[0]);
  for (int i = 0; i < num_tests; i++) {
    double x = test_values[i];
    
    // x is inf, or nan we don't want to continue
    if (!isinf_double(x) && !isnan_double(x)) {
      double res = isfinite_double(x);

      // x is not inf, is not nan, the result shall be not 0.
      if (res == 0.0) {
        reach_error();
        return 1;
      }
    }
  }
  
  printf("All tests completed successfully.\n");
  return 0;
}