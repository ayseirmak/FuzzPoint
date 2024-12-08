#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

// Constants
#define PI 3.14159
#define OCTANT (PI / 3)

// Function to substitute __VERIFIER_nondet_float()
float determinate_float() {
    return (OCTANT + 0.1); // A fixed value for x in range (octant, pi)
}

// Function to substitute __VERIFIER_nondet_int()
int determinate_int() {
    return 0; // Always returns 0 to exit the loop
}

void assume_abort_if_not(int cond) {
    if (!cond) { abort(); }
}

void __VERIFIER_assert(int cond) {
    assert(cond);
}

int main() {
    float x = determinate_float();
    float oddExp = x;
    float evenExp = 1.0;
    float term = x;
    unsigned int count = 2;
    int multFactor = 0;
    
    // Ensure x is within the specified range
    assume_abort_if_not(x > OCTANT && x < PI);

    while (1) {
        term = term * (x / count);
        multFactor = ((count >> 1) % 2 == 0) ? 1 : -1;

        evenExp = evenExp + multFactor * term;

        count++;

        term = term * (x / count);

        oddExp = oddExp + multFactor * term;

        count++;

        // Deterministic check to exit the loop
        int temp = determinate_int();
        if (temp == 0) break;
    }

    __VERIFIER_assert(oddExp >= evenExp);

    printf("Completed without error.\n");

    return 0;
}