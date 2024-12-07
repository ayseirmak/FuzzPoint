#include <stdio.h>
#include <stdint.h>
#include <assert.h>

typedef union {
    float value;
    uint32_t word;
} ieee_float_shape_type;

float round_float(float x) {
    uint32_t w;
    int exponent_less_127;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    exponent_less_127 = ((w & 0x7f800000) >> 23) - 127;

    if (exponent_less_127 < 23) {
        if (exponent_less_127 < 0) {
            w &= 0x80000000;
            if (exponent_less_127 == -1) {
                w |= ((uint32_t)127 << 23);
            }
        } else {
            unsigned int exponent_mask = 0x007fffff >> exponent_less_127;
            if ((w & exponent_mask) == 0) {
                return x;
            }
            w += 0x00400000 >> exponent_less_127;
            w &= ~exponent_mask;
        }
    } else {
        if (exponent_less_127 == 128) {
            return x + x;
        } else {
            return x;
        }
    }
    
    ieee_float_shape_type sf_u;
    sf_u.word = w;
    x = sf_u.value;
    
    return x;
}

// infinity check for floats
int isinf_float(float x) {
    int32_t ix;
    ieee_float_shape_type gf_u;
    gf_u.value = x;
    ix = gf_u.word;
    ix &= 0x7fffffff;
    return (ix == 0x7f800000L);
}

int main() {
    float x = -1.0f / 0.0f; // -INF
    float res = round_float(x);

    // result shall be x
    if (!isinf_float(res)) {
        printf("Error: result is not infinity as expected.\n");
        return 1;
    }

    printf("Test passed: Infinity input results in infinity output as expected.\n");
    return 0;
}