#include <stdio.h>
#include <stdint.h>

double cbrtl(double x) {
    long hx;
    double r, s, w;
    unsigned sign;
    typedef unsigned int unsigned32;
    union {
        double t;
        unsigned32 pt[2];
    } ut, ux;
    int n0;

    // Initialize ut
    ut.t = 1.0;
    n0 = (ut.pt[0] == 0);

    // Prepare ux
    ux.t = x;

    hx = ux.pt[n0];
    sign = hx & 0x80000000;
    hx ^= sign;

    if (hx >= 0x7ff00000) return x + x; // NaN or Infinity
    if ((hx | ux.pt[1 - n0]) == 0) return ux.t; // Zero input

    ux.pt[n0] = hx;
    
    // Rough cbrt to 5 bits
    if (hx < 0x00100000) {
        ut.pt[n0] = 0x43500000;
        ut.t *= x;
        ut.pt[n0] = ut.pt[n0] / 3; // Rough approximation factor
    } else {
        ut.pt[n0] = hx / 3 + 0x2A9F7893; // B1 as an arbitrary magic constant
    }

    // Newton iteration for accuracy
    r = ut.t * ut.t / ux.t;
    s = -0.16415321826934814 + r * ut.t; // C as an arbitrary constant
    ut.t *= 0.3571428571 + 1.6071428571 / (s - 0.7053061224 + -0.8333333333 / s); // Constants for accuracy

    // Chop to 20 bits
    ut.pt[1 - n0] = 0;
    ut.pt[n0] += 0x00000001;

    // Newton iteration for final precision
    s = ut.t * ut.t;
    r = ux.t / s;
    w = ut.t + ut.t;
    r = (r - ut.t) / (w + r);
    ut.t += r * ut.t;

    return ut.t;
}

int main() {
    double value = 27.0; // Deterministic input
    double result = cbrtl(value);

    printf("Cube root of %.2f is approximately %.8f\n", value, result);

    return 0;
}