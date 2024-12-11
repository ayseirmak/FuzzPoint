#include <stdio.h>

int main() {
    // Initialize the union with a constant value
    union { unsigned int __l; float __d; } GlobalUnion = { 0x70c00000U };
    union { unsigned int __l; float __d; } LocalUnion = { 0x3f800000U }; // using the value equivalent to 1.0f in IEEE 754

    // Print the float values from the unions
    printf("%f %f\n", GlobalUnion.__d, LocalUnion.__d);

    // Return 0 to indicate successful execution
    return 0;
}