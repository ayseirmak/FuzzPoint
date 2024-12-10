#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Initialize x with a value to represent a typical use case or edge case. 
    // For demonstration, we use NaN for one scenario, change it for different use cases.
    double x = NAN; // Change to specific edge cases: INFINITY, -0.0, or a normal number, etc.

    double result = fabs(x);

    if (isnan(x)) {
        if (signbit(x)) {
            printf("-ve nan\n");
        } else {
            printf("+ve nan\n");
        }
        assert(!signbit(result));
        assert(isnan(result));
    } else if (isinf(x)) {
        if (signbit(x)) {
            printf("-ve inf\n");
        } else {
            printf("+ve inf\n");
        }
        assert(!signbit(result));
        assert(isinf(result) == 1);
    } else if (x == 0.0) {
        if (signbit(x)) {
            printf("-ve 0.0\n");
        } else {
            printf("+ve 0.0\n");
        }
        assert(!signbit(result));
        assert(result == 0.0);
    } else {
        printf("result > 0.0\n");
        assert(result > 0.0);
    }

    return 0;
}