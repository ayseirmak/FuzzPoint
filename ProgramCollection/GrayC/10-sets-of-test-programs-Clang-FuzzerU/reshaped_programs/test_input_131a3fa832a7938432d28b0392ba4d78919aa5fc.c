#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Define some fixed "random" values for use within the program */
static unsigned int deterministic_values[] = {
    42, 137, 198, 1023, 876, 999, 1111, 2045
};
static int value_index = 0;

unsigned int myrnd (void) {
  unsigned int value = deterministic_values[value_index % (sizeof(deterministic_values) / sizeof(deterministic_values[0]))];
  value_index++;
  return value;
}

#define T(S)                               \
struct S s##S;                             \
struct S retme##S (struct S x) {           \
  return x;                                \
}                                          \
                                           \
unsigned int fn1##S (unsigned int x) {     \
  struct S y = s##S;                       \
  y.k += x;                                \
  y = retme##S (y);                        \
  return y.k;                              \
}                                          \
                                           \
unsigned int fn2##S (unsigned int x) {     \
  struct S y = s##S;                       \
  y.k += x;                                \
  y.k %= 15;                               \
  return y.k;                              \
}                                          \
                                           \
unsigned int retit##S (void) {             \
  return s##S.k;                           \
}                                          \
                                           \
unsigned int fn3##S (unsigned int x) {     \
  s##S.k += x;                             \
  return retit##S ();                      \
}                                          \
                                           \
void test##S (void) {                      \
  int i;                                   \
  unsigned int mask = 0, v = 0, a = 0, r = 0;  \
  struct S x;                              \
  char *p = (char *) &s##S;                \
  for (i = 0; i < sizeof (s##S); ++i)      \
    *p++ = myrnd ();                       \
  if (__builtin_classify_type (s##S.l) == 8) \
    s##S.l = 5.25;                         \
  s##S.k = -1;                             \
  mask = s##S.k;                           \
  v = myrnd ();                            \
  a = myrnd ();                            \
  s##S.k = v;                              \
  x = s##S;                                \
  r = fn1##S (a);                          \
  if (r != (v + a) % (1 << 12)) {          \
    printf("Test " #S " failed\n");        \
    abort();                               \
  }                                        \
}

struct O { unsigned long long l, k : 12, j : 23, i : 29; }; T(O)
struct P { unsigned long long k : 12, j : 23, i : 29, l; }; T(P)
struct Q { unsigned int k : 12, j : 13, i : 7; unsigned long long l; }; T(Q)
struct R { unsigned int k : 12, j : 11, i : 9; unsigned long long l; }; T(R)
struct S { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; T(S)
struct T { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; T(T)
struct U { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; T(U)
struct V { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; T(V)
struct W { long double l; unsigned int k : 12, j : 13, i : 7; }; T(W)
struct X { unsigned int k : 12, j : 13, i : 7; long double l; }; T(X)
struct Y { unsigned int k : 12, j : 11, i : 9; long double l; }; T(Y)
struct Z { long double l; unsigned int j : 13, i : 7, k : 12; }; T(Z)

int main(void) {
  testO();
  testP();
  testQ();
  testR();
  testS();
  testT();
  testU();
  testV();
  testW();
  testX();
  testY();
  testZ();
  printf("All tests passed\n");
  exit(0);
}