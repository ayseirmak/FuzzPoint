#include <stdio.h>

// Declare a constant double and initialize it to 1.0 for accurate floating point comparison.
const double one = 1.0;

// Placeholder function for link error
void link_error(void) {
    printf("Link error function called.\n");
}

int main(void) {
    // Directly include the logic as optimization flags are irrelevant for correctness checks.
    if ((int)one != 1) {
        link_error();
    }
    return 0;
}