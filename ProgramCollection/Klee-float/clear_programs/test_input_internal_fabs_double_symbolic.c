#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    // Initialize x with a test value like -NAN, +INFINITY, or any specific float value to simulate test cases
    double x = -NAN;  // Example test value; adjust as needed for different scenarios

    double result = fabs(x);  // Use standard library fabs for absolute value

    if (isnan(x)) {
        if (signbit(x)) {
            printf("-ve nan\n");
        } else {
            printf("+ve nan\n");
        }
        assert(!signbit(result));
        assert(isnan(result));
        return 0;
    }

    if (isinf(x)) {
        if (signbit(x)) {
            printf("-ve inf\n");
        } else {
            printf("+ve inf\n");
        }
        assert(!signbit(result));
        assert(isinf(result) == 1);
        return 0;
    }

    if (x == 0.0) {
        if (signbit(x)) {
            printf("-ve 0.0\n");
        } else {
            printf("+ve 0.0\n");
        }
        assert(!signbit(result));
        assert(result == 0.0);
        return 0;
    }

    printf("result > 0.0\n");
    assert(result > 0.0);

    return 0;
}