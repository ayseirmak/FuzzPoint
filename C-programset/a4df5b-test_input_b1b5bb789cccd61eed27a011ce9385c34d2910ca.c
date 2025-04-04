#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

// Function prototypes

void test1(int a, int b, int c, int d, int e, int f, int g, long double h, ...);
void test2(int a, int b, int c, int d, int e, int f, int g, long double h, int i,
           long double j, int k, long double l, int m, long double n, ...);
void test3(double a, double b, double c, double d, double e, double f,
           double g, long double h, ...);
void test4(double a, double b, double c, double d, double e, double f, double g,
           long double h, double i, long double j, double k, long double l,
           double m, long double n, ...);

int main() {
    test1(0, 0, 0, 0, 0, 0, 0, 0.0L, 1234);
    test2(0, 0, 0, 0, 0, 0, 0, 0.0L, 0, 0.0L, 0, 0.0L, 0, 0.0L, 1234);
    test3(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, 1234.0);
    test4(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, 0.0, 0.0L, 0.0, 0.0L, 0.0, 0.0L, 1234.0);
    return 0;
}

void test1(int a, int b, int c, int d, int e, int f, int g, long double h, ...) {
    int i;
    va_list ap;
    va_start(ap, h);
    i = va_arg(ap, int);
    if (i != 1234) {
        printf("test1 failed\n");
        exit(1);
    }
    va_end(ap);
}

void test2(int a, int b, int c, int d, int e, int f, int g, long double h, int i,
           long double j, int k, long double l, int m, long double n, ...) {
    int o;
    va_list ap;
    va_start(ap, n);
    o = va_arg(ap, int);
    if (o != 1234) {
        printf("test2 failed\n");
        exit(1);
    }
    va_end(ap);
}

void test3(double a, double b, double c, double d, double e, double f,
           double g, long double h, ...) {
    double i;
    va_list ap;
    va_start(ap, h);
    i = va_arg(ap, double);
    if (i != 1234.0) {
        printf("test3 failed\n");
        exit(1);
    }
    va_end(ap);
}

void test4(double a, double b, double c, double d, double e, double f, double g,
           long double h, double i, long double j, double k, long double l,
           double m, long double n, ...) {
    double o;
    va_list ap;
    va_start(ap, n);
    o = va_arg(ap, double);
    if (o != 1234.0) {
        printf("test4 failed\n");
        exit(1);
    }
    va_end(ap);
}