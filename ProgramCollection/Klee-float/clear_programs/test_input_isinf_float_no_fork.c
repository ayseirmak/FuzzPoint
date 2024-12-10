#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    float x;

    // Initialize x with an infinite value to simulate the symbolic execution environment
    x = INFINITY;

    // Simulate klee_assume(isinf(x)); by checking if x is indeed infinite
    if (isinf(x)) {
        // Assert that x is infinite, as per the original logic.
        assert(isinf(x));
    } else {
        // If x is not infinite, print a debug message (this path reflects what would trigger an assumption failure in KLEE)
        printf("Warning: x is not infinite, assumption failed.\n");
    }

    return 0;
}