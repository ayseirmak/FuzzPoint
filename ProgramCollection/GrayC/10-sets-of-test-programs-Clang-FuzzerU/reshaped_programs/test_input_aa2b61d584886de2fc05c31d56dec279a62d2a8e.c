#include <stdio.h>
#include <stdlib.h>

struct S1 {
    double for_alignment;
    struct { int x, y, z; } a[16];
};

void f1(struct S1 *s) __attribute__((noinline));

void f1(struct S1 *s) {
    unsigned int i;

    for (i = 0; i < 16; ++i) {
        s->a[i].x = 0;
        s->a[i].y = 0;
        s->a[i].z = 0;
    }
}

struct S2 {
    unsigned short s[64];
};

__attribute__((noinline, noclone)) void foo(struct S2 *s) {
    // This function currently does nothing problematic
}

int main(void) {
    struct S1 s1;
    f1(&s1);  // Initialize the S1 structure with specific values

    struct S2 s2;
    
    unsigned int i;
    for (i = 0; i < 64; i++) {
        s2.s[i] = i + ((64 - i) << 8);
    }

    foo(&s2);

    for (i = 0; i < 64; i++) {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        if (s2.s[i] != (64 - i) + (i << 8)) {
            printf("Test failed at index %d: value is %d, expected %d\n", i, s2.s[i], (64 - i) + (i << 8));
            return 1;  // Failure
        }
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        if (s2.s[i] != i + ((64 - i) << 8)) {
            printf("Test failed at index %d: value is %d, expected %d\n", i, s2.s[i], i + ((64 - i) << 8));
            return 1;  // Failure
        }
#endif
    }

    printf("All tests passed.\n");
    return 0;  // Success
}