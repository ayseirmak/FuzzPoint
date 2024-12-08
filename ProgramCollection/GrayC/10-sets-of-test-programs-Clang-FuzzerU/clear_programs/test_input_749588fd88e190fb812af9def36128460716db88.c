#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void test1(int a, int b, int c, int d, int e, int f, int g, long double h, ...) {
    int i;
    va_list ap;

    va_start(ap, h);
    i = va_arg(ap, int);
    if (i != 1234) {
        printf("Error in test1: expected 1234, got %d\n", i);
        exit(1);
    }
    va_end(ap);
}

void test2(int j, double k, long double l, double m, long double n, ...) {
    double o;
    va_list ap;

    va_start(ap, n);
    o = va_arg(ap, double);
    if (o != 1234.0) {
        printf("Error in test2: expected 1234.0, got %f\n", o);
        exit(1);
    }
    va_end(ap);
}

void test3(double a, double b, double c, double d, double e, double f, double g, long double h, ...) {
    double i;
    va_list ap;

    va_start(ap, h);
    i = va_arg(ap, double);
    if (i != 1234.0) {
        printf("Error in test3: expected 1234.0, got %f\n", i);
        exit(1);
    }
    va_end(ap);
}

void test4(double a, double b, double c, double d, double e, double f, double g, long double h, double i, long double j, double k, long double l, double m, long double n, ...) {
    double o;
    va_list ap;

    va_start(ap, n);
    o = va_arg(ap, double);
    if (o != 1234.0) {
        printf("Error in test4: expected 1234.0, got %f\n", o);
        exit(1);
    }
    va_end(ap);
}

int main() {
    test1(0, 0, 0, 0, 0, 0, 0, 0.0L, 1234);
    test2(0, 0.0, 0.0L, 0.0, 0.0L, 1234.0);
    test3(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, 1234.0);
    test4(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, 0.0, 0.0L, 0.0, 0.0L, 0.0, 0.0L, 1234.0);
    printf("All tests passed successfully.\n");
    return 0;
}