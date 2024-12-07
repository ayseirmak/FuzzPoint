#include <stdio.h>
#include <assert.h>

// Define HALFPI as a constant as no dynamic input is allowed
#define HALFPI 1.57079632679f

// Define NR and VAL based on the original program's conditions
#define NR 8
#if NR == 1
#define VAL 0.99
#elif NR == 2
#define VAL 1.0f
#elif NR == 3
#define VAL 1.001f
#elif NR == 4
#define VAL 1.01f
#elif NR == 5
#define VAL 1.1f
#elif NR == 6
#define VAL 1.2f
#elif NR == 7
#define VAL 1.5f
#elif NR == 8
#define VAL 2.0f
#endif

// Function to simulate the reach_error behavior
void reach_error() {
    printf("Error: Assertion failed\n");
    assert(0);
}

int main() {
    // Initialize IN with a deterministic value within the allowed range
    float IN = 1.0f;

    // Check the assumption as a condition before proceeding
    if (!(IN > -HALFPI && IN < HALFPI)) {
        printf("Assumption not met\n");
        return 0;
    }

    float x = IN;
    
    // Compute the mathematical result
    float result = x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;

    // Check the result using assert to ensure it is within the range
    if (!(result <= VAL && result >= -VAL)) {
        reach_error();
    }

    // Print the result for verification purposes
    printf("Result: %f\n", result);
    return 0;
}