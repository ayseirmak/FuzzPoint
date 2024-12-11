#include <stdio.h>

float example_float = 123.456f; // Example float value for initialization

int test_endianness(float input_value) {
    union doubleword {
        double d;
        unsigned long u[2];
    } dw;
    
    dw.d = input_value;
    return dw.u[0] != 0 ? 1 : 0;
}

int test_endianness_vol(float input_value) {
    union doubleword {
        volatile double d;
        volatile long u[2];
    } dw;
    
    dw.d = input_value;
    return dw.u[0] != 0 ? 1 : 0;
}

int main() {
    float test_value = example_float;

    // Conduct tests using the test_value
    if (test_endianness(test_value) != test_endianness_vol(test_value)) {
        // Log an error message as abort is removed
        printf("Error: Endianness tests do not match.\n");
    } else {
        printf("Success: Endianness tests match.\n");
    }

    return 0; // Return 0 to indicate successful execution
}