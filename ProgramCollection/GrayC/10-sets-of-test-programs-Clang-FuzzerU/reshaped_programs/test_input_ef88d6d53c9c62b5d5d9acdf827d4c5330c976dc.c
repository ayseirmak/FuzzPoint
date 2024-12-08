#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long int st;
typedef unsigned long long dt;

typedef union {
    dt d;
    struct {
        st h, l;
    } s;
} t_be;

typedef union {
    dt d;
    struct {
        st l, h;
    } s;
} t_le;

#define df(f, t)                                 \
int f(t afh, t bfh) {                            \
    t hh;                                        \
    t hp, lp, dp, m;                             \
    st ad, bd;                                   \
    int s;                                       \
    s = 0;                                       \
    ad = afh.s.h - afh.s.l;                      \
    bd = bfh.s.l - bfh.s.h;                      \
    if (bd > bfh.s.l) {                          \
        bd = -bd;                                \
        s = ~s;                                  \
    }                                            \
    lp.d = (dt)afh.s.l * bfh.s.l;                \
    hp.d = (dt)afh.s.h * bfh.s.h;                \
    dp.d = (dt)ad * bd;                          \
    dp.d ^= s;                                   \
    hh.d = hp.d + hp.s.h + lp.s.h + dp.s.h;      \
    m.d = (dt)lp.s.h + hp.s.l + lp.s.l + dp.s.l; \
    return hh.s.l + m.s.l;                       \
}

df(f_le, t_le)
df(f_be, t_be)

void foo(int a_init, int b[], int c_init, int d[]) {
    int a = a_init;
    int c = c_init;
    if (a != 2 || c != 2) {
        abort();
    }
}

int main() {
    t_be x;
    x.s.h = 0x10000000U;
    x.s.l = 0xe0000000U;
    
    if (x.d == 0x10000000e0000000ULL &&
        f_be((t_be){.d = 0x100000000ULL}, (t_be){.d = 0x100000000ULL}) != -1) {
        abort();
    }
    
    if (x.d == 0xe0000000ULL &&
        f_le((t_le){.d = 0x100000000ULL}, (t_le){.d = 0x100000000ULL}) != -1) {
        abort();
    }
    
    int e[10] = {0};
    foo(1, e, 1, e);

    struct A { unsigned int i : 6, l : 1, j : 10, k : 15; };
    struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; };
    struct C { unsigned int l; unsigned int i : 6, j : 11, k : 15; };
    struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; };
    struct E { unsigned long long l, i : 12, j : 23, k : 29; };
    struct F { unsigned long long i : 12, j : 23, k : 29, l; };
    struct G { unsigned int i : 12, j : 13, k : 7; unsigned long long l; };

    /* Add the remaining structs and corresponding generated test functions here */

    /* Call all test functions for struct types defined */
    /* Example: */
    // testA();
    // testB();
    // ...
    // testZ();

    return 0;
}