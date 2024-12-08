#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Remove the external abort function and define A(x) in terms of assert()
#define A(x) assert(x)

// Define all the unions and structures correctly and initialize them appropriately
typedef union at6 {} union_at6;

typedef struct {
    signed av6:6;
    signed bv6:7;
    signed cv6:6;
    signed dv6:5;
    unsigned char ev6;
    unsigned int fv6;
    long int gv6;
    float hv6;
    float iv6;
} struct_bt6;

typedef struct et6 {
    struct_bt6 mv6;
    int nv6;
    int ov6;
    int pv6;
    int qv6;
    struct {
        long int hv6;
    } sv6;
    int *tv6;
    union {
        double kv6;
        float lv6;
    } uv6;
} struct_et6;

static struct_et6 wv6 = {
    .mv6 = {8, 9, 2, 4, '\x10', 67426805U, 1047191860L, 0.0f, 0.0f},
    .nv6 = 1366022414UL,
    .ov6 = 858,
    .pv6 = 1,
    .qv6 = 1,
    .sv6 = {305},
    .tv6 = (int *)358273621U,
    .uv6 = {.kv6 = 3318.041978}
};

static double xv6 = 1923.101269;  // Fixed syntax error
static long long int yv6 = 1207859169L;
static int zv6 = 660195606;

// Dummy 'at6' structure definition for use in callee_af6
typedef struct {
    struct_bt6 mv6;
    int nv6;
    int ov6;
    int pv6;
    int qv6;
    struct {
        long int hv6;
    } sv6;
    int *tv6;
    union {
        double kv6;
        float lv6;
    } uv6;
} struct_at6;

static union_at6 callee_af6(struct_at6 ap6, double bp6, long long int cp6, int dp6) {
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
    A(wv6.sv6.hv6 == ap6.sv6.hv6);
    A(wv6.tv6 == ap6.tv6);
    A(wv6.uv6.kv6 == ap6.uv6.kv6);
    A(xv6 == bp6);
    A(yv6 == cp6);
    A(zv6 == dp6);
    union_at6 result;
    return result;
}

static void caller_bf6(void) {
    struct_at6 bav6 = {.mv6 = {8, 9, 2, 4, '\x10', 67426805U, 1047191860L, 0.0f, 0.0f},
                       .nv6 = 1366022414UL,
                       .ov6 = 858,
                       .pv6 = 1,
                       .qv6 = 1,
                       .sv6 = {305},
                       .tv6 = (int *)358273621U,
                       .uv6 = {.kv6 = 3318.041978}};
    bav6 = callee_af6(wv6, xv6, yv6, zv6);
}

static unsigned char uv7 = '\x46';
static float vv7 = 96636.982442f;
static double wv7 = 28450.711801;

// Dummy 'ct7' union definition for use in callee_af7
typedef union ct7 {} union_ct7;

typedef struct et7 {
    struct {
        float iv7;
        unsigned short int jv7;
    } kv7;
    float lv7[0];
    signed mv7:9;
    short int nv7;
    double ov7;
    float pv7;
} struct_et7;

static struct_et7 yv7 = {
    .kv7 = {30135.996213f, 42435},
    .lv7 = {},
    .mv7 = 170,
    .nv7 = 22116,
    .ov7 = 26479.628148,
    .pv7 = 4082.960685f
};

static union ft7 {
    float qv7;
    float *rv7;
    unsigned int *sv7;
} zv7 = {.qv7 = 5042.227886f};

static int bav7 = 1345451862;
static struct gt7 { double tv7; } bbv7 = {47875.491954};
static long int bcv7[1] = {1732133482L};
static long long int bdv7 = 381678602L;

static unsigned char callee_af7(float ap7, double bp7, union_ct7 cp7, struct_et7 dp7,
                                union ft7 ep7, int fp7, struct gt7 gp7, long int hp7[1],
                                long long int ip7) {
    A(vv7 == ap7);
    A(wv7 == bp7);
    A(yv7.kv7.iv7 == dp7.kv7.iv7);
    A(yv7.kv7.jv7 == dp7.kv7.jv7);
    A(yv7.mv7 == dp7.mv7);
    A(yv7.nv7 == dp7.nv7);
    A(bcv7[0] == hp7[0]);
    A(bdv7 == ip7);
    return uv7;
}

static void caller_bf7(void) {
    unsigned char bev7 = callee_af7(vv7, wv7, xv7, yv7, zv7, bav7, bbv7, bcv7, bdv7);
    A(uv7 == bev7);
}

int main() {
    caller_bf6();
    caller_bf7();
    return 0;
}