#include <stdio.h>
#include <assert.h>

void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
  if (!cond) {
    printf("Aborting due to assumption failure\n");
    abort();
  }
}

float f(float x) {
  return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;
}

float fp(float x) {
  return 1 - (x * x) / 2.0f + (x * x * x * x) / 24.0f + (x * x * x * x * x * x) / 720.0f;
}

int main() {
  // Using a fixed deterministic input value
  const float fixed_input = 1.0f;
  const float VAL = 1.4f; // Based on NR being 7
  const int ITERATIONS = 1;

  // Ensuring the input meets the specified conditions
  assume_abort_if_not(fixed_input > -VAL && fixed_input < VAL);

  // Calculating x based on deterministic input
  float x = fixed_input - f(fixed_input) / fp(fixed_input);
#if ITERATIONS > 1
  x = x - f(x) / fp(x);
#if ITERATIONS > 2
  x = x - f(x) / fp(x);
#endif
#endif

  // Verifying the condition and triggering an error if the condition is violated
  if (!(x < 0.1)) {
    reach_error();
  } else {
    printf("Success: x is less than 0.1\n");
  }

  return 0;
}