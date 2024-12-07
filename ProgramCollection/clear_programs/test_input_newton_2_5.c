#include <stdio.h>
#include <assert.h>

// Define constants based on provided configurations
#define NR 5
#define VAL 1.0f // Based on NR==5

#define ITERATIONS 2 
#define FIXED_INPUT 0.05f // Set a deterministic input value

// Function declarations
float f(float x);
float fp(float x);
void reach_error();

// Function implementations
float f(float x) {
    return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;
}

float fp(float x) {
    return 1 - (x*x)/2.0f + (x*x*x*x)/24.0f + (x*x*x*x*x*x)/720.0f;
}

void reach_error() {
    assert(0); // Trigger an assertion error if reached
}

int main() {
    float IN = FIXED_INPUT;
    
    // Ensure the assumption is valid
    if (!(IN > -VAL && IN < VAL)) {
        // Abort the program if assumption is not met
        printf("Assumption not met.\n");
        return -1;
    }
    
    // Initialize and compute x with Newton's method
    float x = IN - f(IN) / fp(IN);
    #if ITERATIONS > 1 
    x = x - f(x) / fp(x);
    #if ITERATIONS > 2
    x = x - f(x) / fp(x);
    #endif
    #endif
    
    // Verify the result
    if (!(x < 0.1)) {
        reach_error();
    }

    return 0;
}