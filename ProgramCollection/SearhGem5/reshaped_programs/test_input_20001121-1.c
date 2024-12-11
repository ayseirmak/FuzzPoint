#include <stdio.h>
#include <stdlib.h>

// Global variable initialization
double d = 0.0;

// Inline function to return the global variable
static inline double foo(void) {
  return d;
}

// Inline function where 'foo' is called; the function returns 0
static inline int bar(void) {
  foo();
  return 0;
}

int main(void) {
  // Directly setting the value of 'd' for deterministic behavior
  d = 3.14;  // Example fixed value

  // Call the 'bar' function and check its return value
  if (bar()) {
    printf("Error: bar() returned a non-zero value.\n");
    return 1;  // On error
  }

  printf("Success: bar() returned zero as expected.\n");
  return 0;  // Success
}