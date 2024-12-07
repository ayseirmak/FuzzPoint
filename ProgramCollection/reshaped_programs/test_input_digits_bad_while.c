#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reach_error() {
    assert(0 && "reach_error");
}

int main() {
    long double x = 1.0 / 7.0;
    long long res = 0;

    int i = 1;

    // This loop would run indefinitely in practice because x will never exactly become 0
    // We'll add a sensible iteration limit instead for demonstration
    // Assuming 10 digits of precision for simplicity
    const int max_iterations = 10;
    
    while (x != 0 && i <= max_iterations) {
        res += ((int)(x * 10) % 10) * (i * 10);
        x = (x * 10) - ((int)x * 10);
        i++;
    }

    // Replacing __VERIFIER_assert with assert from standard library
    if (!(res > 67050)) {
        reach_error();
        abort();
    }

    printf("Computation finished successfully with res = %lld\n", res); 
    return 0;
}