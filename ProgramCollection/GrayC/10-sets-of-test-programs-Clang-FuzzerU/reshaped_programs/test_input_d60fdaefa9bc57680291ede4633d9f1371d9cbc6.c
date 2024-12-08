#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define A(x) if (!(x)) abort()

struct bt6 {
    signed av6 : 6;
    signed bv6 : 7;
    signed cv6 : 6;
    signed dv6 : 5;
    unsigned char ev6;
    unsigned int fv6;
    long int gv6;
};

struct et6 {
    struct bt6 mv6;
    unsigned long int nv6;
    signed ov6 : 12;
    signed pv6 : 3;
    signed qv6 : 2;
    signed rv6 : 10;
    union {
        long int hv6;
        float iv6;
        float jv6;
    } sv6;
    int *tv6;
    union {
        double kv6;
        float lv6;
    } uv6;
};

// Predefined data
static struct et6 wv6 = {
    {8, 9, 2, 4, '\x10', 67426805U, 1047191860L},
    1366022414UL, 858, 1, 1, 305,
    {1069379046L}, (int *)358273621U,
    {3318.041978}
};
static double xv6 = 1923.101269;
static long long int yv6 = 1207859169L;
static int zv6 = 660195606;

static union {
    float qv7;
    float *rv7;
    unsigned int *sv7;
} zv7 = {5042.227886};

static int bav7 = 1345451862;
static struct { double tv7; } bbv7 = {47875.491954};
static long int bcv7[1] = {1732133482L};
static long long int bdv7 = 381678602L;

static void callee_af6(struct et6 ap6, double bp6, long long int cp6, int dp6) {
    assert(ap6.mv6.av6 == wv6.mv6.av6);
    assert(ap6.mv6.bv6 == wv6.mv6.bv6);
    assert(bp6 == xv6);
    assert(cp6 == yv6);
    assert(dp6 == zv6);
}

static unsigned char callee_af7(float ap7, double bp7, union {
    double kv7;
    float lv7;
} cp7, struct { double tv7; } dp7, union {
    float qv7;
    float *rv7;
    unsigned int *sv7;
} ep7, int fp7, struct { double tv7; } gp7, long int hp7[1], long long int ip7) {
    assert(ap7 == zv7.qv7);
    assert(bp7 == wv6.nl6);
    assert(cp7.kv7 == wv6.uv6.kv6);
    assert(dp7.tv7 == gp7.tv7);
    assert(hp7[0] == bcv7[0]);
    assert(ip7 == bdv7);
    return (unsigned char)gp7.tv7;
}

static void caller_bf7(void) {
    unsigned char bev7;

    // Adjusted invalid call to match functional intent assuming the parameters
    bev7 = callee_af7(zv7.qv7, wv6.nl6, wv6.uv6, bbv7, zv7, bav7, bbv7, bcv7, bdv7);
    A(wv6.nl6 == (double)bev7);
}

int main() {
    caller_bf7();
    return 0;
}