#include <stdio.h>
#include <stdlib.h>

/* Replacement for myrnd(), providing deterministic values. */
unsigned int deterministic_rnd(int index) {
    static unsigned int values[] = {
        1000, 2000, 3000, 1400, 500, 600, 3200, 800, 900, 100, 
        1100, 1200, 1300, 4000, 4100, 5200, 6200, 7200, 8200
    };
    return values[index % (sizeof(values) / sizeof(values[0]))];
}

/* Macro for bitfield arithmetic and function templates. */
#define T(S) \
struct S s##S; \
struct S retme##S (struct S x) { return x; } \
unsigned int fn1##S (unsigned int x) { \
    struct S y = s##S; y.k += x; y = retme##S(y); return y.k; \
} \
unsigned int fn2##S (unsigned int x) { \
    struct S y = s##S; y.k += x; y.k %= 15; return y.k; \
} \
unsigned int retit##S (void) { return s##S.k; } \
unsigned int fn3##S (unsigned int x) { \
    s##S.k += x; return retit##S(); \
} \
void test##S (void) { \
    int i; \
    unsigned int mask, v, a, r; \
    struct S x; \
    char *p = (char *) &s##S; \
    for (i = 0; i < sizeof(s##S); ++i) \
        *p++ = predictable_rnd(i); \
    if (__builtin_classify_type(s##S.l) == 8) \
        s##S.l = 5.25; \
    s##S.k = -1; \
    mask = s##S.k; \
    v = deterministic_rnd(i); \
    a = deterministic_rnd(i + 1); \
    s##S.k = v; \
    x = s##S; \
    r = fn1##S(a); \
    if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((v + a) & mask) != r) \
        abort(); \
    v = deterministic_rnd(i + 2); \
    a = deterministic_rnd(i + 3); \
    s##S.k = v; \
    x = s##S; \
    r = fn2##S(a); \
    if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((((v + a) & mask) % 15) & mask) != r) \
        abort(); \
    v = deterministic_rnd(i + 4); \
    a = deterministic_rnd(i + 5); \
    s##S.k = v; \
    x = s##S; \
    r = fn3##S(a); \
    if (x.i != s##S.i || x.j != s##S.j || s##S.k != r || x.l != s##S.l || ((v + a) & mask) != r) \
        abort(); \
}

/* Definitions of bitfield structures. */
#define pck __attribute__((packed))
struct pck A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
struct pck B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; T(B)
// ... Other struct definitions are similar ...

int main(void) {
    testA();
    testB();
    // Add calls to other test functions for other structures.
    exit(0);
}