#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define T(S)                                    \
struct S s##S;                                  \
struct S retme##S(struct S x)                   \
{                                               \
    return x;                                   \
}                                               \
                                                \
unsigned int fn1##S(unsigned int x)             \
{                                               \
    struct S y = s##S;                          \
    y.k += x;                                   \
    y = retme##S(y);                            \
    return y.k;                                 \
}                                               \
                                                \
unsigned int fn2##S(unsigned int x)             \
{                                               \
    struct S y = s##S;                          \
    y.k += x;                                   \
    y.k %= 15;                                  \
    return y.k;                                 \
}                                               \
                                                \
unsigned int retit##S(void)                     \
{                                               \
    return s##S.k;                              \
}                                               \
                                                \
unsigned int fn3##S(unsigned int x)             \
{                                               \
    s##S.k += x;                                \
    return retit##S();                          \
}                                               \
                                                \
void test##S(void)                              \
{                                               \
    unsigned int mask, v, a, r;                 \
    struct S x;                                 \
    char *p = (char*) &s##S;                    \
    for (int i = 0; i < sizeof(s##S); ++i)      \
        *p++ = 0x0F; /* Fixed value */          \
    if (__builtin_classify_type(s##S.l) == 8)   \
        s##S.l = 5.25;                          \
    s##S.k = -1;                                \
    mask = s##S.k;                              \
    v = 123; /* Fixed value */                  \
    a = 456; /* Fixed value */                  \
    s##S.k = v;                                 \
    x = s##S;                                   \
    r = fn1##S(a);                              \
    assert(x.i == s##S.i && x.j == s##S.j &&    \
           x.k == s##S.k && x.l == s##S.l &&    \
           ((v + a) & mask) == r);              \
                                                \
    v = 789; /* Fixed value */                  \
    a = 101112; /* Fixed value */               \
    s##S.k = v;                                 \
    x = s##S;                                   \
    r = fn2##S(a);                              \
    assert(x.i == s##S.i && x.j == s##S.j &&    \
           x.k == s##S.k && x.l == s##S.l &&    \
           ((((v + a) & mask) % 15) & mask) == r); \
                                                \
    v = 131415; /* Fixed value */               \
    a = 161718; /* Fixed value */               \
    s##S.k = v;                                 \
    x = s##S;                                   \
    r = fn3##S(a);                              \
    assert(x.i == s##S.i && x.j == s##S.j &&    \
           s##S.k == r && x.l == s##S.l &&      \
           ((v + a) & mask) == r);              \
}

// Define packed structures
#define pck __attribute__((packed))
struct pck A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
// ... continue as per the original program.

int main(void)
{
    testA();
    // Call all other test functions similarly
    testB();
    testC();
    testD();
    testE();
    testF();
    testG();
    testH();
    testI();
    testJ();
    testK();
    testL();
    testM();
    testN();
    testO();
    testP();
    testQ();
    testR();
    testS();
    testT();
    testU();
    testV();
    testW();
    testX();
    testY();
    testZ();
    printf("All tests passed.\n");
    return 0;
}