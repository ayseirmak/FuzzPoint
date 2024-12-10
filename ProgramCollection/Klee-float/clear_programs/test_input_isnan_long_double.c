#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    long double x = NAN; // Initialize x to a typical NaN scenario for demonstration

    if (isnan(x)) {
        assert(x != x); // Standard behavior check for NaN
        printf("x is NaN\n");
    } else {
        assert(x == x); // Check that x equals itself if it's not NaN (valid float behavior)
        printf("x is not NaN\n");
    }

    return 0;
}