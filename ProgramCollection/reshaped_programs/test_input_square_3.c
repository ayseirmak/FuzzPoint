#include <stdio.h>
#include <assert.h>

// Approximates sqrt(1+x)
#define NR 3

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

void reach_error() { assert(0); }

int main() {
    // Using a fixed value for `IN` to replace the non-deterministic input
    float IN = 0.5f; // Assuming a fixed input within the specified range [0.0, 1.0)

    // Ensure the input is within the valid range
    if (IN < 0.0f || IN >= 1.0f) {
        printf("Input out of range.\n");
        return -1;
    }

    float x = IN;
  
    float result = 
        1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    } else {
        printf("Result is within the acceptable range.\n");
    }

    return 0;
}