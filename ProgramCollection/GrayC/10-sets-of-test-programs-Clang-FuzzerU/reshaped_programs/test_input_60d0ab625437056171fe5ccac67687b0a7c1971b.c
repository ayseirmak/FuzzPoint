#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int f1(int x, int y) {
    return x % y;
}

int f2(int x, int y) {
    return x % -y;
}

int f3(int x, int y) {
    int z = -y;
    return x % z;
}

int main() {
    // Check function outputs with fixed deterministic inputs
    if (f1(-INT_MAX - 1, 1) != 0 || 
        f2(-INT_MAX - 1, -1) != 0 || 
        f3(-INT_MAX - 1, -1) != 0) {
        printf("Test failed!\n");
        return EXIT_FAILURE;
    } else {
        printf("All tests passed!\n");
    }
  
    return EXIT_SUCCESS;
}