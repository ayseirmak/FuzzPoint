#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct S {
    double for_alignment;
    struct {
        int x, y, z;
    } a[16];
};

void f(struct S *s) __attribute__((noinline));

void f(struct S *s) {
    unsigned int i;
    for (i = 0; i < 16; ++i) {
        s->a[i].x = 0;
        s->a[i].y = 0;
        s->a[i].z = 0;
    }
}

struct T {
    unsigned short s[64];
};

__attribute__((noinline, noclone)) void foo(struct T *t) {
    unsigned int i;
    for (i = 0; i < 64; i++) {
        t->s[i] = i + ((64 - i) << 8);
    }

    for (i = 0; i < 64; i++) {
#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        if (t->s[i] != (64 - i) + (i << 8)) {
            printf("Assertion failed at index %d\n", i);
            exit(EXIT_FAILURE);
        }
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        if (t->s[i] != i + ((64 - i) << 8)) {
            printf("Assertion failed at index %d\n", i);
            exit(EXIT_FAILURE);
        }
#endif
    }
}

int main(void) {
    struct S s1;
    f(&s1);

    struct T t1;
    foo(&t1);

    printf("Program completed successfully.\n");
    return 0;
}