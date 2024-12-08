#include <stdio.h>
#include <stdlib.h>

// Replaced the myrnd function with static values for deterministic behavior
unsigned int myrnd_index = 0;
const unsigned int myrnd_values[] = {
    1001, 1024, 2025, 2047, 512, 256, 878, 979, 300, 145,
    867, 915, 230, 741, 156, 138, 986, 432, 321, 654,
    789, 234, 1011, 1234, 1837, 483, 565, 765, 888, 234,
    555, 777, 888, 999, 333, 666, 222, 111, 444, 666
};

unsigned int myrnd(void) {
    unsigned int value = myrnd_values[myrnd_index];
    myrnd_index = (myrnd_index + 1) % (sizeof(myrnd_values) / sizeof(myrnd_values[0]));
    return value;
}

#define T(S)                                       \
struct S s##S;                                     \
struct S retme##S (struct S x)                     \
{                                                  \
    return x;                                      \
}                                                  \
                                                   \
unsigned int fn1##S (unsigned int x)               \
{                                                  \
    struct S y = s##S;                             \
    y.k += x;                                      \
    y = retme##S (y);                              \
    return y.k;                                    \
}                                                  \
                                                   \
unsigned int fn2##S (unsigned int x)               \
{                                                  \
    struct S y = s##S;                             \
    y.k += x;                                      \
    y.k %= 15;                                     \
    return y.k;                                    \
}                                                  \
                                                   \
unsigned int retit##S (void)                       \
{                                                  \
    return s##S.k;                                 \
}                                                  \
                                                   \
unsigned int fn3##S (unsigned int x)               \
{                                                  \
    s##S.k += x;                                   \
    return retit##S ();                            \
}                                                  \
                                                   \
void test##S (void)                                \
{                                                  \
    int i;                                         \
    unsigned int mask, v, a, r;                    \
    struct S x;                                    \
    char *p = (char *) &s##S;                      \
    for (i = 0; i < sizeof (s##S); ++i)            \
        *p++ = myrnd ();                           \
    if (__builtin_classify_type (s##S.l) == 8)     \
        s##S.l = 5.25;                             \
    s##S.k = -1;                                   \
    mask = s##S.k;                                 \
    v = myrnd ();                                  \
    a = myrnd ();                                  \
    s##S.k = v;                                    \
    x = s##S;                                      \
    r = fn1##S (a);                                \
    if (x.i != s##S.i || x.j != s##S.j             \
        || x.k != s##S.k || x.l != s##S.l          \
        || ((v + a) & mask) != r)                  \
        abort ();                                  \
    v = myrnd ();                                  \
    a = myrnd ();                                  \
    s##S.k = v;                                    \
    x = s##S;                                      \
    r = fn2##S (a);                                \
    if (x.i != s##S.i || x.j != s##S.j             \
        || x.k != s##S.k || x.l != s##S.l          \
        || ((((v + a) & mask) % 15) & mask) != r)  \
        abort ();                                  \
    v = myrnd ();                                  \
    a = myrnd ();                                  \
    s##S.k = v;                                    \
    x = s##S;                                      \
    r = fn3##S (a);                                \
    if (x.i != s##S.i || x.j != s##S.j             \
        || s##S.k != r || x.l != s##S.l            \
        || ((v + a) & mask) != r)                  \
        abort ();                                  \
}

#define PACKED __attribute__((packed))
struct PACKED A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
struct PACKED B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; T(B)
struct PACKED C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; T(C)
struct PACKED D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct PACKED E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct PACKED F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)
struct PACKED G { unsigned short i : 1, j : 1, k : 6; unsigned long long l; }; T(G)
struct PACKED H { unsigned short i : 6, j : 2, k : 8; unsigned long long l; }; T(H)
struct PACKED I { unsigned short i : 1, j : 6, k : 1; unsigned long long l; }; T(I)
struct PACKED J { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; T(J)
struct PACKED K { unsigned int k : 6, l : 1, j : 10, i : 15; }; T(K)
struct PACKED L { unsigned int k : 6, j : 11, i : 15; unsigned int l; }; T(L)
struct PACKED M { unsigned int l; unsigned short k : 6, j : 11, i : 15; }; T(M)
struct PACKED N { unsigned long long l : 6, k : 6, j : 23, i : 29; }; T(N)
struct PACKED O { unsigned long long l, k : 12, j : 23, i : 29; }; T(O)
struct PACKED P { unsigned long long k : 12, j : 23, i : 29, l; }; T(P)
struct PACKED Q { unsigned short k : 12, j : 1, i : 3; unsigned long long l; }; T(Q)
struct PACKED R { unsigned short k : 2, j : 11, i : 3; unsigned long long l; }; T(R)
struct PACKED S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; T(S)
struct PACKED T { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(T)
struct PACKED U { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; T(U)
struct PACKED V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(V)
struct PACKED W { long double l; unsigned int k : 12, j : 13, i : 7; }; T(W)
struct PACKED X { unsigned int k : 12, j : 13, i : 7; long double l; }; T(X)
struct PACKED Y { unsigned int k : 12, j : 11, i : 9; long double l; }; T(Y)
struct PACKED Z { long double l; unsigned int j : 13, i : 7, k : 12; }; T(Z)

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