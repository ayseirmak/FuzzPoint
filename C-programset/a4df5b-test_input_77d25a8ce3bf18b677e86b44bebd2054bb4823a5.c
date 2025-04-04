#include <stdio.h>
#include <stdlib.h>

int err;

#define TEST(TYPE, FUNC)                        \
__complex__ TYPE                                \
ctest_##FUNC(__complex__ TYPE x)                \
{                                               \
    __complex__ TYPE res;                       \
    res = ~x;                                   \
    return res;                                 \
}                                               \
                                                \
void                                            \
test_##FUNC(void)                               \
{                                               \
    __complex__ TYPE res, x;                    \
    x = 1.0 + 2.0i;                             \
    res = ctest_##FUNC(x);                      \
    if (res != 1.0 - 2.0i)                      \
    {                                           \
        printf("test_" #FUNC " failed\n");      \
        ++err;                                  \
    }                                           \
}

TEST(float, float)
TEST(double, double)
TEST(long double, long_double)
TEST(int, int)
TEST(long int, long_int)

int main(void)
{
    err = 0;

    test_float();
    test_double();
    test_long_double();
    test_int();
    test_long_int();

    if (err != 0)
    {
        printf("Some tests failed.\n");
    }
    else
    {
        printf("All tests passed.\n");
    }

    return 0;
}