#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// Error reaching function, will cause a program halt if triggered
void reach_error() { 
    assert(0); 
}

// Custom function to simulate abort if condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Constants
#define NR 2

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

#define ITERATIONS 2

#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
#error Number of iterations must be between 1 and 3
#endif 

// Function to compute a mathematical series approximation
float f(float x) {
    return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + 
           (x * x * x * x * x * x * x) / 5040.0f;
}

// Derivative of the function
float fp(float x) {
    return 1 - (x * x) / 2.0f + (x * x * x * x) / 24.0f + (x * x * x * x * x * x) / 720.0f;
}

int main() {
    // Deterministic input for IN to replace nondeterministic behavior
    float IN = 0.3f;

    // Check that the input satisfies the expected condition
    assume_abort_if_not(IN > -VAL && IN < VAL);

    // Perform Newton iteration to find a fixed point approximation
    float x = IN - f(IN) / fp(IN);
#if ITERATIONS > 1 
    x = x - f(x) / fp(x);
#if ITERATIONS > 2
    x = x - f(x) / fp(x);
#endif 
#endif

    // Check result and possibly trigger error
    if (!(x < 0.1)) {
        reach_error();
    }

    // Output result for verification
    printf("Final x value: %f\n", x);
    
    return 0;
}