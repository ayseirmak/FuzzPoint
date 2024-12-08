#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long simple_rand() {
    static unsigned long long seed = 47114711ULL;
    unsigned long long this = seed * 1103515245ULL + 12345ULL;
    seed = this;
    return this >> 8;
}

unsigned long long int random_bitstring() {
    unsigned long long int x = 0;
    int n_bits;
    long long ran;
    int tot_bits = 0;

    while (1) {
        ran = simple_rand();
        n_bits = (ran >> 1) % 16;
        tot_bits += n_bits;

        if (n_bits == 0)
            return x;
        else {
            x <<= n_bits;
            if (ran & 1)
                x |= (1ULL << n_bits) - 1;

            if (tot_bits > 8 * sizeof(long long) + 6)
                return x;
        }
    }
}

#define ABS(x) ((x) >= 0 ? (x) : -(x))

int main() {
    long long int i;

    for (i = 0; i < 10000; i++) {
        unsigned long long x, y;
        x = random_bitstring();
        y = random_bitstring();

        if (sizeof(int) == sizeof(long long))
            continue;

        unsigned long long xx = x, yy = y, r1, r2;
        if (yy == 0) continue;
        r1 = xx / yy;
        r2 = xx % yy;

        if ((unsigned int) xx << 1 == 0 && yy == (unsigned long long)-1) {
            continue;
        }
        
        r1 = xx / yy;
        r2 = xx % yy;
        
        if (ABS((long long)r2) >= (unsigned int) ABS((long long)yy) || 
            (signed int)(r1 * yy + r2) != (signed int)xx) {
            printf("Error: values do not match\n");
            abort();
        }
    }

    printf("All calculations are correct.\n");

    return 0;
}