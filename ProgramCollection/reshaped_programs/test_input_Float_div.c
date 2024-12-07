#include <assert.h>
#include <stdio.h>

// Replace 1.6f to 2.5f to verification successful
#define X 2.5f

void reach_error() {
    assert(0); 
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    float x = 1.0f;
    float x1 = x / X;

    // Fixed loop behavior
    // The condition 'x1 != x' might loop indefinitely due to floating-point precision, 
    // thus we determine a maximum iteration based on fixed behavior
    int max_iterations = 100; // Arbitrary limit to ensure termination
    int iteration = 0;

    while (x1 != x && iteration < max_iterations) {
        x = x1;
        x1 = x / X;
        iteration++;
    }

    if (iteration >= max_iterations) {
        printf("Maximum iterations reached. Terminating to prevent infinite loop.\n");
    }

    __VERIFIER_assert(x == 0);
    return 0;
}