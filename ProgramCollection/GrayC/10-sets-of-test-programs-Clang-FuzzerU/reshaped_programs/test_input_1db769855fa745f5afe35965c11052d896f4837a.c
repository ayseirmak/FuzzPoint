#include <stdio.h>
#include <stdlib.h>

// Define macro for assertions
#define A(x) if (!(x)) abort()

// Definitions of unions and structs
typedef union at6 {} at6;
typedef struct et6 {
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
} et6;

typedef union at2 {} at2;
typedef union ft7 {
    float qv7;
    float *rv7;
    unsigned int *sv7;
} ft7;

typedef struct gt7 {
    double tv7;
} gt7;

// Static initializations with deterministic values
static et6 wv6 = {
    { 8, 9, 2, 4, 0x10, 67426805U, 1047191860L },
    1366022414UL, 858, 1, 1, 305,
    { 1069379046L }, (int *) 358273621U,
    { .lv6 = 3318.041978F }
};

static double xv6 = 1923.101269;
static long long int yv6 = 1207859169L;
static int zv6 = 660195606;

// Example caller function
static at2
callee_af6(et6 ap6, double bp6, long long int cp6, int dp6)
{
    // Pass arbitrary conditions as the original context is missing
    A(ap6.mv6.av6 == 8);
    A(bp6 == 1923.101269);
    A(cp6 == 1207859169L);
    A(dp6 == 660195606);
    
    at2 result; // for demonstration purposes
    // Function return logic
    return result;
}

static unsigned char
callee_af7(float ap7, double bp7, union ct6 cp7, et6 dp7,
           ft7 ep7, int fp7, gt7 gp7, long int hp7[1],
           long long int ip7)
{
    // Static assertions for deterministic comparisons
    A(ap7 == 5042.227886F);
    A(bp7 == 47875.491954);
    A(dp7.sv6.iv6 == cp7.iv6);  // Assuming within struct usage
    A(gp7.tv7 == 47875.491954);
    A(hp7[0] == 1732133482L);
    A(ip7 == 381678602L);

    return 0; // Return unsigned char
}

static void caller_bf7(void)
{
    unsigned char bev7;
    long int hp7[1] = { 1732133482L };
    gt7 gp7 = { 47875.491954 };
    union ct6 cp7 = { .iv6 = 305 };
    ft7 ft7_instance = { .qv7 = 5042.227886F };

    bev7 = callee_af7(5042.227886F, 47875.491954, cp7, wv6, ft7_instance, 1345451862, gp7, hp7, 381678602L);
}

int main()
{
    // Assuming the existence of caller_bf6 with valid logic
    // caller_bf6();
    caller_bf7();
    return 0;
}