#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    return t == 0 || x / t > 1.0e30;
}

void test_integer_to_float() {
    assert(u2f(0U) == (float)0U);
    assert(fnear(u2f(~0U), (float)~0U));
    assert(fnear(u2f((~0U) >> 1), (float)((~0U) >> 1)));
    assert(u2f(~((~0U) >> 1)) == (float)~((~0U) >> 1));

    assert(u2d(0U) == (double)0U);
    assert(dnear(u2d(~0U), (double)~0U));
    assert(dnear(u2d((~0U) >> 1), (double)((~0U) >> 1)));
    assert(u2d(~((~0U) >> 1)) == (double)~((~0U) >> 1));

    assert(u2ld(0U) == (long double)0U);
    assert(ldnear(u2ld(~0U), (long double)~0U));
    assert(ldnear(u2ld((~0U) >> 1), (long double)((~0U) >> 1)));
    assert(u2ld(~((~0U) >> 1)) == (long double)~((~0U) >> 1));

    assert(s2f(0) == (float)0);
    assert(fnear(s2f(~0), (float)~0));
    assert(fnear(s2f((int)((~0U) >> 1)), (float)(int)((~0U) >> 1)));
    assert(s2f((int)(~((~0U) >> 1))) == (float)(int)~((~0U) >> 1));

    assert(s2d(0) == (double)0);
    assert(dnear(s2d(~0), (double)~0));
    assert(dnear(s2d((int)((~0U) >> 1)), (double)(int)((~0U) >> 1)));
    assert(s2d((int)~((~0U) >> 1)) == (double)(int)~((~0U) >> 1));

    assert(s2ld(0) == (long double)0);
    assert(ldnear(s2ld(~0), (long double)~0));
    assert(ldnear(s2ld((int)((~0U) >> 1)), (long double)(int)((~0U) >> 1)));
    assert(s2ld((int)~((~0U) >> 1)) == (long double)(int)~((~0U) >> 1));
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
    assert(f2u(0.0f) == 0U);
    assert(f2u(0.999f) == 0U);
    assert(f2u(1.0f) == 1U);
    assert(f2u(1.99f) == 1U);
    assert(f2u((float)((~0U) >> 1)) == ((~0U) >> 1));
    assert(f2u((float)~((~0U) >> 1)) == ~((~0U) >> 1));

    if (sizeof(double) >= 8) {
        assert(d2u(0.0) == 0U);
        assert(d2u(0.999) == 0U);
        assert(d2u(1.0) == 1U);
        assert(d2u(1.99) == 1U);
        assert(d2u((double)(~0U)) == ~0U);
        assert(d2u((double)((~0U) >> 1)) == ((~0U) >> 1));
        assert(d2u((double)~((~0U) >> 1)) == ~((~0U) >> 1));
    }

    if (sizeof(long double) >= 8) {
        assert(ld2u(0.0L) == 0U);
        assert(ld2u(0.999L) == 0U);
        assert(ld2u(1.0L) == 1U);
        assert(ld2u(1.99L) == 1U);
        assert(ld2u((long double)(~0U)) == ~0U);
        assert(ld2u((long double)((~0U) >> 1)) == ((~0U) >> 1));
        assert(ld2u((long double)~((~0U) >> 1)) == ~((~0U) >> 1));
    }

    assert(f2s(0.0f) == 0);
    assert(f2s(0.999f) == 0);
    assert(f2s(1.0f) == 1);
    assert(f2s(1.99f) == 1);
    assert(f2s(-0.999f) == 0);
    assert(f2s(-1.0f) == -1);
    assert(f2s(-1.99f) == -1);
    assert(f2s((float)(int)~((~0U) >> 1)) == (int)~((~0U) >> 1));

    if (sizeof(double) >= 8) {
        assert(d2s(0.0) == 0);
        assert(d2s(0.999) == 0);
        assert(d2s(1.0) == 1);
        assert(d2s(1.99) == 1);
        assert(d2s(-0.999) == 0);
        assert(d2s(-1.0) == -1);
        assert(d2s(-1.99) == -1);
        assert(d2s((double)((~0U) >> 1)) == ((~0U) >> 1));
        assert(d2s((double)(int)~((~0U) >> 1)) == (int)~((~0U) >> 1));
    }

    if (sizeof(long double) >= 8) {
        assert(ld2s(0.0L) == 0);
        assert(ld2s(0.999L) == 0);
        assert(ld2s(1.0L) == 1);
        assert(ld2s(1.99L) == 1);
        assert(ld2s(-0.999L) == 0);
        assert(ld2s(-1.0L) == -1);
        assert(ld2s(-1.99L) == -1);
        assert(ld2s((long double)((~0U) >> 1)) == ((~0U) >> 1));
        assert(ld2s((long double)(int)~((~0U) >> 1)) == (int)~((~0U) >> 1));
    }
}

int main() {
    test_integer_to_float();
    test_float_to_integer();
    return 0;
}