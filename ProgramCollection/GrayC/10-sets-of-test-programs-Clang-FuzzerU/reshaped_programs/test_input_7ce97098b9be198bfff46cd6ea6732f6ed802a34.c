#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

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

#define T(type, name) \
    _Complex type foo_##name (int x) { \
        _Complex type r; \
        __real__ r = x + 1; \
        __imag__ r = x - 1; \
        return r; \
    } \
    void bar_##name (type *x) { \
        *x = __real__ foo_##name(5); \
    } \
    void baz_##name (type *x) { \
        *x = __imag__ foo_##name(5); \
    }

typedef long double ldouble_t;
typedef long long llong;

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
    #define T(type, name) \
    { \
        type var = 0; \
        bar_##name(&var); \
        if (var != 6) \
            return 1; \
        var = 0; \
        baz_##name(&var); \
        if (var != 4) \
            return 1; \
    }
    T(float, float)
    T(double, double)
    T(long double, ldouble_t)
    T(char, char)
    T(short, short)
    T(int, int)
    T(long, long)
    T(long long, llong)
    
    #undef T
    
    unsigned long a[5];
    int start, end, k;
    
    for (start = 0; start < 5; start++) {
        for (end = 0; end < 5; end++) {
            for (k = 0; k < 5; k++)
                a[k] = k;

            foo(a + start, a + end);

            for (k = 0; k <= start; k++)
                if (a[k] != k)
                    return 1;

            for (k = start + 1; k <= end; k++)
                if (a[k] != k - 1)
                    return 1;

            for (k = end + 1; k < 5; k++)
                if (a[k] != k)
                    return 1;
        }
    }

    return 0;
}