#include <stdio.h>
#include <assert.h>

// APPROXIMATES sqrt(1+x)
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

void reach_error() {
    printf("Error: Result out of expected range.\n");
    assert(0); // Simulate the reach_error condition
}

int main() {
    // Deterministic input: replace nondeterministic input with a fixed value
    float IN = 0.5f;  // Example fixed value (can be between 0.0f and 1.0f)

    // Precondition
    if (!(IN >= 0.0f && IN < 1.0f)) {
        printf("Invalid input. IN must be in the range [0.0, 1.0).\n");
        return 1;  // Exit if input is invalid
    }

    float x = IN;
    float result = 
        1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x -
        0.0390625f * x * x * x * x;
    
    // Post-condition and result check
    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    } else {
        printf("Result is within the expected range: %.6f\n", result);
    }

    return 0;
}