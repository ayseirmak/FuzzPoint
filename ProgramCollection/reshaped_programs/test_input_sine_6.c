#include <stdio.h>
#include <assert.h>

#define HALFPI 1.57079632679f
#define NR 6

#define VAL 1.2f  // Predefined for NR == 6

void reach_error() {
    assert(0);
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        // A simple replacement for demonstration; in practice, this might exit or handle errors differently
        printf("Error: Assumption failed.\n");
    }
}

int main() {
    // Fixed deterministic input instead of __VERIFIER_nondet_float
    float IN = 1.0f;

    assume_abort_if_not(IN > -HALFPI && IN < HALFPI);

    float x = IN;
    float result = x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;

    if (!(result <= VAL && result >= -VAL)) {
        reach_error();
    }

    return 0;
}