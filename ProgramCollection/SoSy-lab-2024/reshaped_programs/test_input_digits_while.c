#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    fprintf(stderr, "Assertion failed: reach_error\n");
    abort();
}

void __ASSERT(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    long double x = 1.0 / 7.0;
    long long res = 0;

    int i = 1;

    // Limiting to 5 iterations to avoid infinite loop since the decimal of 1/7 is repeating
    const int max_iterations = 5;

    while(i <= max_iterations) {
        res += ((int)(x * 10) % 10) * (i * 10);
        x = (x * 10) - (int) x * 10;
        i++;
    }

    __ASSERT(res == 67050);
    printf("Result: %lld\n", res);

    return 0;
}