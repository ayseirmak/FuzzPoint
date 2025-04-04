#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>

long long foo(long long t) {
    while (t > -4) {
        t -= 2;
    }
    return t;
}

void test_foo_function() {
    if (foo(0) != -4) {
        abort();
    }
}

struct s3 { char x[3]; };
struct s4 { char x[4]; };
struct s5 { char x[5]; };
struct s6 { char x[6]; };
struct s7 { char x[7]; };
struct s8 { char x[8]; };
struct s9 { char x[9]; };
struct s10 { char x[10]; };
struct s11 { char x[11]; };
struct s12 { char x[12]; };
struct s13 { char x[13]; };
struct s14 { char x[14]; };
struct s15 { char x[15]; };
struct s16 { char x[16]; };
struct s17 { char x[17]; };

struct hfa11 { float a; };
struct cv { float a, b; };
struct hfa13 { float a, b, c; };
struct hfa14 { float a, b, c, d; };

struct hfa21 { double a; };
struct hfa22 { double a, b; };
struct hfa23 { double a, b, c; };
struct hfa24 { double a, b, c, d; };

struct hfa31 { long double a; };
struct hfa32 { long double a, b; };
struct hfa33 { long double a, b, c; };
struct hfa34 { long double a, b, c, d; };

void fa_s3(struct s3 a) { printf("%.3s\n", a.x); }
void fa_s4(struct s4 a) { printf("%.4s\n", a.x); }
void fa_s5(struct s5 a) { printf("%.5s\n", a.x); }
void fa_s6(struct s6 a) { printf("%.6s\n", a.x); }
void fa_s7(struct s7 a) { printf("%.7s\n", a.x); }
void fa_s8(struct s8 a) { printf("%.8s\n", a.x); }
void fa_s9(struct s9 a) { printf("%.9s\n", a.x); }
void fa_hfa11(struct hfa11 a) { printf("%.1f\n", a.a); }

void myprintf(const char *format, ...) {
    const char *s;
    va_list ap;
    va_start(ap, format);
    for (s = format; *s; s++) {
        if (*s == '%') {
            s++;
            if (*s == '7' && *(s + 1) == 's') {
                struct s7 t7 = va_arg(ap, struct s7);
                printf("%.7s", t7.x);
                s += 1;
            }
            else if (*s == '9' && *(s + 1) == 's') {
                struct s9 t9 = va_arg(ap, struct s9);
                printf("%.9s", t9.x);
                s += 1;
            }
            // More formats can be handled similarly
        }
        else {
            putchar(*s);
        }
    }
    putchar('\n');
    va_end(ap);
}

void stdarg_example() {
    struct s9 s9 = {"ABCDEFGHI"};
    struct s7 s7 = {"lmnopqr"};
    printf("Standard Argument Example:\n");
    myprintf("%9s %7s", s9, s7);
}

int main() {
    test_foo_function();
    
    struct s3 s3 = {"345"};
    fa_s3(s3);

    stdarg_example();

    return 0;
}