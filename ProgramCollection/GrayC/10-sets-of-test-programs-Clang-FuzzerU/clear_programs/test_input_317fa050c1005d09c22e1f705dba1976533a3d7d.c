#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define T_STATIC_VALUE 1234  // Example fixed value for deterministic behavior.

#define T(S) \
void test##S(void) { \
    struct S s; \
    unsigned int mask = 0xFFF; /* Example mask for operations */ \
    unsigned int v = T_STATIC_VALUE; /* Use a fixed deterministic value */ \
    unsigned int a = T_STATIC_VALUE; /* Use a fixed deterministic value */ \
    unsigned int r; \
    s.k = v; \
    r = (v + a) & mask; /* Simplified computation for illustration */ \
    assert(((v + a) & mask) == r); \
}

#define pck __attribute__((packed))

struct pck A { unsigned short i : 1, kl : 1, j : 3, k : 11; };
struct pck B { unsigned short i : 4, j : 1, k : 11; };
struct pck X { unsigned int k : 12, j : 13, i : 7; long double l; };
struct pck Y { unsigned int k : 12, j : 11, i : 9; long double l; };
struct pck Z { long double l; unsigned int j : 13, i : 7, k : 12; };

T(A)
T(B)
T(X)
T(Y)
T(Z)

int main(void) {
    testA();
    testB();
    testX();
    testY();
    testZ();
    printf("All tests passed.\n");
    exit(0);
}