#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* Corpus Test for Arithmetics on Bitfields without non-deterministic inputs */

#define FIXED_VAL 42  // A deterministic value used instead of randomness

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
struct U { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; 
struct V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; 
struct W { long double l; unsigned int k : 12, j : 13, i : 7; }; 
struct X { unsigned int k : 12, j : 13, i : 7; long double l; }; 
struct Y { unsigned int k : 12, j : 11, i : 9; long double l; }; 
struct Z { long double l; unsigned int j : 13, i : 7, k : 12; };

#define DEFINE_TESTS(S) \
struct S s##S = {0}; \
\
struct S retme##S(struct S x) { \
    return x; \
} \
\
unsigned int fn1##S(unsigned int x) { \
    struct S y = s##S; \
    y.k += x; \
    y = retme##S(y); \
    return y.k; \
} \
\
unsigned int fn2##S(unsigned int x) { \
    struct S y = s##S; \
    y.k += x; \
    y.k %= 15; \
    return y.k; \
} \
\
unsigned int retit##S(void) { \
    return s##S.k; \
} \
\
unsigned int fn3##S(unsigned int x) { \
    s##S.k += x; \
    return retit##S(); \
} \
\
void test##S(void) { \
    unsigned int v = FIXED_VAL, a = FIXED_VAL; \
    s##S.k = v; \
    struct S x = s##S; \
    unsigned int r = fn1##S(a); \
    assert((x.k != s##S.k) == ((v + a) != r)); \
    v = FIXED_VAL; \
    s##S.k = v; \
    x = s##S; \
    r = fn1##S(a); \
    assert((x.k != s##S.k) == (((v + a) % 15) != r)); \
    v = FIXED_VAL; \
    s##S.k = v; \
    x = s##S; \
    r = fn3##S(a); \
    assert((x.k != r) == ((v + a) != r)); \
}

DEFINE_TESTS(A)
DEFINE_TESTS(B)
DEFINE_TESTS(C)
DEFINE_TESTS(D)
DEFINE_TESTS(E)
DEFINE_TESTS(F)
DEFINE_TESTS(G)
DEFINE_TESTS(H)
DEFINE_TESTS(I)
DEFINE_TESTS(J)
DEFINE_TESTS(K)
DEFINE_TESTS(L)
DEFINE_TESTS(M)
DEFINE_TESTS(N)
DEFINE_TESTS(O)
DEFINE_TESTS(P)
DEFINE_TESTS(Q)
DEFINE_TESTS(R)
DEFINE_TESTS(S)
DEFINE_TESTS(T)
DEFINE_TESTS(U)
DEFINE_TESTS(V)
DEFINE_TESTS(W)
DEFINE_TESTS(X)
DEFINE_TESTS(Y)
DEFINE_TESTS(Z)

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
    printf("All tests passed.\n");
    return 0;
}