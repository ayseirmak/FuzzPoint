#include <stdio.h>
#include <assert.h>

int main() {
  // Initialize variable x to a typical floating-point value within the specified range
  float x = 50.5f;  // Example value within the range (-128.9, 128.9)
  
  // Directly casting the float value to a signed int
  signed int y = (signed int) x;
  
  // Assert that the casted value stays within expected bounds
  assert(y >= -128);
  assert(y <= 128);
  
  // Print result to comply with ARM compatibility and usability
  printf("The value of y is: %d\n", y);

  return 0;
}