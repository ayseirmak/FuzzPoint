#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define T(S)                                    \
struct S s##S;                                  \
struct S retme##S(struct S x)                   \
{                                               \
    return x;                                   \
}                                               \
                                                \
unsigned int fn1##S(unsigned int x)             \
{                                               \
    struct S y = s##S;                          \
    y.k += x;                                   \
    y = retme##S(y);                            \
    return y.k;                                 \
}                                               \
                                                \
unsigned int fn2##S(unsigned int x)             \
{                                               \
    struct S y = s##S;                          \
    y.k += x;                                   \
    y.k %= 15;                                  \
    return y.k;                                 \
}                                               \
                                                \
unsigned int retit##S(void)                     \
{                                               \
    return s##S.k;                              \
}                                               \
                                                \
unsigned int fn3##S(unsigned int x)             \
{                                               \
    s##S.k += x;                                \
    return retit##S();                          \
}                                               \
                                                \
void test##S(void)                              \
{                                               \
    unsigned int mask, v = 100, a = 200, r;     \
    struct S x;                                 \
    char *p = (char *)&s##S;                    \
    for (int i = 0; i < sizeof(s##S); ++i)      \
        *p++ = 1;   /* Deterministic value */   \
    if (__builtin_classify_type(s##S.l) == 8)   \
        s##S.l = 5.25;                          \
    s##S.k = -1;                                \
    mask = s##S.k;                              \
    s##S.k = v;                                 \
    x = s##S;                                   \
    r = fn1##S(a);                              \
    assert(x.i == s##S.i && x.j == s##S.j       \
           && x.k == s##S.k && x.l == s##S.l    \
           && (((v + a) & mask) == r));         \
    v = 300; a = 400;                           \
    s##S.k = v;                                 \
    x = s##S;                                   \
    r = fn2##S(a);                              \
    assert(x.i == s##S.i && x.j == s##S.j       \
           && x.k == s##S.k && x.l == s##S.l    \
           && ((((v + a) & mask) % 15) & mask) == r); \
    v = 500; a = 600;                           \
    s##S.k = v;                                 \
    x = s##S;                                   \
    r = fn3##S(a);                              \
    assert(x.i == s##S.i && x.j == s##S.j       \
           && s##S.k == r && x.l == s##S.l      \
           && ((v + a) & mask) == r);           \
}

#define pck __attribute__((packed))

struct pck A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
struct pck B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; T(B)
struct pck C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; T(C)
struct pck D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
// Other structures omitted for brevity. Define similarly as needed.

int main(void)
{
    testA();
    testB();
    testC();
    testD();
    // Call other tests...
    return 0;
}