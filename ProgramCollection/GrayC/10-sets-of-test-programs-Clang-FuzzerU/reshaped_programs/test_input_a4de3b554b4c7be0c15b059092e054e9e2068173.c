#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define NR 1

#if NR == 1
typedef unsigned int uint32_t;
#else
typedef unsigned uint32_t;
#endif

#define VAL 1.39f

int main() {
    float IN = 0.7f; // Deterministically set value within the allowed range
    if (!(IN >= 0.0f && IN < 1.0f)) {
        printf("Aborting due to input range violation.\n");
        abort();
    }

    float x = IN;

    float result = 
        1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

    if(!(result >= 0.0f && result < VAL)) {
        printf("Assertion failed: The computed result is out of expected range.\n");
        assert(0);
    }

    printf("Result is within the expected range.\n");
    
    return 0;
}