#include <assert.h>
#include <stdio.h>

// Error handling function
void reach_error() { 
    printf("Error: Assertion failed.\n"); 
    assert(0); 
}

// Replacement for the `assume_abort_if_not` function
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Macro definitions
#define NR 1

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

#define ITERATIONS 3

#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
#error Number of iterations must be between 1 and 3
#endif 

// Function declarations
float f(float x) {
    return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;
}

float fp(float x) {
    return 1 - (x*x)/2.0f + (x*x*x*x)/24.0f + (x*x*x*x*x*x)/720.0f;
}

int main() {
    // Fixed deterministic input replacing the nondeterministic function call
    float IN = 0.15f; 
    assume_abort_if_not(IN > -VAL && IN < VAL);

    // Newton's method for refinement
    float x = IN - f(IN)/fp(IN);
#if ITERATIONS > 1 
    x = x - f(x)/fp(x);
#if ITERATIONS > 2
    x = x - f(x)/fp(x);
#endif 
#endif

    // Assertion check
    if (!(x < 0.1)) {
        reach_error();
    }

    return 0;
}