#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct s {
  double d;
};

struct s sub(struct s s) {
  s.d += 1.0;
  return s;
}

int main() {
  // Initialize a fixed value to simulate input (for example, 5.0)
  double fixed_value = 5.0;
  
  struct s t = { fixed_value };
  t = sub(t);
  
  // Use assert to verify the functionality
  assert(t.d == fixed_value + 1.0);
  
  printf("Assertion passed. Value: %f\n", t.d);

  return 0;
}