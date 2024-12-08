#include <stdio.h>
#include <stdlib.h>

// Initialize deterministic values
unsigned int fixedValues[] = {1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600, 2800};

unsigned int myrnd_index = 0;

unsigned int myrnd(void) {
    return fixedValues[myrnd_index++ % (sizeof(fixedValues) / sizeof(unsigned int))];
}

#define T(S)                                                        \
struct S s##S;                                                      \
struct S retme##S(struct S x) { return x; }                         \
unsigned int fn1##S(unsigned int x) {                               \
    struct S y = s##S;                                              \
    y.k += x;                                                       \
    y = retme##S(y);                                                \
    return y.k;                                                     \
}                                                                   \
unsigned int fn2##S(unsigned int x) {                               \
    struct S y = s##S;                                              \
    y.k += x;                                                       \
    y.k %= 15;                                                      \
    return y.k;                                                     \
}                                                                   \
unsigned int retit##S(void) { return s##S.k; }                      \
unsigned int fn3##S(unsigned int x) {                               \
    s##S.k += x;                                                    \
    return retit##S();                                              \
}                                                                   \
void test##S(void) {                                                \
    int i;                                                          \
    unsigned int mask, v, a, r;                                     \
    struct S x;                                                     \
    char *p = (char *)&s##S;                                        \
    for (i = 0; i < sizeof(s##S); ++i) *p++ = myrnd();              \
    if (__builtin_classify_type(s##S.l) == 8) s##S.l = 5.25;        \
    s##S.k = -1;                                                    \
    mask = s##S.k;                                                  \
    v = myrnd();                                                    \
    a = myrnd();                                                    \
    s##S.k = v;                                                     \
    x = s##S;                                                       \
    r = fn1##S(a);                                                  \
    if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((v + a) & mask) != r) abort(); \
    v = myrnd();                                                    \
    a = myrnd();                                                    \
    s##S.k = v;                                                     \
    x = s##S;                                                       \
    r = fn2##S(a);                                                  \
    if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((((v + a) & mask) % 15) & mask) != r) abort(); \
    v = myrnd();                                                    \
    a = myrnd();                                                    \
    s##S.k = v;                                                     \
    x = s##S;                                                       \
    r = fn3##S(a);                                                  \
    if (x.i != s##S.i || x.j != s##S.j || s##S.k != r || x.l != s##S.l || ((v + a) & mask) != r) abort(); \
}

// Define various structures with bitfields
struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B)
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; T(C)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)
struct G { unsigned int i : 12, j : 13, k : 7; unsigned long long l; }; T(G)
struct H { unsigned int i : 12, j : 11, k : 9; unsigned long long l; }; T(H)
struct V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(V)
struct W { long double l; unsigned int k : 12, j : 13, i : 7; }; T(W)
struct X { unsigned int k : 12, j : 13, i : 7; long double l; }; T(X)
struct Y { unsigned int k : 12, j : 11, i : 9; long double l; }; T(Y)
struct Z { long double l; unsigned int j : 13, i : 7, k : 12; }; T(Z)

int main(void) {
    testA();
    testB();
    testC();
    testD();
    testE();
    testF();
    testG();
    testH();
    testV();
    testW();
    testX();
    testY();
    testZ();
    exit(0);
}