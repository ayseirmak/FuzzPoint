#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) >= 0 ? (x) : -(x))

long simple_rand(void) {
    // Although "random" isn't used, we'll define a specific pattern for demonstration.
    static unsigned long seed = 47114711;
    unsigned long this = seed * 1103515245 + 12345;
    seed = this;
    return this >> 8;
}

unsigned long int random_bitstring(void) {
    unsigned long int x = 0; // Initializing x
    int tot_bits = 0;

    for (;;) {
        long ran = simple_rand();
        int n_bits = (ran >> 1) % 16;
        tot_bits += n_bits;

        if (n_bits == 0)
            return x;
        else {
            x <<= n_bits;
            if (ran & 1)
                x |= (1 << n_bits) - 1;

            if (tot_bits > 8 * sizeof(long) + 6)
                return x;
        }
    }
}

int main(void) {
    long int i;

    for (i = 0; i < 1000; i++) {
        unsigned long x = random_bitstring();
        unsigned long y = random_bitstring();

        // If division by zero is possible or if y == -1 for signed types
        // skipping that iteration
        if (sizeof(int) == sizeof(long)) {
            unsigned long xx = x, yy = y, r1, r2;
            if (yy != 0) {
                r1 = xx / yy;
                r2 = xx % yy;
                if (r2 >= yy || r1 * yy + r2 != xx) {
                    abort();
                }
            }
        }

        // Processing logic ensured with explicit checks without any randomness
        // and ensuring logic is complete
        {
            unsigned long xx = x, yy = y, r1, r2;
            if (yy != 0) {
                r1 = xx / yy;
                r2 = xx % yy;
                if (r2 >= yy || r1 * yy + r2 != xx) {
                    abort();
                }
            }
        }
        {
            signed long xx = x, yy = y, r1, r2;
            if (((unsigned long) xx << 1) != 0 && yy != -1) {
                r1 = xx / yy;
                r2 = xx % yy;
                if (ABS(r2) >= (unsigned long) ABS(yy) || (signed long) (r1 * yy + r2) != xx) {
                    abort();
                }
            }
        }
        {
            unsigned int xx = x, yy = y, r1, r2;
            if (yy != 0) {
                r1 = xx / yy;
                r2 = xx % yy;
                if (r2 >= yy || r1 * yy + r2 != xx) {
                    abort();
                }
            }
        }
        {
            signed int xx = x, yy = y, r1, r2;
            if (((unsigned int) xx << 1) != 0 && yy != -1) {
                r1 = xx / yy;
                r2 = xx % yy;
                if (ABS(r2) >= (unsigned int) ABS(yy) || (signed int) (r1 * yy + r2) != xx) {
                    abort();
                }
            }
        }
        {
            unsigned short xx = x, yy = y, r1, r2;
            if (yy != 0) {
                r1 = xx / yy;
                r2 = xx % yy;
                if (r2 >= yy || r1 * yy + r2 != xx) {
                    abort();
                }
            }
        }
        {
            signed short xx = x, yy = y, r1, r2;
            if (yy != 0) {
                r1 = xx / yy;
                r2 = xx % yy;
                if (ABS(r2) >= (unsigned short) ABS(yy) || (signed short) (r1 * yy + r2) != xx) {
                    abort();
                }
            }
        }
    }

    return 0;
}