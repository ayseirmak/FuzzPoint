#include <stdio.h>  // For printf
#include <stdlib.h> // For exit

// Function prototypes
float u2f(unsigned int u);
double u2d(unsigned int u);
long double u2ld(unsigned int u);
float s2f(int s);
double s2d(int s);
long double s2ld(int s);
int fnear(float x, float y);
int dnear(double x, double y);
int ldnear(long double x, long double y);
void test_integer_to_float();
void test_float_to_integer();
#if __GNUC__
void test_longlong_integer_to_float();
void test_float_to_longlong_integer();
#endif

/* Conversions from unsigned int to float, double, long double */
float u2f(unsigned int u) { return (float)u; }
double u2d(unsigned int u) { return (double)u; }
long double u2ld(unsigned int u) { return (long double)u; }

/* Conversions from signed int to float, double, long double */
float s2f(int s) { return (float)s; }
double s2d(int s) { return (double)s; }
long double s2ld(int s) { return (long double)s; }

/* Float comparison helper functions */
int fnear(float x, float y) {
    float t = x - y;
    return t == 0 || x / t > 1000000.0;
}

int dnear(double x, double y) {
    double t = x - y;
    return t == 0 || x / t > 100000000000000.0;
}

int ldnear(long double x, long double y) {
    long double t = x - y;
    return t == 0 || x / t > 100000000000000000000.0;
}

/* Conversion tests: Integer to Float */
void test_integer_to_float() {
    if (u2f(0U) != (float)0U) exit(1);
    if (!fnear(u2f(~0U), (float)~0U)) exit(1);
    if (!fnear(u2f((~0U) >> 1), (float)((~0U) >> 1))) exit(1);
    if (u2f(~((~0U) >> 1)) != (float)~((~0U) >> 1)) exit(1);

    if (u2d(0U) != (double)0U) exit(1);
    if (!dnear(u2d(~0U), (double)~0U)) exit(1);
    if (!dnear(u2d((~0U) >> 1), (double)((~0U) >> 1))) exit(1);
    if (u2d(~((~0U) >> 1)) != (double)~((~0U) >> 1)) exit(1);

    if (u2ld(0U) != (long double)0U) exit(1);
    if (!ldnear(u2ld(~0U), (long double)~0U)) exit(1);
    if (!ldnear(u2ld((~0U) >> 1), (long double)((~0U) >> 1))) exit(1);
    if (u2ld(~((~0U) >> 1)) != (long double)~((~0U) >> 1)) exit(1);

    if (s2f(0) != (float)0) exit(1);
    if (!fnear(s2f(~0), (float)~0)) exit(1);
    if (!fnear(s2f((int)((~0U) >> 1)), (float)(int)((~0U) >> 1))) exit(1);
    if (s2f((int)(~((~0U) >> 1))) != (float)(int)~((~0U) >> 1)) exit(1);

    if (s2d(0) != (double)0) exit(1);
    if (!dnear(s2d(~0), (double)~0)) exit(1);
    if (!dnear(s2d((int)((~0U) >> 1)), (double)(int)((~0U) >> 1))) exit(1);
    if (s2d((int)~((~0U) >> 1)) != (double)(int)~((~0U) >> 1)) exit(1);

    if (s2ld(0) != (long double)0) exit(1);
    if (!ldnear(s2ld(~0), (long double)~0)) exit(1);
    if (!ldnear(s2ld((int)((~0U) >> 1)), (long double)(int)((~0U) >> 1))) exit(1);
    if (s2ld((int)~((~0U) >> 1)) != (long double)(int)~((~0U) >> 1)) exit(1);
}

/* Conversion tests: Float to Integer */
void test_float_to_integer() {
    if (f2u(0.0) != 0) exit(1);
    if (f2u(0.999) != 0) exit(1);
    if (f2u(1.0) != 1) exit(1);
    if (f2u(1.99) != 1) exit(1);

#ifdef __SPU__
    if (f2u((float)((~0U) >> 1)) != 0x7fffff80) exit(1);
#else
    if (f2u((float)((~0U) >> 1)) != (~0U) >> 1 &&
        f2u((float)((~0U) >> 1)) != ((~0U) >> 1) + 1) exit(1);
#endif

    if (f2u((float)~((~0U) >> 1)) != ~((~0U) >> 1)) exit(1);

    if (sizeof(double) >= 8) {
        if (d2u(0.0) != 0) exit(1);
        if (d2u(0.999) != 0) exit(1);
        if (d2u(1.0) != 1) exit(1);
        if (d2u(1.99) != 1) exit(1);
        if (d2u((double)(~0U)) != ~0U) exit(1);
        if (d2u((double)((~0U) >> 1)) != (~0U) >> 1) exit(1);
        if (d2u((double)~((~0U) >> 1)) != ~((~0U) >> 1)) exit(1);
    }

    if (sizeof(long double) >= 8) {
        if (ld2u(0.0) != 0) exit(1);
        if (ld2u(0.999) != 0) exit(1);
        if (ld2u(1.0) != 1) exit(1);
        if (ld2u(1.99) != 1) exit(1);
        if (ld2u((long double)(~0U)) != ~0U) exit(1);
        if (ld2u((long double)((~0U) >> 1)) != (~0U) >> 1) exit(1);
        if (ld2u((long double)~((~0U) >> 1)) != ~((~0U) >> 1)) exit(1);
    }

    if (f2s(0.0) != 0) exit(1);
    if (f2s(0.999) != 0) exit(1);
    if (f2s(1.0) != 1) exit(1);
    if (f2s(1.99) != 1) exit(1);
    if (f2s(-0.999) != 0) exit(1);
    if (f2s(-1.0) != -1) exit(1);
    if (f2s(-1.99) != -1) exit(1);
    if (f2s((float)(int)~((~0U) >> 1)) != (int)~((~0U) >> 1)) exit(1);

    if (sizeof(double) >= 8) {
        if (d2s(0.0) != 0) exit(1);
        if (d2s(0.999) != 0) exit(1);
        if (d2s(1.0) != 1) exit(1);
        if (d2s(1.99) != 1) exit(1);
        if (d2s(-0.999) != 0) exit(1);
        if (d2s(-1.0) != -1) exit(1);
        if (d2s(-1.99) != -1) exit(1);
        if (d2s((double)((~0U) >> 1)) != (~0U) >> 1) exit(1);
        if (d2s((double)(int)~((~0U) >> 1)) != (int)~((~0U) >> 1)) exit(1);
    }

    if (sizeof(long double) >= 8) {
        if (ld2s(0.0) != 0) exit(1);
        if (ld2s(0.999) != 0) exit(1);
        if (ld2s(1.0) != 1) exit(1);
        if (ld2s(1.99) != 1) exit(1);
        if (ld2s(-0.999) != 0) exit(1);
        if (ld2s(-1.0) != -1) exit(1);
        if (ld2s(-1.99) != -1) exit(1);
        if (ld2s((long double)((~0U) >> 1)) != (~0U) >> 1) exit(1);
        if (ld2s((long double)(int)~((~0U) >> 1)) != (int)~((~0U) >> 1)) exit(1);
    }
}

/* Main function */
int main() {
    test_integer_to_float();
    test_float_to_integer();
    #if __GNUC__
    test_longlong_integer_to_float();
    test_float_to_longlong_integer();
    #endif
    return 0;
}

#if __GNUC__
float ull2f(unsigned long long int u) { return (float)u; }
double ull2d(unsigned long long int u) { return (double)u; }
long double ull2ld(unsigned long long int u) { return (long double)u; }
long long int f2sll(float f) { return (long long int)f; }
long long int d2sll(double d) { return (long long int)d; }
long long int ld2sll(long double d) { return (long long int)d; }
unsigned int f2u(float f) { return (unsigned int)f; }
unsigned int d2u(double d) { return (unsigned int)d; }
unsigned int ld2u(long double d) { return (unsigned int)d; }
int f2s(float f) { return (int)f; }
int d2s(double d) { return (int)d; }
int ld2s(long double d) { return (int)d; }

void test_longlong_integer_to_float() {
    if (ull2f(~((~0ULL) >> 1)) != (float)~((~0ULL) >> 1)) exit(1);
    if (ull2d(~0ULL) != (double)~0ULL) exit(1);
    if (ull2ld(~((~0ULL) >> 1)) != (long double)~((~0ULL) >> 1)) exit(1);

    if (sll2f(0LL) != (float)0LL) exit(1);
    if (sll2f(~0LL) != (float)~0LL) exit(1);
    if (!fnear(sll2f((long long int)((~0ULL) >> 1)), (float)(long long int)((~0ULL) >> 1))) exit(1);
    if (sll2f((long long int)(~((~0ULL) >> 1))) != (float)(long long int)~((~0ULL) >> 1)) exit(1);

    if (sll2d(0LL) != (double)0LL) exit(1);
    if (sll2d(~0LL) != (double)~0LL) exit(1);
    if (!dnear(sll2d((long long int)((~0ULL) >> 1)), (double)(long long int)((~0ULL) >> 1))) exit(1);
    if (sll2ld(0LL) != (long double)0LL) exit(1);
    if (sll2ld(~0LL) != (long double)~0LL) exit(1);
    if (!ldnear(sll2ld((long long int)((~0ULL) >> 1)), (long double)(long long int)((~0ULL) >> 1))) exit(1);
    if (!ldnear(sll2ld((long long int)~((~0ULL) >> 1)), (long double)(long long int)~((~0ULL) >> 1))) exit(1);
}

void test_float_to_longlong_integer() {
    if (f2ull(0.0) != 0LL) exit(1);
    if (f2ull(0.999) != 0LL) exit(1);
    if (f2ull(1.0) != 1LL) exit(1);
    if (f2ull(1.99) != 1LL) exit(1);

    if (d2ull(0.0) != 0LL) exit(1);
    if (d2ull(0.999) != 0LL) exit(1);
    if (d2ull(1.0) != 1LL) exit(1);
    if (d2ull(1.99) != 1LL) exit(1);

    if (ld2ull(0.0) != 0LL) exit(1);
    if (ld2ull(0.999) != 0LL) exit(1);
    if (ld2ull(1.0) != 1LL) exit(1);
    if (ld2ull(1.99) != 1LL) exit(1);

    if (f2sll(0.0) != 0LL) exit(1);
    if (f2sll(0.999) != 0LL) exit(1);
    if (f2sll(1.0) != 1LL) exit(1);
    if (f2sll(1.99) != 1LL) exit(1);
    if (f2sll(-0.999) != 0LL) exit(1);
    if (f2sll(-1.0) != -1LL) exit(1);
    if (f2sll(-1.99) != -1LL) exit(1);
    if (f2sll((float)(long long int)~((~0ULL) >> 1)) != (long long int)~((~0ULL) >> 1)) exit(1);

    if (d2sll(0.0) != 0LL) exit(1);
    if (d2sll(0.999) != 0LL) exit(1);
    if (d2sll(1.0) != 1LL) exit(1);
    if (d2sll(1.99) != 1LL) exit(1);
    if (d2sll(-0.999) != 0LL) exit(1);
    if (d2sll(-1.0) != -1LL) exit(1);
    if (d2sll(-1.99) != -1LL) exit(1);
    if (d2sll((double)(long long int)~((~0ULL) >> 1)) != (long long int)~((~0ULL) >> 1)) exit(1);

    if (ld2sll(0.0) != 0LL) exit(1);
    if (ld2sll(0.999) != 0LL) exit(1);
    if (ld2sll(1.0) != 1LL) exit(1);
    if (ld2sll(1.99) != 1LL) exit(1);
    if (ld2sll(-0.999) != 0LL) exit(1);
    if (ld2sll(-1.0) != -1LL) exit(1);
    if (ld2sll(-1.99) != -1LL) exit(1);
    if (ld2sll((long double)(long long int)~((~0ULL) >> 1)) != (long long int)~((~0ULL) >> 1)) exit(1);
}
#endif