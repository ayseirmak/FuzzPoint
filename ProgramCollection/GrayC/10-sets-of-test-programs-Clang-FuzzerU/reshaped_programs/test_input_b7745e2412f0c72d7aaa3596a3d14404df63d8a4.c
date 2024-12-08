#include <stdio.h>
#include <stdlib.h>

// Define the macros for the test
#define DECLARE_STRUCT_AND_FUNCS(S)                   \
    struct S {                                        \
        unsigned int k : 12, j : 13, i : 7;           \
        long double l;                                \
    } s##S;                                           \
    struct S retme##S(struct S x) { return x; }       \
    unsigned int fn1##S(unsigned int x) {             \
        struct S y = s##S;                            \
        y.k += x;                                     \
        y = retme##S(y);                              \
        return y.k;                                   \
    }

#define RUN_TEST_CASE(S)                              \
    void test##S(void) {                              \
        int flag = 0;                                 \
        unsigned int a = 100, v = 200; /* Fixed values */ \
        unsigned int mask = -1, r;                    \
        struct S x;                                   \
        x = s##S;                                     \
        r = fn1##S(a);                                \
        if (x.i != s##S.i || x.j != s##S.j            \
            || x.k != s##S.k || x.l != s##S.l         \
            || ((v + a) & mask) != r) {               \
            flag = 1;                                 \
        }                                             \
        if (flag) {                                   \
            printf("Test %s failed\n", #S);           \
        } else {                                      \
            printf("Test %s passed\n", #S);           \
        }                                             \
    }

// Declaration of all structures and functions
DECLARE_STRUCT_AND_FUNCS(A)
DECLARE_STRUCT_AND_FUNCS(B)
DECLARE_STRUCT_AND_FUNCS(C)
DECLARE_STRUCT_AND_FUNCS(D)
DECLARE_STRUCT_AND_FUNCS(E)
DECLARE_STRUCT_AND_FUNCS(F)
DECLARE_STRUCT_AND_FUNCS(G)
DECLARE_STRUCT_AND_FUNCS(H)
DECLARE_STRUCT_AND_FUNCS(I)
DECLARE_STRUCT_AND_FUNCS(J)
DECLARE_STRUCT_AND_FUNCS(K)
DECLARE_STRUCT_AND_FUNCS(L)
DECLARE_STRUCT_AND_FUNCS(M)
DECLARE_STRUCT_AND_FUNCS(N)
DECLARE_STRUCT_AND_FUNCS(O)
DECLARE_STRUCT_AND_FUNCS(P)
DECLARE_STRUCT_AND_FUNCS(Q)
DECLARE_STRUCT_AND_FUNCS(R)
DECLARE_STRUCT_AND_FUNCS(S)
DECLARE_STRUCT_AND_FUNCS(T)
DECLARE_STRUCT_AND_FUNCS(U)
DECLARE_STRUCT_AND_FUNCS(V)
DECLARE_STRUCT_AND_FUNCS(W)
DECLARE_STRUCT_AND_FUNCS(X)
DECLARE_STRUCT_AND_FUNCS(Y)
DECLARE_STRUCT_AND_FUNCS(Z)

// Run all test cases
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