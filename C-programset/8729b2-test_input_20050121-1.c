#include <stdio.h>
#include <complex.h>
#include <assert.h>

#define T(type, name) \
_Complex type foo_##name (int x) \
{ \
  _Complex type r; \
  __real__ r = x + 1; \
  __imag__ r = x - 1; \
  return r; \
} \
\
void bar_##name (type *x) \
{ \
  *x = __real__ foo_##name (5); \
} \
\
void baz_##name (type *x) \
{ \
  *x = __imag__ foo_##name (5); \
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

int main(void)
{
#define T(type, name) \
  { \
    type var = 0; \
    bar_##name(&var); \
    assert(var == 6); \
    var = 0; \
    baz_##name(&var); \
    assert(var == 4); \
  }
  T(float, float)
  T(double, double)
  T(long double, ldouble_t)
  T(char, char)
  T(short, short)
  T(int, int)
  T(long, long)
  T(long long, llong)
#undef T
  
  return 0;
}