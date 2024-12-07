#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef union {
    float value;
    unsigned int word;
} ieee_float_shape_type;

float round_float(float x) {
    unsigned int w;
    int exponent_less_127;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    w = gf_u.word;

    exponent_less_127 = (int)((w & 0x7f800000) >> 23) - 127;

    if (exponent_less_127 < 23) {
        if (exponent_less_127 < 0) {
            w &= 0x80000000;
            if (exponent_less_127 == -1)
                w |= (unsigned int)127 << 23;
        } else {
            unsigned int exponent_mask = 0x007fffff >> exponent_less_127;
            if ((w & exponent_mask) == 0)
                return x;

            w += 0x00400000 >> exponent_less_127;
            w &= ~exponent_mask;
        }
    } else {
        if (exponent_less_127 == 128)
            return x + x;
        else
            return x;
    }

    ieee_float_shape_type sf_u;
    sf_u.word = w;
    x = sf_u.value;

    return x;
}

// NaN check for float
int isnan_float(float x) {
    return x != x;
}

int main() {
    float x = 0.0f / 0.0f; // NaN
    float res = round_float(x);

    // The result should be NaN
    if (!isnan_float(res)) {
        printf("Error: Result should be NaN\n");
        // Using assert to simulate reach_error functionality
        assert(0);
        return 1;
    }

    printf("Result is NaN as expected.\n");
    return 0;
}