#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

// Deterministic sequence instead of randomness
unsigned int get_fixed_myrnd_value(unsigned int index) {
    static const unsigned int fixed_values[] = {
        1000, 300, 500, 750, 980, 120, 340, 555, 675, 890
    };
    return fixed_values[index % (sizeof(fixed_values) / sizeof(fixed_values[0]))];
}

#define DEFINE_STRUCT_AND_FUNCTIONS(S)                           \
    struct S s##S;                                               \
    struct S retme##S(struct S x) { return x; }                  \
    unsigned int fn1##S(unsigned int x) {                        \
        struct S y = s##S;                                       \
        y.k += x;                                                \
        y = retme##S(y);                                         \
        return y.k;                                              \
    }                                                            \
    unsigned int fn2##S(unsigned int x) {                        \
        struct S y = s##S;                                       \
        y.k += x;                                                \
        y.k %= 15;                                               \
        return y.k;                                              \
    }                                                            \
    unsigned int retit##S(void) { return s##S.k; }               \
    unsigned int fn3##S(unsigned int x) {                        \
        s##S.k += x;                                             \
        return retit##S();                                       \
    }                                                            \
    void test##S(void) {                                         \
        unsigned int mask, v, a, r;                              \
        struct S x;                                              \
        s##S.k = -1;                                             \
        mask = s##S.k;                                           \
        v = get_fixed_myrnd_value(0);                            \
        a = get_fixed_myrnd_value(1);                            \
        s##S.k = v;                                              \
        x = s##S;                                                \
        r = fn1##S(a);                                           \
        assert(x.i == s##S.i && x.j == s##S.j                     \
            && x.k == s##S.k && x.l == s##S.l                    \
            && (((v + a) & mask) == r));                         \
        v = get_fixed_myrnd_value(2);                            \
        a = get_fixed_myrnd_value(3);                            \
        s##S.k = v;                                              \
        x = s##S;                                                \
        r = fn2##S(a);                                           \
        assert(x.i == s##S.i && x.j == s##S.j                     \
            && x.k == s##S.k && x.l == s##S.l                    \
            && (((v + a) & mask) % 15 & mask) == r);             \
        v = get_fixed_myrnd_value(4);                            \
        a = get_fixed_myrnd_value(5);                            \
        s##S.k = v;                                              \
        x = s##S;                                                \
        r = fn3##S(a);                                           \
        assert(x.i == s##S.i && x.j == s##S.j                    \
            && s##S.k == r && x.l == s##S.l                      \
            && (((v + a) & mask) == r));                         \
    }

#define PACKED __attribute__((packed))

struct PACKED A { unsigned short i : 1, l : 1, j : 3, k : 11; }; DEFINE_STRUCT_AND_FUNCTIONS(A)
struct PACKED B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; DEFINE_STRUCT_AND_FUNCTIONS(B)
struct PACKED C { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; DEFINE_STRUCT_AND_FUNCTIONS(C)
struct PACKED D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; DEFINE_STRUCT_AND_FUNCTIONS(D)
struct PACKED E { unsigned long long l, i : 12, j : 23, k : 29; }; DEFINE_STRUCT_AND_FUNCTIONS(E)
struct PACKED F { unsigned long long i : 12, j : 23, k : 29, l; }; DEFINE_STRUCT_AND_FUNCTIONS(F)
struct PACKED G { unsigned short i : 1, j : 1, k : 6; unsigned long long l; }; DEFINE_STRUCT_AND_FUNCTIONS(G)
struct PACKED H { unsigned short i : 6, j : 2, k : 8; unsigned long long l; }; DEFINE_STRUCT_AND_FUNCTIONS(H)
struct PACKED I { unsigned short i : 1, j : 6, k : 1; unsigned long long l; }; DEFINE_STRUCT_AND_FUNCTIONS(I)
struct PACKED J { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; DEFINE_STRUCT_AND_FUNCTIONS(J)
struct PACKED K { unsigned int k : 6, l : 1, j : 10, i : 15; }; DEFINE_STRUCT_AND_FUNCTIONS(K)
struct PACKED L { unsigned int k : 6, j : 11, i : 15; unsigned int l; }; DEFINE_STRUCT_AND_FUNCTIONS(L)
struct PACKED M { unsigned int l; unsigned short k : 6, j : 11, i : 15; }; DEFINE_STRUCT_AND_FUNCTIONS(M)
struct PACKED N { unsigned long long l : 6, k : 6, j : 23, i : 29; }; DEFINE_STRUCT_AND_FUNCTIONS(N)
struct PACKED O { unsigned long long l, k : 12, j : 23, i : 29; }; DEFINE_STRUCT_AND_FUNCTIONS(O)
struct PACKED P { unsigned long long k : 12, j : 23, i : 29, l; }; DEFINE_STRUCT_AND_FUNCTIONS(P)
struct PACKED Q { unsigned short k : 12, j : 1, i : 3; unsigned long long l; }; DEFINE_STRUCT_AND_FUNCTIONS(Q)
struct PACKED R { unsigned short k : 2, j : 11, i : 3; unsigned long long l; }; DEFINE_STRUCT_AND_FUNCTIONS(R)
struct PACKED S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; DEFINE_STRUCT_AND_FUNCTIONS(S)
struct PACKED T { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; DEFINE_STRUCT_AND_FUNCTIONS(T)
struct PACKED U { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; DEFINE_STRUCT_AND_FUNCTIONS(U)
struct PACKED V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; DEFINE_STRUCT_AND_FUNCTIONS(V)
struct PACKED W { long double l; unsigned int k : 12, j : 13, i : 7; }; DEFINE_STRUCT_AND_FUNCTIONS(W)
struct PACKED X { unsigned int k : 12, j : 13, i : 7; long double l; }; DEFINE_STRUCT_AND_FUNCTIONS(X)
struct PACKED Y { unsigned int k : 12, j : 11, i : 9; long double l; }; DEFINE_STRUCT_AND_FUNCTIONS(Y)
struct PACKED Z { long double l; unsigned int j : 13, i : 7, k : 12; }; DEFINE_STRUCT_AND_FUNCTIONS(Z)

int main(void) {
    testA();
    testB();
    testC();
    testD();
    testE();
    testF();
    testG();
    testH();
    testI();
    testJ();
    testK();
    testL();
    testM();
    testN();
    testO();
    testP();
    testQ();
    testR();
    testS();
    testT();
    testU();
    testV();
    testW();
    testX();
    testY();
    testZ();
    return 0;
}