#include <stdio.h>  // For using printf
#include <assert.h> // For using assert

#define NUM_TESTS 26

// Mock random function with fixed sequence to make it deterministic
unsigned int fixed_myrnd(unsigned int index) {
    unsigned int fixed_values[8] = {42, 24, 65, 13, 86, 97, 57, 38};
    return fixed_values[index % 8];
}

#define T(S)                                \
struct S s##S = {0};                        \
unsigned int fn1##S(unsigned int x) {       \
    struct S y = s##S;                      \
    y.k += x;                               \
    return y.k;                             \
}                                           \
unsigned int fn2##S(unsigned int x) {       \
    struct S y = s##S;                      \
    y.k += x;                               \
    y.k %= 15;                              \
    return y.k;                             \
}                                           \
void test##S(void) {                        \
    unsigned int v, a, r;                   \
    unsigned int mask = s##S.k = -1;        \
    v = fixed_myrnd(0);                     \
    a = fixed_myrnd(1);                     \
    s##S.k = v;                             \
    r = fn1##S(a);                          \
    assert(((v + a) & mask) == r);          \
    v = fixed_myrnd(2);                     \
    a = fixed_myrnd(3);                     \
    s##S.k = v;                             \
    r = fn2##S(a);                          \
    assert((((v + a) & mask) % 15) == r);   \
}

struct A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
struct B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; T(B)
struct C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; T(C)
// You can redefine other structs as needed in a similar manner

int main(void) {
    testA();
    testB();
    testC();
    // Add calls to other test functions similarly
    printf("All tests passed!\n");
    return 0;
}