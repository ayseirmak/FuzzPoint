#include <stdio.h>
#include <assert.h>

#define NR 4

#define VAL 0.8f

#define ITERATIONS 2

void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
  if (!cond) { 
    printf("Abort due to assumption failure\n");
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
  // Fixed deterministic input, replacing nondeterministic input
  float IN = 0.1f;

  // Assume IN is within the specified range
  assume_abort_if_not(IN > -VAL && IN < VAL);

  float x = IN - f(IN) / fp(IN);
#if ITERATIONS > 1
  x = x - f(x) / fp(x);
#if ITERATIONS > 2
  x = x - f(x) / fp(x);
#endif
#endif

  // Check if the final value is within the required range
  if (!(x < 0.1f)) {
    reach_error();
  }

  return 0;
}