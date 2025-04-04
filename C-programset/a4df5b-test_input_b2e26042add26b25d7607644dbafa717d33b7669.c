#include <stdio.h>
#include <stdlib.h>

/* Test arithmetics on bitfields. */

#define DEFINE_STRUCT_AND_FUNCTIONS(NAME, K_WIDTH, J_WIDTH, I_WIDTH, L_TYPE) \
    struct NAME { \
        unsigned int k : K_WIDTH, j : J_WIDTH, i : I_WIDTH; L_TYPE l; \
    }; \
    struct NAME s##NAME; \
    struct NAME retme##NAME(struct NAME x) { \
        return x; \
    } \
    unsigned int fn1##NAME(unsigned int x) { \
        struct NAME y = s##NAME; \
        y.k += x; \
        y = retme##NAME(y); \
        return y.k; \
    } \
    unsigned int fn2##NAME(unsigned int x) { \
        struct NAME y = s##NAME; \
        y.k += x; \
        y.k %= 15; \
        return y.k; \
    } \
    unsigned int retit##NAME(void) { \
        return s##NAME.k; \
    } \
    unsigned int fn3##NAME(unsigned int x) { \
        s##NAME.k += x; \
        return retit##NAME(); \
    } \
    void test##NAME(void) { \
        for (int i = 0; i < 10; i++) { \
            unsigned int val = (i + 1) * 10; \
            printf("Test %s with increment %u: %u\n", #NAME, val, fn3##NAME(val)); \
        } \
    }

/* Define structures and associated functions */
DEFINE_STRUCT_AND_FUNCTIONS(O, 12, 23, 29, unsigned long long)
DEFINE_STRUCT_AND_FUNCTIONS(P, 12, 13, 7, unsigned long long)
DEFINE_STRUCT_AND_FUNCTIONS(Q, 13, 11, 9, unsigned long long)
DEFINE_STRUCT_AND_FUNCTIONS(R, 12, 11, 9, unsigned long long)
DEFINE_STRUCT_AND_FUNCTIONS(S, 1, 6, 9, unsigned long long)
DEFINE_STRUCT_AND_FUNCTIONS(T, 1, 8, 7, unsigned short)
DEFINE_STRUCT_AND_FUNCTIONS(U, 6, 1, 9, unsigned long long)
DEFINE_STRUCT_AND_FUNCTIONS(V, 8, 1, 7, unsigned short)
DEFINE_STRUCT_AND_FUNCTIONS(W, 12, 13, 7, long double)
DEFINE_STRUCT_AND_FUNCTIONS(X, 12, 13, 7, long double)
DEFINE_STRUCT_AND_FUNCTIONS(Y, 12, 11, 9, long double)
DEFINE_STRUCT_AND_FUNCTIONS(Z, 12, 7, 13, long double)

int main(void) {
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