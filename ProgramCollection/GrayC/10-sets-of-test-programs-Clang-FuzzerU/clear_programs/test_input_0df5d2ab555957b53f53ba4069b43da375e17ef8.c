#include <stdio.h>
#include <stdlib.h>

int f(int a, int *y) {
    int x = a; // Initialize x

    if (a == 0)
        return *y; // Return value of y if a is zero

    return f(a - 1, &x); // Recursively call f with reduced a and address of x
}

int main() {
    int fixed_value = 0; // Instead of NULL, a definite addressable value
    if (f(100, &fixed_value) != 1) {
        printf("Mismatch in return value!\n");
        abort(); // Abort if the function does not return 1
    } else {
        printf("Function execution successful.\n");
    }
    return 0; 
}