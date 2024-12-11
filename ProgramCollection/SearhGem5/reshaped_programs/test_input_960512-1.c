#include <stdio.h>

double f(int a[]) {
    double c;

    a[9] = 0; // Assuming this is the desired behavior since a[9] is set before use.
    c = a[9];
    return c;
}

int main() {
    double c;
    int a[40] = {0}; // Initialize all elements to 0 to avoid uninitialized use.

    c = f(a);

    if (c != 0.0) {
        printf("Unexpected non-zero value\n");
        return 1;
    }

    printf("Program executed successfully.\n");
    return 0;
}