#include <stdio.h>
#include <stdlib.h>

#define T(type, name) \
_Complex type foo_##name(int x) { \
    _Complex type r; \
    __real r = x + 1; \
    __imag r = x - 1; \
    return r; \
} \
\
void bar_##name(type *x) { \
    *x = __real foo_##name(5); \
} \
\
void baz_##name(type *x) { \
    *x = __imag foo_##name(5); \
}

typedef long double ldouble_t;
typedef long long llong;

T(float, float)
T(double, double)
T(ldouble_t, ldouble_t)
T(char, char)
T(short, short)
T(int, int)
T(long, long)
T(long long, llong)

int main(void) {
    #define T(type, name) \
    { \
        type var = 0; \
        bar_##name(&var); \
        if (var != 6) { \
            printf("Test failed for bar_" #name "\n"); \
            abort(); \
        } \
        baz_##name(&var); \
        if (var != 4) { \
            printf("Test failed for baz_" #name "\n"); \
            abort(); \
        } \
    }

    T(float, float)
    T(double, double)
    T(ldouble_t, ldouble_t)
    T(char, char)
    T(short, short)
    T(int, int)
    T(long, long)
    T(long long, llong)

    printf("All tests passed successfully.\n");
    return 0;
}