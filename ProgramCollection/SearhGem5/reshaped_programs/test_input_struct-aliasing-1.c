#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct S { float f; };

// Function that mimics the original behavior
int __attribute__((noinline)) foo(int *r, struct S *p) {
    int *q = (int *)&p->f;
    int i = *q;
    *r = 0;
    return i + *q;
}

// Main function without command line arguments
int main(void) {
    // Initialize variables
    int i = 0x3F800000; // Represents 1.0 in IEEE 754 floating point representation
    struct S s_obj;

    // Copy the bits from 'i' into the structure's float field
    s_obj.f = *(float *)&i;

    // Check the condition using foo
    if (foo(&i, &s_obj) != 0x3F800000) { // 0x3F800000 corresponds to 1.0
        printf("Assertion failed!\n"); // Substitute for abort(), with a meaningful message
        return 1;
    }

    // Print success message
    printf("Passed the check.\n");

    return 0;
}