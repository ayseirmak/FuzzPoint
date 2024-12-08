#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TEST_STRUCT(S)                                   \
    struct S s##S;                                       \
    struct S retme##S(struct S x) { return x; }          \
    unsigned int fn1##S(unsigned int x) {                \
        struct S y = s##S;                               \
        y.k += x;                                        \
        y = retme##S(y);                                 \
        return y.k;                                      \
    }                                                    \
    unsigned int fn2##S(unsigned int x) {                \
        struct S y = s##S;                               \
        y.k += x;                                        \
        y.k %= 15;                                       \
        return y.k;                                      \
    }                                                    \
    unsigned int retit##S(void) { return s##S.k; }       \
    unsigned int fn3##S(unsigned int x) {                \
        s##S.k += x;                                     \
        return retit##S();                               \
    }                                                    \
    void test##S(void) {                                 \
        unsigned int mask, v, a, r;                      \
        struct S x;                                      \
        mask = 0xFFFFFFFF;                               \
        v = 123;                                         \
        a = 456;                                         \
        s##S.k = v;                                      \
        x = s##S;                                        \
        r = fn1##S(a);                                   \
        assert(x.i == s##S.i && x.j == s##S.j && x.k == s##S.k && x.l == s##S.l && ((v + a) & mask) == r); \
        v = 789;                                         \
        a = 101;                                         \
        s##S.k = v;                                      \
        x = s##S;                                        \
        r = fn2##S(a);                                   \
        assert(x.i == s##S.i && x.j == s##S.j && x.k == s##S.k && x.l == s##S.l && ((((v + a) & mask) % 15) & mask) == r); \
        v = 202;                                         \
        a = 303;                                         \
        s##S.k = v;                                      \
        x = s##S;                                        \
        r = fn3##S(a);                                   \
        assert(x.i == s##S.i && x.j == s##S.j && s##S.k == r && x.l == s##S.l && ((v + a) & mask) == r); \
    }

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; TEST_STRUCT(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; TEST_STRUCT(B)
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; TEST_STRUCT(C)
// Similar structures and TEST_STRUCT invocations need to continue for D, E, F...

int main(void) {
    testA();
    testB();
    testC();
    // Continue testing for other structures...
    printf("All tests passed.\n");
    return 0;
}