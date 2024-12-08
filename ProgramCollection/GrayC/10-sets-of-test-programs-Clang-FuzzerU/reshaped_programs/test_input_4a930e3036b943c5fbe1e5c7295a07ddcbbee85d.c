#include <stdio.h>
#include <stdlib.h>

// Initialization of static variable for deterministic behavior
unsigned int deterministicSeq(unsigned int seed) {
    seed *= 1103515245;
    seed += 12345;
    return (seed / 65536) % 2048;
}

// Macro to define structures and associated functions
#define T(S) \
struct S s##S; \
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
    int i; \
    unsigned int mask, v, a, r; \
    struct S x; \
    char *p = (char *) &s##S; \
    unsigned int seed = 1388815473; \
    for (i = 0; i < sizeof(s##S); ++i) { \
        *p++ = (char) deterministicSeq(seed); \
        seed += 1; \
    } \
    s##S.k = (unsigned int) -1; \
    mask = s##S.k; \
    v = deterministicSeq(seed); seed += 1; \
    a = deterministicSeq(seed); seed += 1; \
    s##S.k = v; \
    x = s##S; \
    r = fn1##S(a); \
    if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || \
        ((v + a) & mask) != r) { \
        abort(); \
    } \
    v = deterministicSeq(seed); seed += 1; \
    a = deterministicSeq(seed); seed += 1; \
    s##S.k = v; \
    x = s##S; \
    r = fn2##S(a); \
    if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || \
        ((((v + a) & mask) % 15) & mask) != r) { \
        abort(); \
    } \
    v = deterministicSeq(seed); seed += 1; \
    a = deterministicSeq(seed); seed += 1; \
    s##S.k = v; \
    x = s##S; \
    r = fn3##S(a); \
    if (x.i != s##S.i || x.j != s##S.j || s##S.k != r || \
        x.l != s##S.l || ((v + a) & mask) != r) { \
        abort(); \
    } \
}

#define pck __attribute__((packed))

// Structures definitions
struct pck A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
struct pck B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; T(B)
struct pck C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; T(C)
struct pck D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct pck E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct pck F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)
struct pck G { unsigned short i : 1, j : 1, k : 6; unsigned long long l; }; T(G)
struct pck H { unsigned short i : 6, j : 2, k : 8; unsigned long long l; }; T(H)
struct pck I { unsigned short i : 1, j : 6, k : 1; unsigned long long l; }; T(I)
struct pck J { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; T(J)
struct pck K { unsigned int k : 6, l : 1, j : 10, i : 15; }; T(K)
struct pck L { unsigned int k : 6, j : 11, i : 1; unsigned int l : 13, m : 7; }; T(L)
struct pck M { unsigned int k : 12, j : 13, i : 7; long double l; }; T(M)
struct pck N { unsigned int k : 12, j : 11, i : 9; long double l; }; T(N)
struct pck O { long double l; unsigned int j : 13, i : 7, k : 12; }; T(O)

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
    printf("All tests passed.\n");
    exit(0);
}