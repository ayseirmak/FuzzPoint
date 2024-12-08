#include <stdio.h>
#include <stdlib.h>
#include <complex.h> // For complex number support
#include <assert.h>  // For assertions

typedef _Complex float cf;

// Define a packed struct x
struct x {
    char c;
    cf f;
} __attribute__((__packed__));

void f1(void);
void f2(struct x *y);

int main(void) {
    f1();
    return 0;
}

void f1(void) {
    struct x s;   // Declare and initialize a variable of type struct x
    s.f = 1.0f;   // Initialize the complex float field
    s.c = 42;     // Initialize the char field
    f2(&s);       // Call function f2 with the address of s
}

void f2(struct x *y) {
    // Check if the fields of the struct are as expected
    if (y->f != 1.0f || y->c != 42) {
        printf("Assertion failed: The struct contains unexpected values.\n");
        abort();  // Terminate the program if values are not as expected
    } else {
        printf("Values are as expected.\n");
    }
}