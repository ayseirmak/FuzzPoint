#include <stdio.h>
#include <math.h>
#include <stdint.h>

// Function to check if float is NaN
int isnan_float(float x) {
    return x != x;
}

// Function to calculate absolute value of a float
float fabs_float(float x) {
    uint32_t ix;
    union {
        float value;
        uint32_t word;
    } u;
    u.value = x;
    ix = u.word;
    u.word = ix & 0x7fffffff;
    return u.value;
}

// Predefined constants
static const float atanhi_atan[] = {
    4.6364760399e-01,
    7.8539812565e-01,
    9.8279368877e-01,
    1.5707962513e+00,
};

static const float atanlo_atan[] = {
    5.0121582440e-09,
    3.7748947079e-08,
    3.4473217170e-08,
    7.5497894159e-08,
};

static const float aT_atan[] = {
    3.3333334327e-01, -2.0000000298e-01, 1.4285714924e-01, -1.1111110449e-01,
    9.0908870101e-02, -7.6918758452e-02, 6.6610731184e-02, -5.8335702866e-02,
    4.9768779427e-02, -3.6531571299e-02, 1.6285819933e-02,
};

static const float one_atan = 1.0, huge_atan = 1.0e30,
                   pi_o_4 = 7.8539818525e-01, pi_o_2 = 1.5707963705e+00,
                   pi = 3.1415927410e+00;

// Arctangent function
float atan_float(float x) {
    float w, s1, s2, z;
    int32_t ix, hx, id;
    union {
        float value;
        uint32_t word;
    } u;
    u.value = x;
    hx = u.word;
    ix = hx & 0x7fffffff;

    if (ix >= 0x50800000) {
        if (ix > 0x7f800000UL)
            return x + x;
        if (hx > 0)
            return atanhi_atan[3] + atanlo_atan[3];
        else
            return -atanhi_atan[3] - atanlo_atan[3];
    }
    if (ix < 0x3ee00000) {
        if (ix < 0x31000000) {
            if (huge_atan + x > one_atan) return x;
        }
        id = -1;
    } else {
        x = fabs_float(x);
        if (ix < 0x3f980000) {
            if (ix < 0x3f300000) {
                id = 0; x = ((float)2.0 * x - one_atan) / ((float)2.0 + x);
            } else {
                id = 1; x = (x - one_atan) / (x + one_atan);
            }
        } else {
            if (ix < 0x401c0000) {
                id = 2; x = (x - (float)1.5) / (one_atan + (float)1.5 * x);
            } else {
                id = 3; x = -(float)1.0 / x;
            }
        }
    }
    z = x * x;
    w = z * z;
    s1 = z * (aT_atan[0] + w * (aT_atan[2] + w * (aT_atan[4] + w * (aT_atan[6] + w * (aT_atan[8] + w * aT_atan[10])))));
    s2 = w * (aT_atan[1] + w * (aT_atan[3] + w * (aT_atan[5] + w * (aT_atan[7] + w * aT_atan[9]))));
    if (id < 0) return x - x * (s1 + s2);
    else {
        z = atanhi_atan[id] - ((x * (s1 + s2) - atanlo_atan[id]) - x);
        return (hx < 0) ? -z : z;
    }
}

// Arctangent of two variables function
float __ieee754_atan2f(float y, float x) {
    float z;
    int32_t k, m, hx, hy, ix, iy;
    union {
        float value;
        uint32_t word;
    } u;
    
    // Extract exponent and sign for x
    u.value = x;
    hx = u.word;
    ix = hx & 0x7fffffff;

    // Extract exponent and sign for y
    u.value = y;
    hy = u.word;
    iy = hy & 0x7fffffff;

    if (ix > 0x7f800000UL || iy > 0x7f800000UL) return x + y;

    if (hx == 0x3f800000) return atan_float(y);

    m = (hy >> 31 & 1) | (hx >> 30 & 2);

    // When y is zero
    if (iy == 0) {
        switch (m) {
            case 0: case 1: return y;
            case 2: return pi + 1.0e-30;
            case 3: return -pi - 1.0e-30;
        }
    }

    // When x is zero
    if (ix == 0) return (hy < 0) ? -pi_o_2 - 1.0e-30 : pi_o_2 + 1.0e-30;

    // When x is infinity
    if (ix == 0x7f800000L) {
        if (iy == 0x7f800000L) {
            switch (m) {
                case 0: return pi_o_4 + 1.0e-30;
                case 1: return -pi_o_4 - 1.0e-30;
                case 2: return (float)3.0 * pi_o_4 + 1.0e-30;
                case 3: return (float)-3.0 * pi_o_4 - 1.0e-30;
            }
        } else {
            switch (m) {
                case 0: return 0.0;
                case 1: return -0.0;
                case 2: return pi + 1.0e-30;
                case 3: return -pi - 1.0e-30;
            }
        }
    }

    // When y is infinity
    if (iy == 0x7f800000L) return (hy < 0) ? -pi_o_2 - 1.0e-30 : pi_o_2 + 1.0e-30;

    // Calculate arctangent based on the differences
    k = (iy - ix) >> 23;
    if (k > 60) z = pi_o_2 + (float)0.5 * -8.7422776573e-08;
    else if (hx < 0 && k < -60) z = 0.0;
    else z = atan_float(fabs_float(y / x));

    switch (m) {
        case 0: return z;
        case 1: 
            // Negate the result
            u.value = z;
            u.word ^= 0x80000000;
            return u.value;
        case 2: return pi - (z - -8.7422776573e-08);
        default: return (z - -8.7422776573e-08) - pi;
    }
}

int main() {
    // Define fixed x and y values
    float x = NAN;
    float y = 1.0f;

    // Check if x or y is NaN
    if (isnan_float(x) || isnan_float(y)) {
        // Calculate the result using atan2 function
        float res = __ieee754_atan2f(y, x);

        // Assert that result is NaN
        if (!isnan_float(res)) {
            printf("Error: Result is not NaN when it should be.\n");
            return 1;
        }
    }

    printf("Completed successfully.\n");
    return 0;
}