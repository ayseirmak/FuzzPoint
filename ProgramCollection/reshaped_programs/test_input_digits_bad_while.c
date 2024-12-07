#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reach_error() {
    printf("Error triggered.\n");
    abort();
}

void verifier_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int main() {
    long double x = 1.0 / 7.0;
    long long res = 0;

    int i = 1;
    int max_iterations = 100;  // Limit the number of iterations to prevent infinite loop.
    int loop_counter = 0;

    while (x != 0 && loop_counter < max_iterations) {
        res += ((int)(x * 10) % 10) * (i * 10);
        x = (x * 10) - (int) x * 10;
        i++;
        loop_counter++;
    }

    // Use the standard assert functionality
    assert(res > 67050);
    
    return 0;
}