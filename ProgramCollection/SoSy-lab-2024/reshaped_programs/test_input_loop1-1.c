#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reach_error() {
    fprintf(stderr, "Error reached in verification.\n");
    abort();
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Since we can't use nondeterministic input, replace with a fixed input.
    float x = 0.5; // Fixed input between -1 and 1
    assume_abort_if_not(x > -1.0);
    assume_abort_if_not(x < 1.0);

    float exp = 1.0;
    float term = 1.0;
    unsigned int count = 1;
    float result = 2 * (1 / (1 - x));

    // Using a fixed iteration count instead of nondeterministic stopping condition
    int max_iterations = 100; // Arbitrary fixed number of iterations
    for (int i = 0; i < max_iterations; i++) {
        term = term * (x / count);
        exp = exp + term;
        count++;
        
        // Break early if terms become negligibly small 
        // to simulate a convergence condition
        if (term < 1e-6) break;
    }

    __VERIFIER_assert(result >= exp);

    // Output for debugging
    printf("Calculated exp: %f\n", exp);
    printf("Calculated result: %f\n", result);

    return 0;
}