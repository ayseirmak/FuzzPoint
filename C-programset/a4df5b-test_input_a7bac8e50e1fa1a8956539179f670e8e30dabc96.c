#include <stdio.h>
#include <stdlib.h>

// Define struct s1
struct s1 {
    double d;
};

// Define struct s2
struct s2 {
    double d;
};

// Define union u
union u {
    struct s1 x;
    struct s2 y;
};

// Function f modifies the value of a->d and returns an addition result
double f(struct s1 *a, struct s2 *b) {
    a->d = 1.0;
    return b->d + 1.0;
}

int main() {
    union u a;
    a.x.d = 0.0;

    // Check if the function f provides expected result and print output
    if (f(&a.x, &a.y) != 2.0) {
        printf("Check failed: The function f did not return the expected value.\n");
        return EXIT_FAILURE;
    }

    printf("Success: The function f returned the expected value.\n");
    return EXIT_SUCCESS;
}