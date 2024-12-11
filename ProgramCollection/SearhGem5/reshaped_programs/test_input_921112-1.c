#include <stdio.h>
#include <stdlib.h>

union u {
    struct { int i1, i2; } t;
    double d;
} x[2], v;

void f(union u *x, union u v) {
    *++x = v;
}

int main() {
    // Initialize values for testing without command-line arguments
    int initial_i1 = 5;  // Example initialization
    int initial_i2 = 10; // Example initialization
    int expected_i1 = 5; // Expected value for verification
    int expected_i2 = 10; // Expected value for verification

    x[1].t.i1 = x[1].t.i2 = 0;
    v.t.i1 = initial_i1;
    v.t.i2 = initial_i2;
    f(x, v);

    if (x[1].t.i1 != expected_i1 || x[1].t.i2 != expected_i2) {
        printf("Test failed: expected (%d, %d), got (%d, %d)\n", 
               expected_i1, expected_i2, x[1].t.i1, x[1].t.i2);
    } else {
        printf("Test passed: (%d, %d)\n", x[1].t.i1, x[1].t.i2);
    }

    return 0;
}