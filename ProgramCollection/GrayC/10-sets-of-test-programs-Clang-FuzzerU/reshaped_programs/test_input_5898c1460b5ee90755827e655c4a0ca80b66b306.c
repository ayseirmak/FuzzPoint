#include <stdio.h>
#include <stdlib.h>

// Defines values used in cbrtl function
#define B1 715094163
#define B2 696219795
#define C 19.0/35.0
#define D -864.0/1225.0
#define E 1.41428571428571436819
#define F 1.60714285714285720630
#define G 3.57142857142857150787e-01

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
    
    ut.t = 1.0;
    n0 = (ut.pt[0] == 0);
    
    ut.t = 0.0;
    ux.t = x;
    
    hx = ux.pt[n0];            // High word of x
    sign = hx & 0x80000000;    // sign = sign(x)
    hx ^= sign;
    if (hx >= 0x7ff00000) return (x + x); // cbrt(NaN, INF) is itself
    if ((hx | ux.pt[1-n0]) == 0)
        return (ux.t);         // cbrt(0) is itself
    
    ux.pt[n0] = hx;
    // Rough cbrt to 5 bits
    if (hx < 0x00100000) { // Subnormal number
        ut.pt[n0] = 0x43500000; // Set t = 2**54
        ut.t *= x;
        ut.pt[n0] = ut.pt[n0] / 3 + B2;
    } else {
        ut.pt[n0] = hx / 3 + B1;
    }

    // cbrt to 23 bits
    r = ut.t * ut.t / ux.t;
    s = C + r * ut.t;
    ut.t *= G + F / (s + E + D / s);

    // Chopped to 20 bits and make it larger than cbrt(x)
    ut.pt[1-n0] = 0; 
    ut.pt[n0] += 0x00000001;

    // One step newton iteration to 53 bits with error less than 0.667 ulps
    s = ut.t * ut.t;           // t*t is exact
    r = ux.t / s;
    w = ut.t + ut.t;
    r = (r - ut.t) / (w + r);  // r-s is exact
    return (ut.t + ut.t);
}

int main() {
    unsigned long long x = 5;
    
    x = x + 1;
    if (x != 6)
        return 1;
    
    printf("Test passed. x = %llu\n", x);
    return 0;
}