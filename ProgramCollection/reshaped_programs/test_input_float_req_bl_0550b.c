#include <stdio.h>
#include <math.h>
#include <assert.h>

// Define constants used in the program
static const float huge_floor = 1.0e30;
static const float two25_scalbn = 3.3554432e+07;
static const float twom25_scalbn = 2.9802322388e-08;
static const float huge_scalbn = 1.0e+30;
static const float tiny_scalbn = 1.0e-30;
static const int init_jk_krempio[] = {4, 7, 9};
static const float PIo2_krempio[] = { 
    1.5703125000e+00, 4.5776367188e-04, 2.5987625122e-05, 7.5437128544e-08,
    6.0026650317e-11, 7.3896444519e-13, 5.3845816694e-15, 5.6378512969e-18,
    8.3009228831e-20, 3.2756352257e-22, 6.3331015649e-25
};
static const float zero_krempio = 0.0, one_krempio = 1.0,
                   two8_krempio = 2.5600000000e+02, twon8_krempio = 3.9062500000e-03;

// Helper functions for float operations
float floor_float(float x) {
    return floorf(x);
}

int isinf_float(float x) {
    return isinf(x);
}

int isnan_float(float x) {
    return isnan(x);
}

float tan_float(float x) {
    return tanf(x);
}

int main() {
    // Test case to validate the tan function for -INF input.
    // Calculate tan(-INF) which should return NaN.
    float x = -HUGE_VALF; // -INF
    float res = tan_float(x);

    // Check if result is NaN
    assert(isnan_float(res));

    // If the assertion holds, the program will print success.
    printf("Test passed: tan(-INF) results in NaN.\n");
    return 0;
}