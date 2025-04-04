#include <stdio.h>
#include <stdlib.h>

volatile char s[256][3];
char g;

// Dummy function that assigns to a global variable.
static void dummy(char a) {
    g = a;
}

// This function simulates a test for endianness.
int test_endianness() {
    union doubleword {
        double d;
        unsigned long u[2];
    } dw;
    dw.d = 10.0;
    return dw.u[0] != 0 ? 1 : 0;
}

// Function to simulate a similar endianness check with volatile union.
int test_endianness_vol() {
    union doubleword {
        volatile double d;
        volatile unsigned long u[2];
    } dw;
    dw.d = 10.0;
    return dw.u[0] != 0 ? 1 : 0;
}

// Main function demonstrating an endianness test and a dummy function call.
int main() {
    // Test endianness functions for consistency.
    int endianness_check = test_endianness();
    int endianness_check_vol = test_endianness_vol();

    if (endianness_check != endianness_check_vol) {
        printf("Endianness check mismatch!\n");
        abort();
    } else {
        printf("Endianness check passed.\n");
    }

    // Call dummy function and verify its behavior by observing 'g'.
    for (int i = 0; i < 256; i++) {
        dummy(s[i][0]);
    }

    printf("Dummy function was called successfully.\n");
    
    return 0;
}