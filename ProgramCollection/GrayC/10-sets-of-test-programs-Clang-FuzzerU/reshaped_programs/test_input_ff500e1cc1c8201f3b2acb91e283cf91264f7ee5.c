#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Function prototypes
int add512(int a, int *b);
int add513(int a, int *b);

int add512(int a, int *b) {
    int c = a + 512;
    if (c != 0) {
        *b = a;
    }
    return c;
}

int add513(int a, int *b) {
    int c = a + 513;
    if (c == 0) {
        *b = a;
    }
    return c;
}

int main(void) {
    int b0 = -1;
    int b1 = -1;
    
    // Static, deterministic inputs are used
    if (add512(-512, &b0) != 0 || b0 != -1 || (add513(-513, &b1) != 0 && b1 != -1)) {
        abort();
    }

    printf("All tests passed.\n");
    return 0;
}