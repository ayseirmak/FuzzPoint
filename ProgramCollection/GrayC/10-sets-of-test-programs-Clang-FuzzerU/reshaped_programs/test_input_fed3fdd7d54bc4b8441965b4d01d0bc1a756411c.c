#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

static void dump_bfd_file (int, int, int, unsigned long, char *);

long long simple_rand() {
    static unsigned long long seed = 47114711; // Fixed seed for deterministic behavior
    unsigned long long this_val = seed * 1103515245 + 12345;
    seed = this_val;
    return this_val >> 8;
}

unsigned long long random_bitstring() {
    unsigned long long int x = 0;
    int n_bits;
    long long ran;
    int tot_bits = 0;

    while (1) {
        ran = simple_rand();
        n_bits = (ran >> 1) % 16;
        tot_bits += n_bits;

        if (n_bits == 0) {
            return x; // Changed to return x directly on zero bits
        }
        
        x = (x << n_bits) | (ran & ((1U << n_bits) - 1));
        tot_bits += n_bits;
    }
}

void fpTest(double x, double y) {
    double result1 = (35.7 * 100.0) / 45.0;
    double result2 = (x * 100.0) / y;

    assert((result1 > result2 - 0.0001) && (result1 < result2 + 0.0001)); // Simple comparison
}

static char hello[] = "hello";

int main(void) {
    fpTest(35.7, 45.0);
    dump_bfd_file(0, 0, 0, (unsigned long)0xdeadbeef, hello);
    return 0;
}

static void dump_bfd_file(int a, int b, int c, unsigned long addr, char *str) {
    printf("Dump BFD file at address: 0x%lx with message: %s\n", addr, str);
}