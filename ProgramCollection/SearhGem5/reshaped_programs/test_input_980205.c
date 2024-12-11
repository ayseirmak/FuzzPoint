#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

void fdouble(double one, ...) {
    double value;
    va_list ap;

    va_start(ap, one);
    value = va_arg(ap, double);
    va_end(ap);

    // Modify these values as needed for testing
    double expected_one = 2.0;
    double expected_value = 3.5;

    if (one != expected_one || value != expected_value) {
        printf("Test failed: one = %f, value = %f\n", one, value);
    } else {
        printf("Test passed.\n");
    }
}

int main() {
    // Directly pass predetermined values to the function for testing
    fdouble(2.0, 3.5);
    return 0;
}