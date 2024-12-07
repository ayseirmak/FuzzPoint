#include <stdio.h>
#include <assert.h>

// Define constants directly instead of using a nondeterministic input
#define VAL 0.6f
#define PREDEFINED_IN 0.05f  // Deterministic input
#define ITERATIONS 3

// Ensure iterations are within the specified range
#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
#error Number of iterations must be between 1 and 3
#endif 

// Function to emulate assuming a condition
void assume_abort_if_not(int cond) {
  if (!cond) {
    printf("Condition failed, aborting.\n");
    abort();
  }
}

// Mathematical function approximations
float f(float x) {
  return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;
}

float fp(float x) {
  return 1 - (x * x) / 2.0f + (x * x * x * x) / 24.0f + (x * x * x * x * x * x) / 720.0f;
}

int main() {
  // Use a predetermined, constant input value
  float IN = PREDEFINED_IN;
  assume_abort_if_not(IN > -VAL && IN < VAL);

  float x = IN - f(IN) / fp(IN);

#if ITERATIONS > 1
  x = x - f(x) / fp(x);
#if ITERATIONS > 2
  x = x - f(x) / fp(x);
#endif 
#endif

  // Validate the final value of x
  if (!(x < 0.1)) {
    printf("Reach error triggered.\n");
    assert(0);  // Trigger assertion failure to indicate error
  }

  return 0;
}