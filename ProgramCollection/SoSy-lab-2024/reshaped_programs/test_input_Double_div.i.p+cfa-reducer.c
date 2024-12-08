#include <stdio.h>
#include <assert.h>

// Function that triggers a runtime assertion if an error is reached
void reach_error() { 
    assert(0 && "reach_error"); 
}

// Main function
int main() {
    // Initialize variables
    double main_x = 1.0;
    double main_x1 = main_x / 2.5;

    // Loop until main_x1 equals main_x
    while (main_x1 != main_x) {
        main_x = main_x1;
        main_x1 = main_x / 2.5;
    }

    // Condition verification step
    int __tmp_1 = (main_x == 0);
    int __VERIFIER_assert__cond = __tmp_1;

    if (!__VERIFIER_assert__cond) {
        reach_error();
    }

    return 0; // Return success
}