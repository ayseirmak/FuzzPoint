#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) { abort(); }
}

#define NR 4

// Assign a predefined value instead of nondeterministic input
float get_fixed_input() {
    switch (NR) {
        case 1: return 0.1f;
        case 2: return 0.3f;
        case 3: return 0.5f;
        case 4: return 0.7f;
        case 5: return 0.9f;
        case 6: return 1.1f;
        case 7: return 1.3f;
        case 8: return 1.9f;
        default: return 0.0f; // Default case to handle undefined NR
    }
}

#define ITERATIONS 3

#if !(ITERATIONS >= 1 && ITERATIONS <= 3)
#error Number of iterations must be between 1 and 3
#endif 

float f(float x) {
    return x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;
}

float fp(float x) {
    return 1 - (x*x)/2.0f + (x*x*x*x)/24.0f + (x*x*x*x*x*x)/720.0f;
}

int main() {
    float IN = get_fixed_input(); // Use the fixed input
    const float VAL = 0.8f; // Set VAL based on defined NR

    // Value checking based on the predefined NR and VAL
    assume_abort_if_not(IN > -VAL && IN < VAL);

    // Initialize x based on IN and correct computation
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

    return 0;
}