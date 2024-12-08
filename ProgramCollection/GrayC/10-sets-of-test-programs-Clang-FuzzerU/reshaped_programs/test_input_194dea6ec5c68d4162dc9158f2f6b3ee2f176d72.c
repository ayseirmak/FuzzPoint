#include <stdio.h>
#include <stdlib.h>

// Custom abort function to print and exit
void my_abort() {
    printf("Abort called\n");
    exit(1);
}

#define T(S)                                         \
struct S s##S = {0};                                  \
struct S retme##S (struct S x) { return x; }         \
                                                     \
unsigned int fn1##S (unsigned int x) {               \
    struct S y = s##S;                               \
    y.k += x;                                        \
    y = retme##S(y);                                 \
    return y.k;                                      \
}                                                    \
                                                     \
unsigned int fn2##S (unsigned int x) {               \
    struct S y = s##S;                               \
    y.k += x;                                        \
    y.k %= 15;                                       \
    return y.k;                                      \
}                                                    \
                                                     \
unsigned int retit##S (void) {                       \
    return s##S.k;                                   \
}                                                    \
                                                     \
unsigned int fn3##S (unsigned int x) {               \
    s##S.k += x;                                     \
    return retit##S();                               \
}                                                    \
                                                     \
void test##S (void) {                                \
    int i;                                           \
    unsigned int mask, v, a, r;                      \
    struct S x;                                      \
    unsigned char deterministic_values[] = {         \
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,   \
        14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,  \
    };                                               \
    char *p = (char *) &s##S;                        \
    for (i = 0; i < sizeof(s##S); ++i)               \
        *p++ = deterministic_values[i % 24];         \
                                                     \
    if ((__builtin_classify_type(s##S.l) == 8))      \
        s##S.l = 5.25;                               \
    s##S.k = -1;                                     \
    mask = s##S.k;                                   \
    v = deterministic_values[0] % 2048;              \
    a = deterministic_values[1] % 2048;              \
    s##S.k = v;                                      \
    x = s##S;                                        \
    r = fn1##S(a);                                   \
    if (x.i != s##S.i || x.j != s##S.j               \
        || x.k != s##S.k || x.l != s##S.l            \
        || ((v + a) & mask) != r)                    \
        my_abort();                                  \
    v = deterministic_values[2] % 2048;              \
    a = deterministic_values[3] % 2048;              \
    s##S.k = v;                                      \
    x = s##S;                                        \
    r = fn2##S(a);                                   \
    if (x.i != s##S.i || x.j != s##S.j               \
        || x.k != s##S.k || x.l != s##S.l            \
        || ((((v + a) & mask) % 15) & mask) != r)    \
        my_abort();                                  \
    v = deterministic_values[4] % 2048;              \
    a = deterministic_values[5] % 2048;              \
    s##S.k = v;                                      \
    x = s##S;                                        \
    r = fn3##S(a);                                   \
    if (x.i != s##S.i || x.j != s##S.j               \
        || s##S.k != r || x.l != s##S.l              \
        || ((v + a) & mask) != r)                    \
        my_abort();                                  \
}

#define STRUCT_decl(S, f1, f2, f3, f4) struct S { unsigned f1 : 1, f2 : 1, f3 : 3, f4 : 11; }; T(S)

STRUCT_decl(A, short, short, short, short)
STRUCT_decl(B, short, short, short, short)
STRUCT_decl(C, int, short, short, short)
STRUCT_decl(D, long long, long long, long long, int)
STRUCT_decl(E, long long, long long, long long, int)
STRUCT_decl(F, long long, long long, long long, long long)
STRUCT_decl(G, short, short, short, long long)
STRUCT_decl(H, short, short, short, long long)
STRUCT_decl(I, short, short, short, long long)
STRUCT_decl(J, short, short, short, short)
STRUCT_decl(K, int, int, int, int)
STRUCT_decl(L, int, int, int, int)
STRUCT_decl(M, int, short, short, short)
STRUCT_decl(N, long long, long long, long long, long long)
STRUCT_decl(O, long long, long long, long long, long long)
STRUCT_decl(P, long long, long long, long long, long long)
STRUCT_decl(Q, short, short, short, long long)
STRUCT_decl(R, short, short, short, long long)
STRUCT_decl(S, short, short, short, long long)
STRUCT_decl(T, short, short, short, short)
STRUCT_decl(U, int, int, short, long long)
STRUCT_decl(V, short, short, short, short)
STRUCT_decl(W, double, int, int, int)
STRUCT_decl(X, int, int, int, double)
STRUCT_decl(Y, int, int, int, double)
STRUCT_decl(Z, double, int, int, int)

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
    exit(0);
}