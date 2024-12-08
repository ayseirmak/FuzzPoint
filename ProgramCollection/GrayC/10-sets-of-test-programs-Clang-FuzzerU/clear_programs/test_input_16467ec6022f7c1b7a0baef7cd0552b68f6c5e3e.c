#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define T(type, name) \
_Complex type foo_##name(int x) \
{ \
    _Complex type r = 0; \
    __real__ r = x + 1; \
    __imag__ r = x - 1; \
    return r; \
} \
void bar_##name(type* x) \
{ \
    *x = __real__ foo_##name(5); \
} \
void baz_##name(type* x) \
{ \
    *x = __imag__ foo_##name(5); \
}

typedef long double ldouble_t;
typedef long long llong;

T(float, float)
T(double, double)
T(long double, ldouble_t)
T(long, long)
T(long long, llong)

#undef T

int main(void)
{
    #define T(type, name) \
    { \
        type var = 0; \
        bar_##name(&var); \
        if (var != 6) { \
            printf("Error in bar_" #name ": Expected 6 but got %d\n", (int)var); \
            abort(); \
        } \
        var = 0; \
        baz_##name(&var); \
        if (var != 4) { \
            printf("Error in baz_" #name ": Expected 4 but got %d\n", (int)var); \
            abort(); \
        } \
    }
    T(float, float)
    T(double, double)
    T(long double, ldouble_t)
    T(long, long)
    T(long long, llong)
    return 0;
}