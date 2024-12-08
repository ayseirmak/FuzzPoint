#include <stdio.h>
#include <stdlib.h>

#define COMPLEX_IMAG_PART(x) ((x) == 4)
#define COMPLEX_REAL_PART(x) ((x) == 6)

#define T(type, name) \
_Complex type foo_##name (int x) \
{ \
    _Complex type r = 0; \
    __real__ r = x + 1; \
    __imag__ r = x - 1; \
    return r; \
} \
\
void bar_##name (type *x) \
{ \
    *x = (type) __real__ foo_##name (5); \
} \
\
void baz_##name (type *x) \
{ \
    *x = (type) __imag__ foo_##name (5); \
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
        if (!COMPLEX_REAL_PART(var)) { \
            fprintf(stderr, "Test failed: bar_" #name "\n"); \
            abort(); \
        } \
        var = 0; \
        baz_##name(&var); \
        if (!COMPLEX_IMAG_PART(var)) { \
            fprintf(stderr, "Test failed: baz_" #name "\n"); \
            abort(); \
        } \
    }

    T(float, float)
    T(double, double)
    T(long double, ldouble_t)
    T(char, char)
    T(short, short)
    T(int, int)
    T(long, long)
    T(long long, llong)

    return 0;
}