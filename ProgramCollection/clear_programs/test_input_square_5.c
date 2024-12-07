#include <stdio.h>
#include <assert.h>

// Define constants
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
    // This function will be triggered if an error condition is met
    assert(0);
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        // Simulate abort behavior
        printf("Abort assumption violated\n");
        // Emulating abort() behavior
        while (1) {}
    }
}

int main() {
    // Preset deterministic input value
    float IN = 0.5f; // A chosen fixed value for deterministic behavior
    assume_abort_if_not(IN >= 0.0f && IN < 1.0f);

    float x = IN;

    // Polynomial approximation of the square root function
    float result = 
        1.0f + 0.5f * x - 0.125f * x * x + 0.0625f * x * x * x - 0.0390625f * x * x * x * x;

    // Check if result satisfies the expected conditions
    if (!(result >= 0.0f && result < VAL)) {
        reach_error();
    }

    printf("Computation finished successfully.\n");
    return 0;
}