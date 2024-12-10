#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define EXP_MASK 0x7ff0000000000000LL
#define SIGNIFICAND_MASK 0x000fffffffffffffLL

int main() {
  double f = 0.0; // Initialize with zero as symbolic equivalence
  assert(sizeof(uint64_t) == sizeof(double));

  // Do some operation that means that f is more
  // than just a read of some bytes. It now is
  // an expression of type float.
  f = f + 1;

  uint64_t x = 0;
  memcpy(&x, &f, sizeof(double));

  // copy back
  double g;
  memcpy(&g, &x, sizeof(double));

  if ( (x & EXP_MASK) == EXP_MASK) {
    // Number is either NaN or infinity
    if ( (x & SIGNIFICAND_MASK) == 0) {
      // Check if f is infinity
      assert(isinf(f) != 0);
      assert(isinf(g) != 0);
    } else {
      // Check if f is NaN
      assert(isnan(f) != 0);
      assert(isnan(g) != 0);
    }
  }

  return 0;
}