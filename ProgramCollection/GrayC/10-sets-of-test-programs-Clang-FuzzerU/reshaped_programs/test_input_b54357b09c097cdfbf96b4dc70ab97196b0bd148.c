#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Test arithmetics on bitfields. */

#define FIXED_SEED 1388815473U

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; };
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; };
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; };
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; };
struct E { unsigned long long l, i : 12, j : 23, k : 29; };
struct F { unsigned long long i : 12, j : 23, k : 29, l; };
struct G { unsigned int i : 12, j : 13, k : 7; unsigned long long l; };
struct H { unsigned int i : 12, j : 11, k : 9; unsigned long long l; };
struct I { unsigned short i : 1, j : 6, k : 9; unsigned long long l; };
struct J { unsigned short i : 1, j : 8, k : 7; unsigned short l; };
struct K { unsigned int k : 6, l : 1, j : 10, i : 15; };
struct L { unsigned int k : 6, j : 11, i : 15; unsigned int l; };
struct M { unsigned int l; unsigned int k : 6, j : 11, i : 15; };
struct N { unsigned long long l : 6, k : 6, j : 23, i : 29; };
struct O { unsigned long long l, k : 12, j : 23, i : 29; };
struct P { unsigned long long k : 12, j : 23, i : 29, l; };
struct Q { unsigned int k : 12, j : 13, i : 7; unsigned long long l; };
struct R { unsigned int k : 12, j : 11, i : 9; unsigned long long l; };
struct S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; };
struct T { unsigned short k : 1, j : 8, i : 7; unsigned short l; };
struct U { unsigned short j : 3, k : 1, i : 9; unsigned long long l; };
struct V { unsigned short j : 8, k : 1, i : 7; unsigned short l; };
struct W { long double l; unsigned int k : 12, j : 13, i : 7; };
struct X { unsigned int k : 12, j : 13, i : 7; long double l; };
struct Y { unsigned int k : 12, j : 11, i : 9; long double l; };
struct Z { long double l; unsigned int j : 13, i : 7, k : 12; };

unsigned int myrnd_fixed(void) {
    static unsigned int s = FIXED_SEED;
    s *= 1103515245U;
    s += 12345U;
    return (s / 65536) % 2048;
}

#define T(S)                           \
struct S s##S;                         \
struct S retme##S(struct S x) {        \
    return x;                          \
}                                      \
                                       \
unsigned int fn1##S(unsigned int x) {  \
    struct S y = s##S;                 \
    y.k += x;                          \
    y = retme##S(y);                   \
    return y.k;                        \
}                                      \
                                       \
unsigned int fn2##S(unsigned int x) {  \
    struct S y = s##S;                 \
    y.k += x;                          \
    y.k %= 15;                         \
    return y.k;                        \
}                                      \
                                       \
unsigned int retit##S(void) {          \
    return s##S.k;                     \
}                                      \
                                       \
unsigned int fn3##S(unsigned int x) {  \
    s##S.k += x;                       \
    return retit##S();                 \
}                                      \
                                       \
void test##S(void) {                   \
    int i;                             \
    unsigned int mask, v, a, r;        \
    struct S x;                        \
    char *p = (char *)&s##S;           \
    for (i = 0; i < sizeof(s##S); ++i) \
        *p++ = (char)myrnd_fixed();    \
    if (__builtin_classify_type(s##S.l) == 8) \
        s##S.l = 5.25;                 \
    s##S.k = -1;                       \
    mask = s##S.k;                     \
    v = myrnd_fixed();                 \
    a = myrnd_fixed();                 \
    s##S.k = v;                        \
    x = s##S;                          \
    r = fn1##S(a);                     \
    assert(x.i == s##S.i && x.j == s##S.j && x.k == s##S.k && x.l == s##S.l && ((v + a) & mask) == r);\
    v = myrnd_fixed();                 \
    a = myrnd_fixed();                 \
    s##S.k = v;                        \
    x = s##S;                          \
    r = fn1##S(a);                     \
    assert(x.i == s##S.i && x.j == s##S.j && x.k == s##S.k && x.l == s##S.l && ((((v + a) & mask) % 15) & mask) == r);\
    v = myrnd_fixed();                 \
    a = myrnd_fixed();                 \
    s##S.k = v;                        \
    x = s##S;                          \
    r = fn3##S(a);                     \
    assert(x.i == s##S.i && x.j == s##S.j && s##S.k == r && x.l == s##S.l && ((v + a) & mask) == r);\
}

T(A)
T(B)
T(C)
T(D)
T(E)
T(F)
T(G)
T(H)
T(I)
T(J)
T(K)
T(L)
T(M)
T(N)
T(O)
T(P)
T(Q)
T(R)
T(S)
T(T)
T(U)
T(V)
T(W)
T(X)
T(Y)
T(Z)

int main(void) {
    testA();
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

    return 0;
}