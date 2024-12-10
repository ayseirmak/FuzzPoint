#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>

// Initialize global variable
long double globalLongDouble = 0.0l;

void dump_long_double(long double ld) {
  uint64_t data[2] = {0, 0};
  memcpy(data, &ld, 10);
  printf("a: 0x%.4" PRIx16 " %.16" PRIx64 "\n", (uint16_t)data[1], data[0]);
}

int main() {
  // Initialize 'x' with a test case value, e.g., 1.0l
  long double x = 1.0l;

  // Remove symbolic operations and provide deterministic behavior
  // As symbolic execution is not part of standard C, initialize with a realistic value

  if (x > 0.0l) {
    printf("Greater than 0.0l\n");
  } else {
    printf("Not greater than 0.0l\n");
  }

  if (x == globalLongDouble) {
    printf("globalLongDouble equal\n");
  } else {
    printf("globalLongDouble not equal\n");
  }

  return 0; // Indicate successful execution
}