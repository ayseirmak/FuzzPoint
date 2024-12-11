#include <stdio.h>
#include <string.h>
#include <assert.h>

struct S {
  char c;
  char arr[4];
  float f;
};

char A[4] = { '1', '2', '3', '4' };

void foo(struct S s) {
  // Check if the arrays are identical; replace abort with assert
  assert(memcmp(s.arr, A, 4) == 0);
}

int main() {
  // Initialize a typical value for x, here, we are choosing 1
  int x = 1;
  
  struct S s;
  memcpy(s.arr, A, 4);

  foo(s);
  
  // Return 0 to indicate successful execution
  return 0;
}