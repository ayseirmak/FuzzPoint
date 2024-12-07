#include <assert.h>
#include <stdio.h>

// Fixed values defined directly within the program
#define NR 4

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

// Function to simulate reach_error using assert
void reach_error() {
    assert(0 && "Reached error condition!");
}

int main() {
    // Deterministically initialized value in place of nondeterministic input
    float IN = 0.5f;  // Example fixed value within [0.0, 1.0)

    // Ensures precondition is met
    if (!(IN >= 0.0f && IN < 1.0f)) {
        assert(0 && "Precondition failed: IN is outside [0.0, 1.0)");
    }

    float x = IN;
    
    // Calculate the approximate square root
    float result = 
        1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x - 0.0390625f * x * x * x * x;

    // Check if the result meets the specification
    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    }

    // Log the result for verification
    printf("Input: %f, Result: %f, VAL: %f\n", IN, result, VAL);

    return 0;
}