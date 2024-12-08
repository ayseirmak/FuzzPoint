#include <stdio.h>
#include <stdlib.h>

// Custom error handling function
void reach_error() {
    printf("Error: Assertion failed in function 'reach_error'.\n");
    exit(1);
}

// Assertion function
void assert_custom(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    long double x = 1.0 / 7.0;
    long long res = 0;

    // Fixed iteration limit to avoid an infinite loop
    int max_iterations = 1000; // Arbitrary large number
    for (int i = 1; x != 0 && i <= max_iterations; i++) {
        res += ((int)(x * 10) % 10) * (i * 10);
        x = (x * 10) - (int)x * 10;
    }

    assert_custom(res > 67050);

    return 0;
}