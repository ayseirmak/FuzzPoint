#include <stdio.h>
#include <stdlib.h>

// Function macros for generating complex operations for various types
#define T(type, name) \
_Complex type foo_##name(int x) { \
    _Complex type r; \
    __real__ r = x + 1; \
    __imag__ r = x - 1; \
    return r; \
} \
void bar_##name(type *x) { \
    *x = __real__ foo_##name(5); \
} \
void baz_##name(type *x) { \
    *x = __imag__ foo_##name(5); \
}

// Defining necessary type aliases
typedef long double ldouble_t;
typedef long long llong;

// Applying the macro to various data types
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
        if (var != 6) { \
            printf("Test failed for bar_%s with value %d\n", #name, (int)var); \
            abort(); \
        } \
        var = 0; \
        baz_##name(&var); \
        if (var != 4) { \
            printf("Test failed for baz_%s with value %d\n", #name, (int)var); \
            abort(); \
        } \
    }
    
    // Run tests for each type
    T(float, float)
    T(double, double)
    T(long double, ldouble_t)
    T(char, char)
    T(short, short)
    T(int, int)
    T(long, long)
    T(long long, llong)

    printf("All tests passed successfully.\n");
    return 0;
}