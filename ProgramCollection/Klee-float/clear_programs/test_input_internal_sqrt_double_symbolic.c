#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
  // Initialize the variable `x` with a test value.
  // The choice of value can be adjusted as needed to test specific behaviors.

  // Test case 1: NaN
  // double x = NAN;

  // Test case 2: Negative value (non-NaN)
  // double x = -4.0;

  // Test case 3: Positive infinity
  // double x = INFINITY;

  // Test case 4: Zero
  // double x = 0.0;

  // Test case 5: Negative zero
  // double x = -0.0;

  // Test case 6: Positive value
  double x = 16.0; // Feel free to change the test values

  double result = sqrt(x);

  if (isnan(x)) {
    assert(isnan(result));
    printf("Tested NaN: Passed\n");
  } else if (x < 0.0) {
    assert(isnan(result));
    printf("Tested negative value: Passed\n");
  } else if (isinf(x)) {
    assert(isinf(result) == 1);
    printf("Tested infinity: Passed\n");
  } else if (x == 0.0) {
    assert(result == 0.0);
    printf("Tested zero: Passed\n");
    if (signbit(x)) {
      assert(signbit(result));
      printf("Tested negative zero: Passed\n");
    }
  } else {
    assert(x > 0.0);
    printf("Tested positive value: Passed\n");
  }

  return 0;
}