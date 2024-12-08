#include <stdio.h>
#include <assert.h>

#define NR 5

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

// Helper function to reach error assertion
void reach_error() {
    assert(0);
}

// Function implementing the mathematical function f(x)
float f(float x) {
    return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;
}

// Function implementing the derivative f'(x)
float fp(float x) {
    return 1 - (x * x) / 2.0f + (x * x * x * x) / 24.0f + (x * x * x * x * x * x) / 720.0f;
}

int main() {
    // Fixed deterministic input value that satisfies the condition
    float IN = 0.5f; // You can choose any value between -VAL and VAL

    // Ensure the input is within the valid range
    if (IN <= -VAL || IN >= VAL) {
        printf("Input out of expected range.\n");
        return 1;
    }

    // Perform iterations for the Newton-Raphson method
    float x = IN - f(IN) / fp(IN);
#if ITERATIONS > 1 
    x = x - f(x) / fp(x);
#if ITERATIONS > 2
    x = x - f(x) / fp(x);
#endif 
#endif

    // Check if the resulting x is within the required range
    if (!(x < 0.1)) {
        reach_error();
    }

    printf("Computation successful, x = %.5f\n", x);
    return 0;
}