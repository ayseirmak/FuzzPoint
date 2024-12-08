#include <stdio.h>
#include <assert.h>

// Definitions for constants based on NR value
#define NR 6
#define ITERATIONS 2

// Value of VAL according to NR
#if NR == 1
#define VAL 0.2f
#elif NR == 2
#define VAL 0.4f
#elif NR == 3
#define VAL 0.6f
#elif NR == 4
#define VAL 0.8f
#elif NR == 5
#define VAL 1.0f
#elif NR == 6
#define VAL 1.2f
#elif NR == 7
#define VAL 1.4f
#elif NR == 8
#define VAL 2.0f
#endif

// Function definitions
float f(float x) {
    return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;
}

float fp(float x) {
    return 1 - (x*x)/2.0f + (x*x*x*x)/24.0f + (x*x*x*x*x*x)/720.0f;
}

// Main function
int main() {
    // Use a fixed value for input; simulation of nondeterministic behavior with a fixed input.
    float IN = 0.1f;

    // Ensure IN is within the expected range.
    if (!(IN > -VAL && IN < VAL)) {
        fprintf(stderr, "Input out of expected range.\n");
        return 1; // Exit with error if input is out of range
    }

    // Perform the calculations as per the original logic in the provided code.
    float x = IN - f(IN)/fp(IN);
#if ITERATIONS > 1 
    x = x - f(x)/fp(x);
#if ITERATIONS > 2
    x = x - f(x)/fp(x);
#endif 
#endif

    // Check the final condition and print an error if not met
    if (!(x < 0.1)) {
        printf("Error: x is not less than 0.1\n");
        reach_error();
    }

    return 0;
}