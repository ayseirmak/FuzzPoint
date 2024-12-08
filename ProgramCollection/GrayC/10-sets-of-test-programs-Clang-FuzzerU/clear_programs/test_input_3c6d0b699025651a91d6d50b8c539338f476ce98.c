#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

void test(int x, ...) {
    va_list ap;
    va_start(ap, x);

    // Read and assert the expected values
    if (va_arg(ap, int) != 1) {
        printf("Error: Expected value of 1 not found.\n");
        abort();
    }
    if (va_arg(ap, int) != 2) {
        printf("Error: Expected value of 2 not found.\n");
        abort();
    }
    if (va_arg(ap, int) != 3) {
        printf("Error: Expected value of 3 not found.\n");
        abort();
    }
    if (va_arg(ap, int) != 4) {
        printf("Error: Expected value of 4 not found.\n");
        abort();
    }

    va_end(ap);
}

int main(void) {
    double a = 40.0;

    // Call test with fixed values
    test(0, 1, 2, 3, (int)(a / 10.0));

    return 0;
}