#include <stdio.h>
#include <stdlib.h>

#define NUM_STRUCTS 26

// Define a fixed value for myrnd function
unsigned int myrnd_fixed_value = 42;

#define T(S)                                          \
struct S s##S;                                        \
                                                     \
unsigned int fn1##S(unsigned int x) {                 \
    struct S y = s##S;                                \
    y.k += x;                                         \
    return y.k;                                       \
}                                                     \
                                                     \
unsigned int fn2##S(unsigned int x) {                 \
    struct S y = s##S;                                \
    y.k += x;                                         \
    y.k %= 15;                                        \
    return y.k;                                       \
}                                                     \
                                                     \
unsigned int retit##S(void) {                         \
    return s##S.k;                                    \
}                                                     \
                                                     \
unsigned int fn3##S(unsigned int x) {                 \
    s##S.k += x;                                      \
    return s##S.k;                                    \
}                                                     \
                                                     \
void test##S(void) {                                  \
    struct S x;                                        \
    unsigned int mask, v, a, r;                       \
                                                      \
    for (int i = 0; i < sizeof(struct S); ++i) {     \
        ((char *)&s##S)[i] = (char)myrnd_fixed_value; \
    }                                                 \
                                                      \
    s##S.k = -1;                                      \
    mask = s##S.k;                                    \
                                                      \
    v = myrnd_fixed_value;                            \
    a = myrnd_fixed_value;                            \
                                                      \
    s##S.k = v;                                       \
    x = s##S;                                         \
    r = fn1##S(a);                                    \
    if (x.i != s##S.i || x.j != s##S.j ||             \
        x.k != s##S.k || x.l != s##S.l ||             \
        ((v + a) & mask) != r)                        \
        abort();                                      \
                                                      \
    v = myrnd_fixed_value;                            \
    a = myrnd_fixed_value;                            \
    s##S.k = v;                                       \
    x = s##S;                                         \
    r = fn2##S(a);                                    \
    if (x.i != s##S.i || x.j != s##S.j ||             \
        x.k != s##S.k || x.l != s##S.l ||             \
        ((((v + a) & mask) % 15) & mask) != r)        \
        abort();                                      \
                                                      \
    v = myrnd_fixed_value;                            \
    a = myrnd_fixed_value;                            \
    s##S.k = v;                                       \
    x = s##S;                                         \
    r = fn3##S(a);                                    \
    if (x.i != s##S.i || x.j != s##S.j ||             \
        s##S.k != r || x.l != s##S.l ||               \
        ((v + a) & mask) != r)                        \
        abort();                                      \
}

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B)
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; T(C)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)
struct G { unsigned int i : 12, j : 13, k : 7; unsigned int l; }; T(G)
struct H { unsigned long long l; unsigned int k : 6, j : 11, i : 15; }; T(H)
struct I { unsigned int l; unsigned int k : 6, j : 11, i : 15; }; T(I)
struct J { unsigned long long l : 6, k : 6, j : 23, i : 29; }; T(J)
struct K { unsigned long long l, k : 12, j : 23, i : 29; }; T(K)
struct L { unsigned long long k : 12, j : 23, i : 29, l; }; T(L)
struct M { unsigned int k : 12, j : 13, i : 7; unsigned long long l; }; T(M)
struct N { unsigned int k : 12, j : 11, i : 9; unsigned long long l; }; T(N)
struct O { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; T(O)
struct P { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(P)
struct Q { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; T(Q)
struct R { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(R)
struct S { long double l; unsigned int k : 12, j : 13, i : 7; }; T(S)
struct T { long double l; unsigned int j : 13, i : 7, k : 12; }; T(T)
struct U { unsigned int k : 12, j : 11, i : 9; long double l; }; T(U)
struct V { long double l; unsigned int k : 12, j : 11, i : 9; }; T(V)
struct W { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(W)
struct X { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(X)
struct Y { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(Y)
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