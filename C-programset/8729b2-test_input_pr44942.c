#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// Custom abort function as a replacement for __builtin_abort for standard compliance
void custom_abort() {
    printf("Aborted due to failed condition.\n");
    exit(1);
}

void test1(int a, int b, int c, int d, int e, int f, int g, long double h, ...) {
    int i;
    va_list ap;
    
    va_start(ap, h);
    i = va_arg(ap, int);
    if (i != 1234)
        custom_abort();
    va_end(ap);
}

void test2(int a, int b, int c, int d, int e, int f, int g, long double h, int i,
    long double j, int k, long double l, int m, long double n, ...) {
    int o;
    va_list ap;
    
    va_start(ap, n);
    o = va_arg(ap, int);
    if (o != 1234)
        custom_abort();
    va_end(ap);
}

void test3(double a, double b, double c, double d, double e, double f,
    double g, long double h, ...) {
    double i;
    va_list ap;
    
    va_start(ap, h);
    i = va_arg(ap, double);
    if (i != 1234.0)
        custom_abort();
    va_end(ap);
}

void test4(double a, double b, double c, double d, double e, double f, double g,
    long double h, double i, long double j, double k, long double l,
    double m, long double n, ...) {
    double o;
    va_list ap;
    
    va_start(ap, n);
    o = va_arg(ap, double);
    if (o != 1234.0)
        custom_abort();
    va_end(ap);
}

int main() {
    // Fixed test values for demonstration purposes (since no reading operations are allowed)
    int arg1 = 1234;           // Integer test value
    double arg2 = 1234.0;      // Double test value
    
    test1(0, 0, 0, 0, 0, 0, 0, 0.0L, arg1);
    test2(0, 0, 0, 0, 0, 0, 0, 0.0L, 0, 0.0L, 0, 0.0L, 0, 0.0L, arg1);
    test3(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, arg2);
    test4(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0L, 0.0, 0.0L, 0.0, 0.0L, 0.0, 0.0L, arg2);

    return 0;
}