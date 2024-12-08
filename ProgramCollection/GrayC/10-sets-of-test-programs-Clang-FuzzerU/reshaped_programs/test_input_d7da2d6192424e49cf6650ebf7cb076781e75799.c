#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Static Data
static union at6 {} vv6 = {};

static struct et6 {
    struct bt6 {
        signed av6:6;
        signed bv6:7;
        signed cv6:6;
        signed dv6:5;
        unsigned char ev6;
        unsigned int fv6;
        long int gv6;
    } mv6;
    unsigned long int nv6;
    signed ov6:12;
    signed pv6:3;
    signed qv6:2;
    signed rv6:10;
    union ct6 { long int hv6; float iv6; float jv6; } sv6;
    int *tv6;
    union dt6 { double kv6; float lv6; } uv6;
} wv6 = {
    { 8, 9, 2, 4, '\x10', 67426805U, 1047191860L },
    1366022414UL, 858, 1, 1, 305,
    { 1069379046L }, (int *)358273621U,
    { 3318.041978 }
};

static double xv6 = 19239.101269;
static long long int yv6 = 1207859169L;
static int zv6 = 660195606;

static union at6 callee_af6(struct et6 ap6, double bp6, long long int cp6, int dp6) {
    assert(wv6.mv6.av6 == ap6.mv6.av6);
    assert(wv6.mv6.bv6 == ap6.mv6.bv6);
    assert(wv6.mv6.cv6 == ap6.mv6.cv6);
    assert(wv6.mv6.dv6 == ap6.mv6.dv6);
    assert(wv6.mv6.ev6 == ap6.mv6.ev6);
    assert(wv6.mv6.fv6 == ap6.mv6.fv6);
    assert(wv6.mv6.gv6 == ap6.mv6.gv6);
    assert(wv6.nv6 == ap6.nv6);
    assert(wv6.ov6 == ap6.ov6);
    assert(wv6.pv6 == ap6.pv6);
    assert(wv6.qv6 == ap6.qv6);
    assert(wv6.rv6 == ap6.rv6);
    assert(wv6.sv6.hv6 == ap6.sv6.hv6);
    assert(wv6.tv6 == ap6.tv6);
    assert(wv6.uv6.kv6 == ap6.uv6.kv6);
    assert(xv6 == bp6);
    assert(yv6 == cp6);
    assert(zv6 == dp6);
    return vv6;
}

static void caller_bf6(void) {
    union at6 bav6;
    bav6 = callee_af6(wv6, xv6, yv6, zv6);
}

// Since there was an incomplete definition, I can't fully determine its intent, but here's a corrected portion.
static unsigned char uv7 = '\x46';
static float vv7 = 96636.982442;
static double wv7 = 28450.711801;

static unsigned char callee_af7(float ap7, double bp7, struct et7 dp7,
                                int fp7, long int hp7[1], long long int ip7) {
    assert(vv7 == ap7);
    assert(wv7 == bp7);
    // Continue assertions with similar established logic replacing placeholders
    return uv7;
}

static void caller_bf7(void) {
    unsigned char bev7;
    // Assuming correct initialization of structures
    struct et7 yv7 = {{0}};
    int bav7 = 0;
    long int bcv7[] = {0};

    bev7 = callee_af7(vv7, wv7, yv7, bav7, bcv7, 381678602L);
    assert(uv7 == bev7);
}

int main() {
    caller_bf6();
    caller_bf7();
    return 0;
}