#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

// Conversion functions
float u2f(unsigned int u) {
  return (float)u;
}

double u2d(unsigned int u) {
  return (double)u;
}

long double u2ld(unsigned int u) {
  return (long double)u;
}

float s2f(int s) {
  return (float)s;
}

double s2d(int s) {
  return (double)s;
}

long double s2ld(int s) {
  return (long double)s;
}

int fnear(float x, float y) {
  float t = x - y;
  return t == 0 || x / t > 1000000.0f;
}

int dnear(double x, double y) {
  double t = x - y;
  return t == 0 || x / t > 100000000000000.0;
}

int ldnear(long double x, long double y) {
  long double t = x - y;
  return t == 0 || x / t > 100000000000000000000000000000000.0L;
}

void test_integer_to_float() {
  if (u2f(0U) != (float)0U)
    printf("Test failed\n");
  if (!fnear(u2f(~0U), (float)~0U))
    printf("Test failed\n");
  if (!fnear(u2f((~0U) >> 1), (float)((~0U) >> 1)))
    printf("Test failed\n");
  if (u2f(~((~0U) >> 1)) != (float)~((~0U) >> 1))
    printf("Test failed\n");

  if (u2d(0U) != (double)0U)
    printf("Test failed\n");
  if (!dnear(u2d(~0U), (double)~0U))
    printf("Test failed\n");
  if (!dnear(u2d((~0U) >> 1), (double)((~0U) >> 1)))
    printf("Test failed\n");
  if (u2d(~((~0U) >> 1)) != (double)~((~0U) >> 1))
    printf("Test failed\n");

  if (u2ld(0U) != (long double)0U)
    printf("Test failed\n");
  if (!ldnear(u2ld(~0U), (long double)~0U))
    printf("Test failed\n");
  if (!ldnear(u2ld((~0U) >> 1), (long double)((~0U) >> 1)))
    printf("Test failed\n");
  if (u2ld(~((~0U) >> 1)) != (long double)~((~0U) >> 1))
    printf("Test failed\n");

  if (s2f(0) != (float)0)
    printf("Test failed\n");
  if (!fnear(s2f(~0), (float)~0))
    printf("Test failed\n");
  if (!fnear(s2f((int)((~0U) >> 1)), (float)(int)((~0U) >> 1)))
    printf("Test failed\n");
  if (s2f((int)(~((~0U) >> 1))) != (float)(int)~((~0U) >> 1))
    printf("Test failed\n");

  if (s2d(0) != (double)0)
    printf("Test failed\n");
  if (!dnear(s2d(~0), (double)~0))
    printf("Test failed\n");
  if (!dnear(s2d((int)((~0U) >> 1)), (double)(int)((~0U) >> 1)))
    printf("Test failed\n");
  if (s2d((int)~((~0U) >> 1)) != (double)(int)~((~0U) >> 1))
    printf("Test failed\n");

  if (s2ld(0) != (long double)0)
    printf("Test failed\n");
  if (!ldnear(s2ld(~0), (long double)~0))
    printf("Test failed\n");
  if (!ldnear(s2ld((int)((~0U) >> 1)), (long double)(int)((~0U) >> 1)))
    printf("Test failed\n");
  if (s2ld((int)~((~0U) >> 1)) != (long double)(int)~((~0U) >> 1))
    printf("Test failed\n");
}

unsigned int f2u(float f) {
  return (unsigned int)f;
}

unsigned int d2u(double d) {
  return (unsigned int)d;
}

unsigned int ld2u(long double d) {
  return (unsigned int)d;
}

int f2s(float f) {
  return (int)f;
}

int d2s(double d) {
  return (int)d;
}

int ld2s(long double d) {
  return (int)d;
}

void test_float_to_integer() {
  if (f2u(0.0f) != 0)
    printf("Test failed\n");
  if (f2u(0.999f) != 0)
    printf("Test failed\n");
  if (f2u(1.0f) != 1)
    printf("Test failed\n");
  if (f2u(1.99f) != 1)
    printf("Test failed\n");

  if (sizeof(double) >= 8) {
    if (d2u(0.0) != 0)
      printf("Test failed\n");
    if (d2u(0.999) != 0)
      printf("Test failed\n");
    if (d2u(1.0) != 1)
      printf("Test failed\n");
    if (d2u(1.99) != 1)
      printf("Test failed\n");
  }

  if (sizeof(long double) >= 8) {
    if (ld2u(0.0L) != 0)
      printf("Test failed\n");
    if (ld2u(0.999L) != 0)
      printf("Test failed\n");
    if (ld2u(1.0L) != 1)
      printf("Test failed\n");
    if (ld2u(1.99L) != 1)
      printf("Test failed\n");
  }

  if (f2s(0.0f) != 0)
    printf("Test failed\n");
  if (f2s(0.999f) != 0)
    printf("Test failed\n");
  if (f2s(1.0f) != 1)
    printf("Test failed\n");
  if (f2s(1.99f) != 1)
    printf("Test failed\n");
  if (f2s(-0.999f) != 0)
    printf("Test failed\n");
  if (f2s(-1.0f) != -1)
    printf("Test failed\n");
  if (f2s(-1.99f) != -1)
    printf("Test failed\n");
  
  if (sizeof(double) >= 8) {
    if (d2s(0.0) != 0)
      printf("Test failed\n");
    if (d2s(0.999) != 0)
      printf("Test failed\n");
    if (d2s(1.0) != 1)
      printf("Test failed\n");
    if (d2s(1.99) != 1)
      printf("Test failed\n");
  }

  if (sizeof(long double) >= 8) {
    if (ld2s(0.0L) != 0)
      printf("Test failed\n");
    if (ld2s(0.999L) != 0)
      printf("Test failed\n");
    if (ld2s(1.0L) != 1)
      printf("Test failed\n");
    if (ld2s(1.99L) != 1)
      printf("Test failed\n");
  }
}

int main() {
  test_integer_to_float();
  test_float_to_integer();
  return 0;
}