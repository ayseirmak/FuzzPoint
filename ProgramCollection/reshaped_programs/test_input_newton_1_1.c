#include <stdio.h>
#include <assert.h>

void reach_error() {
    assert(0);
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        // Simulate abort by forcing an error state
        reach_error();
    }
}

#define VAL 0.2f
#define FIXED_INPUT 0.1f  // Deterministic input for replacement

#define ITERATIONS 1  // Ensure this is between 1 and 3

float f(float x) {
    return x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;
}

float fp(float x) {
    return 1 - (x * x) / 2.0f + (x * x * x * x) / 24.0f + (x * x * x * x * x * x) / 720.0f;
}

int main() {
    float IN = FIXED_INPUT;  // Replaced nondeterministic input with fixed input
    assume_abort_if_not(IN > -VAL && IN < VAL);

    float x = IN - f(IN) / fp(IN);
#if ITERATIONS > 1
    x = x - f(x) / fp(x);
#if ITERATIONS > 2
    x = x - f(x) / fp(x);
#endif
#endif

    if (!(x < 0.1)) {
        reach_error();
    }

    printf("Calculated x: %f\n", x);

    return 0;
}