#include <stdio.h>
#include <assert.h>

// Approximates sqroot(1+x)
#define NR 6

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

void reach_error() {
    assert(0);
}

int main() {
    // Deterministic input
    float IN = 0.5f; // Example of a fixed value input between 0.0f and 1.0f
    
    // Validate input assumption
    if (!(IN >= 0.0f && IN < 1.0f)) {
        return 1; // Exit if input does not meet the requirement
    }

    float x = IN;

    // Calculate the approximation
    float result = 1.0f + 0.5f * x
                   - 0.125f * x * x
                   + 0.0625f * x * x * x
                   - 0.0390625f * x * x * x * x;
    
    // Validate the result
    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    }

    printf("Result: %f\n", result);
    return 0;
}