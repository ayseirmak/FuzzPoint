#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>

// Define the union for ieee_double_shape_type
typedef union {
    double value;
    struct {
        uint32_t lsw;
        uint32_t msw;
    } parts;
} ieee_double_shape_type;

// Function to check if a double is NaN
int isnan_double(double x) {
    return x != x;
}

// Function to round a double value
double round_double(double x) {
    int32_t msw, exponent_less_1023;
    uint32_t lsw;

    ieee_double_shape_type ew_u;
    ew_u.value = x;
    msw = ew_u.parts.msw;
    lsw = ew_u.parts.lsw;

    exponent_less_1023 = ((msw & 0x7ff00000) >> 20) - 1023;
    if (exponent_less_1023 < 20) {
        if (exponent_less_1023 < 0) {
            msw &= 0x80000000;
            if (exponent_less_1023 == -1) {
                msw |= (1023 << 20);
            }
            lsw = 0;
        } else {
            uint32_t exponent_mask = 0x000fffff >> exponent_less_1023;
            if ((msw & exponent_mask) == 0 && lsw == 0) {
                return x;
            }
            msw += 0x00080000 >> exponent_less_1023;
            msw &= ~exponent_mask;
            lsw = 0;
        }
    } else if (exponent_less_1023 > 51) {
        if (exponent_less_1023 == 1024) {
            return x + x;
        } else {
            return x;
        }
    } else {
        uint32_t exponent_mask = 0xffffffff >> (exponent_less_1023 - 20);
        uint32_t tmp;
        if ((lsw & exponent_mask) == 0) {
            return x;
        }
        tmp = lsw + (1 << (51 - exponent_less_1023));
        if (tmp < lsw) {
            msw += 1;
        }
        lsw = tmp;
        lsw &= ~exponent_mask;
    }
    
    ieee_double_shape_type iw_u;
    iw_u.parts.msw = msw;
    iw_u.parts.lsw = lsw;
    x = iw_u.value;
    
    return x;
}

int main() {
    // Define a NaN double value for testing
    double x = 0.0 / 0.0; // NaN
    double res = round_double(x);

    // Assert that result should be NaN
    assert(isnan_double(res));

    printf("Test passed.\n");

    return 0;
}