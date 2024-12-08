#include <stdio.h>
#include <stdlib.h>

/* Reconstructed and fixed conceptual structure-related examples from the programs */

struct S_1 {
    double for_alignment;
    struct { int x, y, z; } a[16];
};

void f(struct S_1 *s) {
    unsigned int i = 0;
    for (; i < 16; ++i) {
        s->a[i].x = 0;
        s->a[i].z = 0;
    }
}

struct S_2 {
    unsigned short s[64];
};

void foo(struct S_2* x) __attribute__((noinline, noclone)) {
    unsigned int i = 0;
    unsigned char* s = (unsigned char*)x->s;
    for (; i < 64; i++) {
        x->s[i] = s[i * 2] | (s[i * 2 + 1] << 8);
    }
}

int main(void) {
    // Program 1
    struct S_1 s1;
    f(&s1);

    // Program 2
    struct S_2 s2;
    int arr[][3][5] = {
        {
            { 0, 0, 3, 5, 0 },
            { 1, 0, 0, 6, 7 }
        },
        {
            { 1, 2, 0, 0, 0 },
            { 0, 0, 0, 0, 7 }
        }
    };

    if (!(arr[0][1][4] == arr[1][1][4])) {
        printf("Assertion Failed!\n");
        return 1;
    }

    // Additional processing on struct S_2
    unsigned int i;
    for (i = 0; i < 64; i++) {
        s2.s[i] = i + ((64 - i) << 8);
    }

    foo(&s2);

#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    for (i = 0; i < 64; i++) {
        if (s2.s[i] != (64 - i) + (i << 8)) {
            abort();
        }
    }
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    for (i = 0; i < 64; i++) {
        if (s2.s[i] != i + ((64 - i) << 8)) {
            abort();
        }
    }
#endif

    return 0;
}