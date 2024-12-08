#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

union at6 {};

struct bt6 {
    signed av6:6;
    signed bv6:7;
    signed cv6:6;
    signed dv6:5;
    unsigned char ev6;
    unsigned int fv6;
    long int gv6;
};

struct et6 {
    struct bt6 mv6;
    unsigned long int nv6;
    signed ov6:12;
    signed pv6:3;
    signed qv6:2;
    signed rv6:10;
    union ct6 { long int hv6; float iv6; float jv6; } sv6;
    int *tv6;
    union dt6 { double kv6; float lv6; } uv6;
};

union at6 vv6 = {};

static struct et6 wv6 = {
    {8, 9, 2, 4, 0x10, 67426805U, 10479239L},
    0, 0, 0, 0, 0, {0.0f, 0.0f, 0.0f}, NULL, {0.0, 0.0f}
};

static long long int yv60 = 1207859169L;
static int zv6 = 660195606;

union at6 callee_af6(struct et6 ap6, double bp6, long long int cp6, int dp6) {
    assert(wv6.mv6.av6 == ap6.mv6.av6);
    assert(wv6.mv6.bv6 == ap6.mv6.bv6);
    assert(wv6.mv6.cv6 == ap6.mv6.cv6);
    // Static check on fixed value as dynamic values are disallowed
    signed int fixedDv6 = 4; 
    assert(wv6.mv6.dv6 == fixedDv6);
    return vv6;
}

void caller_bf6() {
    struct et6 fixed_ap6 = wv6; // Static definition using wv6
    double fixed_bp6 = 1.0;     // Fixed value
    long long int fixed_cp6 = 1207859169L; // Fixed value
    int fixed_dp6 = 3;          // Fixed value

    callee_af6(fixed_ap6, fixed_bp6, fixed_cp6, fixed_dp6);
}

int main() {
    caller_bf6();
    return 0;
}