#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/* Equivalent fixed values for testing */
#define NR 1
#define VAL 1.39f

unsigned long long simple_rand_fixed() {
    // Return a deterministic pseudo-random number
    return 1234567890123456789ULL >> 8;
}

unsigned long long int random_bitstring() {
    unsigned long long int x;
    int tot_bits = 0;
    
    x = 0;
    for (;;) {
        long long ran = simple_rand_fixed();
        int n_bits = (ran >> 2) % 16;
        tot_bits += n_bits;

        if (n_bits == 0)
            return x;
        else
            x = (x << n_bits) | ((1ULL << n_bits) - 1);
    }
}

int main() {
    float IN = 0.5f;  // Example deterministic input that meets condition for the original code
    if (!(IN >= 0.0f && IN < 1.0f)) abort();

    float x = IN;
    float result = 1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

    if (!(result >= 0.0f && result < VAL)) { 
        assert(0); 
    }
  
    printf("Computation successful, result = %f\n", result);
    return 0;
}