#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define NUM_STRUCTS 26

unsigned int myrnd_fixed(void) {
    static unsigned int s = 1388815473;
    s *= 1103515245;
    s += 12345;
    return (s / 65536) % 2048;
}

#define DEFINE_STRUCTS_AND_FUNCTIONS(S)                                 \
    struct S {                                                          \
        unsigned int i;                                                 \
        unsigned int j;                                                 \
        unsigned int k;                                                 \
    };                                                                  \
                                                                        \
    struct S s##S;                                                      \
                                                                        \
    unsigned int fn1##S(unsigned int x) {                               \
        struct S y = s##S;                                              \
        y.k += x;                                                       \
        return y.k;                                                     \
    }                                                                   \
                                                                        \
    unsigned int fn2##S(unsigned int x) {                               \
        struct S y = s##S;                                              \
        y.k += x;                                                       \
        y.k %= 15;                                                      \
        return y.k;                                                     \
    }                                                                   \
                                                                        \
    unsigned int retit##S(void) {                                       \
        return s##S.k;                                                  \
    }                                                                   \
                                                                        \
    unsigned int fn3##S(unsigned int x) {                               \
        s##S.k += x;                                                    \
        return retit##S();                                              \
    }                                                                   \
                                                                        \
    void test##S(void) {                                                \
        unsigned int mask, v, a, r;                                     \
        struct S x;                                                     \
        char *p = (char *)&s##S;                                        \
        for (int i = 0; i < sizeof(s##S); ++i)                          \
            *p++ = myrnd_fixed();                                       \
        s##S.k = -1;                                                    \
    }

DEFINE_STRUCTS_AND_FUNCTIONS(A)
DEFINE_STRUCTS_AND_FUNCTIONS(B)
DEFINE_STRUCTS_AND_FUNCTIONS(C)
DEFINE_STRUCTS_AND_FUNCTIONS(D)
DEFINE_STRUCTS_AND_FUNCTIONS(E)
DEFINE_STRUCTS_AND_FUNCTIONS(F)
DEFINE_STRUCTS_AND_FUNCTIONS(G)
DEFINE_STRUCTS_AND_FUNCTIONS(H)
DEFINE_STRUCTS_AND_FUNCTIONS(I)
DEFINE_STRUCTS_AND_FUNCTIONS(J)
DEFINE_STRUCTS_AND_FUNCTIONS(K)
DEFINE_STRUCTS_AND_FUNCTIONS(L)
DEFINE_STRUCTS_AND_FUNCTIONS(M)
DEFINE_STRUCTS_AND_FUNCTIONS(N)
DEFINE_STRUCTS_AND_FUNCTIONS(O)
DEFINE_STRUCTS_AND_FUNCTIONS(P)
DEFINE_STRUCTS_AND_FUNCTIONS(Q)
DEFINE_STRUCTS_AND_FUNCTIONS(R)
DEFINE_STRUCTS_AND_FUNCTIONS(S)
DEFINE_STRUCTS_AND_FUNCTIONS(T)
DEFINE_STRUCTS_AND_FUNCTIONS(U)
DEFINE_STRUCTS_AND_FUNCTIONS(V)
DEFINE_STRUCTS_AND_FUNCTIONS(W)
DEFINE_STRUCTS_AND_FUNCTIONS(X)
DEFINE_STRUCTS_AND_FUNCTIONS(Y)
DEFINE_STRUCTS_AND_FUNCTIONS(Z)

volatile _Complex float f1 = 1.1f + 2.2if;
volatile _Complex float f2 = 3.3f + 4.4if;
volatile _Complex float f3 = 5.5f + 6.6if;
volatile _Complex float f4 = 7.7f + 8.8if;
volatile _Complex float f5 = 9.9f + 10.1if;
volatile _Complex double d1 = 1.1 + 2.2i;
volatile _Complex double d2 = 3.3 + 4.4i;
volatile _Complex double d3 = 5.5 + 6.6i;
volatile _Complex double d4 = 7.7 + 8.8i;
volatile _Complex double d5 = 9.9 + 10.1i;
volatile _Complex long double ld1 = 1.1L + 2.2L * I;
volatile _Complex long double ld2 = 3.3L + 4.4L * I;
volatile _Complex long double ld3 = 5.5L + 6.6L * I;
volatile _Complex long double ld4 = 7.7L + 8.8L * I;
volatile _Complex long double ld5 = 9.9L + 10.1L * I;

void check_float(int check, volatile _Complex float a1, 
                volatile _Complex float a2, 
                volatile _Complex float a3, 
                volatile _Complex float a4, 
                volatile _Complex float a5) {
    if (check != 0) {
        abort();
    }
}

void check_double(int check, volatile _Complex double a1, 
                  volatile _Complex double a2, 
                  volatile _Complex double a3, 
                  volatile _Complex double a4, 
                  volatile _Complex double a5) {
    if (check != 0) {
        abort();
    }
}

void check_long_double(int check, volatile _Complex long double a1, 
                       volatile _Complex long double a2, 
                       volatile _Complex long double a3, 
                       volatile _Complex long double a4, 
                       volatile _Complex long double a5) {
    if (check != 0) {
        abort();
    }
}

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

    check_float(0, f1, f2, f3, f4, f5);
    check_double(0, d1, d2, d3, d4, d5);
    check_long_double(0, ld1, ld2, ld3, ld4, ld5);

    exit(0);
}