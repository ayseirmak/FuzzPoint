#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct pckA { unsigned short i : 1, l : 1, j : 3, k : 11; };
struct pckB { unsigned short i : 4, j : 1, k : 11; unsigned int l; }; 
struct pckC { unsigned int l; unsigned short i : 4, j : 1, k : 11; }; 
struct pckD { unsigned long long l : 6, i : 6, j : 23, k : 29; }; 
struct pckE { unsigned long long l, i : 12, j : 23, k : 29; }; 
struct pckF { unsigned long long i : 12, j : 23, k : 29, l; }; 
struct pckG { unsigned short i : 1, j : 1, k : 6; unsigned long long l; }; 
struct pckH { unsigned short i : 6, j : 2, k : 8; unsigned long long l; }; 
struct pckI { unsigned short i : 1, j : 6, k : 1; unsigned long long l; }; 
struct pckJ { unsigned short i : 1, j : 8, k : 7; unsigned short l; }; 
struct pckK { unsigned int k : 6, l : 1, j : 10, i : 15; }; 
struct pckL { unsigned int k : 6, j : 11, i : 15; unsigned int l; }; 
struct pckM { unsigned int l; unsigned short k : 6, j : 11, i : 15; }; 
struct pckN { unsigned long long l : 6, k : 6, j : 23, i : 29; }; 
struct pckO { unsigned long long l, k : 12, j : 23, i : 29; }; 
struct pckP { unsigned long long k : 12, j : 23, i : 29, l; }; 
struct pckQ { unsigned short k : 12, j : 1, i : 3; unsigned long long l; }; 
struct pckR { unsigned short k : 2, j : 11, i : 3; unsigned long long l; }; 
struct pckS { unsigned short k : 1, j : 6, i : 9; unsigned long long l; }; 
struct pckT { unsigned short k : 1, j : 8, i : 7; unsigned short l; }; 
struct pckU { unsigned short j : 6, k : 1, i : 9; unsigned long long l; }; 
struct pckV { unsigned short j : 8, k : 1, i : 7; unsigned short l; }; 
struct pckW { long double l; unsigned int k : 12, j : 13, i : 7; }; 
struct pckX { unsigned int k : 12, j : 13, i : 7; long double l; }; 
struct pckY { unsigned int k : 12, j : 11, i : 9; long double l; }; 
struct pckZ { long double l; unsigned int j : 13, i : 7, k : 12; };

#define T(S)                            \
struct S s##S;                          \
struct S retme##S (struct S x)          \
{                                       \
  return x;                             \
}                                       \
                                        \
unsigned int fn1##S (unsigned int x)    \
{                                       \
  struct S y = s##S;                    \
  y.k += x;                             \
  y = retme##S (y);                     \
  return y.k;                           \
}                                       \
                                        \
unsigned int fn2##S (unsigned int x)    \
{                                       \
  struct S y = s##S;                    \
  y.k += x;                             \
  y.k %= 15;                            \
  return y.k;                           \
}                                       \
                                        \
unsigned int retit##S (void)            \
{                                       \
  return s##S.k;                        \
}                                       \
                                        \
unsigned int fn3##S (unsigned int x)    \
{                                       \
  s##S.k += x;                          \
  return retit##S ();                   \
}                                       \
                                        \
void test##S (void)                     \
{                                       \
  struct S x;                           \
  int v = 123, a = 456; /* Determine the values */ \
  s##S.k = v;                           \
  x = s##S;                             \
  int r = fn2##S (a);                   \
  assert(x.i == s##S.i && x.j == s##S.j && x.k == s##S.k && x.l == s##S.l); \
  assert(((((v + a) % 15) & 0xFFF) == r)); \
  v = 789; /* Another fixed value */     \
  a = 654; /* Another determined fixed value */ \
  s##S.k = v;                           \
  x = s##S;                             \
  r = fn3##S (a);                       \
  assert(x.i == s##S.i && x.j == s##S.j && s##S.k == r && x.l == s##S.l); \
  assert(((v + a) & 0xFFF) == r);      \
}

#define FIXED_VALUE 12345

int main(void) {
    testA();
    testB();
    testC();
    testD();
    testE();
    testF();
    testG();
    testH();
    testI();
    testJ();
    testK();
    testL();
    testM();
    testN();
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
    printf("All tests passed.\n");
    return 0;
}