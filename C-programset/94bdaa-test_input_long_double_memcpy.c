#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

// Global variable
long double globalLongDouble = 0.0l;

// Function to print the representation of a long double
void dump_long_double(long double ld) {
    uint64_t data[2] = {0, 0};
    memcpy(data, &ld, 10);
    printf("a: 0x%.4" PRIx16 " %.16" PRIx64 "\n", (uint16_t)data[1], data[0]);
}

int main() {
    // Initialize and declare local variable
    long double x = 1.0l;

    // Copy and check using assert
    long double localCopy = NAN;
    memcpy(&localCopy, &x, sizeof(long double));
    assert(localCopy == x);

    memcpy(&globalLongDouble, &x, sizeof(long double));
    assert(globalLongDouble == x);

    return 0; // Indicate successful execution
}