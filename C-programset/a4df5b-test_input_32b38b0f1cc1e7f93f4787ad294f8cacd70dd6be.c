#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) >= 0 ? (x) : -(x))

void custom_abort() {
    printf("Abort called!\n");
    exit(1);
}

long simple_rand() {
    static unsigned long seed = 47114711;
    unsigned long this = seed * 1103515245 + 12345;
    seed = this;
    return this >> 8;
}

unsigned long int random_bitstring() {
    unsigned long int x = 0;
    int n_bits;
    long ran;
    int tot_bits = 0;

    for (;;) {
        ran = simple_rand();
        n_bits = (ran >> 0) % 16;
        tot_bits += n_bits;

        if (n_bits == 0) {
            return x;
        } else {
            x <<= n_bits;
            if (ran & 1) {
                x |= (1 << n_bits) - 1;
            }

            if (tot_bits > 8 * sizeof(long) + 6) {
                return x;
            }
        }
    }
}

int main() {
    long int i;

    for (i = 0; i < 1000; i++) {
        unsigned long x = random_bitstring();
        unsigned long y = random_bitstring();

        if (sizeof(int) == sizeof(long))
            goto save_time;

        { 
            unsigned long xx = x, yy = y, r1, r2;
            if (yy == 0) continue;
            r1 = xx / yy;
            r2 = xx % yy;
            if (r2 >= yy || r1 * yy + r2 != xx)
                custom_abort();
        }
        
        {
            signed long xx = x, yy = y, r1, r2;
            if ((unsigned long)xx << 1 == 0 && yy == -1)
                continue;
            r1 = xx / yy;
            r2 = xx % yy;
            if (ABS(r2) >= (unsigned long)ABS(yy) || (signed long)(r1 * yy + r2) != xx)
                custom_abort();
        }
        
    save_time:
        {
            unsigned int xx = x, yy = y, r1, r2;
            if (yy == 0) continue;
            r1 = xx / yy;
            r2 = xx % yy;
            if (r2 >= yy || r1 * yy + r2 != xx)
                custom_abort();
        }
        
        {
            signed int xx = x, yy = y, r1, r2;
            if ((unsigned int)xx << 1 == 0 && yy == -1)
                continue;
            r1 = xx / yy;
            r2 = xx % yy;
            if (ABS(r2) >= (unsigned int)ABS(yy) || (signed int)(r1 * yy + r2) != xx)
                custom_abort();
        }
        
        {
            unsigned short xx = x, yy = y, r1, r2;
            if (yy == 0) continue;
            r1 = xx / yy;
            r2 = xx % yy;
            if (r2 >= yy || r1 * yy + r2 != xx)
                custom_abort();
        }
        
        {
            signed short xx = x, yy = y, r1, r2;
            r1 = xx / yy;
            r2 = xx % yy;
            if (ABS(r2) >= (unsigned short)ABS(yy) || (signed short)(r1 * yy + r2) != xx)
                custom_abort();
        }
    }
    
    return 0;
}