#include <stdarg.h>
#include <stdio.h>

void ld_after_zero(int first, ...) {
    va_list ap;
    long double dub;

    // Initialize va_list
    va_start(ap, first);

    // Consume all integer parameters until zero is encountered
    while (va_arg(ap, int) != 0)
        ;

    // Now fetch the long double
    dub = va_arg(ap, long double);

    // Print the long double value
    printf("%Lf\n", dub);

    // Clean up the va_list
    va_end(ap);
}

int main() {
    long double dub = 1.123456L; // Initialize with a fixed long double value
    int zero = 0;  // Explicitly declaring and initializing zero
    int one = 1;   // Explicitly declaring and initializing one

    // Call the function with different parameter sets to test alignment
    ld_after_zero(one, zero, dub);
    ld_after_zero(one, one, zero, dub);

    return 0;  // Return 0 to indicate successful execution
}