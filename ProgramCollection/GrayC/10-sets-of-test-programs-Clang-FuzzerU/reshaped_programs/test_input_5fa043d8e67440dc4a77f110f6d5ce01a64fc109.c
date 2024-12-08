#include <stdio.h>
#include <stdlib.h>

// Definition of struct stuff
struct stuff {
    int g;
};

// Function that checks if the 'g' member is equal to 2
void bar(struct stuff *x) __attribute__ ((noinline));
void bar(struct stuff *x) {
    if (x->g != 2) {
        printf("Abort: x->g is not 2\n");
        exit(EXIT_FAILURE);  // Replacing __builtin_abort() with exit for standard compliance
    }
}

int main() {
    // Declare and initialize the multi-dimensional array
    int arr[2][3][5] = {
        {
            {0, 0, 3, 5, 0},
            {1, 0, 0, 6, 7},
            {0, 0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 6, 7},
            {0, 0, 0, 0, 0}
        }
    };

    // Check equality of specific elements in the array
    int result = arr[0][1][4] == arr[1][1][4];

    // Print the result
    if (result) {
        printf("Match: arr[0][1][4] is equal to arr[1][1][4]\n");
    } else {
        printf("No Match: arr[0][1][4] is not equal to arr[1][1][4]\n");
    }

    return 0;
}