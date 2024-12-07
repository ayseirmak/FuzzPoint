#include <stdio.h>
#include <assert.h>

// APPROXIMATES sqroot(1+x)

#define NR 3

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
    assert(0);
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        printf("Assumption failed, aborting.\n");
        abort();
    }
}

int main() {
    // Instead of using __VERIFIER_nondet_float(), initialize with a fixed value within the defined range.
    float IN = 0.5f;  // Example value, should be 0 <= IN < 1

    assume_abort_if_not(IN >= 0.0f && IN < 1.0f);

    float x = IN;

    float result = 1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    }

    return 0;
}