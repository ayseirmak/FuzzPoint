#include <assert.h>
#include <stdio.h>
#include <stdint.h>

int main() {
    float x;
    int32_t y = 123456789; // Initialize with a typical or edge case value

    x = (float)y;

    // Replace KLEE specific checks with standard checks using assertions.
    assert(x >= -0x1.000000p31 && x <= 0x1.000000p31);

    printf("y = %d, casted float x = %f\n", y, x);

    return 0;
}