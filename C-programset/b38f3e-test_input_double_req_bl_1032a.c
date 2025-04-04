#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define two types for the 32-bit integers
typedef int __int32_t;
typedef unsigned int __uint32_t;

// Define the union for IEEE double representation
typedef union {
  double value;
  struct {
    __uint32_t lsw;  // least significant word
    __uint32_t msw;  // most significant word
  } parts;
} ieee_double_shape_type;

// Function that checks if a double is NaN (Not a Number)
int isnan_double(double x) {
  return x != x; // NaN is not equal to itself
}

// Function to round a double to the nearest integer
double round_double(double x) {
  __int32_t msw; // most significant word
  __uint32_t lsw; // least significant word
  __int32_t exponent_less_1023;
  
  ieee_double_shape_type ew_u;
  ew_u.value = x;
  msw = ew_u.parts.msw;
  lsw = ew_u.parts.lsw;
  
  exponent_less_1023 = ((msw & 0x7ff00000) >> 20) - 1023;
  if (exponent_less_1023 < 20) {
    if (exponent_less_1023 < 0) {
      msw &= 0x80000000;
      if (exponent_less_1023 == -1)
        msw |= (1023 << 20);
      lsw = 0;
    } else {
      __uint32_t exponent_mask = 0x000fffff >> exponent_less_1023;
      if ((msw & exponent_mask) == 0 && lsw == 0)
        return x;
      msw += 0x00080000 >> exponent_less_1023;
      msw &= ~exponent_mask;
      lsw = 0;
    }
  } else if (exponent_less_1023 > 51) {
    if (exponent_less_1023 == 1024)
      return x + x;
    else
      return x;
  } else {
    __uint32_t exponent_mask = 0xffffffff >> (exponent_less_1023 - 20);
    __uint32_t tmp = lsw + (1 << (51 - exponent_less_1023));
    if (tmp < lsw)
      msw += 1;
    lsw = tmp;
    lsw &= ~exponent_mask;
  }
  
  ieee_double_shape_type iw_u;
  iw_u.parts.msw = msw;
  iw_u.parts.lsw = lsw;
  x = iw_u.value;
  
  return x;
}

// Function to check the sign bit of a double
int __signbit_double(double x) {
  __uint32_t msw;
  ieee_double_shape_type gh_u;
  gh_u.value = x;
  msw = gh_u.parts.msw;

  return (msw & 0x80000000) != 0;
}

int main() {
  double x = 0.0;
  double res = round_double(x);

  // Assert result shall be x
  if (!(res == 0.0 && __signbit_double(res) == 0)) {
    printf("Error: result is not as expected.\n");
    return 1;
  }
  
  printf("Round test passed, result is as expected.\n");
  return 0;
}