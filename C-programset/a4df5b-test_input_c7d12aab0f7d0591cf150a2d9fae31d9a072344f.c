#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define VAL based on NR for demonstration
#define NR 1

#if NR == 1
#define VAL 1.39f
#elif NR == 2
#define VAL 1.398f
#elif NR == 3
#define VAL 1.39843f
#elif NR == 4
#define VAL 1.39844f
#elif NR == 5
#define VAL 1.39849f
#endif

int main() {
    // Deterministic input
    float IN = 0.5f;

    // Ensure the input is within the required range
    if (!(IN >= 0.0f && IN < 1.0f)) {
        abort();
    }

    float x = IN;

    // Perform the calculation
    float result = 1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x - 0.0390625f * x * x * x * x;

    // Check the result meets expected conditions
    if (!(result >= 0.0f && result < VAL)) {
        assert(0);
    }

    printf("Result: %f\n", result);
    return 0;
}