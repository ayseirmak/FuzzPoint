#include <stdio.h>
#include <assert.h>

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

#define ITERATIONS 1

#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
#error Number of iterations must be between 1 and 3
#endif 

void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
  if (!cond) {
    printf("Aborting due to assumption failure\n");
    abort();
  }
}

float f(float x) {
  return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;
}

float fp(float x) {
  return 1 - (x*x)/2.0f + (x*x*x*x)/24.0f + (x*x*x*x*x*x)/720.0f;
}

int main() {
  // Deterministically defining the input value instead of using a nondet function
  float IN = 0.5f; // Example deterministic value

  // Ensuring the input is within the specified range
  assume_abort_if_not(IN > -VAL && IN < VAL);
  
  // Perform Newton's method or similar iteration
  float x = IN - f(IN)/fp(IN);
#if ITERATIONS > 1 
  x = x - f(x)/fp(x);
#if ITERATIONS > 2
  x = x - f(x)/fp(x);
#endif 
#endif

  // Verification: ensuring the result is below a certain value
  if (!(x < 0.1)) {
    reach_error();
  }

  return 0;
}