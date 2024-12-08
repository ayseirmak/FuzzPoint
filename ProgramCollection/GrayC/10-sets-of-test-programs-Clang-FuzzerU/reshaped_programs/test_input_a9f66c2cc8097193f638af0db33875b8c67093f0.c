#include <stdio.h>
#include <assert.h>

// Define A as an assertion instead of using abort()
#define A(x) assert(x)

static union at6 {} vv6; // No initializer necessary as it's unused
static struct et6
{
    struct bt6
    {
        signed av6:6;
        signed bv6:7;
        signed cv6:6;
        signed dv6:5;
        unsigned char ev6;
        struct intt7
        {
            float iv7;
            unsigned short int jv7;
        } kv7;
        float lv7[0];
        signed mv7:9;
        short int nv7;
        double ov7;
        float pv7;
    } yv7;
} yv7 = {
    { 0, 0 }, 170, 22116, 26479.628148, 4082.960685
};

static union ft7
{
    float qv7;
    float *rv7;
    unsigned int *sv7;
} zv7 = { 5042.227886 };

static int bav7 = 1345451862;
static struct gt7 { double tv7; } bbv7 = { 47875.491954 };
static long int bcv7[1] = { 1732133482L };
static long long int bdv7 = 381678602L;

// Using fixed values for test variables
static float vv7_dummy = 30135.996213f;
static double wv7 = 42435.0;
static struct et6 xv7 = yv7; // deterministic input
static unsigned char uv7 = 0; // deterministic result placeholder

static unsigned char
callee_af7(float ap7, double bp7, struct et6 cp7, struct et6 dp7,
           union ft7 ep7, int fp7, struct gt7 gp7, long int hp7[1],
           long long int ip7)
{
    A(vv7_dummy == ap7);
    A(wv7 == bp7);
    A(yv7.kv7.iv7 == dp7.kv7.iv7);
    A(yv7.kv7.jv7 == dp7.kv7.jv7);
    A(yv7.mv7 == dp7.mv7);
    A(yv7.nv7 == dp7.nv7);
    A(yv7.ov7 == dp7.ov7);
    A(yv7.pv7 == dp7.pv7);
    A(zv7.qv7 == ep7.qv7);
    A(bav7 == fp7);
    A(bbv7.tv7 == gp7.tv7);
    A(bcv7[0] == hp7[0]);
    A(bdv7 == ip7);
    return uv7;
}

static void
caller_bf7(void)
{
    unsigned char bev7;

    bev7 = callee_af7(vv7_dummy, wv7, yv7, yv7, zv7, bav7, bbv7, bcv7, bdv7);
    A(uv7 == bev7);
}

int main(void)
{
    caller_bf7();
    return 0;
}