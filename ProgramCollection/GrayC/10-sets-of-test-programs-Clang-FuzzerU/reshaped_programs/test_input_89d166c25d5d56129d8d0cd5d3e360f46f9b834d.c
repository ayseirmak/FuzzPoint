// Test arithmetics on bitfields (deterministic version for ARM architecture)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Functions to simulate specific arithmetic operations on structures with bitfields

#define DEFINE_STRUCT_AND_FUNCTIONS(S) \
    struct S s##S; \
    struct S retme##S (struct S x) \
    { \
        return x; \
    } \
    unsigned int fn1##S (unsigned int x) \
    { \
        struct S y = s##S; \
        y.k += x; \
        y = retme##S (y); \
        return y.k; \
    } \
    unsigned int fn2##S (unsigned int x) \
    { \
        struct S y = s##S; \
        y.k += x; \
        y.k %= 15; \
        return y.k; \
    } \
    unsigned int retit##S (void) \
    { \
        return s##S.k; \
    } \
    unsigned int fn3##S (unsigned int x) \
    { \
        s##S.k += x; \
        return retit##S (); \
    } \
    void test##S (void) \
    { \
        unsigned int mask, v, a, r; \
        struct S x; \
        for (int i = 0; i < sizeof(s##S); ++i) \
            *((unsigned char*) &s##S + i) = 0; \
        s##S.l = 5; /* Initialize for deterministic behavior */ \
        s##S.k = -1; \
        mask = s##S.k; \
        v = 1027; /* Fixed value instead of random */ \
        a = 258;  /* Fixed value instead of random */ \
        s##S.k = v; \
        x = s##S; \
        r = fn1##S (a); \
        assert((x.i == s##S.i) && (x.j == s##S.j) && (x.k == s##S.k) && (x.l == s##S.l) && (((v + a) & mask) == r)); \
        v = 532;  /* Fixed value instead of random */ \
        a = 105;  /* Fixed value instead of random */ \
        s##S.k = v; \
        x = s##S; \
        r = fn2##S (a); \
        assert((x.i == s##S.i) && (x.j == s##S.j) && (x.k == s##S.k) && (x.l == s##S.l) && ((((v + a) & mask) % 15) & mask) == r); \
        v = 891;  /* Fixed value instead of random */ \
        a = 147;  /* Fixed value instead of random */ \
        s##S.k = v; \
        x = s##S; \
        r = fn3##S (a); \
        assert((x.i == s##S.i) && (x.j == s##S.j) && (s##S.k == r) && (x.l == s##S.l) && (((v + a) & mask) == r)); \
    }

// Simulate the packed structures and their tests
#define pck __attribute__((packed))
struct pck A { unsigned short i : 1, l : 1, j : 3, k : 11; }; DEFINE_STRUCT_AND_FUNCTIONS(A)
struct pck B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; DEFINE_STRUCT_AND_FUNCTIONS(B)
struct pck C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; DEFINE_STRUCT_AND_FUNCTIONS(C)
struct pck D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; DEFINE_STRUCT_AND_FUNCTIONS(D)
// ... Continue definition for all structs as in the original example ...

int main(void) {
    testA();
    testB();
    testC();
    testD();
    // Call tests for all other structs as defined...
    printf("All tests passed!\n");
    return 0;
}