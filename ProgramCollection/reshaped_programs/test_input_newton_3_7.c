#include <stdio.h>
#include <assert.h>

// Error function that will halt execution if reached
void reach_error() { 
    assert(0); 
}

// A function to simulate the behavior of aborting if the condition is not met
void assume_abort_if_not(int cond) {
  if (!cond) {
    printf("Condition failed\n");
    reach_error();
  }
}

// Declaration of NR and VAL based on the preprocessing directive
#define NR 7

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

// Define the number of iterations
#define ITERATIONS 3

#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
#error Number of iterations must be between 1 and 3
#endif 

// Function f as defined in the original code
float f(float x) {
  return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;
}

// Function fp as defined in the original code
float fp(float x) {
  return 1 - (x * x) / 2.0f + (x * x * x * x) / 24.0f + (x * x * x * x * x * x) / 720.0f;
}

int main() {
  // Deterministic input value (can be any value between -VAL and VAL based on the constraint)
  float IN = 0.0f; // Example value that falls within (-VAL, VAL) for the current configuration
  assume_abort_if_not(IN > -VAL && IN < VAL);

  float x = IN - f(IN) / fp(IN);
#if ITERATIONS > 1
  x = x - f(x) / fp(x);
#if ITERATIONS > 2
  x = x - f(x) / fp(x);
#endif
#endif

  if (!(x < 0.1)) {
    reach_error();
  }

  return 0;
}