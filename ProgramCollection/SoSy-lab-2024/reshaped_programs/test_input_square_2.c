#include <assert.h>
#include <stdio.h>

// APPROXIMATES sqroot(1+x)
#define NR 2

#if NR == 1
#define VAL 1.39f
#elif NR == 2
#define VAL 1.398f
#elif NR == 3
#define VAL 1.39843f
#elif NR == 4
#define VAL 1.39844f
#elif NR == 5
#define VAL 1.3985f
#elif NR == 6
#define VAL 1.399f
#elif NR == 7
#define VAL 1.4f
#elif NR == 8
#define VAL 1.5f
#endif

void assume_abort_if_not(int cond) {
  if (!cond) {
    printf("Assumption failed, aborting.\n");
  }
}

void reach_error() {
  assert(0);
}

int main() {
  // Using a fixed deterministic input within the given range [0.0, 1.0)
  float IN = 0.5f; 
  assume_abort_if_not(IN >= 0.0f && IN < 1.0f);

  float x = IN;
  
  float result = 
    1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

  if(!(result >= 0.0f && result < VAL)) {
    reach_error();
  } else {
    printf("Computation successful: result = %f\n", result);
  }

  return 0;
}