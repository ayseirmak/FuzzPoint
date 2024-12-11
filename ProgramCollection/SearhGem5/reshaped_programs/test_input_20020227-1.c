#include <stdio.h>
#include <stdlib.h>

// Define a complex float type using a standard approach
typedef float cf;

struct x {
    char c;
    cf f;
};

void f2(struct x* y);
void f1(void);

int main(void) {
    f1();
    return 0;
}

void f1(void) {
    struct x s;

    // Initialize 's' explicitly. Setting some typical test values.
    // In real-world usage, you might simulate some computation values.
    s.f = 3.14f;  // Example float value
    s.c = 1;      // Example char (integer) value

    f2(&s);
}

void f2(struct x* y) {
    // Check based on initialized values to simulate a computation check
    if (y->f != 3.14f || y->c != 1) {
        printf("Abort due to failed condition!\n");
    } else {
        printf("Condition passed!\n");
    }
}