#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned int myrnd(void) {
    static unsigned int s = 1388815473;
    s *= 1103515245;
    s += 12345;
    return (s / 65536) % 2048;
}

#define T(S) \
struct S s##S; \
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
    unsigned int mask, v, a, r; \
    struct S x; \
    char *p = (char *)&s##S; \
    for (int i = 0; i < sizeof(s##S); ++i) { \
        *p++ = (char) myrnd(); \
    } \
    if (__builtin_classify_type(s##S.l) == 8) { \
        s##S.l = 5.25; \
    } \
    s##S.k = -1; \
    mask = s##S.k; \
    v = myrnd(); \
    a = myrnd(); \
    s##S.k = v; \
    x = s##S; \
    r = fn1##S(a); \
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
    exit(0);
}