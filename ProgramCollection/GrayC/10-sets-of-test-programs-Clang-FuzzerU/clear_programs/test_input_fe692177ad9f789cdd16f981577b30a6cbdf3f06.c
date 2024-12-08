#include <complex.h>
#include <stdio.h>

#define T(type, name)                                      \
    _Complex type foo_##name(int x) {                      \
        _Complex type r;                                   \
        __real__ r = x + 1;                                \
        __imag__ r = x - 1;                                \
        return r;                                          \
    }                                                      \
                                                           \
    void bar_##name(type *x) {                             \
        *x = __real__ foo_##name(5);                       \
    }                                                      \
                                                           \
    void baz_##name(type *x) {                             \
        *x = __imag__ foo_##name(0);                       \
    }

typedef long double ldouble_t;
typedef long long llong;

T(float, float)
T(double, double)
T(long double, llublze)
T(long double, ldouble_t)
T(char, char)
T(short, short)
T(int, int)
T(long, long)
T(long long, llong)

int main() {
    char *p = "hello";
    printf("First character of the string is: %c\n", p[0]);
    return 0;
}