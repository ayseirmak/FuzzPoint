#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Test arithmetics on bitfields. */

#define DEFINE_STRUCT_AND_FUNCTIONS(S, fixedValues)   \
struct S { unsigned int i : 6, l : 1, j : 10, k : 15; }; \
struct S s##S;                                        \
struct S retme##S (struct S x)                        \
{                                                     \
  return x;                                           \
}                                                     \
                                                      \
unsigned int fn1##S (unsigned int x)                  \
{                                                     \
  struct S y = s##S;                                  \
  y.k += x;                                           \
  y = retme##S (y);                                   \
  return y.k;                                         \
}                                                     \
                                                      \
unsigned int fn2##S (unsigned int x)                  \
{                                                     \
  struct S y = s##S;                                  \
  y.k += x;                                           \
  y.k %= 15;                                          \
  return y.k;                                         \
}                                                     \
                                                      \
unsigned int retit##S (void)                          \
{                                                     \
  return s##S.k;                                      \
}                                                     \
                                                      \
unsigned int fn3##S (unsigned int x)                  \
{                                                     \
  s##S.k += x;                                        \
  return retit##S ();                                 \
}                                                     \
                                                      \
void test##S (void)                                   \
{                                                     \
  int i;                                              \
  unsigned int mask, v, a, r;                         \
  struct S x;                                         \
  unsigned char fixedValuesArray[] = fixedValues;     \
  unsigned char *p = (unsigned char *) &s##S;         \
  for (i = 0; i < sizeof (s##S); ++i)                 \
    *p++ = fixedValuesArray[i];                       \
  if (s##S.l == 1)                                    \
    s##S.l = 5.25;                                    \
  s##S.k = -1;                                        \
  mask = s##S.k;                                      \
  v = fixedValuesArray[0];                            \
  a = fixedValuesArray[1];                            \
  s##S.k = v;                                         \
  x = s##S;                                           \
  r = fn1##S (a);                                     \
  if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((v + a) & mask) != r) \
    abort();                                          \
  v = fixedValuesArray[2];                            \
  a = fixedValuesArray[3];                            \
  s##S.k = v;                                         \
  x = s##S;                                           \
  r = fn1##S (a);                                     \
  if (x.i != s##S.i || x.j != s##S.j || x.k != s##S.k || x.l != s##S.l || ((((v + a) & mask) % 15) & mask) != r) \
    abort();                                          \
  v = fixedValuesArray[4];                            \
  a = fixedValuesArray[5];                            \
  s##S.k = v;                                         \
  x = s##S;                                           \
  r = fn3##S (a);                                     \
  if (x.i != s##S.i || x.j != s##S.j || s##S.k != r || x.l != s##S.l || ((v + a) & mask) != r) \
    abort();                                          \
}

// Assign fixed deterministic values
DEFINE_STRUCT_AND_FUNCTIONS(A, {1, 2, 3, 4, 5, 6})
DEFINE_STRUCT_AND_FUNCTIONS(B, {7, 8, 9, 10, 11, 12})
// Repeat similar struct definitions for other letters C-Z...

int main(void)
{
    testA();
    testB();
    // Call test functions for other structs C-Z...
    printf("All tests passed.\n");
    return 0;
}