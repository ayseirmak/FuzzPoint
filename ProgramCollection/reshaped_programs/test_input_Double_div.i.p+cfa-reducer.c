#include <assert.h>
#include <stdio.h>

int main() {
    // Initialize variables
    double x = 1.0;
    double x1 = x / 2.5;

label_27:
    if (x1 != x) {
        x = x1;
        x1 = x / 2.5;
        goto label_27;
    } else {
        // Assertion check instead of reach_error
        assert(x == 0);

        // Logging the output (for debugging purposes or verification)
        printf("Final value of x: %f\n", x);

        return 0;
    }
}