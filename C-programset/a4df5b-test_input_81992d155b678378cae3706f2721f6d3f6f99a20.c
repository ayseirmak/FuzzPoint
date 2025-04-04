#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Test arithmetics on bitfields. */

unsigned int myrnd_fixed(int seed) {
    return (seed / 65536) % 2048;
}

#define T(S, seed1, seed2)                                    \
struct S s##S;                                                \
                                                              \
struct S retme##S(struct S x) {                               \
    return x;                                                 \
}                                                             \
                                                              \
unsigned int fn1##S(unsigned int x) {                         \
    struct S y = s##S;                                        \
    y.k += x;                                                 \
    y = retme##S(y);                                          \
    return y.k;                                               \
}                                                             \
                                                              \
unsigned int fn2##S(unsigned int x) {                         \
    struct S y = s##S;                                        \
    y.k += x;                                                 \
    y.k %= 15;                                                \
    return y.k;                                               \
}                                                             \
                                                              \
unsigned int retit##S(void) {                                 \
    return s##S.k;                                            \
}                                                             \
                                                              \
unsigned int fn3##S(unsigned int x) {                         \
    s##S.k += x;                                              \
    return retit##S();                                        \
}                                                             \
                                                              \
void test##S(void) {                                          \
    int i;                                                    \
    unsigned int mask, v, a, r;                               \
    struct S x;                                               \
    char *p = (char *)&s##S;                                  \
    for (i = 0; i < sizeof(s##S); ++i)                        \
        *p++ = myrnd_fixed(seed1);                            \
    s##S.k = -1;                                              \
    mask = s##S.k;                                            \
    v = myrnd_fixed(seed2);                                   \
    a = myrnd_fixed(seed1);                                   \
    s##S.k = v;                                               \
    x = s##S;                                                 \
    r = fn1##S(a);                                            \
    assert((x.i == s##S.i) && (x.j == s##S.j) &&              \
           (x.k == s##S.k) && (x.l == s##S.l) &&              \
           (((v + a) & mask) == r));                          \
                                                              \
    v = myrnd_fixed(seed2);                                   \
    a = myrnd_fixed(seed1);                                   \
    s##S.k = v;                                               \
    x = s##S;                                                 \
    r = fn1##S(a);                                            \
    assert((x.i == s##S.i) && (x.j == s##S.j) &&              \
           (x.k == s##S.k) && (x.l == s##S.l) &&              \
           (((((v + a) & mask) % 15) & mask) == r));          \
                                                              \
    v = myrnd_fixed(seed2);                                   \
    a = myrnd_fixed(seed1);                                   \
    s##S.k = v;                                               \
    x = s##S;                                                 \
    r = fn3##S(a);                                            \
    assert((x.i == s##S.i) && (x.j == s##S.j) &&              \
           (s##S.k == r) && (x.l == s##S.l) &&                \
           (((v + a) & mask) == r));                          \
}

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A, 1, 2)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B, 3, 4)
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; T(C, 5, 6)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D, 7, 8)
struct E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E, 9, 10)
struct F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F, 11, 12)
struct G { unsigned int i : 12, j : 13, k : 7; unsigned long long l; }; T(G, 13, 14)
struct H { unsigned int i : 12, j : 11, k : 9; unsigned long long l; }; T(H, 15, 16)
struct I { unsigned short i : 1, j : 6, k : 9; unsigned long long l; }; T(I, 17, 18)
struct J { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; T(J, 19, 20)
struct K { unsigned int k : 6, l : 1, j : 10, i : 15; }; T(K, 21, 22)
struct L { unsigned int k : 6, j : 11, i : 15; unsigned int l; }; T(L, 23, 24)
struct M { unsigned int l; unsigned int k : 6, j : 11, i : 15; }; T(M, 25, 26)
struct N { unsigned long long l : 6, k : 6, j : 23, i : 29; }; T(N, 27, 28)
struct O { unsigned long long l, k : 13, j : 23, i : 29; }; T(O, 29, 30)
struct P { unsigned long long k : 12, j : 23, i : 29, l; }; T(P, 31, 32)
struct Q { unsigned int k : 12, j : 13, i : 7; unsigned long long l; }; T(Q, 33, 34)
struct R { unsigned int k : 12, j : 11, i : 9; unsigned long long l; }; T(R, 35, 36)
struct S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; T(S, 37, 38)
struct T { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(T, 39, 40)
struct U { unsigned short j : 3, k : 1, i : 9; unsigned long long l; }; T(U, 41, 42)
struct V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(V, 43, 44)
struct W { long double l; unsigned int k : 12, j : 13, i : 7; }; T(W, 45, 46)
struct X { unsigned int k : 12, j : 13, i : 7; long double l; }; T(X, 47, 48)
struct Y { unsigned int k : 12, j : 11, i : 9; long double l; }; T(Y, 49, 50)
struct Z { long double l; unsigned int j : 13, i : 7, k : 12; }; T(Z, 51, 52)

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
    printf("All tests passed!\n");
    return 0;
}