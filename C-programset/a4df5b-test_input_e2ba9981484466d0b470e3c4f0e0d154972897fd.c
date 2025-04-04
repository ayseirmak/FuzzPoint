#include <stdio.h>
#include <complex.h>

int err;

#define TEST(TYPE, FUNC)                        \
__complex__ TYPE                                \
ctest_ ## FUNC (__complex__ TYPE x)             \
{                                               \
  return conj(x);                               \
}                                               \
                                                \
void test_ ## FUNC(void)                        \
{                                               \
  __complex__ TYPE res, x;                      \
                                                \
  x = 1.0 + 2.0 * I;                            \
                                                \
  res = ctest_ ## FUNC(x);                      \
                                                \
  if (creal(res) != 1.0 || cimag(res) != -2.0)  \
  {                                             \
    printf("test_" #FUNC " failed\n");          \
    ++err;                                      \
  }                                             \
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
    printf("There were %d errors\n", err);
    return 1;
  }

  printf("All tests passed successfully!\n");
  return 0;
}