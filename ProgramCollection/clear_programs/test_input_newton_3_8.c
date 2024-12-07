#include <stdio.h>
#include <assert.h>

#define NR 8

// Defines a fixed value based on NR
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

// Function f defined as per original logic
float f(float x)
{
  return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;
}

// Function fp defined as per original logic
float fp(float x)
{
  return 1 - (x*x)/2.0f + (x*x*x*x)/24.0f + (x*x*x*x*x*x)/720.0f;
}

// Function to report error, replacing reach_error
void report_error() {
    printf("Error: Assertion failed!\n");
    assert(0);
}

int main()
{
    // Static deterministic input replacing nondeterministic function
    float IN = 1.5f; // A fixed deterministic input
    assert(IN > -VAL && IN < VAL); // Replacing assume_abort_if_not

    float x = IN - f(IN)/fp(IN);
#if ITERATIONS > 1 
    x = x - f(x)/fp(x);
#if ITERATIONS > 2
    x = x - f(x)/fp(x);
#endif 
#endif

    // Checking condition and reporting error if necessary
    if(!(x < 0.1)) {
        report_error();
    }

    return 0;
}