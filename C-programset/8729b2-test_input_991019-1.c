#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double epsilon;
} material_type;

material_type foo(double x) {
  material_type m;
  m.epsilon = 1.0 + x;
  return m;
}

int main() {
  int iterations = 10;  // Initialized with a fixed value, could be any typical number.
  int i;
  material_type x;

  for (i = 0; i < iterations; i++) {
    x = foo(1.0);
    if (x.epsilon != 1.0 + 1.0) {
      printf("Assertion failed: x.epsilon should be 2.0 after foo(1.0)\n");
    }
  }

  return 0;  // Indicate successful execution
}