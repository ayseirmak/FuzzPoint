#include <stdio.h>
#include <stdint.h>

// Define the structures with initial values
struct hfa11 { float a; } hfa11 = { 11.1 };
struct hfa12 { float a, b; } hfa12 = { 12.1, 12.2 };
struct hfa13 { float a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
struct hfa14 { float a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

struct hfa21 { double a; } hfa21 = { 21.1 };
struct hfa24 { double a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

struct hfa31 { long double a; } hfa31 = { 31.1 };
struct hfa32 { long double a, b; } hfa32 = { 32.1, 32.2 };
struct hfa33 { long double a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
struct hfa34 { long double a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

// Define the structures for character arrays
#define DEFINE_STRUCT_AND_FUNC(n) \
    struct s##n { char x[n+1]; } s##n = { # n# };

DEFINE_STRUCT_AND_FUNC(1)
DEFINE_STRUCT_AND_FUNC(2)
DEFINE_STRUCT_AND_FUNC(3)
DEFINE_STRUCT_AND_FUNC(4)
DEFINE_STRUCT_AND_FUNC(5)
DEFINE_STRUCT_AND_FUNC(6)
DEFINE_STRUCT_AND_FUNC(7)
DEFINE_STRUCT_AND_FUNC(8)
DEFINE_STRUCT_AND_FUNC(9)
DEFINE_STRUCT_AND_FUNC(10)
DEFINE_STRUCT_AND_FUNC(11)
DEFINE_STRUCT_AND_FUNC(12)
DEFINE_STRUCT_AND_FUNC(13)
DEFINE_STRUCT_AND_FUNC(14)
DEFINE_STRUCT_AND_FUNC(15)
DEFINE_STRUCT_AND_FUNC(16)
DEFINE_STRUCT_AND_FUNC(17)

// Function to print hexadecimal values
void pll(unsigned long long x) {
    printf("%llx\n", x);
}

// Arithmetic operations
static uint32_t addip0(uint32_t x) { return x + 0; }
static uint64_t sublp0(uint64_t x) { return x - 0; }
static uint32_t addip123(uint32_t x) { return x + 123; }
static uint64_t addlm123(uint64_t x) { return x + -123; }
static uint64_t sublp4095(uint64_t x) { return x - 4095; }
static uint32_t subim503808(uint32_t x) { return x - -503808; }
static uint64_t addp12345(uint64_t x) { return x + 12345; }
static uint32_t subp12345(uint32_t x) { return x - 12345; }

// Bitwise operations
static uint32_t mvni(uint32_t x) { return 0xffffffff - x; }
static uint64_t negl(uint64_t x) { return 0 - x; }
static uint32_t rsbi123(uint32_t x) { return 123 - x; }
static uint32_t andi0(uint32_t x) { return x & 0; }
static uint32_t orrim1(uint32_t x) { return x | -1; }
static uint32_t eori0(uint32_t x) { return x ^ 0; }
static uint64_t eorlm1(uint64_t x) { return x ^ -1; }
static uint32_t and0xf0(uint32_t x) { return x & 0xf0; }
static uint32_t orr0xf0(uint32_t x) { return x | 0xf0; }
static uint32_t eor0xf0(uint32_t x) { return x ^ 0xf0; }

// Shift operations
static uint32_t lsli0(uint32_t x) { return x << 0; }
static uint32_t lsri0(uint32_t x) { return x >> 0; }
static int64_t asrl0(int64_t x) { return x >> 0; }
static uint32_t lsli1(uint32_t x) { return x << 1; }
static uint32_t lsli31(uint32_t x) { return x << 31; }
static uint64_t lsll1(uint64_t x) { return x << 1; }
static uint64_t lsll63(uint64_t x) { return x << 63; }
static uint32_t lsri1(uint32_t x) { return x >> 1; }
static uint32_t lsri31(uint32_t x) { return x >> 31; }
static uint64_t lsrl1(uint64_t x) { return x >> 1; }
static uint64_t lsrl63(uint64_t x) { return x >> 63; }
static int32_t asri1(int32_t x) { return x >> 1; }
static int32_t asri31(int32_t x) { return x >> 31; }
static int64_t asrl1(int64_t x) { return x >> 1; }
static int64_t asrl63(int64_t x) { return x >> 63; }

void movi(void) {
    printf("MOVI:\n");
    pll(0xabcdef0123456789ULL);
    // Additional pre-defined values for verification
    pll(0xabcd1234);
    pll(0xabcdffff);
}

void opi(void) {
    int x = 1000;
    pll(addip0(x));
    pll(sublp0(x));
    pll(addip123(x));
    pll(addlm123(x));
    pll(sublp4095(x));
    pll(subim503808(x));
    pll(addp12345(x));
    pll(subp12345(x));
    pll(mvni(x));
    pll(negl(x));
    pll(rsbi123(x));
    pll(andi0(x));
    pll(orrim1(x));
    pll(eori0(x));
    pll(eorlm1(x));
    pll(and0xf0(x));
    pll(orr0xf0(x));
    pll(eor0xf0(x));
    pll(lsli0(x));
    pll(lsri0(x));
    pll(asrl0(x));
    pll(lsli1(x));
    pll(lsli31(x));
    pll(lsll1(x));
    pll(lsll63(x));
    pll(lsri1(x));
    pll(lsri31(x));
    pll(lsrl1(x));
    pll(lsrl63(x));
    pll(asri1(x));
    pll(asri31(x));
    pll(asrl1(x));
    pll(asrl63(x));
}

int main() {
    movi();
    opi();
    return 0;
}