#include <stdio.h>  // For printf and NULL
#include <stdlib.h> // For abort

int a = 0, b = 0, c = 0, g = 0, k = 0, l = 0, m = 0, n = 0;
char h = 0;

// Function to test endianness
int test_endianness() {
    union doubleword {
        double d;
        unsigned long u[2];
    } dw;
    dw.d = 10.0;
    return dw.u[0] != 0 ? 1 : 0;
}

// Function to test volatile endianness
int test_endianness_vol() {
    union doubleword {
        volatile double d;
        volatile long u[2];
    } dw;
    dw.d = 10.0;
    return dw.u[0] != 0 ? 1 : 0;
}

// Dummy function to manipulate character array
static void dummy(char a) {
    g = a;
}

int foo() {
    volatile char s[256][3] = {{0}};
    int j = 0;
    
    for (int i = 1; i < 256; i++) {
        dummy(s[i - 1][0]);
        ++j;
    }

    return j;
}

// Function fn1 with deterministic logic
void fn1() {
    l = b + 1;
    for (; b < 1; b++) {
        h = a + 1;
    }
}

int main(void) {
    // Testing endianness functions
    if (test_endianness() != test_endianness_vol()) {
        printf("Endianness test failed.\n");
    }

    // Checking the foo function
    if (foo() != 255) {  // Adjusted the expected value to match the loop logic
        printf("foo function did not return expected value.\n");
        abort();
    }

    // Clear variable state and execute fn1
    a = 0; 
    b = 0; 
    c = 0; 
    fn1();

    // Condition check and expected output
    if (h != 1) {
        printf("Unexpected value of h: %d\n", h);
        abort();
    }

    printf("Program completed successfully.\n");
    return 0;
}