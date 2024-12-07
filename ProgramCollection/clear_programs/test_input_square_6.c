#include <assert.h>
#include <stdio.h>

// Function to emulate abort behavior
void assume_abort_if_not(int cond) {
    if (!cond) {
        printf("Assumption failed, aborting.\n");
    }
}

// Error function that mimics the verifier's error handling
void reach_error() {
    assert(0 && "Error reached");
}

// Fixed value emulating a non-deterministic float input within a specific range
float fixed_float_input(void) {
    return 0.5f; // A fixed value between 0.0f and 1.0f
}

#define NR 6

// Define the target value based on the macro NR
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

int main() {
    // Deterministic input value
    float IN = fixed_float_input();
    
    // Assertion to ensure that the input value is within the expected range
    assume_abort_if_not(IN >= 0.0f && IN < 1.0f);

    float x = IN;
    
    // Calculate the result using a polynomial approximation
    float result = 1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

    // Verify that the result is within a specific range
    if (!(result >= 0.0f && result < VAL)) {
        reach_error(); // Reach an error state if the condition is not met
    }
    
    return 0;
}