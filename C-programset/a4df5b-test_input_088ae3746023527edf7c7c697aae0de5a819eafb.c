#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

/* Functions for conversions */

float u2f(unsigned int u) {
    return (float) u;
}

double u2d(unsigned int u) {
    return (double) u;
}

long double u2ld(unsigned int u) {
    return (long double) u;
}

float s2f(int s) {
    return (float) s;
}

double s2d(int s) {
    return (double) s;
}

long double s2ld(int s) {
    return (long double) s;
}

/* Functions to check near equality for floating points */

int fnear(float x, float y) {
    float t = x - y;
    return (t == 0 || x / t > 1000000.0);
}

int dnear(double x, double y) {
    double t = x - y;
    return (t == 0 || x / t > 100000000000000.0);
}

int ldnear(long double x, long double y) {
    long double t = x - y;
    return (t == 0 || x / t > 100000000000000000000000000000000.0L);
}

/* Tests */

void test_integer_to_float() {
    if (u2f(0U) != (float)0U) abort();
    if (!fnear(u2f(~0U), (float)~0U)) abort();
    if (!fnear(u2f((~0U) >> 1), (float)((~0U) >> 1))) abort();
    if (u2f(~((~0U) >> 1)) != (float)~((~0U) >> 1)) abort();

    if (u2d(0U) != (double)0U) abort();
    if (!dnear(u2d(~0U), (double)~0U)) abort();
    if (!dnear(u2d((~0U) >> 1), (double)((~0U) >> 1))) abort();
    if (u2d(~((~0U) >> 1)) != (double)~((~0U) >> 1)) abort();

    if (u2ld(0U) != (long double)0U) abort();
    if (!ldnear(u2ld(~0U), (long double)~0U)) abort();
    if (!ldnear(u2ld((~0U) >> 1), (long double)((~0U) >> 1))) abort();
    if (u2ld(~((~0U) >> 1)) != (long double)~((~0U) >> 1)) abort();

    if (s2f(0) != (float)0) abort();
    if (!fnear(s2f(~0), (float)~0)) abort();
    if (!fnear(s2f((int)((~0U) >> 1)), (float)(int)((~0U) >> 1))) abort();
    if (s2f((int)(~((~0U) >> 1))) != (float)(int)~((~0U) >> 1)) abort();

    if (s2d(0) != (double)0) abort();
    if (!dnear(s2d(~0), (double)~0)) abort();
    if (!dnear(s2d((int)((~0U) >> 1)), (double)(int)((~0U) >> 1))) abort();
    if (s2d((int)~((~0U) >> 1)) != (double)(int)~((~0U) >> 1)) abort();

    if (s2ld(0) != (long double)0) abort();
    if (!ldnear(s2ld(~0), (long double)~0)) abort();
    if (!ldnear(s2ld((int)((~0U) >> 1)), (long double)(int)((~0U) >> 1))) abort();
    if (s2ld((int)~((~0U) >> 1)) != (long double)(int)~((~0U) >> 1)) abort();
}

void test_float_to_integer() {
    if ((unsigned int)(float)0.0f != 0) abort();
    if ((unsigned int)(float)0.999f != 0) abort();
    if ((unsigned int)(float)1.0f != 1) abort();
    if ((unsigned int)(float)1.99f != 1) abort();
    
    if ((int)0.0f != 0) abort();
    if ((int)0.999f != 0) abort();
    if ((int)1.0f != 1) abort();
    if ((int)1.99f != 1) abort();
}

int main() {
    test_integer_to_float();
    test_float_to_integer();
    exit(0);
}