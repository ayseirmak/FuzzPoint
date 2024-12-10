#include <stdio.h>
#include <assert.h>

int main() {
  double a1 = -1.1;
  double a2 = 1.2;
  
  int b1 = (int) a1;
  assert(b1 == -1);
  
  int b2 = (int) a2;
  assert(b2 == 1);

  a1 = (double) b1;
  assert(a1 == -1);

  a2 = (double) b2;
  assert(a2 == 1);

  printf("All assertions passed successfully.\n");

  return 0;
}