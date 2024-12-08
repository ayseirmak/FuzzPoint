#include <stdio.h>
#include <stdlib.h>

#define NUM_STRUCTS 26

unsigned int myrnd(void) {
    // Return a fixed deterministic value
    return 1234;
}

#define TEST(S)                                  \
struct S s##S;                                   \
                                                 \
unsigned int fn1##S(unsigned int x) {            \
    struct S y = s##S;                           \
    y.k += x;                                    \
    return y.k;                                  \
}                                                \
                                                 \
unsigned int fn2##S(unsigned int x) {            \
    struct S y = s##S;                           \
    y.k += x;                                    \
    y.k %= 15;                                   \
    return y.k;                                  \
}                                                \
                                                 \
unsigned int fn3##S(unsigned int x) {            \
    s##S.k += x;                                 \
    return s##S.k;                               \
}                                                \
                                                 \
void test##S(void) {                             \
    unsigned int v = 1000, a = 200, r;           \
    struct S x = s##S;                           \
    s##S.k = v;                                  \
    x = s##S;                                    \
    r = fn1##S(a);                               \
    if (((v + a) % 15) != r) abort();            \
    s##S.k = v;                                  \
    x = s##S;                                    \
    r = fn2##S(a);                               \
    if ((((v + a) % 15) % 15) != r) abort();     \
    s##S.k = v;                                  \
    x = s##S;                                    \
    r = fn3##S(a);                               \
    if ((v + a) != r) abort();                   \
}

#define PCK __attribute__((packed))
struct PCK A { unsigned short i : 1, l : 1, j : 3, k : 11; }; TEST(A)
struct PCK B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; TEST(B)
struct PCK C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; TEST(C)
struct PCK D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; TEST(D)
struct PCK E { unsigned long long l, i : 12, j : 23, k : 29; }; TEST(E)
struct PCK F { unsigned long long i : 12, j : 23, k : 29, l; }; TEST(F)
struct PCK G { unsigned short i : 1, j : 1, k : 6; unsigned long long l; }; TEST(G)
struct PCK H { unsigned short i : 6, j : 2, k : 8; unsigned long long l; }; TEST(H)
struct PCK I { unsigned short i : 1, j : 6, k : 1; unsigned long long l; }; TEST(I)
struct PCK J { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; TEST(J)
struct PCK K { unsigned int k : 6, l : 1, j : 10, i : 15; }; TEST(K)
struct PCK L { unsigned int k : 6, j : 11, i : 15; unsigned int l; }; TEST(L)
struct PCK M { unsigned int l; unsigned short k : 6, j : 11, i : 15; }; TEST(M)
struct PCK N { unsigned long long l : 6, k : 6, j : 23, i : 29; }; TEST(N)
struct PCK O { unsigned long long l, k : 12, j : 23, i : 29; }; TEST(O)
struct PCK P { unsigned long long k : 12, j : 23, i : 29, l; }; TEST(P)
struct PCK Q { unsigned short k : 12, j : 1, i : 3; unsigned long long l; }; TEST(Q)
struct PCK R { unsigned short k : 2, j : 11, i : 3; unsigned long long l; }; TEST(R)
struct PCK S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; TEST(S)
struct PCK T { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; TEST(T)
struct PCK U { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; TEST(U)
struct PCK V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; TEST(V)
struct PCK W { long double l; unsigned int k : 12, j : 13, i : 7; }; TEST(W)
struct PCK X { unsigned int k : 12, j : 13, i : 7; long double l; }; TEST(X)
struct PCK Y { unsigned int k : 12, j : 11, i : 9; long double l; }; TEST(Y)
struct PCK Z { long double l; unsigned int j : 13, i : 7, k : 12; }; TEST(Z)

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