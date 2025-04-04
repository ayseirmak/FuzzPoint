#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
  // Initialize x with a typical value for testing square root
  double x = 100.0;
  double result = sqrt(x); // Use standard sqrt function
  printf("sqrt(%f) = %f\n", x, result);
  assert(result == 10.0);

  // Initialize y with a typical float value for testing square root
  float y = 100.0f;
  result = sqrt(y); // Use standard sqrt function with float
  printf("sqrt(%f) = %f\n", y, result);
  assert(result == 10.0f);

  // Test square root of negative zero
  printf("Test sqrt negative zero\n");
  x = -0.0;
  assert(signbit(x));
  result = sqrt(x);
  printf("sqrt(%f) = %f\n", x, result);
  assert(result == 0.0); // sqrt of -0.0 is 0.0
  assert(signbit(result) == signbit(x)); // Check for sign preservation

  // Test square root of a negative double value
  printf("Test sqrt negative\n");
  x = -DBL_MIN;
  assert(signbit(x));
  assert(x < 0.0);
  result = sqrt(x);
  printf("sqrt(%f) = %f\n", x, result);
  assert(isnan(result));

  return 0;
}