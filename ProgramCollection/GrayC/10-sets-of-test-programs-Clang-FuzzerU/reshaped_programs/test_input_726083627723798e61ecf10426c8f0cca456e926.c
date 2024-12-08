#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define VAL (8 * sizeof(int))

int fooctz(int i) {
    return (i == 0) ? VAL : __builtin_ctz(i);
}

int fooctz2(int i) {
    return (i != 0) ? __builtin_ctz(i) : VAL;
}

unsigned int fooctz3(unsigned int i) {
    return (i > 0) ? __builtin_ctz(i) : VAL;
}

int fooclz(int i) {
    return (i == 0) ? VAL : __builtin_clz(i);
}

int fooclz2(int i) {
    return (i != 0) ? __builtin_clz(i) : VAL;
}

unsigned int fooclz3(unsigned int i) {
    return (i > 0) ? __builtin_clz(i) : VAL;
}

typedef struct {
    struct {
        signed av6 : 6;
        signed bv6 : 7;
        signed cv6 : 6;
        signed dv6 : 5;
        unsigned char ev6;
        unsigned int fv6;
        long int gv6;
    } mv6;
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
} et6;

static et6 wv6 = {
    {8, 9, 2, 4, '\x10', 67426805U, 1047191860L},
    1366022414UL, 858, 1, 1, 305,
    {1069379046L}, (int *) 358273621U,
    {3318.041978}
};

static double xv6 = 19239.101269;
static long long int yv6 = 1207859169L;
static int zv6 = 660195606;

typedef struct {
    float iv7;
    unsigned short int jv7;
} dt7;

typedef struct {
    dt7 kv7;
    float lv7[0];
    signed mv7 : 9;
    short int nv7;
    double ov7;
    float pv7;
} et7;

static et7 yv7 = {
    {30135.996213, 42435}, {}, 170, 22116, 26479.628148, 4082.960685
};

struct gt7 { double tv7; };
static struct gt7 bbv7 = {47875.491954};

static void caller_bf6(void) {
    assert(wv6.mv6.av6 == wv6.mv6.av6);
    assert(wv6.mv6.bv6 == wv6.mv6.bv6);
    assert(wv6.mv6.cv6 == wv6.mv6.cv6);
    assert(wv6.mv6.dv6 == wv6.mv6.dv6);
    printf("All assertions passed for caller_bf6\n");
}

static unsigned char callee_af7(float ap7, double bp7, et7 dp7, int fp7, struct gt7 gp7, long int hp7[], long long int ip7) {
    assert(96636.982442 == ap7);
    assert(28450.711801 == bp7);
    assert(yv7.kv7.iv7 == dp7.kv7.iv7);
    assert(yv7.kv7.jv7 == dp7.kv7.jv7);
    assert(47875.491954 == gp7.tv7);
    assert(1732133482L == hp7[0]);
    assert(381678602L == ip7);
    return '\x46';
}

static void caller_bf7(void) {
    unsigned char bev7;
    long int hp7[1] = {1732133482L};
    bev7 = callee_af7(96636.982442, 28450.711801, yv7, 1345451862, bbv7, hp7, 381678602L);
    assert('\x46' == bev7);
    printf("All assertions passed for caller_bf7\n");
}

int main(void) {
    caller_bf6();
    caller_bf7();
    return 0;
}