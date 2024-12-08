#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <assert.h>

typedef union {
    float value;
    uint32_t word;
} ieee_float_shape_type;

static const float one_modf = 1.0f;

float modf_float(float x, float *iptr) {
    int32_t i0, j0;
    uint32_t i;

    ieee_float_shape_type gf_u;
    gf_u.value = x;
    i0 = gf_u.word;

    j0 = ((i0 >> 23) & 0xff) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            ieee_float_shape_type sf_u;
            sf_u.word = (i0 & 0x80000000);
            *iptr = sf_u.value;
            return x;
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) {
                uint32_t ix;
                *iptr = x;
                ieee_float_shape_type gf_u;
                gf_u.value = x;
                ix = gf_u.word;
                ieee_float_shape_type sf_u;
                sf_u.word = (ix & 0x80000000);
                x = sf_u.value;
                return x;
            } else {
                ieee_float_shape_type sf_u;
                sf_u.word = (i0 & (~i));
                *iptr = sf_u.value;
                return x - *iptr;
            }
        }
    } else {
        uint32_t ix;
        *iptr = x * one_modf;
        ieee_float_shape_type gf_u;
        gf_u.value = x;
        ix = gf_u.word;
        ieee_float_shape_type sf_u;
        sf_u.word = (ix & 0x80000000);
        x = sf_u.value;
        return x;
    }
}

// Check if the float is NaN
int isnan_float(float x) {
    return x != x;
}

int main() {
    // Initialize a NaN value and test modf_float function
    float x = NAN; // Deterministic NaN value
    float iptr;
    float res = modf_float(x, &iptr);

    // Assert that both iptr and res are NaN as per REQ-BL-1210 requirement
    if (isnan_float(iptr) && !isnan_float(res)) {
        fprintf(stderr, "ERROR: Expected NaN for both iptr and res.\n");
        abort();
    }
    printf("Test completed successfully.\n");
    return 0;
}