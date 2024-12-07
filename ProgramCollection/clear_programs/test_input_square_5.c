#include <stdio.h>
#include <assert.h>

// APPROXIMATES sqroot(1+x)

#define NR 5

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

void reach_error() {
    printf("Error: Assertion failed.\n");
    assert(0);
}

int main() {
    // Use a fixed value for IN instead of a non-deterministic float
    float IN = 0.5f; // A sample value within the specified range [0.0, 1.0)

    // Check the precondition
    if (!(IN >= 0.0f && IN < 1.0f)) {
        printf("Fixed input value is out of expected range [0.0, 1.0).\n");
        return 1; // Exit if the selected IN is not valid
    }

    float x = IN;
  
    // Calculate the result using the polynomial approximation
    float result = 1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x - 0.0390625f * x * x * x * x;

    // Assert that the result should be in the expected range
    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    }

    printf("Computation successful: result = %f, expected result < %f\n", result, VAL);

    return 0;
}