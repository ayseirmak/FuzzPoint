#include <stdio.h>
#include <stdlib.h>

#define NUM_STRUCTS 26

typedef struct {
    unsigned int i : 6, l : 1, j : 10, k : 15;
} A;

typedef struct {
    unsigned int i : 6, j : 11, k : 15;
    unsigned int l;
} B;

// ... Define all other structures similarly ...

typedef struct {
    long double l;
    unsigned int j : 13, i : 7, k : 12;
} Z;

unsigned int fixed_value = 520;

unsigned int deterministic_val(int index) {
    return (fixed_value + index) % 2048;
}

#define T(S)                                            \
    struct S s##S;                                      \
    struct S retme##S(struct S x) {                     \
        return x;                                       \
    }                                                   \
                                                        \
    unsigned int fn1##S(unsigned int x) {               \
        struct S y = s##S;                              \
        y.k += x;                                       \
        y = retme##S(y);                                \
        return y.k;                                     \
    }                                                   \
                                                        \
    unsigned int fn2##S(unsigned int x) {               \
        struct S y = s##S;                              \
        y.k += x;                                       \
        y.k %= 15;                                      \
        return y.k;                                     \
    }                                                   \
                                                        \
    unsigned int retit##S(void) {                       \
        return s##S.k;                                  \
    }                                                   \
                                                        \
    unsigned int fn3##S(unsigned int x) {               \
        s##S.k += x;                                    \
        return retit##S();                              \
    }                                                   \
                                                        \
    void test##S(void) {                                \
        int i;                                          \
        unsigned int mask, v, a, r;                     \
        struct S x;                                     \
        char *p = (char *)&s##S;                        \
        for (i = 0; i < sizeof(s##S); ++i) {            \
            *p++ = deterministic_val(i);                \
        }                                               \
        s##S.l = 5.25;                                  \
        s##S.k = -1;                                    \
        mask = s##S.k;                                  \
        v = deterministic_val(1);                       \
        a = deterministic_val(2);                       \
        s##S.k = v;                                     \
        x = s##S;                                       \
        r = fn1##S(a);                                  \
        if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((v + a) & mask) != r) { \
            printf("Test failed for struct " #S "\n");   \
            exit(EXIT_FAILURE);                         \
        }                                               \
        v = deterministic_val(3);                       \
        a = deterministic_val(4);                       \
        s##S.k = v;                                     \
        x = s##S;                                       \
        r = fn1##S(a);                                  \
        if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((((v + a) & mask) % 15) & mask) != r) { \
            printf("Test failed for struct " #S "\n");   \
            exit(EXIT_FAILURE);                         \
        }                                               \
        v = deterministic_val(5);                       \
        a = deterministic_val(6);                       \
        s##S.k = v;                                     \
        x = s##S;                                       \
        r = fn3##S(a);                                  \
        if (x.i != s##S.i || x.j != s##S.j || s##S.k != r || x.l != s##S.l || ((v + a) & mask) != r) { \
            printf("Test failed for struct " #S "\n");   \
            exit(EXIT_FAILURE);                         \
        }                                               \
    }

T(A)
// Define T for all other structs: B, C, ..., Z

int main(void) {
    printf("All tests passed.\n");
    return EXIT_SUCCESS;
}