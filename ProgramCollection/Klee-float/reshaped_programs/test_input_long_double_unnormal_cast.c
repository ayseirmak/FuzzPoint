#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void dump_long_double(long double ld) {
    uint64_t data[2] = {0, 0};
    memcpy(data, &ld, 10);
    printf("a: 0x%.4" PRIx16 " %.16" PRIx64 "\n", (uint16_t)data[1], data[0]);
}

int main() {
    const uint64_t lowBits = 0x2000000000000000;
    const uint16_t highBits = 0xc001;
    long double v = 0.0l;
    
    memcpy(&v, &lowBits, sizeof(lowBits));       // 64 bits
    memcpy(((uint8_t *)(&v)) + 8, &highBits, 2); // 16 bits

    dump_long_double(v);

    long double x = 1.0l;
    
    assert(isnan((float)v));
    assert(isnan((double)v));

    // Check signed casts
    assert(((int8_t)v) == 0);
    
    int16_t temp = (int16_t)v;
    assert((temp == 0) || (temp == -32768));

    assert(((int32_t)v) == -2147483648);
    assert(((int64_t)v) == INT64_MIN);

    // Check unsigned casts
    assert(((uint8_t)v) == 0);
    assert(((uint16_t)v) == 0);
    assert(((uint32_t)v) == 0);
    
    uint64_t temp2 = (uint64_t)v;
    assert(temp2 == 0 || temp2 == 0x8000000000000000);

    return 0;
}