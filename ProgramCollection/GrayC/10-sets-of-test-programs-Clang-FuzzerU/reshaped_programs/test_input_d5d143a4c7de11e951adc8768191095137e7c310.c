#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int err;

#define TEST(TYPE, FUNC)                                   \
    __complex__ TYPE                                        \
    ctest_ ## FUNC (__complex__ TYPE x)                     \
    {                                                       \
        __complex__ TYPE res;                               \
        /* Placeholder for conjugate operation */           \
        /* res = ~x; */ /* This is incorrect for complex */ \
        res = __builtin_conj(x);                            \
        return res;                                         \
    }                                                       \
                                                            \
    void                                                    \
    test_ ## FUNC (void)                                    \
    {                                                       \
        __complex__ TYPE res, x;                            \
        x = (1.0 + 2.0i);                                   \
        res = ctest_ ## FUNC (x);                           \
        if (creal(res) != 1.0 || cimag(res) != -2.0)        \
        {                                                   \
            printf("test_" #FUNC " failed\n");              \
            ++err;                                          \
        }                                                   \
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
        abort();
    }
    
    return 0;
}