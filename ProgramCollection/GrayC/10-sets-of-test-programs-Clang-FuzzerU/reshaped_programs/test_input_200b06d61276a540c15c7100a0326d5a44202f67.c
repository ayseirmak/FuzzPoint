#include <stdio.h>
#include <stdlib.h>

// Defines a struct A with a float and an int
struct A {
    float a1;
    int a2;
} a;

// Global variable b
int b;

// Function declaration
int bar(float);

// Function foo that performs specific operations on struct A
void foo(void) {
    // Call bar and assign its result to a.a2
    a.a2 = bar(a.a1);
    // Update a.a2 based on a comparison with b - 1
    a.a2 = a.a2 < b - 1 ? a.a2 : b - 1;
    // If a.a2 is greater than or equal to b - 1, call abort
    if (a.a2 >= b - 1) {
        abort();
    }
}

// Function bar that returns a constant integer
int bar(float x) {
    return 2241;
}

// Main function
int main() {
    // Initialize a.a1 to a fixed float value
    a.a1 = 1.0f;
    // Set b to a fixed integer value
    b = 3384;
    // Call foo
    foo();
    // Return 0 to indicate successful execution
    return 0;
}