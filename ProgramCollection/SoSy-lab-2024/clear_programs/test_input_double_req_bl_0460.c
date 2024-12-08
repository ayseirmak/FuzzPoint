#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <assert.h>

// Function to simulate reach_error()
void reach_error() {
    printf("Error: reach_error was called.\n");
    assert(0);
}

// Simulate a non-deterministic double value
double predetermined_value = 2.0; // Set a predetermined value that is outside the range [-1, 1]

// Function to replace __ieee754_sqrt
double __ieee754_sqrt(double x) {
    return sqrt(x);
}

double __ieee754_acos(double x) {
    double z, p, q, r, w, s, c, df;
    int32_t hx, ix;
    union {
        double value;
        struct {
            uint32_t lsw;
            uint32_t msw;
        } parts;
    } gh_u;
    gh_u.value = x;
    hx = gh_u.parts.msw;

    ix = hx & 0x7fffffff;
    if (ix >= 0x3ff00000) {
        uint32_t lx;
        union {
            double value;
            struct {
                uint32_t lsw;
                uint32_t msw;
            } parts;
        } gl_u;
        gl_u.value = x;
        lx = gl_u.parts.lsw;
        if (((ix - 0x3ff00000) | lx) == 0) {
            if (hx > 0)
                return 0.0;
            else
                return M_PI + 2.0 * (6.12323399573676603587e-17);
        }
        return (x - x) / (x - x);  // This will produce NaN
    }
    if (ix < 0x3fe00000) {
        if (ix <= 0x3c600000)
            return (M_PI / 2.0) + (6.12323399573676603587e-17);
        z = x * x;
        p = z * (1.66666666666666657415e-01 +
                 z * (-3.25565818622400915405e-01 +
                      z * (2.01212532134862925881e-01 + 
                           z * (-4.00555345006794114027e-02 +
                                z * (7.91534994289814532176e-04 +
                                     z * 3.47933107596021167570e-05)))));
        q = 1.0 + z * (-2.40339491173441421878e+00 +
                       z * (2.02094576023350569471e+00 +
                            z * (-6.88283971605453293030e-01 +
                                 z * 7.70381505559019352791e-02)));
        r = p / q;
        return (M_PI / 2.0) - (x - (6.12323399573676603587e-17 + x * r));
    } else if (hx < 0) {
        z = (1.0 + x) * 0.5;
        p = z * (1.66666666666666657415e-01 +
                 z * (-3.25565818622400915405e-01 +
                      z * (2.01212532134862925881e-01 +
                           z * (-4.00555345006794114027e-02 +
                                z * (7.91534994289814532176e-04 +
                                     z * 3.47933107596021167570e-05)))));
        q = 1.0 + z * (-2.40339491173441421878e+00 +
                       z * (2.02094576023350569471e+00 +
                            z * (-6.88283971605453293030e-01 +
                                 z * 7.70381505559019352791e-02)));
        s = __ieee754_sqrt(z);
        r = p / q;
        w = r * s - (6.12323399573676603587e-17);
        return M_PI - 2.0 * (s + w);
    } else {
        z = (1.0 - x) * 0.5;
        s = __ieee754_sqrt(z);
        df = s;
        union {
            double value;
            struct {
                uint32_t lsw;
                uint32_t msw;
            } parts;
        } sl_u;
        sl_u.value = df;
        sl_u.parts.lsw = 0;
        df = sl_u.value;
        c = (z - df * df) / (s + df);
        p = z * (1.66666666666666657415e-01 +
                 z * (-3.25565818622400915405e-01 +
                      z * (2.01212532134862925881e-01 +
                           z * (-4.00555345006794114027e-02 +
                                z * (7.91534994289814532176e-04 +
                                     z * 3.47933107596021167570e-05)))));
        q = 1.0 + z * (-2.40339491173441421878e+00 +
                       z * (2.02094576023350569471e+00 +
                            z * (-6.88283971605453293030e-01 +
                                 z * 7.70381505559019352791e-02)));
        r = p / q;
        w = r * s + c;
        return 2.0 * (df + w);
    }
}

int isnan_double(double x) {
    return x != x;
}

int main() {
    // Use the predetermined_value instead of __VERIFIER_nondet_double()
    double x = predetermined_value;

    if (x < -1.0 || x > 1.0) {
        double res = __ieee754_acos(x);
        // x is not in [-1,1] the result shall be NaN
        if (!isnan_double(res)) {
            reach_error();
            return 1;
        }
    }

    return 0;
}