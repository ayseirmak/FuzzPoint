#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
  float x = 1.0e-40f; // Example of a subnormal float value.

  if (fpclassify(x) == FP_SUBNORMAL) {
    assert(fpclassify(x) == FP_SUBNORMAL);
  } else {
    assert(fpclassify(x) != FP_SUBNORMAL);
    // Could be 0, NaN, Inf, normal
  }

  printf("Execution path completed successfully.\n");
  return 0;
}