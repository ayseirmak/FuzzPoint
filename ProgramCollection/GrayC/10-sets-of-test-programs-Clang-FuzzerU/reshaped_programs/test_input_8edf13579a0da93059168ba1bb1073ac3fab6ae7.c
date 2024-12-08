#include <stdio.h>
#include <stdint.h>
#include <assert.h>

// Structure and union definitions
typedef struct {
    signed av6:6;
    signed bv6:7;
    signed cv6:6;
    signed dv6:5;
    unsigned char ev6;
    struct {
        float iv7;
        unsigned short int jv7;
    } kv7;
    float lv7[0];
    signed mv7:9;
    short int nv7;
    double ov7;
    float pv7;
} et6;

typedef union {
    float qv7;
    float *rv7;
    unsigned int *sv7;
} ft7;

// Global variables with initial values
static float vv7 = 30135.996213;
static double wv7 = 42435.0;
static et6 yv7 = {
    { 30135.996213, 42435 },
    {}, 170, 22116, 26479.628148, 4082.960685
};
static ft7 zv7 = { 5042.227886 };
static int bav7 = 1732133482;
static long long int bdv7 = 381678602;
static unsigned char uv7 = 0;

// Function prototypes
static unsigned char callee_af7(float ap7, double bp7, et6 dp7, ft7 ep7, int fp7, long long int ip7);
static void caller_bf7(void);

// Function definitions
static unsigned char callee_af7(float ap7, double bp7, et6 dp7, ft7 ep7, int fp7, long long int ip7) {
    assert(vv7 == ap7);
    assert(wv7 == bp7);
    assert(yv7.kv7.iv7 == dp7.kv7.iv7);
    assert(yv7.kv7.jv7 == dp7.kv7.jv7);
    assert(yv7.mv7 == dp7.mv7);
    assert(yv7.nv7 == dp7.nv7);
    assert(yv7.ov7 == dp7.ov7);
    assert(yv7.pv7 == dp7.pv7);
    assert(zv7.qv7 == ep7.qv7);
    assert(bav7 == fp7);
    assert(bdv7 == ip7);
    return uv7;
}

static void caller_bf7(void) {
    unsigned char bev7;
    bev7 = callee_af7(vv7, wv7, yv7, zv7, bav7, bdv7);
    assert(uv7 == bev7);
}

int main() {
    caller_bf7();
    printf("All assertions passed.\n");
    return 0;
}