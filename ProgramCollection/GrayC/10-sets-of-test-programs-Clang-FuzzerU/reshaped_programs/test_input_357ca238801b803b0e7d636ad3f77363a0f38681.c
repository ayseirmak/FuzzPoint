#include <stdio.h>
#include <stdlib.h>

// Mock random number generator with deterministic output
unsigned int myrnd(void) {
    static unsigned int seq[] = {1000, 2000, 1500, 3000, 2500, 3500, 4000, 4500};
    static int index = 0;
    unsigned int result = seq[index % 8];
    index++;
    return result;
}

#define T(S)                                        \
struct S s##S = {0};                                \
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
    unsigned int mask, v, a, r;                     \
    struct S x;                                     \
    char *p = (char *)&s##S;                        \
    for (int i = 0; i < sizeof(s##S); ++i) {        \
        *p++ = myrnd();                             \
    }                                               \
    s##S.k = (unsigned int)-1;                      \
    mask = s##S.k;                                  \
    v = myrnd();                                    \
    a = myrnd();                                    \
    s##S.k = v;                                     \
    x = s##S;                                       \
    r = fn1##S(a);                                  \
    if (x.i != s##S.i || x.j != s##S.j              \
        || x.k != s##S.k || x.l != s##S.l           \
        || ((v + a) & mask) != r) {                 \
        printf("Abort\n");                          \
        exit(1);                                    \
    }                                               \
    v = myrnd();                                    \
    a = myrnd();                                    \
    s##S.k = v;                                     \
    x = s##S;                                       \
    r = fn2##S(a);                                  \
    if (x.i != s##S.i || x.j != s##S.j              \
        || x.k != s##S.k || x.l != s##S.l           \
        || ((((v + a) & mask) % 15) & mask) != r) { \
        printf("Abort\n");                          \
        exit(1);                                    \
    }                                               \
    v = myrnd();                                    \
    a = myrnd();                                    \
    s##S.k = v;                                     \
    x = s##S;                                       \
    r = fn3##S(a);                                  \
    if (x.i != s##S.i || x.j != s##S.j              \
        || s##S.k != r || x.l != s##S.l             \
        || ((v + a) & mask) != r) {                 \
        printf("Abort\n");                          \
        exit(1);                                    \
    }                                               \
}

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B)
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; T(C)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)
struct G { unsigned int i : 12, j : 13, k : 7; unsigned long long l; }; T(G)
struct H { unsigned int i : 12, j : 12, k : 8; unsigned short l; }; T(H)
struct I { unsigned short i : 5, j : 4, k : 5; unsigned int l : 18; }; T(I)
struct J { unsigned int i : 6, j : 6, k : 6; unsigned int l; }; T(J)
struct K { unsigned int k : 6, l : 1, j : 10, i : 15; }; T(K)
struct L { unsigned int k : 6, j : 11, i : 15; unsigned int l; }; T(L)
struct M { unsigned int l; unsigned int k : 6, j : 11, i : 15; }; T(M)
struct N { unsigned long long l : 6, k : 6, j : 23, i : 29; }; T(N)
struct O { unsigned long long l, k : 12, j : 23, i : 29; }; T(O)
struct P { unsigned long long k : 12, j : 23, i : 29, l; }; T(P)
struct Q { unsigned int k : 12, j : 13, i : 7; unsigned long long l; }; T(Q)
struct R { unsigned int k : 12, j : 11, i : 9; unsigned long long l; }; T(R)
struct S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; T(S)
struct T { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(T)
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
    
    printf("All tests passed\n");
    return 0;
}