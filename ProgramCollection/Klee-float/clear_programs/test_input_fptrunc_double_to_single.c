#include <assert.h>
#include <stdio.h>

int main() {
  float x;
  double y;

  // Initialize 'y' with a positive value to simulate the original program behavior
  y = 1.2345; // You can choose any positive value

  x = (float)y;
  
  if (x > 0.0f) {
    printf("no truncation around 0.0\n");
  } else {
    // If x is 0.0f, assert the condition
    assert(x == 0.0f);
    printf("truncation around 0.0\n");
  }

  return 0;
}