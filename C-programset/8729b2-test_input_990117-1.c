#include <stdio.h>
#include <stdlib.h>

int foo(int x, int y, int i, int j) {
    double tmp1 = ((double)x / y);
    double tmp2 = ((double)i / j);
    return tmp1 < tmp2;
}

int main() {
    // Initialize the variables with typical non-zero values for testing
    int x = 10;
    int y = 2; 
    int i = 25;
    int j = 5;

    // Call foo function with initialized values
    if (foo(x, y, i, j) == 0) {
        printf("Foo returned 0, indicating tmp1 is not less than tmp2.\n");
    } else {
        printf("Foo returned non-zero, indicating tmp1 is less than tmp2.\n");
    }

    return 0;
}