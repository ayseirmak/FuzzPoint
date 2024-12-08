#include <stdio.h>
#include <stdlib.h>

#define FIXED_VAL_1 1234
#define FIXED_VAL_2 5678
#define FIXED_VAL_3 91011
#define FIXED_VAL_4 121314

#define T(S)                                   \
struct S s##S;                                 \
struct S retme##S (struct S x)                 \
{                                              \
  return x;                                    \
}                                              \
                                               \
unsigned int fn1##S (unsigned int x)           \
{                                              \
  struct S y = s##S;                           \
  y.k += x;                                    \
  y = retme##S (y);                            \
  return y.k;                                  \
}                                              \
                                               \
unsigned int fn2##S (unsigned int x)           \
{                                              \
  struct S y = s##S;                           \
  y.k += x;                                    \
  y.k %= 15;                                   \
  return y.k;                                  \
}                                              \
                                               \
unsigned int retit##S (void)                   \
{                                              \
  return s##S.k;                               \
}                                              \
                                               \
unsigned int fn3##S (unsigned int x)           \
{                                              \
  s##S.k += x;                                 \
  return retit##S ();                          \
}                                              \
                                               \
void test##S (void)                            \
{                                              \
  int i;                                       \
  unsigned int mask, v, a, r;                  \
  struct S x;                                  \
  char *p = (char *) &s##S;                    \
  for (i = 0; i < sizeof (s##S); ++i)          \
    *p++ = FIXED_VAL_1;                        \
  if (__builtin_classify_type (s##S.l) == 8)   \
    s##S.l = 5.25;                             \
  s##S.k = -1;                                 \
  mask = s##S.k;                               \
  v = FIXED_VAL_2;                             \
  a = FIXED_VAL_3;                             \
  s##S.k = v;                                  \
  x = s##S;                                    \
  r = fn1##S (a);                              \
  if (x.i != s##S.i || x.j != s##S.j           \
      || x.k != s##S.k || x.l != s##S.l        \
      || ((v + a) & mask) != r)                \
  {                                            \
    printf("Test failed in fn1: struct %s\n", #S); \
    exit (1);                                  \
  }                                            \
  v = FIXED_VAL_3;                             \
  a = FIXED_VAL_4;                             \
  s##S.k = v;                                  \
  x = s##S;                                    \
  r = fn2##S (a);                              \
  if (x.i != s##S.i || x.j != s##S.j           \
      || x.k != s##S.k || x.l != s##S.l        \
      || ((((v + a) & mask) % 15) & mask) != r)\
  {                                            \
    printf("Test failed in fn2: struct %s\n", #S); \
    exit (1);                                  \
  }                                            \
  v = FIXED_VAL_4;                             \
  a = FIXED_VAL_1;                             \
  s##S.k = v;                                  \
  x = s##S;                                    \
  r = fn3##S (a);                              \
  if (x.i != s##S.i || x.j != s##S.j           \
      || s##S.k != r || x.l != s##S.l          \
      || ((v + a) & mask) != r)                \
  {                                            \
      printf("Test failed in fn3: struct %s\n", #S); \
      exit (1);                                \
  }                                            \
}

/* Removed __attribute__((packed)) for safety */
struct A { unsigned short i : 1, l : 1, j : 3, k : 11; }; T(A)
struct B { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; T(B)
struct C { unsigned int l; unsigned short i : 5, j : 1, k : 11; }; T(C)
struct D { unsigned long long l : 6, i : 6, j : 23, k : 29; }; T(D)
/* Other struct definitions ... */

int main (void)
{
  testA ();
  testB ();
  testC ();
  testD ();
  /* Other test function calls ... */
  printf("All tests passed.\n");
  exit (0);
}