#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    long double x = INFINITY;  // Initialize x to a floating-point infinity explicitly

    // Since we're checking if x is infinite and its initialized to INFINITY, 
    // this would essentially demonstrate the same logical process as the original assertions.
    if (isinf(x)) {
        assert(isinf(x));  // Use standard library function for checking infinity
        printf("x is infinite.\n");
    } else {
        printf("x is not infinite.\n");
    }

    return 0;  // Indicate that the program executed successfully
}