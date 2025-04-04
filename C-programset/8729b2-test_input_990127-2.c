#include <stdio.h>
#include <assert.h>

void fpEq(double x, double y) {
  if (x != y) {
    fprintf(stderr, "Floating point values not equal: %f != %f\n", x, y);
    assert(0); // Will trigger abort-like behavior with a more standard function
  }
}

void fpTest(double x, double y) {
  double result1 = (35.7 * 100.0) / 45.0;
  double result2 = (x * 100.0) / y;
  fpEq(result1, result2);
}

int main() {
  // Initialize x and y to fixed, meaningful test values
  double x = 35.7;
  double y = 45.0;

  // Call test function
  fpTest(x, y);

  // Indicate successful execution
  return 0;
}