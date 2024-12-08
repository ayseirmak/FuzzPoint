#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NR 1

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

int main() {
    // Initialize and declare all variables explicitly before use
    float IN = 0.5f; // Use a deterministic input value that satisfies the condition
    float x = IN;

    // Check condition
    if (!(IN >= 0.0f && IN < 1.0f)) {
        abort();
    }

    // Calculate result using the formula with known fixed value for `x`
    float result = 1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x * x;

    // Assert that the result is within the expected range
    if (!(result >= 0.0f && result < VAL)) {
        assert(0);
    }

    // Print the result to verify the output
    printf("The result is: %f\n", result);

    return 0;
}