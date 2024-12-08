#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Function to replace "myrnd" with a fixed value generator for deterministic behavior
unsigned int get_fixed_value(void) {
    static unsigned int fixed_value = 0;
    return fixed_value++;
}

// Macro to define a test with structures
#define T(S)                                   \
    struct S s##S;                             \
    struct S retme##S(struct S x)              \
    {                                          \
        return x;                              \
    }                                          \
                                                \
    unsigned int fn1##S(unsigned int x)        \
    {                                          \
        struct S y = s##S;                     \
        y.k += x;                              \
        y = retme##S(y);                       \
        return y.k;                            \
    }                                          \
                                                \
    unsigned int fn2##S(unsigned int x)        \
    {                                          \
        struct S y = s##S;                     \
        y.k += x;                              \
        y.k %= 15;                             \
        return y.k;                            \
    }                                          \
                                                \
    unsigned int retit##S(void)                \
    {                                          \
        return s##S.k;                         \
    }                                          \
                                                \
    unsigned int fn3##S(unsigned int x)        \
    {                                          \
        s##S.k += x;                           \
        return retit##S();                     \
    }                                          \
                                                \
    void test##S(void)                         \
    {                                          \
        unsigned int mask, v, a, r;            \
        struct S x;                            \
        char *p = (char *)&s##S;               \
        for (int i = 0; i < sizeof(s##S); ++i) \
            *p++ = get_fixed_value();          \
        if (__builtin_classify_type(s##S.l) == 8) \
            s##S.l = 5.25;                     \
        s##S.k = -1;                           \
        mask = s##S.k;                         \
        v = get_fixed_value();                 \
        a = get_fixed_value();                 \
        s##S.k = v;                            \
        x = s##S;                              \
        r = fn1##S(a);                         \
        assert((x.i == s##S.i && x.j == s##S.j && x.k == s##S.k && x.l == s##S.l && ((v + a) & mask) == r));\
        v = get_fixed_value();                 \
        a = get_fixed_value();                 \
        s##S.k = v;                            \
        x = s##S;                              \
        r = fn2##S(a);                         \
        assert((x.i == s##S.i && x.j == s##S.j && x.k == s##S.k && x.l == s##S.l && ((((v + a) & mask) % 15) & mask) == r));\
        v = get_fixed_value();                 \
        a = get_fixed_value();                 \
        s##S.k = v;                            \
        x = s##S;                              \
        r = fn3##S(a);                         \
        assert((x.i == s##S.i && x.j == s##S.j && s##S.k == r && x.l == s##S.l && ((v + a) & mask) == r));\
    }

// Define structures
struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B)
struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; }; T(C)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
struct E { unsigned long long l, i : 12, j : 23, k : 29; }; T(E)
struct F { unsigned long long i : 12, j : 23, k : 29, l; }; T(F)

// Main function, tests all defined structures
int main(void) {
    testA();
    testB();
    testC();
    testD();
    testE();
    testF();

    // Add as many calls to test functions as you defined structures (A-Z in original, here limited for brevity)
  
    printf("All tests passed.\n");
    exit(0);
}