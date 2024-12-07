#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reach_error() {
    assert(!"reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main()
{
    // Fixed value for the deterministic behavior
    float x = 0.5f;  // Example fixed value, change as per requirement
    float exp = 1.0f;
    float term = 1.0f;
    unsigned int count = 1;
    float result = 2 * (1 / (1 - x));
    int iterations = 10;  // Fixed number of iterations for deterministic execution

    for (int i = 0; i < iterations; i++) {
        term = term * (x / count);
        exp = exp + term;
        count++;
    }

    __VERIFIER_assert(result >= exp);
    printf("Computed exp: %f\n", exp);
    printf("Expected result: %f\n", result);

    return 0;
}