#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

// Define a macro to generate functions.
#define T(type, name) \
    /* A function with a pure attribute returning a complex number */ \
    _Complex type foo_##name (int x) { \
        _Complex type r = 0.0; \
        __real__ r = x + 1; \
        __imag__ r = x - 1; \
        return r; \
    } \
    \
    /* Set the real part of the complex result to the variable */ \
    void bar_##name (type *x) { \
        *x = __real__ foo_##name(5); \
    } \
    \
    /* Set the imaginary part of the complex result to the variable */ \
    void baz_##name (type *x) { \
        *x = __imag__ foo_##name(5); \
    }

// Declare types for use in generated functions
typedef long double ldouble_t;
typedef long long llong;

// Generate functions for each type
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
    // Generate test cases for each type
    #define T(type, name) \
    { \
        type var = 0; \
        bar_##name(&var); \
        if (var != 6) { \
            printf("Test failed for bar_"#name". Expected 6, but got %d\n", (int)var); \
            return 1; \
        } \
        var = 0; \
        baz_##name(&var); \
        if (var != 4) { \
            printf("Test failed for baz_"#name". Expected 4, but got %d\n", (int)var); \
            return 1; \
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

    printf("All tests passed.\n");
    return 0;
}