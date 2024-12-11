#include <stdio.h>

// Function to determine the sign bit of a double
int __signbit(double __x) {
  union { double __d; int __i[2]; } __u = {.__d = __x};
  return __u.__i[1] < 0;
}

int main() {
  // Initialize static double values for testing the function
  double val1 = -3.14;
  double val2 = 2.71;

  // Print the results of __signbit for the initialized values
  printf("Signbit of val1: %d\n", __signbit(val1));
  printf("Signbit of val2: %d\n", __signbit(val2));

  return 0;
}