#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* Function to initialize deterministic pseudo-random sequence */
unsigned int myrnd_deterministic(void) {
  static unsigned int values[] = {101, 732, 321, 987, 555, 213, 174, 234}; // Predefined fixed values
  static int index = 0;
  return values[index++ % 8];
}

/* Define structures with bitfields. */
#define T(S)                                   \
    struct S s##S;                             \
    struct S retme##S(struct S x) {            \
        return x;                              \
    }                                          \
    unsigned int fn1##S(unsigned int x) {      \
        struct S y = s##S;                     \
        y.k += x;                              \
        y = retme##S(y);                       \
        return y.k;                            \
    }                                          \
    unsigned int fn2##S(unsigned int x) {      \
        struct S y = s##S;                     \
        y.k += x;                              \
        y.k %= 15;                             \
        return y.k;                            \
    }                                          \
    unsigned int retit##S(void) {              \
        return s##S.k;                         \
    }                                          \
    unsigned int fn3##S(unsigned int x) {      \
        s##S.k += x;                           \
        return retit##S();                     \
    }                                          \
    void test##S(void) {                       \
        int i;                                 \
        unsigned int mask, v, a, r;            \
        struct S x;                            \
        char *p = (char *) &s##S;              \
        for (i = 0; i < sizeof(s##S); ++i)     \
            *p++ = (char)myrnd_deterministic();\
        s##S.k = (unsigned int)-1;             \
        mask = s##S.k;                         \
        v = myrnd_deterministic();             \
        a = myrnd_deterministic();             \
        s##S.k = v;                            \
        x = s##S;                              \
        r = fn1##S(a);                         \
        if (x.i != s##S.i || x.j != s##S.j     \
            || x.k != s##S.k || x.l != s##S.l  \
            || ((v + a) & mask) != r) {        \
            printf("Test failed in " #S "\n"); \
            abort();                           \
        }                                      \
    }

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B)
/* Repeat the structure and macro pattern for other structs as needed */
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; T(C)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)

// Define more structs following the pattern as needed...

int main(void) {
    testA();
    testB();
    testC();
    testD();
    // Call more test functions following the pattern as needed...
    printf("All tests passed.\n");
    return 0;
}