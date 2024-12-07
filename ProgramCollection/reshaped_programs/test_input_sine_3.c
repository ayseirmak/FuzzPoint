#include <stdio.h>
#include <assert.h>

#define HALFPI 1.57079632679f
#define NR 3

#if NR == 1
#define VAL 0.99f
#elif NR == 2
#define VAL 1.0f
#elif NR == 3
#define VAL 1.001f
#elif NR == 4
#define VAL 1.01f
#elif NR == 5
#define VAL 1.1f
#elif NR == 6
#define VAL 1.2f
#elif NR == 7
#define VAL 1.5f
#elif NR == 8
#define VAL 2.0f
#endif

void reach_error() {
    assert(0);
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        printf("Assumption failed, aborting.\n");
        abort();
    }
}

int main() {
    // Fixed deterministic input value within the range (-HALFPI, HALFPI)
    float IN = 1.0f; // This is just an example. You can choose any other fixed value in a similar range.

    assume_abort_if_not(IN > -HALFPI && IN < HALFPI);

    float x = IN;

    // Calculate the result using the provided formula
    float result = x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;

    // Check if the result is within the valid range
    if (!(result <= VAL && result >= -VAL)) {
        reach_error();
    }

    printf("Result: %f is within the range [-%f, %f]\n", result, VAL, VAL);

    return 0;
}