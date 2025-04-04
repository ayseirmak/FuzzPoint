#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Fixed values to replace myrnd function, purely for demonstration
unsigned int myrnd_array[] = {1023, 511, 255, 127, 63, 31, 15, 7, 3, 1};
int myrnd_index = 0;

unsigned int myrnd_fixed(void) {
    unsigned int result = myrnd_array[myrnd_index];
    myrnd_index = (myrnd_index + 1) % (sizeof(myrnd_array) / sizeof(myrnd_array[0]));
    return result;
}

#define T(S)                                \
struct S s##S;                                \
struct S retme##S(struct S x)                \
{                                            \
    return x;                                \
}                                            \
                                             \
unsigned int fn1##S(unsigned int x)          \
{                                            \
    struct S y = s##S;                       \
    y.k += x;                                \
    y = retme##S(y);                         \
    return y.k;                              \
}                                            \
                                             \
unsigned int fn2##S(unsigned int x)          \
{                                            \
    struct S y = s##S;                       \
    y.k += x;                                \
    y.k %= 15;                               \
    return y.k;                              \
}                                            \
                                             \
unsigned int retit##S(void)                  \
{                                            \
    return s##S.k;                           \
}                                            \
                                             \
unsigned int fn3##S(unsigned int x)          \
{                                            \
    s##S.k += x;                             \
    return retit##S();                       \
}                                            \
                                             \
void test##S(void)                           \
{                                            \
    int i;                                   \
    unsigned int mask, v, a, r;              \
    struct S x;                              \
    char *p = (char *)&s##S;                 \
    for (i = 0; i < sizeof(s##S); ++i)       \
        *p++ = myrnd_fixed();                \
    s##S.k = -1;                             \
    mask = s##S.k;                           \
    v = myrnd_fixed();                       \
    a = myrnd_fixed();                       \
    s##S.k = v;                              \
    x = s##S;                                \
    r = fn2##S(a);                           \
    if (x.i != s##S.i || x.j != s##S.j       \
        || x.k != s##S.k || x.l != s##S.l    \
        || ((v + a) & mask) != r)            \
        printf("Test failed.\n");            \
    v = myrnd_fixed();                       \
    a = myrnd_fixed();                       \
    s##S.k = v;                              \
    x = s##S;                                \
    r = fn2##S(a);                           \
    if (x.i != s##S.i || x.j != s##S.j       \
        || x.k != s##S.k || x.l != s##S.l    \
        || ((((v + a) & mask) % 15) & mask) != r) \
        printf("Test failed.\n");            \
    v = myrnd_fixed();                       \
    a = myrnd_fixed();                       \
    s##S.k = v;                              \
    x = s##S;                                \
    r = fn3##S(a);                           \
    if (x.i != s##S.i || x.j != s##S.j       \
        || s##S.k != r || x.l != s##S.l      \
        || ((v + a) & mask) != r)            \
        printf("Test failed.\n");            \
}

// Define packed structures
struct __attribute__((packed)) A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
struct __attribute__((packed)) B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; T(B)
struct __attribute__((packed)) C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; T(C)
struct __attribute__((packed)) D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct __attribute__((packed)) E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct __attribute__((packed)) F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)
struct __attribute__((packed)) G { unsigned short i : 1, j : 1, k : 6; unsigned long long l; }; T(G)
struct __attribute__((packed)) H { unsigned short i : 6, j : 2, k : 8; unsigned long long l; }; T(H)
struct __attribute__((packed)) I { unsigned short i : 1, j : 6, k : 1; unsigned long long l; }; T(I)
struct __attribute__((packed)) J { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; T(J)
struct __attribute__((packed)) K { unsigned int k : 6, l : 1, j : 10, i : 15; }; T(K)
struct __attribute__((packed)) L { unsigned int k : 6, j : 11, i : 15; unsigned int l; }; T(L)
struct __attribute__((packed)) M { unsigned int l; unsigned short k : 6, j : 11, i : 15; }; T(M)
struct __attribute__((packed)) N { unsigned long long l : 6, k : 6, j : 23, i : 29; }; T(N)
struct __attribute__((packed)) O { unsigned long long l, k : 12, j : 23, i : 29; }; T(O)
struct __attribute__((packed)) P { unsigned long long k : 12, j : 23, i : 29, l; }; T(P)
struct __attribute__((packed)) Q { unsigned short k : 12, j : 1, i : 3; unsigned long long l; }; T(Q)
struct __attribute__((packed)) R { unsigned short k : 2, j : 11, i : 3; unsigned long long l; }; T(R)
struct __attribute__((packed)) S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; T(S)
struct __attribute__((packed)) T { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(T)
struct __attribute__((packed)) U { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; T(U)
struct __attribute__((packed)) V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(V)
struct __attribute__((packed)) W { long double l; unsigned int k : 12, j : 13, i : 7; }; T(W)
struct __attribute__((packed)) X { unsigned int k : 12, j : 13, i : 7; long double l; }; T(X)
struct __attribute__((packed)) Y { unsigned int k : 12, j : 11, i : 9; long double l; }; T(Y)
struct __attribute__((packed)) Z { long double l; unsigned int j : 13, i : 7, k : 12; }; T(Z)

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
    printf("All tests completed.\n");
    return 0;
}