#include <assert.h>
#include <math.h>
#include <stdio.h>

// Function to simulate klee_urange behavior
int simulate_range(int start, int end) {
    static int index = 0; // Static variable to alternate between the cases
    return (index++) % (end - start) + start;
}

int main() {
  int a = simulate_range(0, 3);
  int b;

  // fork states
  switch (a) {
  case 0:
    b = -0; // b will be -0, effectively 0
    break;
  case 1:
    b = -1;
    break;
  case 2:
    b = -2;
    break;
  default:
    assert(0 && "Impossible switch target");
  }

  // test 80-bit external dispatch, using long double for precision
  long double d = powl((long double)-11.0, (long double)a);
  printf("powl(-11.0,%d)=%.1Lf\n", a, d);

  // test 80-bit fdiv
  long double e;
  if (b == 0) {
    e = INFINITY; // Division by zero results in infinity
  } else {
    e = (long double)1 / (long double)b;
  }
  printf("1/%d=%Lf\n", b, e);

  return 0;
}