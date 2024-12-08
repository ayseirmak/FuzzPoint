#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Constants to replace dynamic inputs */
#define INT_POINTER_VALUE 358273621U
#define DOUBLE_VALUE 19239.101269
#define LLONG_INT_VALUE 1207859169L
#define INT_VALUE 660195606

/* Custom assertion macro using standard assert */
#define A(x) assert(x)

static union at6 {} vv6 = {}; // Empty union

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
    { 1069379046L }, (int *)INT_POINTER_VALUE,
    { 3318.041978 }
};

static double xv6 = DOUBLE_VALUE;
static long long int yv6 = LLONG_INT_VALUE;
static int zv6 = INT_VALUE;

static union at6 callee_af6(struct et6 ap6, double bp6, long long int cp6, int dp6) {
    A(wv6.mv6.av6 == ap6.mv6.av6);
    A(wv6.mv6.bv6 == ap6.mv6.bv6);
    A(wv6.mv6.cv6 == ap6.mv6.cv6);
    A(wv6.mv6.dv6 == ap6.mv6.dv6);
    A(wv6.mv6.ev6 == ap6.mv6.ev6);
    A(wv6.mv6.fv6 == ap6.mv6.fv6);
    A(wv6.mv6.gv6 == ap6.mv6.gv6);
    A(wv6.nv6 == ap6.nv6);
    A(wv6.ov6 == ap6.ov6);
    A(wv6.pv6 == ap6.pv6);
    A(wv6.qv6 == ap6.qv6);
    A(wv6.rv6 == ap6.rv6);
    A(wv6.sv6.hv6 == ap6.sv6.hv6);
    A(wv6.tv6 == ap6.tv6);
    A(wv6.uv6.kv6 == ap6.uv6.kv6);
    A(xv6 == bp6);
    A(yv6 == cp6);
    A(zv6 == dp6);
    return vv6; // Return empty union
}

static void caller_bf6(void) {
    union at6 bav6;
    bav6 = callee_af6(wv6, xv6, yv6, zv6);
}

static unsigned char uv7 = '\x46';
static float vv7 = 96636.982442;
static double wv7 = 28450.711801;
static union ct7 {} xv7 = {};

static struct et7 {
    struct dt7 {
        float iv7;
        unsigned short int jv7;
    } kv7;
    float lv7[0];
    signed mv7:9;
    short int nv7;
    double ov7;
    float pv7;
} yv7 = {
    { 30135.996213f, 42435 },
    {}, 170, 22116, 26479.628148, 4082.960685
};

static union ft7 {
    float qv7;
    float *rv7;
    unsigned int *sv7;
} zv7 = { 5042.227886f };

static int bav7 = 1345;
static int bbv7[0] = {};
static int bcv7[0] = {};
static int *bdv7 = NULL;

static unsigned char callee_af7(float ap7, double bp7, union ct7 cp7, struct et7 dp7, union ft7 ep7, int fp7, int *gp7, int hp7[], int *ip7) {
    A(uv7 == '\x46');
    A(ap7 == vv7);
    A(bp7 == wv7);
    A(dp7.kv7.iv7 == yv7.kv7.iv7);
    A(dp7.kv7.jv7 == yv7.kv7.jv7);
    A(dp7.mv7 == yv7.mv7);
    A(dp7.nv7 == yv7.nv7);
    A(dp7.ov7 == yv7.ov7);
    A(dp7.pv7 == yv7.pv7);
    A(ep7.qv7 == 5042.227886f);
    A(fp7 == 1345);
    A(bbv7[0] == 0);
    A(bcv7[0] == 0);
    A(bdv7 == NULL);
    return uv7;
}

static void caller_bf7(void) {
    unsigned char bev7;
    int bbv7[1] = {0};
    int bcv7[1] = {0};
    int *bdv7 = NULL;

    bev7 = callee_af7(vv7, wv7, xv7, yv7, zv7, bav7, bbv7, bcv7, bdv7);
    A(uv7 == bev7);
}

int main(void) {
    caller_bf6();
    caller_bf7();
    printf("All checks passed.\n");
    return 0;
}