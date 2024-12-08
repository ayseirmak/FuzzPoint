#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

// Global error count
int err = 0;

// Macro to generate test functions for different data types
#define TEST(TYPE, FUNC)                               \
__complex__ TYPE ctest_##FUNC(__complex__ TYPE x)      \
{                                                      \
    __complex__ TYPE res;                              \
    res = conj(x);                                     \
    return res;                                        \
}                                                      \
                                                       \
void test_##FUNC(void)                                 \
{                                                      \
    __complex__ TYPE res, x;                           \
    x = 1.0 + 2.0 * I;                                 \
    res = ctest_##FUNC(x);                             \
    if (creal(res) != 1.0 || cimag(res) != -2.0)       \
    {                                                  \
        printf("test_" #FUNC " failed\n");             \
        ++err;                                         \
    }                                                  \
}

// Define tests for these data types
TEST(float, float)
TEST(double, double)
TEST(long double, long_double)

// Main function
int main(void) 
{
    // Run all the tests
    test_float();
    test_double();
    test_long_double();

    // Check if there were any errors
    if (err != 0)
    {
        abort();
    }

    return 0;
}