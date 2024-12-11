#include <stdio.h>
#include <stdlib.h>

// Function definition
static int test(int x, int a_i) {
    union {
        int i;
        double d;
    } a;
    a.d = 0.0; // Initializing union member with a floating-point value
    a.i = a_i; // Assign integer part of union the value of a_i
    return x >> a.i; // Right shift x by the value of a.i
}

int main(void) {
    // Initialize variables
    int x = 8;     // Example value
    int a_i = 2;   // Example shift amount

    // Perform the test and check result
    if (test(x, a_i) != 2) {
        printf("Test failed.\n");
        return 1;
    }

    printf("Test passed.\n");
    return 0;
}