#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

// Define modular functions with noinline and noclone attributes
__attribute__((noinline, noclone)) int f1(int x, int y) {
    return x % y;
}

__attribute__((noinline, noclone)) int f2(int x, int y) {
    return x % -y;
}

__attribute__((noinline, noclone)) int f3(int x, int y) {
    int z = -y;
    return x % z;
}

int main() {
    // Test conditions based on fixed values
    int test1 = f1(-INT_MAX - 1, 1);
    int test2 = f2(-INT_MAX - 1, -1);
    int test3 = f3(-INT_MAX - 1, -1);

    // Check results and abort if any condition fails
    if (test1 != 0 || test2 != 0 || test3 != 0) {
        printf("Error: Test failed!\n");
        abort();
    }

    printf("All tests passed!\n");
    return 0;
}