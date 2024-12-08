#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <assert.h>

typedef double L;

void f (L p0, L p1, L p2, L p3, L p4, L p5, L p6, L p7, L p8, ...)
{
  va_list select;
  va_start(select, p8);

  int expected_value = 10;
  int actual_value = va_arg(select, int);

  // Use an assertion instead of aborting the program
  assert(actual_value == expected_value);

  va_end(select);
}

int main ()
{
  // Call function with deterministic inputs
  f(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10, 11, 12);
  
  printf("Program executed successfully.\n"); // Logging success
  return 0; // Use return 0 instead of exit(0)
}