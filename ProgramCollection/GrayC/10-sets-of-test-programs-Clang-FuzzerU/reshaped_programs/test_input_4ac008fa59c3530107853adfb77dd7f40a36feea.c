#include <stdio.h>
#include <stdlib.h>

// Simulated fixed input values instead of random numbers
static unsigned int deterministic_values[] = {
    1023, 2047, 512, 1365, 768, 1024, 235, 985
};

// Index for deterministic input array
static int current_index = 0;

unsigned int fixed_myrnd(void) {
    // Provide a fixed sequence of values
    unsigned int val = deterministic_values[current_index++];
    current_index %= sizeof(deterministic_values)/sizeof(deterministic_values[0]);
    return val;
}

#define T(S)                               \
struct S s##S;                             \
struct S retme##S (struct S x)             \
{                                          \
  return x;                                \
}                                          \
                                           \
unsigned int fn1##S (unsigned int x)       \
{                                          \
  struct S y = s##S;                       \
  y.k += x;                                \
  y = retme##S (y);                        \
  return y.k;                              \
}                                          \
                                           \
unsigned int fn2##S (unsigned int x)       \
{                                          \
  struct S y = s##S;                       \
  y.k += x;                                \
  y.k %= 15;                               \
  return y.k;                              \
}                                          \
                                           \
unsigned int retit##S (void)               \
{                                          \
  return s##S.k;                           \
}                                          \
                                           \
unsigned int fn3##S (unsigned int x)       \
{                                          \
  s##S.k += x;                             \
  return retit##S ();                      \
}                                          \
                                           \
void test##S (void)                        \
{                                          \
  int i;                                   \
  unsigned int mask, v, a, r;              \
  struct S x;                              \
  char *p = (char *) &s##S;                \
  for (i = 0; i < sizeof (s##S); ++i)      \
    *p++ = fixed_myrnd();                  \
  s##S.l = (__builtin_classify_type(s##S.l) == 8) ? 5 : 0; /* Use integer for bitfield logic */ \
  s##S.k = -1;                             \
  mask = s##S.k;                           \
  v = fixed_myrnd();                       \
  a = fixed_myrnd();                       \
  s##S.k = v;                              \
  x = s##S;                                \
  r = fn1##S(a);                           \
  if (x.i != s##S.i || x.j != s##S.j       \
      || x.k != s##S.k || x.l != s##S.l    \
      || ((v + a) & mask) != r)            \
    abort();                               \
  v = fixed_myrnd();                       \
  a = fixed_myrnd();                       \
  s##S.k = v;                              \
  x = s##S;                                \
  r = fn1##S(a);                           \
  if (x.i != s##S.i || x.j != s##S.j       \
      || x.k != s##S.k || x.l != s##S.l    \
      || (((v + a) & mask) % 15) != r)     \
    abort();                               \
  v = fixed_myrnd();                       \
  a = fixed_myrnd();                       \
  s##S.k = v;                              \
  x = s##S;                                \
  r = fn3##S(a);                           \
  if (x.i != s##S.i || x.j != s##S.j       \
      || s##S.k != r || x.l != s##S.l      \
      || ((v + a) & mask) != r)            \
    abort();                               \
}

struct A { unsigned int i : 6, l : 1, j : 10, k : 15; }; T(A)
struct B { unsigned int i : 6, j : 11, k : 15; unsigned int l; }; T(B)
// Other structures (C to Z) are similar...

int main(void) {
    testA();
    testB();
    // Perform tests for other structures (C to Z) similarly...
    exit(0);
}