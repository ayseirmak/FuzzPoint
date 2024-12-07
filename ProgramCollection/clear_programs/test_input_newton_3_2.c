#include <assert.h>
#include <stdio.h>

#define NR 2  // Number of range selector
#define ITERATIONS 3  // Number of iterations

// Set VAL based on NR
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

// Verify that ITERATIONS value falls between 1 and 3
#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
    #error Number of iterations must be between 1 and 3
#endif

void reach_error() {
    assert(0);  // Simulate a failure by asserting false
}

float f(float x) {
    return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;
}

float fp(float x) {
    return 1 - (x*x)/2.0f + (x*x*x*x)/24.0f + (x*x*x*x*x*x)/720.0f;
}

int main() {
    // Fixed deterministic input replacing '__VERIFIER_nondet_float()'
    float IN = 0.3f;  // This value is chosen within the specified VAL constraints

    // Check the fixed input value is within the constraints
    if (!(IN > -VAL && IN < VAL)) {
        printf("Input is outside the acceptable range.\n");
        return 1;  // Abort if assumption is violated
    }

    // Newton's method iterative process
    float x = IN - f(IN) / fp(IN);

    // Conditional iterations based on the ITERATIONS constant
#if ITERATIONS > 1
    x = x - f(x) / fp(x);  
#if ITERATIONS > 2
    x = x - f(x) / fp(x);  
#endif
#endif

    // Assert that x is below 0.1 or trigger error
    if (!(x < 0.1)) {
        reach_error();
    }

    printf("Computation completed successfully.\n");
    return 0;
}