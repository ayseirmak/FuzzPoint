#include <stdio.h>
#include <complex.h>
#include <assert.h>

typedef struct {
  _Complex double a;
  _Complex double b;
} Scf10;

Scf10 g1s;

// Function to check if complex value `x.a` is equal to `y`
void check(Scf10 x, _Complex double y) {
  if (x.a != y) {
    printf("Check failed: x.a != y\n");
  }
}

// Function to initialize the complex structure `p` with value `y`
void init(Scf10 *p, _Complex double y) {
  p->a = y;
}

int main(void) {
  // Initialize variables using typical test values
  _Complex double val = 3.0 + 4.0*I; // Example complex number

  // Initialize and verify the structure
  init(&g1s, val);
  check(g1s, val);
  
  return 0;
}