#include <stdio.h>
#include <stdlib.h>

void do_exit(void) {
    exit(0);
}

void do_abort(void) {
    abort();
}

void foo(int x, int a) {
    if (x < a)
        goto doit;

    do_exit();
    if (x != a)
        goto doit;

    /* else */
    do_abort();
    return;

doit:
    do_abort();
}

#define T(type, name)                                          \
    __attribute__((pure)) _Complex type foo_##name(int x) {    \
        _Complex type r;                                       \
        __real__ r = x + 1;                                    \
        __imag__ r = x - 1;                                    \
        return r;                                              \
    }                                                          \
                                                               \
    void bar_##name(type *x) {                                 \
        *x = __real__ foo_##name(5);                           \
    }                                                          \
                                                               \
    void baz_##name(type *x) {                                 \
        *x = __imag__ foo_##name(5);                           \
    }

typedef long double ldouble_t;
typedef long long llong;

// Instantiate the T macro for each type
T(float, float)
T(double, double)
T(long double, ldouble_t)
T(char, char)
T(short, short)
T(int, int)
T(long, long)
T(long long, llong)
#undef T

int main(void) {
#define T(type, name)                   \
    {                                   \
        type var = 0;                   \
        bar_##name(&var);               \
        if (var != 6) {                 \
            printf("Test failed\n");    \
            do_abort();                 \
        }                               \
        var = 0;                        \
        baz_##name(&var);               \
        if (var != 4) {                 \
            printf("Test failed\n");    \
            do_abort();                 \
        }                               \
    }

    // Run tests
    T(float, float)
    T(double, double)
    T(long double, ldouble_t)
    T(char, char)
    T(short, short)
    T(int, int)
    T(long, long)
    T(long long, llong)
    
    printf("All tests passed\n");
    return 0;
}