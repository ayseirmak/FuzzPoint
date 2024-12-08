#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#define NOIPA __attribute__ ((noclone, noinline))

#define A(expr)                                                 \
  ((expr)                                                       \
   ? (void)0                                                    \
   : (printf ("assertion failed on line %i: %s\n", __LINE__, #expr), \
      abort()))

long double C = 5.0;
long double U = 1.0;
long double Y2 = 11.0;
long double Y1 = 17.0;
long double X, Y, Z, T, R, S;

NOIPA char* get_max_2 (char *p) {
  return p + 1;
}

NOIPA char* get_max_3 (char *p, char *q) {
  return p < q ? q + 1 : p + 1;
}

NOIPA char* get_min_2 (char *p) {
  return p - 1;
}

NOIPA char* get_min_3 (char *p, char *q) {
  return p < q ? p - 1 : q - 1;
}

NOIPA void* test_max_2 (void) {
  char c;
  char *p = get_max_2(&c);
  void *q = p > &c ? p : &c;
  return q;
}

NOIPA void* test_max_3 (void) {
  char c, d;
  char *p = get_max_3(&c, &d);
  void *q = p < &c ? (&c < &d ? &d : &c) : p;
  return q;
}

NOIPA void* test_min_2 (void) {
  char c;
  char *p = get_min_2(&c);
  void *q = p < &c ? p : &c;
  return q;
}

NOIPA void* test_min_3 (void) {
  char a, b;
  char *p0 = &a, *p1 = &b;
  char *p2 = get_min_3(p0, p1);
  char *p3 = get_min_3(p0, p1);
  char *p4 = p2 < p0 ? p2 : p0;
  char *p5 = p3 < p1 ? p3 : p1;
  return p5;
}

void verify_calculations() {
  X = (C + U) * Y2;
  Y = C - U - U;
  Z = C + U + U;
  T = (C - U) * Y1;
  X = X - (Z + U);
  R = Y * Y1;
  S = Z * Y2;
  T = T - Y;
  Y = (U - Y) + R;
  Z = S - (Z + U + U);
  R = (Y2 + U) * Y1;
  Y1 = Y2 * Y1;
  R = R - Y2;
  Y1 = Y1 - 0.5L;

  if (Z != 68. || Y != 49. || X != 22. || Y1 != 186.5 || R != 193. || S != 77. || T != 65. || Y2 != 11.) {
    abort();
  }
}

int main() {
  A(0 != test_max_2());
  A(0 != test_max_3());
  A(0 != test_min_2());
  A(0 != test_min_3());

  verify_calculations();

  exit(0);
}