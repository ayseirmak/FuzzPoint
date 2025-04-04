#include <stdio.h>
#include <stdlib.h>

int test(float c) {
  return !!c * 7LL == 0;
}

int main(void) {
  // Initialize a float value for demonstration.
  // Choose a value that would be equivalent to user input, such as edge cases or typical values.
  float c = 0.5f;  // Example value to test the function.

  // Verify the test function.
  if (test(c) != 0) {
    printf("Test failed for input: %f\n", c);
  } else {
    printf("Test passed for input: %f\n", c);
  }

  return 0;
}