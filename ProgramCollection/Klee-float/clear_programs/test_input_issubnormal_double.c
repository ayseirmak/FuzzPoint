#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
  // Initialize the variable x to a specific value.
  // For demonstration, we choose a small number to trigger subnormal condition.
  double x = 1.0e-308; // Typical subnormal example for demonstration

  // Check if the number is subnormal using standard C checks
  int category = fpclassify(x);
  if (category == FP_SUBNORMAL) {
    assert(category == FP_SUBNORMAL);
  } else {
    // The number is not subnormal, could be 0, normal, NaN or Inf
    assert(category != FP_SUBNORMAL);
  }

  return 0;
}