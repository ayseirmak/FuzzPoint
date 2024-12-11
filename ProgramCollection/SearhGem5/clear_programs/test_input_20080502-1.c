#include <stdio.h>
#include <math.h>

long double foo(long double x) {
    return signbit(x) ? 3.14159265358979323846L : 0.0L;
}

int main() {
    long double x = -5.0L; // Initialize x with a typical use case for testing
    if (foo(x) != 3.14159265358979323846L) {
        printf("Test failed!\n");
    } else {
        printf("Test passed!\n");
    }
    return 0;
}