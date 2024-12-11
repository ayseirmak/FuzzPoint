#include <stdio.h>
#include <stdlib.h>

// Function to test variadic arguments
void test(int x, ...)
{
    va_list ap;
    va_start(ap, x);

    // Check against expected values and exit if mismatched
    if (va_arg(ap, int) != 1) {
        printf("Error: Expected 1\n");
        exit(1);
    }
    if (va_arg(ap, int) != 2) {
        printf("Error: Expected 2\n");
        exit(1);
    }
    if (va_arg(ap, int) != 3) {
        printf("Error: Expected 3\n");
        exit(1);
    }
    if (va_arg(ap, int) != 4) {
        printf("Error: Expected 4\n");
        exit(1);
    }
    va_end(ap);
}

// Main function
int main()
{
    // Fixed values for demonstration
    int fixedValue = 4;

    // Intent: Validate hardcoded arguments
    test(0, 1, 2, 3, fixedValue);

    // Indicate successful execution
    printf("All tests passed successfully.\n");
    return 0;
}