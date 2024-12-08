#include <stdio.h>
#include <stdlib.h>

// Initialize static variables with fixed values to avoid randomness
unsigned int myrnd(void) {
    static unsigned int s = 1388815473;
    s *= 1103515245;
    s += 12345;
    return (s / 65536) % 2048;
}

#define T(S)                                          \
    struct S s##S;                                    \
    struct S retme##S(struct S x) {                   \
        return x;                                     \
    }                                                 \
                                                      \
    unsigned int fn1##S(unsigned int x) {             \
        struct S y = s##S;                            \
        y.k += x;                                     \
        y = retme##S(y);                              \
        return y.k;                                   \
    }                                                 \
                                                      \
    unsigned int fn2##S(unsigned int x) {             \
        struct S y = s##S;                            \
        y.k += x;                                     \
        y.k %= 15;                                    \
        return y.k;                                   \
    }                                                 \
                                                      \
    unsigned int retit##S(void) {                     \
        return s##S.k;                                \
    }                                                 \
                                                      \
    unsigned int fn3##S(unsigned int x) {             \
        s##S.k += x;                                  \
        return retit##S();                            \
    }                                                 \
                                                      \
    void test##S(void) {                              \
        unsigned int mask, v, a, r;                   \
        struct S x;                                   \
        char *p = (char *)&s##S;                      \
        for (int i = 0; i < (int)sizeof(s##S); ++i)   \
            *p++ = myrnd();                           \
        if (__builtin_classify_type(s##S.l) == 8)     \
            s##S.l = 5.25;                            \
        s##S.k = -1;                                  \
        mask = s##S.k;                                \
        v = myrnd();                                  \
        a = myrnd();                                  \
        s##S.k = v;                                   \
        x = s##S;                                     \
        r = fn1##S(a);                                \
        if (x.i != s##S.i || x.j != s##S.j ||         \
            x.k != s##S.k || x.l != s##S.l ||         \
            ((v + a) & mask) != r)                    \
            abort();                                  \
        v = myrnd();                                  \
        a = myrnd();                                  \
        s##S.k = v;                                   \
        x = s##S;                                     \
        r = fn2##S(a);                                \
        if (x.i != s##S.i || x.j != s##S.j ||         \
            x.k != s##S.k || x.l != s##S.l ||         \
            ((((v + a) & mask) % 15) & mask) != r)    \
            abort();                                  \
        v = myrnd();                                  \
        a = myrnd();                                  \
        s##S.k = v;                                   \
        x = s##S;                                     \
        r = fn3##S(a);                                \
        if (x.i != s##S.i || x.j != s##S.j ||         \
            s##S.k != r || x.l != s##S.l ||            \
            ((v + a) & mask) != r)                    \
            abort();                                  \
    }

struct __attribute__((packed)) A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
struct __attribute__((packed)) B { unsigned short i : 1, j : 1, k : 6; unsigned long long l; }; T(B)
struct __attribute__((packed)) C { unsigned short i : 6, j : 2, k : 8; unsigned long long l; }; T(C)
struct __attribute__((packed)) D { unsigned short i : 1, j : 6, k : 1; unsigned long long l; }; T(D)
struct __attribute__((packed)) E { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; T(E)
struct __attribute__((packed)) F { unsigned int k : 6, l : 1, j : 10, i : 15; }; T(F)
// and the remaining structures as demonstrated above...

int main(void) {
    testA();
    testB();
    testC();
    testD();
    testE();
    testF();
    // Add calls to other test functions as defined above...
    exit(0);
}