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
    
    // Use an assertion to check the condition
    assert(value == 2.0);
}

int main() {
    // Call fdouble with fixed, deterministic values
    fdouble(1.0, 2.0);

    // Exit the program successfully
    return 0;
}