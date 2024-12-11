#include <stdio.h>
#include <stdlib.h>

void abort(void);

int main() {
    // Simulate a condition by initializing `d` directly since no input is allowed
    double d = 10000.0; // This is a placeholder value based on the given condition
    long l = (d > 10000) ? (unsigned long) d : (long) d;

    // Check the condition, if `l` should be -12 according to original logic
    if (l != -12)
        abort();

    // Successful execution
    return 0;
}