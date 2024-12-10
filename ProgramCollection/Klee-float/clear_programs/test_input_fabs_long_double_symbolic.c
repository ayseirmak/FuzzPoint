#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main() {
    // Choose a value for x that covers an interesting case, e.g., a negative value
    long double x = -0.0l;  // Example value, change as needed to test different cases

    long double result = fabsl(x);

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
    } else if (x == 0.0l) {
        if (signbit(x)) {
            printf("-ve 0.0\n");
        } else {
            printf("+ve 0.0\n");
        }
        assert(!signbit(result));
        assert(result == 0.0l);
    } else {
        printf("result > 0.0\n");
        assert(result > 0.0l);
    }

    return 0;
}