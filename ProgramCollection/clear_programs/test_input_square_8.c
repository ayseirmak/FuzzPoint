#include <assert.h>
#include <stdio.h>

// Define a fixed input value
#define FIXED_INPUT 0.45f  // This value can be adjusted as needed

// Determine the approximation constant based on the NR value
#define NR 8

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
    // Use a fixed float value for deterministic testing
    float IN = FIXED_INPUT;

    // Ensure IN meets the condition used in assume_abort_if_not
    if (!(IN >= 0.0f && IN < 1.0f)) {
        printf("Error: Input value is out of expected range.\n");
        return 1;
    }

    float x = IN;
    
    // Compute the approximation of (1 + x)^0.5
    float result = 1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

    // Check the result
    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    }

    printf("Computation successful: result = %f\n", result);

    return 0;
}