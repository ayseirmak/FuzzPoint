#include <stdio.h>
#include <stdlib.h>

// Structure with a bit-field to store a signed integer.
struct {
    int b : 16;  // Reduced to 16 bits to ensure consistent behavior
} f;

// Function to set the structure's bit-field to a short integer value.
void foo(short j) {
    f.b = j;
}

// Function to perform some operations on an array of floats.
void modifyArray(float *x) {
    float temp[4] = {1.0, 2.0, 3.0, 4.0}; // Initialize with specific values
    x[0] = temp[0];
    x[1] = temp[1];
    x[2] = temp[2];
    x[3] = temp[3];
}

int main() {
    // Test the foo function
    foo(-55);
    if (f.b != -55) {
        abort();
    }

    // Test the modifyArray function
    float x[4];
    modifyArray(x);

    // Output the modified array to verify the function
    for (int i = 0; i < 4; i++) {
        printf("x[%d] = %.1f\n", i, x[i]);
    }

    return 0;
}