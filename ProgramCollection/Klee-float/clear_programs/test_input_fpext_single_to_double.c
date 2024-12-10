#include <assert.h>
#include <stdio.h>

int main() {
  float x = 1.0f;  // Initializing x to a positive value
  double y;

  // Direct conversion as there's no symbolic execution
  y = (double)x;

  // Asserting y is positive
  assert(y > 0.0);

  printf("x: %f, y: %f\n", x, y);  // Optional: For visibility of the values

  return 0; // Indicate successful execution
}