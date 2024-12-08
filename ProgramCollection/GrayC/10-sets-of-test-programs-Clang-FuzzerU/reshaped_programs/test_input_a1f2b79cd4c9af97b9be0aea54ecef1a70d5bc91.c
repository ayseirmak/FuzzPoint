#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MASK 0xFFF

// Replace myrnd with a fixed sequence of pseudo-random values
unsigned int fixedRndSequence[] = {
    1543, 1612, 1987, 1310, 1703,
    1839, 1754, 1463, 1652, 1921
};
int rndIndex = 0;

unsigned int myrnd(void) {
    unsigned int result = fixedRndSequence[rndIndex];
    rndIndex = (rndIndex + 1) % (sizeof(fixedRndSequence) / sizeof(fixedRndSequence[0]));
    return result;
}

#define T(S)                                                        \
struct S s##S;                                                      \
void fn1##S(unsigned int mask, unsigned int v, unsigned int a) {    \
    struct S x;                                                     \
    unsigned int r;                                                 \
    s##S.k = ((v + a) & mask) % 15;                                 \
    x = s##S;                                                       \
    r = (v + a) & mask;                                             \
    assert(x.i == s##S.i && x.j == s##S.j && x.k == s##S.k &&       \
           ((((v + a) & MASK) % 15) & MASK) == r);                  \
}                                                                   \
void fn2##S(unsigned int mask, unsigned int v, unsigned int a) {    \
    struct S x;                                                     \
    unsigned int r;                                                 \
    s##S.k = v;                                                     \
    x = s##S;                                                       \
    r = (v + a) & mask;                                             \
    assert(x.i == s##S.i && x.j == s##S.j && s##S.k == r);          \
}

// Define structs using packed attribute for exact layout
struct __attribute__((packed)) A {
    unsigned short i : 1, kl : 1, j : 3, k : 11;
};
struct __attribute__((packed)) B {
    unsigned short i : 4, j : 1, k : 11;
};
struct __attribute__((packed)) C {
    unsigned int k : 12, j : 13, i : 7;
    long double l;
};
// More struct definitions as necessary for the tests ...

// Implement your test functions
void testA(void) {
    unsigned int v = myrnd(), a = myrnd();
    fn1A(MASK, v, a);
    fn2A(MASK, v, a);
}

void testB(void) {
    unsigned int v = myrnd(), a = myrnd();
    fn1B(MASK, v, a);
    fn2B(MASK, v, a);
}

// Define more test functions...

int main(void) {
    testA();
    testB();
    // Call more test functions as necessary...
    exit(0);
}