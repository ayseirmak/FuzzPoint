#include <stdio.h>
#include <assert.h>

#define HALFPI 1.57079632679f
#define NR 5

// Define VAL based on NR value
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
#else
#error "Unsupported NR value."
#endif

void reach_error() { 
    printf("Reach error has been triggered.\n");
}

void assume_abort_if_not(int cond) {
    if(!cond) {
        printf("Aborting due to assumption failure.\n");
        abort();
    }
}

int main() {
    // Deterministic input value
    float IN = 1.0f; // Replace this value as needed within the range (-HALFPI, HALFPI)
    assume_abort_if_not(IN > -HALFPI && IN < HALFPI);

    float x = IN;

    // Calculating the series result
    float result = x - (x*x*x)/6.0f + (x*x*x*x*x)/120.0f + (x*x*x*x*x*x*x)/5040.0f;

    // Check the result within bounds
    if(!(result <= VAL && result >= -VAL)) {
        reach_error();
    } else {
        printf("Computation was successful. Result is within bounds.\n");
    }

    return 0;
}