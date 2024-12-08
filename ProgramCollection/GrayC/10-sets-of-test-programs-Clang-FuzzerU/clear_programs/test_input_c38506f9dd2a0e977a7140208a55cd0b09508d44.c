#include <stdio.h>  // Required for printf
#include <stdlib.h> // Required for exit and abort

// Function to test endianness using non-volatile variables
int test_endianness() {
    union doubleword {
        double d;
        unsigned long u[2];
    } dw;
    
    dw.d = 10;
    return dw.u[0] != 0 ? 1 : 0;
}

// Function to test endianness using volatile variables
int test_endianness_vol() {
    union doubleword {
        volatile double d;
        volatile long u[2];
    } dw;
    
    dw.d = 10;
    return dw.u[0] != 0 ? 1 : 0;
}

volatile char s[256][3]; // Declaring volatile char array
char g; // Global char used in the dummy function

// Dummy function to assign value to global variable g
static void dummy(char a) {
    g = a;
}

// Function foo to test array operations
static int foo(void) {
    int i, j = 0;

    for (i = 0; i < 256; i++) {
        if (i >= 128 && i < 256) {
            dummy(s[i - 128][0]);
            ++j;
        }
    }

    return j;
}

int main(void) {
    // Check the result of endianness tests and array manipulation test
    if (test_endianness() != test_endianness_vol()) {
        abort();
    }

    if (foo() != 128) {
        abort();
    }

    printf("All tests passed successfully.\n");
    return 0;
}