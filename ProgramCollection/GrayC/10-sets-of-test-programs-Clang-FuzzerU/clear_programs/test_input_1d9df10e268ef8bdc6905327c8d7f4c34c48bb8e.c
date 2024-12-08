#include <stdio.h>
#include <stdlib.h>

// Simple recursive function
int f(int a, int *y) {
    int x = a;

    if (a == 0)
        return *y;

    return f(a - 1, &x);
}

int main() {
    // Validate the output of the function 'f'
    if (f(100, (int *) 0) != 1) {
        printf("Error: unexpected result\n");
        exit(1);  // Equivalent to 'abort()' but exits the program with a status code
    }
    printf("Program executed successfully.\n");
    return 0;
}