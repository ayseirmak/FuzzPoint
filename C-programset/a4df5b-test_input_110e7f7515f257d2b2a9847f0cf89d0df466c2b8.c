#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Function to return a deterministic "random" number
unsigned int myrnd(void) {
    static unsigned int fixed_value = 1; // Fixed deterministic seed
    return fixed_value;
}

#define T(S)                                \
struct S s##S;                              \
struct S retme##S(struct S x)               \
{                                           \
    return x;                               \
}                                           \
                                            \
unsigned int fn1##S(unsigned int x)         \
{                                           \
    struct S y = s##S;                      \
    y.k += x;                               \
    y = retme##S(y);                        \
    return y.k;                             \
}                                           \
                                            \
unsigned int fn2##S(unsigned int x)         \
{                                           \
    struct S y = s##S;                      \
    y.k += x;                               \
    y.k %= 15;                              \
    return y.k;                             \
}                                           \
                                            \
unsigned int retit##S(void)                 \
{                                           \
    return s##S.k;                          \
}                                           \
                                            \
unsigned int fn3##S(unsigned int x)         \
{                                           \
    s##S.k += x;                            \
    return retit##S();                      \
}                                           \

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B)
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; T(C)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)
struct G { unsigned int i : 12, j : 13, k : 7; unsigned long long l; }; T(G)
struct H { unsigned int i : 12, j : 11, k : 9; unsigned long long l; }; T(H)
struct I { unsigned short i : 1, j : 6, k : 9; unsigned long long l; }; T(I)
struct J { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; T(J)
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
    // Initialize structures with deterministic values
    struct A sA = {0};
    struct B sB = {0};
    struct C sC = {0};
    struct D sD = {0};
    struct E sE = {0};
    struct F sF = {0};
    struct G sG = {0};
    struct H sH = {0};
    struct I sI = {0};
    struct J sJ = {0};
    struct K sK = {0};
    struct L sL = {0};
    struct M sM = {0};
    struct N sN = {0};
    struct O sO = {0};
    struct P sP = {0};
    struct Q sQ = {0};
    struct R sR = {0};
    struct S sS = {0};
    struct T sT = {0};
    struct U sU = {0};
    struct V sV = {0};
    struct W sW = {0};
    struct X sX = {0};
    struct Y sY = {0};
    struct Z sZ = {0};

    // Directly call the test functions (no-operations here)
    exit(0);
}