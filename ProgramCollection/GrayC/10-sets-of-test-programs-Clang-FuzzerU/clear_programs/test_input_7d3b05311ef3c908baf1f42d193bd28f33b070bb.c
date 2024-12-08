#include <stdio.h>
#include <stdlib.h>

#define DEFINE_FUNCTIONS(type, name)                        \
_Complex type foo_##name (int x) __attribute__((pure));     \
_Complex type foo_##name (int x) {                          \
    _Complex type r;                                        \
    __real r = x + 1;                                       \
    __imag r = x - 1;                                       \
    return r;                                               \
}                                                           \
                                                            \
void bar_##name(type *x) {                                  \
    *x = __real foo_##name (5);                             \
}                                                           \
                                                            \
void baz_##name(type *x) {                                  \
    *x = __imag foo_##name (5);                             \
}

typedef long double ldouble_t;
typedef long long llong;

DEFINE_FUNCTIONS(float, float)
DEFINE_FUNCTIONS(double, double)
DEFINE_FUNCTIONS(long double, ldouble_t)
DEFINE_FUNCTIONS(char, char)
DEFINE_FUNCTIONS(short, short)
DEFINE_FUNCTIONS(int, int)
DEFINE_FUNCTIONS(long, long)
DEFINE_FUNCTIONS(long long, llong)

int main(void) {
#define TEST_FUNCTIONS(type, name)          \
    {                                       \
        type var = 0;                       \
        bar_##name(&var);                   \
        if (var != 6) {                     \
            printf("Failed: bar_" #name "\n"); \
            abort();                        \
        }                                   \
        var = 0;                            \
        baz_##name(&var);                   \
        if (var != 4) {                     \
            printf("Failed: baz_" #name "\n"); \
            abort();                        \
        }                                   \
    }

    TEST_FUNCTIONS(float, float)
    TEST_FUNCTIONS(double, double)
    TEST_FUNCTIONS(long double, ldouble_t)
    TEST_FUNCTIONS(char, char)
    TEST_FUNCTIONS(short, short)
    TEST_FUNCTIONS(int, int)
    TEST_FUNCTIONS(long, long)
    TEST_FUNCTIONS(long long, llong)

    printf("All tests passed successfully.\n");
    return 0;
}