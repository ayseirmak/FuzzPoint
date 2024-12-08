#include <stdio.h>
#include <stdlib.h>

typedef long double ldouble_t;
typedef long long llong;

// Function declarations for types and names
#define T(type, name) \
_Complex type foo_##name (int x) { \
  _Complex type r; \
  __real__ r = x + 1; \
  __imag__ r = x - 1; \
  return r; \
} \
\
void bar_##name (type *x) { \
  *x = __real__ foo_##name (5); \
} \
\
void baz_##name (type *x) { \
  *x = __imag__ foo_##name (5); \
}

// Instantiate templates using specified types
T(float, float)
T(double, double)
T(ldouble_t, ldouble_t)
T(char, char)
T(short, short)
T(int, int)
T(long, long)
T(llong, llong)

#undef T

// Goto label-based function
int doit(int x) {
  __label__ lbl1, lbl2;
  static int jtab_init = 0;
  static void *jtab[2];

  if (!jtab_init) {
    jtab[0] = &&lbl1;
    jtab[1] = &&lbl2;
    jtab_init = 1;
  }
  goto *jtab[x];
lbl1:
  return 1;
lbl2:
  return 2;
}

// Main function
int main(void) {
#define T(type, name) \
  { \
    type var = 0; \
    bar_##name(&var); \
    if (var != 6) { \
      abort(); \
    } \
    baz_##name(&var); \
    if (var != 4) { \
      abort(); \
    } \
  }

  T(float, float)
  T(double, double)
  T(ldouble_t, ldouble_t)
  T(char, char)
  T(short, short)
  T(int, int)
  T(long, long)
  T(llong, llong)

#undef T

  // Check `doit` function
  int expect_do1 = 1, expect_do2 = 2;
  if (doit(1) != expect_do2) {
    abort();
  }

  return 0;
}