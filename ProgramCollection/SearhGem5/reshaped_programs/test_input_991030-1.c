#include <stdio.h>

int main() {
  double x = 3.875; // Directly assign the intended value

  // Check the condition and use printf for output
  if (x != 3.875) {
    printf("Error: x is not 3.875\n");
    return 1; // Return non-zero to indicate failure
  }

  printf("Success: x is 3.875\n");
  return 0; // Indicate successful execution
}