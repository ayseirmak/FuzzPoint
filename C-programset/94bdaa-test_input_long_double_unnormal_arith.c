#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>

// Function to dump the internal representation of a long double
void dump_long_double(long double ld) {
    uint64_t data[2] = {0, 0};
    memcpy(data, &ld, 10);
    printf("a: 0x%.4" PRIx16 " %.16" PRIx64 "\n", (uint16_t)data[1], data[0]);
}

int main() {
    // Initialize operand components
    const uint64_t lowBits = 0x0000000000000001;
    const uint16_t highBits = 0x0001;
    
    // Initialize a long double variable
    long double v = 0.0l;

    // Construct invalid floating-point number using memcpy
    memcpy(&v, &lowBits, sizeof(lowBits));       // Copy 64 bits for low bits
    memcpy(((uint8_t *)(&v)) + 8, &highBits, 2); // Copy 16 bits for high bits

    // Output the representation
    dump_long_double(v);

    // Arithmetic operations with a normal long double
    long double x = 1.0l;

    // Asserting if the result of the operations are NaN
    assert(isnan(v + x));
    assert(isnan(v - x));
    assert(isnan(v * x));
    assert(isnan(v / x));

    return 0;
}