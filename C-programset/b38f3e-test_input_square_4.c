#include <stdio.h>
#include <assert.h>

void reach_error() { 
    assert(0); 
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        // Instead of abort, just handle error by printing
        printf("Assumption failed!\n");
    } 
}

// Define VAL based on the preprocessor directive NR
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

int main() {
    // Set a fixed deterministic input value.
    float IN = 0.5f; // Choose a value for deterministic behavior
    assume_abort_if_not(IN >= 0.0f && IN < 1.0f);

    float x = IN;
    
    // Calculate the approximation
    float result = 1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x - 0.0390625f * x * x * x * x;

    // Check the result
    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    } else {
        printf("Result is within expected range.\n");
    }
    
    return 0;
}