#include <stdio.h>
#include <stdlib.h>

// Function f takes an integer a and a pointer to an integer y.
int f(int a, int *y) {
    int x = a; // Initialize x with the value of a

    // If a is 0, return the value pointed by y
    if (a == 0) {
        return *y;
    }

    // Recursive call to f with the decremented a
    return f(a - 1, &x);
}

int main() {
    // Call function f with a = 100 and a null pointer cast as int*
    // Since there's a null dereference attempt, the revised intention is unclear in original code
    // Ensure replacing with a valid pointer in actual non-toy usage.
    int dummy = 1;
    if (f(100, &dummy) != 1) {
        printf("Unexpected result\n");
        abort();
    }

    printf("Program exited successfully\n");
    return 0;
}