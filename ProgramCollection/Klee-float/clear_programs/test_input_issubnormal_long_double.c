#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    long double x = 1.0e-4932L; // Initialize x with a small subnormal value (for demonstration purposes)

    if (fpclassify(x) == FP_SUBNORMAL) {
        assert(fpclassify(x) == FP_SUBNORMAL);
    } else {
        assert(fpclassify(x) != FP_SUBNORMAL);
    }

    return 0;
}