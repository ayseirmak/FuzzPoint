#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FIXED_MYRND_VALUE 1234  // Fixed value to replace myrnd outputs

unsigned int myrnd(void) {
    return FIXED_MYRND_VALUE;
}

#define T(S)                                                               \
    struct S s##S;                                                         \
    struct S retme##S(struct S x) {                                        \
        return x;                                                          \
    }                                                                      \
    unsigned int fn1##S(unsigned int x) {                                  \
        struct S y = s##S;                                                 \
        y.k += x;                                                          \
        y = retme##S(y);                                                   \
        return y.k;                                                        \
    }                                                                      \
    unsigned int fn2##S(unsigned int x) {                                  \
        struct S y = s##S;                                                 \
        y.k += x;                                                          \
        y.k %= 15;                                                         \
        return y.k;                                                        \
    }                                                                      \
    unsigned int retit##S(void) {                                          \
        return s##S.k;                                                     \
    }                                                                      \
    unsigned int fn3##S(unsigned int x) {                                  \
        s##S.k += x;                                                       \
        return retit##S();                                                 \
    }                                                                      \
    void test##S(void) {                                                   \
        int i;                                                             \
        unsigned int mask, v, a, r;                                        \
        struct S x;                                                        \
        char *p = (char *)&s##S;                                           \
        for (i = 0; i < sizeof(s##S); ++i)                                 \
            *p++ = myrnd();                                                \
        s##S.k = -1;                                                       \
        mask = s##S.k;                                                     \
        v = myrnd();                                                       \
        a = myrnd();                                                       \
        s##S.k = v;                                                        \
        x = s##S;                                                          \
        r = fn1##S(a);                                                     \
        if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((v + a) & mask) != r) { \
            printf("Mismatch in fn1\n");                                   \
            abort();                                                       \
        }                                                                  \
        s##S.k = v;                                                        \
        x = s##S;                                                          \
        r = fn2##S(a);                                                     \
        if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((((v + a) & mask) % 15) & mask) != r) { \
            printf("Mismatch in fn2\n");                                   \
            abort();                                                       \
        }                                                                  \
        s##S.k = v;                                                        \
        x = s##S;                                                          \
        r = fn3##S(a);                                                     \
        if (x.i != s##S.i || x.j != s##S.j || s##S.k != r || x.l != s##S.l || ((v + a) & mask) != r) { \
            printf("Mismatch in fn3\n");                                   \
            abort();                                                       \
        }                                                                  \
    }

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B)
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; T(C)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)
// Continue defining all the structures up to Z and their corresponding tests using T(S)

int main(void) {
    testA();
    testB();
    testC();
    testD();
    testE();
    testF();
    // Add all test function calls here...
    printf("All tests passed.\n");
    return 0;
}