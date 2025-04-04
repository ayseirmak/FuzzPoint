#include <stdio.h>
#include <stdlib.h>

// Function to test endianness
int test_endianness() {
    union doubleword {
        double d;
        unsigned long u[2];
    } dw;
    dw.d = 10;
    return dw.u[0] != 0 ? 1 : 0;
}

// Volatile version of the endianness test
int test_endianness_vol() {
    union doubleword {
        volatile double d;
        volatile unsigned long u[2];
    } dw;
    dw.d = 10;
    return dw.u[0] != 0 ? 1 : 0;
}

// Extern declaration of abort function
extern void abort(void);

volatile char s[256][3];
char g;

// Dummy function to assign value
static void dummy(char a) {
    g = a;
}

// Sample function using abort
static int foo(void) {
    int i, j = 0;

    for (i = 0; i < 256; i++) {
        if (i >= 128) {
            dummy(s[i - 128][0]);
            ++j;
        }
    }

    return j;
}

int main(void) {
    if (test_endianness() != test_endianness_vol()) {
        abort();
    }
    
    if (foo() != 128) {
        abort();
    }

    return 0;
}