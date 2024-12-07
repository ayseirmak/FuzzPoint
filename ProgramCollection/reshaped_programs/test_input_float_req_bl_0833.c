#include <stdio.h>
#include <float.h>

// Define a function to simulate a custom error handling similar to reach_error()
void reach_error() {
    printf("Error reached!\n");
}

typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef union {
    float value;
    __uint32_t word;
} ieee_float_shape_type;

// Constants as defined originally.
static const float one_exp = 1.0f,
                   halF_exp[2] = {0.5f, -0.5f},
                   huge_exp = 1.0e+30f, 
                   twom100_exp = 7.8886090522e-31f,
                   ln2HI_exp[2] = {6.9313812256e-01f, -6.9313812256e-01f},
                   ln2LO_exp[2] = {9.0580006145e-06f, -9.0580006145e-06f},
                   invln2_exp = 1.4426950216e+00f, 
                   P1_exp = 1.6666667163e-01f,
                   P2_exp = -2.7777778450e-03f, 
                   P3_exp = 6.6137559770e-05f,
                   P4_exp = -1.6533901999e-06f, 
                   P5_exp = 4.1381369442e-08f;

float __ieee754_expf(float x) {
    float y, hi, lo, c, t;
    __int32_t k = 0, xsb;
    __uint32_t hx, sx;

    do {
        ieee_float_shape_type gf_u;
        gf_u.value = x;
        sx = gf_u.word;
    } while (0);
    xsb = (sx >> 31) & 1;
    hx = sx & 0x7fffffff;

    if (hx > 0x7f800000L) {
        return x + x;
    }
    if (hx == 0x7f800000L) {
        return (xsb == 0) ? x : 0.0f;
    }
    if (sx > 0x42b17217L) {
        return huge_exp * huge_exp;
    }
    if (sx < 0 && hx > 0x42cff1b5L) {
        return twom100_exp * twom100_exp;
    }

    if (hx > 0x3eb17218L) {
        if (hx < 0x3F851592L) {
            hi = x - ln2HI_exp[xsb];
            lo = ln2LO_exp[xsb];
            k = 1 - xsb - xsb;
        } else {
            k = invln2_exp * x + halF_exp[xsb];
            t = k;
            hi = x - t * ln2HI_exp[0];
            lo = t * ln2LO_exp[0];
        }
        x = hi - lo;
    } else if (hx < 0x31800000L) {
        if (huge_exp + x > one_exp) {
            return one_exp + x;
        }
    }

    t = x * x;
    c = x - t * (P1_exp + t * (P2_exp + t * (P3_exp + t * (P4_exp + t * P5_exp))));
    if (k == 0) {
        return one_exp - ((x * c) / (c - 2.0f) - x);
    } else {
        y = one_exp - ((lo - (x * c) / (2.0f - c)) - hi);
    }

    if (k >= -125) {
        __uint32_t hy;
        do {
            ieee_float_shape_type gf_u;
            gf_u.value = y;
            hy = gf_u.word;
        } while (0);
        do {
            ieee_float_shape_type sf_u;
            sf_u.word = hy + (k << 23);
            y = sf_u.value;
        } while (0);
        return y;
    } else {
        __uint32_t hy;
        do {
            ieee_float_shape_type gf_u;
            gf_u.value = y;
            hy = gf_u.word;
        } while (0);
        do {
            ieee_float_shape_type sf_u;
            sf_u.word = hy + ((k + 100) << 23);
            y = sf_u.value;
        } while (0);
        return y * twom100_exp;
    }
}

int __signbit_float(float x) {
    __uint32_t w;
    do {
        ieee_float_shape_type gf_u;
        gf_u.value = x;
        w = gf_u.word;
    } while (0);
    return (w & 0x80000000) != 0;
}

int main() {
    float x = -FLT_MAX; // Simulated -INFINITY using a large negative number
    float res = __ieee754_expf(x);

    if (!(res == 0.0f && __signbit_float(res) == 0)) {
        reach_error();
        return 1;
    }

    return 0;
}