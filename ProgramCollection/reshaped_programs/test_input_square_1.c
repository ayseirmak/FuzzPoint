#include <stdio.h>
#include <assert.h>

// Function to simulate the 'reach_error' function, replacing verification-specific functionality
void reach_error() {
    assert(0);
}

// Predefined constant, representing a deterministic input
#define FIXED_INPUT 0.5f  // Example fixed input within the range [0.0f, 1.0f)

// Use this to select the VAL value as per original program's preprocessor directives
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
#define VAL 1.3985f
#elif NR == 6
#define VAL 1.399f
#elif NR == 7
#define VAL 1.4f
#elif NR == 8
#define VAL 1.5f
#endif

int main() {
    // Deterministic input with explicitly defined input value in place of non-deterministic behavior
    float IN = FIXED_INPUT;
    
    // Sure the input meets the conditions, else static handling; not aborting dynamically here.
    if (!(IN >= 0.0f && IN < 1.0f)) {
        printf("Error: Input is out of acceptable range\n");
        return 1;
    }

    float x = IN;
    
    float result = 
        1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

    // Check condition and print message instead of triggering reach_error
    if (!(result >= 0.0f && result < VAL)) {
        printf("Reach error: Result is out of acceptable range\n");
        return 1;
    }
    
    printf("Execution completed successfully: Result = %f\n", result);
    
    return 0;
}