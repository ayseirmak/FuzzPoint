#include <stdio.h>
#include <stdlib.h>

void f(double *ty) {
  *ty = -1.0;
}

int main() {
  double foo[6]; // Array is defined but not used. Initialized for safety.
  for (int i = 0; i < 6; i++) {
      foo[i] = 0.0;
  }
  
  double tx = 3.0; // Initialize with a test value
  double ty, d;

  f(&ty);

  if (ty < 0) {
    ty = -ty;
  }
  d = (tx > ty) ? tx : ty;
  
  // Use a simple verification with printf. Assume success if it reaches here.
  if (ty != d) {
    printf("Error: Expected ty to equal d.\n");
  } else {
    printf("Success: ty equals d.\n");
  }
  
  return 0;
}