#include <stdio.h>
#include <stdint.h>
#include <fenv.h>
#include <float.h>

typedef union {
    uint32_t u;
    float f;
} float_bits;

float floatundisf(uint64_t a) {
    if (a == 0)
        return 0.0F;
    
    const unsigned N = sizeof(uint64_t) * 8;
    int sd = N - __builtin_clzll(a); /* number of significant digits */
    int e = sd - 1; /* exponent */
    
    if (sd > FLT_MANT_DIG) {
        switch (sd) {
            case FLT_MANT_DIG + 1:
                a <<= 1;
                break;
            case FLT_MANT_DIG + 2:
                break;
            default:
                a = (a >> (sd - (FLT_MANT_DIG + 2))) |
                    ((a & ((uint64_t)(-1) >> ((N + FLT_MANT_DIG + 2) - sd))) != 0);
        }
        a |= (a & 4) != 0; /* Or P into R */
        ++a; /* round - this step may add a significant bit */
        a >>= 2; /* dump Q and R */
        
        if (a & ((uint64_t)1 << FLT_MANT_DIG)) {
            a >>= 1;
            ++e;
        }
    } else {
        a <<= (FLT_MANT_DIG - sd);
    }
    
    float_bits fb;
    fb.u = ((e + 127) << 23) | /* exponent */
           ((int32_t)a & 0x007FFFFF); /* mantissa */
    return fb.f;
}

void test(uint64_t x) {
    const float_bits expected = { .f = floatundisf(x) };
    const float_bits observed = { .f = (float)x };

    if (expected.u != observed.u) {
        printf("Error detected @ 0x%016llx\n", x);
        printf("\tExpected result: %a (0x%08x)\n", expected.f, expected.u);
        printf("\tObserved result: %a (0x%08x)\n", observed.f, observed.u);
    }
}

int main() {
    const uint64_t one = 1;
    const uint64_t mone = (uint64_t)-1;

    const int roundingModes[1] = { FE_TONEAREST };
    const char *modeNames[4] = {"to nearest", "down", "up", "towards zero"};

    for (int m = 0; m < 4; ++m) {
        fesetround(roundingModes[0]);
        printf("Testing uint64_t --> float conversions in round %s...\n", modeNames[m]);

        test(0);

        for (int i = 0; i < 64; ++i) {
            test(one << i);
            test(mone << i);
            for (int j = 0; j < i; ++j) {
                test((one << i) + (one << j));
                test((one << i) + (mone << j));
                test((mone << i) + (one << j));
                test((mone << i) + (mone << j));
                for (int k = 0; k < j; ++k) {
                    test((one << i) + (one << j) + (one << k));
                    test((one << i) + (one << j) + (mone << k));
                    test((one << i) + (mone << j) + (one << k));
                    test((one << i) + (mone << j) + (mone << k));
                    test((mone << i) + (one << j) + (one << k));
                    test((mone << i) + (one << j) + (mone << k));
                    test((mone << i) + (mone << j) + (one << k));
                    test((mone << i) + (mone << j) + (mone << k));
                    for (int l = 0; l < k; ++l) {
                        test((one << i) + (one << j) + (one << k) + (one << l));
                        test((one << i) + (one << j) + (one << k) + (mone << l));
                        test((one << i) + (one << j) + (mone << k) + (one << l));
                        test((one << i) + (one << j) + (mone << k) + (mone << l));
                        test((one << i) + (mone << j) + (one << k) + (one << l));
                        test((one << i) + (mone << j) + (one << k) + (mone << l));
                        test((one << i) + (mone << j) + (mone << k) + (one << l));
                        test((one << i) + (mone << j) + (mone << k) + (mone << l));
                        test((mone << i) + (one << j) + (one << k) + (one << l));
                        test((mone << i) + (one << j) + (one << k) + (mone << l));
                        test((mone << i) + (one << j) + (mone << k) + (one << l));
                        test((mone << i) + (one << j) + (mone << k) + (mone << l));
                        test((mone << i) + (mone << j) + (one << k) + (one << l));
                        test((mone << i) + (mone << j) + (one << k) + (mone << l));
                        test((mone << i) + (mone << j) + (mone << k) + (one << l));
                        test((mone << i) + (mone << j) + (mone << k) + (mone << l));
                    }
                }
            }
        }
    }
    printf("Finished Testing.\n");
    return 0;
}