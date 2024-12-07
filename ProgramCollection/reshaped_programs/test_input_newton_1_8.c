#include <assert.h>
#include <stdio.h>

#define NR 8

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

#define ITERATIONS 1

#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
#error Number of iterations must be between 1 and 3
#endif 

float f(float x) {
    return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;
}

float fp(float x) {
    return 1 - (x*x)/2.0f + (x*x*x*x)/24.0f + (x*x*x*x*x*x)/720.0f;
}

void reach_error() {
    printf("Error: The value of x is not less than 0.1\n");
    assert(0);
}

int main() {
    // Set a fixed deterministic input value within the range (-VAL, VAL)
    // For demonstration, use a value in the middle of the range.
    float IN = (VAL - (-VAL)) / 2.0f;

    if (!(IN > -VAL && IN < VAL)) {
        printf("Input value out of range.\n");
        return 1;  // Exit if the condition is not satisfied
    }

    float x = IN - f(IN)/fp(IN);
#if ITERATIONS > 1 
    x = x - f(x)/fp(x);
#if ITERATIONS > 2
    x = x - f(x)/fp(x);
#endif 
#endif

    if (!(x < 0.1)) {
        reach_error();
    }

    printf("Program completed successfully with x = %f\n", x);
    return 0;
}