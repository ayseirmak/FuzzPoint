#include <stdio.h>
#include <assert.h>

#define HALFPI 1.57079632679f
#define NR 8

#if NR == 1
#define VAL 0.99f
#elif NR == 2
#define VAL 1.0f
#elif NR == 3
#define VAL 1.001f
#elif NR == 4
#define VAL 1.01f
#elif NR == 5
#define VAL 1.1f
#elif NR == 6
#define VAL 1.2f
#elif NR == 7
#define VAL 1.5f
#elif NR == 8
#define VAL 2.0f
#endif

void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) { 
        printf("Assumption failed, aborting.\n");
        abort();
    }
}

int main() {
    // Fixed input value for deterministic behavior
    float IN = 1.0f;  // A chosen value within -HALFPI to HALFPI for testing

    assume_abort_if_not(IN > -HALFPI && IN < HALFPI);

    float x = IN;
    float result = x - (x * x * x) / 6.0f + (x * x * x * x * x) / 120.0f + (x * x * x * x * x * x * x) / 5040.0f;

    if (!(result <= VAL && result >= -VAL)) {
        reach_error();
    }

    printf("Computation was successful without reaching error.\n");

    return 0;
}