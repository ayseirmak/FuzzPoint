#include <stdio.h>
#include <stdlib.h>

// Abort and Exit functions are typically used for program control, and we keep them.
extern void abort(void);
extern void exit(int);

typedef struct S {
    unsigned short i : 1;
    unsigned short l : 1;
    unsigned short j : 3;
    unsigned short k : 11;
} S;

// Fixed deterministic value for testing.
unsigned int fixed_myrnd = 1000; 

unsigned int myrnd(void) {
    return fixed_myrnd; // Always return a fixed value for predictable behavior
}

#define T(S)                                \
    struct S s##S;                          \
    struct S retme##S(struct S x) {         \
        return x;                           \
    }                                       \
    unsigned int fn1##S(unsigned int x) {   \
        struct S y = s##S;                  \
        y.k += x;                           \
        y = retme##S(y);                    \
        return y.k;                         \
    }                                       \
    unsigned int fn2##S(unsigned int x) {   \
        struct S y = s##S;                  \
        y.k += x;                           \
        y.k %= 15;                          \
        return y.k;                         \
    }                                       \
    unsigned int retit##S(void) {           \
        return s##S.k;                      \
    }                                       \
    unsigned int fn3##S(unsigned int x) {   \
        s##S.k += x;                        \
        return retit##S();                  \
    }                                       \
    void test##S(void) {                    \
        int i;                              \
        unsigned int mask, v, a, r;         \
        struct S x;                         \
        char *p = (char *)&s##S;            \
        for (i = 0; i < sizeof(s##S); ++i)  \
            *p++ = myrnd();                 \
        if (__builtin_classify_type(s##S.l) == 8) \
            s##S.l = 5.25;                  \
        s##S.k = -1;                        \
        mask = s##S.k;                      \
        v = myrnd();                        \
        a = myrnd();                        \
        s##S.k = v;                         \
        x = s##S;                           \
        r = fn1##S(a);                      \
        if (x.i != s##S.i || x.j != s##S.j \
            || x.k != s##S.k || x.l != s##S.l \
            || ((v + a) & mask) != r)       \
            abort();                        \
        v = myrnd();                        \
        a = myrnd();                        \
        s##S.k = v;                         \
        x = s##S;                           \
        r = fn2##S(a);                      \
        if (x.i != s##S.i || x.j != s##S.j \
            || x.k != s##S.k || x.l != s##S.l \
            || ((((v + a) & mask) % 15) & mask) != r) \
            abort();                        \
        v = myrnd();                        \
        a = myrnd();                        \
        s##S.k = v;                         \
        x = s##S;                           \
        r = fn3##S(a);                      \
        if (x.i != s##S.i || x.j != s##S.j \
            || s##S.k != r || x.l != s##S.l \
            || ((v + a) & mask) != r)       \
            abort();                        \
    }

struct A T(A)
struct B T(B)
struct C T(C)
struct D T(D)

int main(void) {
    testA();
    testB();
    testC();
    testD();
    exit(0);
}