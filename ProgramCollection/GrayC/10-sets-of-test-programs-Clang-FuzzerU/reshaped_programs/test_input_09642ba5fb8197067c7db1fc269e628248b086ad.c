#include <stdio.h>
#include <stdlib.h>

unsigned int myrnd(void) {
    static unsigned int s = 1388815473;
    s *= 1103515245;
    s += 12345;
    return (s / 65536) % 2048;
}

#define TEST_STRUCT(S) \
    struct S s##S = {0}; \
    struct S retme##S(struct S x) { \
        return x; \
    } \
    unsigned int fn1##S(unsigned int x) { \
        struct S y = s##S; \
        y.k += x; \
        y = retme##S(y); \
        return y.k; \
    } \
    unsigned int fn2##S(unsigned int x) { \
        struct S y = s##S; \
        y.k += x; \
        y.k %= 15; \
        return y.k; \
    } \
    unsigned int retit##S(void) { \
        return s##S.k; \
    } \
    unsigned int fn3##S(unsigned int x) { \
        s##S.k += x; \
        return retit##S(); \
    } \
    void test##S(void) { \
        unsigned int a = 10; /* Fixed value for deterministic inputs */ \
        unsigned int v = 5;  /* Fixed value for deterministic inputs */ \
        unsigned int mask = 0xFFFFFFFF; \
        struct S x = s##S; \
        s##S.k = v; \
        x = s##S; \
        unsigned int r = fn2##S(a); \
        if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((((v + a) & mask) % 15) & mask) != r) \
            abort(); \
        r = fn3##S(a); \
        if (x.i != s##S.i || x.j != s##S.j || s##S.k != r || x.l != s##S.l || ((v + a) & mask) != r) \
            abort(); \
    }

struct __attribute__((packed)) A { unsigned short i : 1, l : 1, j : 3, k : 11; }; TEST_STRUCT(A)
struct __attribute__((packed)) B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; TEST_STRUCT(B)
struct __attribute__((packed)) C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; TEST_STRUCT(C)
struct __attribute__((packed)) D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; TEST_STRUCT(D)
struct __attribute__((packed)) E { unsigned long long l, i : 12, j : 23, k : 29; }; TEST_STRUCT(E)
struct __attribute__((packed)) F { unsigned long long i : 12, j : 23, k : 29, l; }; TEST_STRUCT(F)
struct __attribute__((packed)) G { unsigned short i : 1, j : 1, k : 6; unsigned long long l; }; TEST_STRUCT(G)
struct __attribute__((packed)) H { unsigned short i : 6, j : 2, k : 8; unsigned long long l; }; TEST_STRUCT(H)
struct __attribute__((packed)) I { unsigned short i : 1, j : 6, k : 1; unsigned long long l; }; TEST_STRUCT(I)
struct __attribute__((packed)) J { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; TEST_STRUCT(J)
struct __attribute__((packed)) K { unsigned int k : 6, l : 1, j : 10, i : 15; }; TEST_STRUCT(K)
struct __attribute__((packed)) L { unsigned int k : 6, j : 11, i : 15; unsigned int l; }; TEST_STRUCT(L)
struct __attribute__((packed)) M { unsigned int l; unsigned short k : 6, j : 11, i : 15; }; TEST_STRUCT(M)
struct __attribute__((packed)) N { unsigned long long l : 6, k : 6, j : 23, i : 29; }; TEST_STRUCT(N)
struct __attribute__((packed)) O { unsigned long long l, k : 12, j : 23, i : 29; }; TEST_STRUCT(O)
struct __attribute__((packed)) P { unsigned long long k : 12, j : 23, i : 29, l; }; TEST_STRUCT(P)
struct __attribute__((packed)) Q { unsigned short k : 12, j : 1, i : 3; unsigned long long l; }; TEST_STRUCT(Q)
struct __attribute__((packed)) R { unsigned short k : 2, j : 11, i : 3; unsigned long long l; }; TEST_STRUCT(R)
struct __attribute__((packed)) S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; TEST_STRUCT(S)
struct __attribute__((packed)) T { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; TEST_STRUCT(T)
struct __attribute__((packed)) U { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; TEST_STRUCT(U)
struct __attribute__((packed)) V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; TEST_STRUCT(V)
struct __attribute__((packed)) W { long double l; unsigned int k : 12, j : 13, i : 7; }; TEST_STRUCT(W)
struct __attribute__((packed)) X { unsigned int k : 12, j : 13, i : 7; long double l; }; TEST_STRUCT(X)
struct __attribute__((packed)) Y { unsigned int k : 12, j : 11, i : 9; long double l; }; TEST_STRUCT(Y)
struct __attribute__((packed)) Z { long double l; unsigned int j : 13, i : 7, k : 12; }; TEST_STRUCT(Z)

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
    exit(0);
}