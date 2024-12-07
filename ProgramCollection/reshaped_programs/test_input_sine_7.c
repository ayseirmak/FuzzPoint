#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define HALFPI 1.57079632679f
#define NR 7

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
    if(!cond) {
        abort();
    }
}

int main() {
    // Define a fixed deterministic input value
    float IN = 1.0f; // Example value within -HALFPI and HALFPI

    // Check the assumption
    assume_abort_if_not(IN > -HALFPI && IN < HALFPI);

    // Perform the computations
    float x = IN;
    float result = x - (x*x*x) / 6.0f + (x*x*x*x*x) / 120.0f + (x*x*x*x*x*x*x) / 5040.0f;

    // Validate the computed result
    if (!(result <= VAL && result >= -VAL)) {
        reach_error();
    }

    // Since there's no output requirement, simply return
    return 0;
}