#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define a macro to replace the custom `A(x) if (!(x)) abort ()` function
#define ASSERT(condition) assert(condition)

// Define necessary unions and structs
union ct6 {
    long int hv6;
    float iv6;
    float jv6;
};

union dt6 {
    double kv6;
    float lv6;
};

struct bt6 {
    signed av6 : 6;
    signed bv6 : 7;
    signed cv6 : 6;
    signed dv6 : 5;
    unsigned char ev6;
    unsigned int fv6;
    long int gv6;
};

struct _t6 {
    struct bt6 mv6;
    unsigned long int nv6;
    signed ov6 : 12;
    signed pv6 : 3;
    signed qv6 : 2;
    signed rv6 : 10;
    union ct6 sv6;
    int *tv6;
    union dt6 uv6;
};

// Static global initializations
static struct _t6 wv6 = {
    {8, 9, 2, 4, '\x10', 67426805U, 1047191860L},
    1366022414UL, 858, 1, 1, 305,
    {1069379046L}, (int *)358273621U,
    {3318.041978}
};

static double xv6 = 19239.101269;
static long long int yv6 = 1207859169L;
static int zv6 = 660195606;

// Function prototypes
void caller_bf6(void); 
void caller_bf7(void);

// Function implementations
static void callee_af6(struct _t6 ap6) {
    ASSERT(wv6.mv6.av6 == ap6.mv6.av6);
    ASSERT(wv6.mv6.bv6 == ap6.mv6.bv6);
    ASSERT(wv6.mv6.cv6 == ap6.mv6.cv6);
    ASSERT(wv6.mv6.dv6 == ap6.mv6.dv6);
    ASSERT(wv6.mv6.ev6 == ap6.mv6.ev6);
    ASSERT(wv6.mv6.fv6 == ap6.mv6.fv6);
    ASSERT(wv6.mv6.gv6 == ap6.mv6.gv6);
    ASSERT(wv6.nv6 == ap6.nv6);
    ASSERT(wv6.ov6 == ap6.ov6);
    ASSERT(wv6.pv6 == ap6.pv6);
    ASSERT(wv6.qv6 == ap6.qv6);
    ASSERT(wv6.rv6 == ap6.rv6);
}

static void caller_bf6(void) {
    callee_af6(wv6);
}

int main(void) {
    caller_bf6();
    // Note: caller_bf7 is not implemented due to incomplete input instructions
    // Ensure caller_bf7 is correctly implemented as necessary
    return 0;
}