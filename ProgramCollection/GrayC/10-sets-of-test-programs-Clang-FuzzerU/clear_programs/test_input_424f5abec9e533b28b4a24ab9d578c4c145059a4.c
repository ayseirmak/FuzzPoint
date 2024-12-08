#include <stdio.h>
#include <stdlib.h>

unsigned int myrnd(void) {
    static unsigned int s = 1388815473;
    s *= 1103515245;
    s += 12345;
    return (s / 65536) % 2048;
}

#define T(S)                                  \
struct S s##S;                                \
struct S retme##S(struct S x)                 \
{                                             \
    return x;                                 \
}                                             \
                                              \
unsigned int fn1##S(unsigned int x)           \
{                                             \
    struct S y = s##S;                        \
    y.k += x;                                 \
    y = retme##S(y);                          \
    return y.k;                               \
}                                             \
                                              \
unsigned int fn2##S(unsigned int x)           \
{                                             \
    struct S y = s##S;                        \
    y.k += x;                                 \
    y.k %= 15;                                \
    return y.k;                               \
}                                             \
                                              \
unsigned int retit##S(void)                   \
{                                             \
    return s##S.k;                            \
}                                             \
                                              \
unsigned int fn3##S(unsigned int x)           \
{                                             \
    s##S.k += x;                              \
    return retit##S();                        \
}                                             \
                                              \
void test##S(void)                            \
{                                             \
    int i;                                    \
    for (i = 0; i < 5; i++) {                 \
        unsigned int res1 = fn1##S(i);        \
        unsigned int res2 = fn2##S(i);        \
        unsigned int res3 = fn3##S(i);        \
        printf("Results: %u, %u, %u\n", res1, res2, res3); \
    }                                         \
}

struct A { unsigned int k : 12, j : 13, i : 7; unsigned long long l; }; T(A)
struct B { unsigned int k : 12, j : 11, i : 9; unsigned long long l; }; T(B)
struct C { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; T(C)
struct D { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(D)
struct E { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; T(E)
struct F { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(F)
struct G { long double l; unsigned int k : 12, j : 13, i : 7; }; T(G)
struct H { unsigned int k : 12, j : 13, i : 7; long double l; }; T(H)
struct I { unsigned int k : 12, j : 11, i : 9; long double l; }; T(I)
struct J { long double l; unsigned int j : 13, i : 7, k : 12; }; T(J)
struct K { unsigned long long l; unsigned int k : 12, j : 13, i : 7; }; T(K)
struct L { unsigned int k : 12, j : 11, i : 9; unsigned long long l; }; T(L)
struct M { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; T(M)
struct N { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(N)
struct O { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; T(O)
struct P { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(P)
struct Q { long double l; unsigned int k : 12, j : 13, i : 7; }; T(Q)
struct R { unsigned int k : 12, j : 13, i : 7; long double l; }; T(R)
struct S { unsigned int k : 12, j : 11, i : 9; long double l; }; T(S)
struct T { long double l; unsigned int j : 13, i : 7, k : 12; }; T(T)
struct U { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; T(U)
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