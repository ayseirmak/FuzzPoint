#include <stdio.h>
#include <assert.h>

// Assume abort function similar to the standard library
void assume_abort_if_not(int cond) {
  if (!cond) {
    // Use assertion to simulate abort behavior
    assert(0);
  }
}

#define NR 5

#if NR == 1
#define VAL 0.2f
#elif NR == 2
#define VAL 0.4f
#elif NR == 3
#define VAL 0.6f
#elif NR == 4
#define VAL 0.8f
#elif NR == 5
#define VAL 1.0f
#elif NR == 6
#define VAL 1.2f
#elif NR == 7
#define VAL 1.4f
#elif NR == 8
#define VAL 2.0f
#endif

#define ITERATIONS 2

#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
#error Number of iterations must be between 1 and 3
#endif

float f(float x) {
  return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;
}

float fp(float x) {
  return 1 - (x * x) / 2.0f + (x * x * x * x) / 24.0f + (x * x * x * x * x * x) / 720.0f;
}

int main() {
  // Use a fixed deterministic input value as replacement for nondeterministic input
  float IN = 0.5f; // This value should be within the range (-VAL, VAL)
  
  // Ensure the input value meets the assumed conditions
  assume_abort_if_not(IN > -VAL && IN < VAL);

  float x = IN - f(IN) / fp(IN);
#if ITERATIONS > 1 
  x = x - f(x) / fp(x);
#if ITERATIONS > 2
  x = x - f(x) / fp(x);
#endif 
#endif

  // Check the convergence condition
  if (!(x < 0.1)) {
    printf("Error: x is not less than 0.1\n");
    // Use assertion to trigger error
    assert(0);
  } else {
    printf("Computation successful: x is less than 0.1\n");
  }

  return 0;
}