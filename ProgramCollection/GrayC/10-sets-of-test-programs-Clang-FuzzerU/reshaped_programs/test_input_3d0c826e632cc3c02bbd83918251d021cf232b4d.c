#include <stdio.h>
#include <stdlib.h>

// Defined structs with packed attribute and fixed bit-length fields
struct __attribute__((packed)) V { 
    unsigned short j : 8;
    unsigned short k : 1;
    unsigned short i : 7;
    unsigned short l; 
};

struct __attribute__((packed)) W { 
    long double l;
    unsigned int k : 12;
    unsigned int j : 13;
    unsigned int i : 7; 
};

struct __attribute__((packed)) X { 
    unsigned int k : 12;
    unsigned int j : 13;
    unsigned int i : 7;
    long double l; 
};

struct __attribute__((packed)) Y { 
    unsigned int k : 12;
    unsigned int j : 11;
    unsigned int i : 9;
    long double l; 
};

struct __attribute__((packed)) Z { 
    long double l;
    unsigned int j : 13;
    unsigned int i : 7;
    unsigned int k : 12; 
};

// Fixed seed value
static unsigned int fixed_rnd_value = 1234;

// Replacing original myrnd() function with deterministic behavior
unsigned int myrnd(void) {
    return fixed_rnd_value++;
}

// Macros to define struct instances and functions for test logic
#define T(S)                                             \
struct S s##S;                                           \
                                                         \
struct S retme##S(struct S x) {                          \
    return x;                                            \
}                                                        \
                                                         \
unsigned int fn1##S(unsigned int x) {                    \
    struct S y = s##S;                                   \
    y.k += x;                                            \
    y = retme##S(y);                                     \
    return y.k;                                          \
}                                                        \
                                                         \
unsigned int fn2##S(unsigned int x) {                    \
    struct S y = s##S;                                   \
    y.k += x;                                            \
    y.k %= 15;                                           \
    return y.k;                                          \
}                                                        \
                                                         \
unsigned int retit##S(void) {                            \
    return s##S.k;                                       \
}                                                        \
                                                         \
unsigned int fn3##S(unsigned int x) {                    \
    s##S.k += x;                                         \
    return retit##S();                                   \
}                                                        \
                                                         \
void test##S(void) {                                     \
    int i;                                               \
    unsigned int mask, v, a, r;                          \
    struct S x;                                          \
    char *p = (char *)&s##S;                             \
    for (i = 0; i < sizeof(s##S); ++i)                   \
        *p++ = myrnd();                                  \
    if (__builtin_classify_type(s##S.l) == 8)            \
        s##S.l = 5.25;                                   \
    s##S.k = -1;                                         \
    mask = s##S.k;                                       \
    v = myrnd();                                         \
    a = myrnd();                                         \
    s##S.k = v;                                          \
    x = s##S;                                            \
    r = fn1##S(a);                                       \
    if (x.i != s##S.i || x.j != s##S.j                  \
        || x.k != s##S.k || x.l != s##S.l               \
        || ((v + a) & mask) != r) {                      \
        printf("Error in test function %s\n", #S);       \
        abort();                                         \
    }                                                    \
    v = myrnd();                                         \
    a = myrnd();                                         \
    s##S.k = v;                                          \
    x = s##S;                                            \
    r = fn2##S(a);                                       \
    if (x.i != s##S.i || x.j != s##S.j                  \
        || x.k != s##S.k || x.l != s##S.l               \
        || ((((v + a) & mask) % 15) & mask) != r) {     \
        printf("Error in test function %s\n", #S);       \
        abort();                                         \
    }                                                    \
    v = myrnd();                                         \
    a = myrnd();                                         \
    s##S.k = v;                                          \
    x = s##S;                                            \
    r = fn3##S(a);                                       \
    if (x.i != s##S.i || x.j != s##S.j                  \
        || s##S.k != r || x.l != s##S.l                 \
        || ((v + a) & mask) != r) {                     \
        printf("Error in test function %s\n", #S);       \
        abort();                                         \
    }                                                    \
}

// Apply macros to create test functions
T(V)
T(W)
T(X)
T(Y)
T(Z)

int main(void) {
    testV();
    testW();
    testX();
    testY();
    testZ();
    printf("All tests passed.\n");
    return 0;
}