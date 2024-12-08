#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <complex.h>

// Replacing `abort()` and `exit()` direct calls with standard C counterparts
void handleAbort() {
    fprintf(stderr, "Abort called!\n");
    exit(1);
}

int to_hex(unsigned int a) {
    static char hex[] = "0123456789abcdef";
    if (a > 15) {
        handleAbort();
    }
    return hex[a];
}

void fap(int count, char *format, va_list ap) {
    va_list apc;
    va_copy(apc, ap);

    while (*format) {
        if (*format++ != to_hex(va_arg(ap, int))) {
            handleAbort();
        }
    }
    while (*format) {
        if (*format++ != to_hex(va_arg(apc, int))) {
            handleAbort();
        }
    }

    va_end(apc);
}

void f0(char *format, ...) {
    va_list ap;
    va_start(ap, format);
    fap(0, format, ap);
    va_end(ap);
}

void f1(int a1, char *format, ...) {
    va_list ap;
    va_start(ap, format);
    fap(1, format, ap);
    va_end(ap);
}

void f2(int a1, int a2, char *format, ...) {
    va_list ap;
    va_start(ap, format);
    fap(2, format, ap);
    va_end(ap);
}

void f3(int a1, int a2, int a3, char *format, ...) {
    va_list ap;
    va_start(ap, format);
    fap(3, format, ap);
    va_end(ap);
}

void f4(int a1, int a2, int a3, int a4, char *format, ...) {
    va_list ap;
    va_start(ap, format);
    fap(4, format, ap);
    va_end(ap);
}

void f5(int a1, int a2, int a3, int a4, int a5, char *format, ...) {
    va_list ap;
    va_start(ap, format);
    fap(5, format, ap);
    va_end(ap);
}

// Definitions for complex values to demonstrate correct parameter passing
volatile _Complex float f1_val = 1.1f + 2.2if;
volatile _Complex float f2_val = 3.3f + 4.4if;
volatile _Complex float f3_val = 5.5f + 6.6if;
volatile _Complex float f4_val = 7.7f + 8.8if;
volatile _Complex float f5_val = 9.9f + 10.1if;

volatile _Complex double d1_val = 1.1 + 2.2i;
volatile _Complex double d2_val = 3.3 + 4.4i;
volatile _Complex double d3_val = 5.5 + 6.6i;
volatile _Complex double d4_val = 7.7 + 8.8i;
volatile _Complex double d5_val = 9.9 + 10.1i;

volatile _Complex long double ld1_val = 1.1L + 2.2iL;
volatile _Complex long double ld2_val = 3.3L + 4.4iL;
volatile _Complex long double ld3_val = 5.5L + 6.6iL;
volatile _Complex long double ld4_val = 7.7L + 8.8iL;
volatile _Complex long double ld5_val = 9.9L + 10.1iL;

void check_float(int a, _Complex float a1, _Complex float a2, _Complex float a3, _Complex float a4, _Complex float a5) {
    if (a1 != f1_val || a2 != f2_val || a3 != f3_val || a4 != f4_val || a5 != f5_val) {
        handleAbort();
    }
}

void check_double(int a, _Complex double a1, _Complex double a2, _Complex double a3, _Complex double a4, _Complex double a5) {
    if (a1 != d1_val || a2 != d2_val || a3 != d3_val || a4 != d4_val || a5 != d5_val) {
        handleAbort();
    }
}

void check_long_double(int a, _Complex long double a1, _Complex long double a2, _Complex long double a3, _Complex long double a4, _Complex long double a5) {
    if (a1 != ld1_val || a2 != ld2_val || a3 != ld3_val || a4 != ld4_val || a5 != ld5_val) {
        handleAbort();
    }
}

int main(void) {
    char *f = "0123456789abcdef";

    f0(f + 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    f1(0, f + 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    f2(0, 1, f + 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    f3(0, 1, 2, f + 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    f4(0, 1, 2, 3, f + 4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    f5(0, 1, 2, 3, 4, f + 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

    check_float(0, f1_val, f2_val, f3_val, f4_val, f5_val);
    check_double(0, d1_val, d2_val, d3_val, d4_val, d5_val);
    check_long_double(0, ld1_val, ld2_val, ld3_val, ld4_val, ld5_val);

    return 0;
}