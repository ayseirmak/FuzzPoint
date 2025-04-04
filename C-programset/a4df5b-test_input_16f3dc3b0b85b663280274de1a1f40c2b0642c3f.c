#include <stdio.h>
#include <stdlib.h>

// Fixed arrays as deterministic inputs
int ops[13] = {11, 12, 46, 3, 2, 2, 3, 2, 1, 3, 2, 1, 2};
int correct[13] = {46, 12, 11, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1};

int main() {
    int num = 13;
    int i, j; // Declare loop variables

    // Perform a bubble sort in descending order
    for (i = 0; i < num; i++) {
        for (j = num - 1; j > i; j--) {
            if (ops[j-1] < ops[j]) {
                int temp = ops[j]; // Swap operation
                ops[j] = ops[j-1];
                ops[j-1] = temp;
            }
        }
    }

    // Verify sorted order matches the `correct` array
    for (i = 0; i < num; i++) {
        if (ops[i] != correct[i]) {
            printf("Sorting failure at index %d: expected %d, got %d.\n", i, correct[i], ops[i]);
            abort(); // Abort if verification fails
        }
    }

    printf("Sorting successful. The array matches the expected result.\n");
    return 0; // Use return instead of exit() in main
}