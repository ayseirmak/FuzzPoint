#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

// Defining structures to handle string data
struct s1 { char x[1]; } s1 = { "0" };
struct s2 { char x[2]; } s2 = { "12" };
struct s3 { char x[3]; } s3 = { "345" };
struct s4 { char x[4]; } s4 = { "6789" };
struct s5 { char x[5]; } s5 = { "abcde" };
struct s6 { char x[6]; } s6 = { "fghijk" };
struct s7 { char x[7]; } s7 = { "lmnopqr" };
struct s8 { char x[8]; } s8 = { "stuvwxyz" };
struct s9 { char x[9]; } s9 = { "ABCDEFGHI" };
struct s10 { char x[10]; } s10 = { "JKLMNOPQRS" };
struct s11 { char x[11]; } s11 = { "TUVWXYZ0123" };
struct s12 { char x[12]; } s12 = { "456789abcdef" };
struct s13 { char x[13]; } s13 = { "ghijklmnopqrs" };
struct s14 { char x[14]; } s14 = { "tuvwxyzABCDEFG" };
struct s15 { char x[15]; } s15 = { "HIJKLMNOPQRSTUV" };
struct s16 { char x[16]; } s16 = { "WXYZ0123456789ab" };
struct s17 { char x[17]; } s17 = { "cdefghijklmnopqrs" };

// Defining structures to handle floating-point data
struct hfa11 { float a; } hfa11 = { 11.1 };
struct hfa12 { float a, b; } hfa12 = { 12.1, 12.2 };
struct hfa13 { float a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
struct hfa14 { float a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

struct hfa21 { double a; } hfa21 = { 21.1 };
struct hfa22 { double a, b; } hfa22 = { 22.1, 22.2 };
struct hfa23 { double a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
struct hfa24 { double a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

struct hfa31 { long double a; } hfa31 = { 31.1 };
struct hfa32 { long double a, b; } hfa32 = { 32.1, 32.2 };
struct hfa33 { long double a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
struct hfa34 { long double a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

// Function prototypes for printing data
void print_structs(void);
void print_return_values(void);
void print_varargs(void);
void print_operations(void);
static uint64_t do_operations(uint64_t x);

int main() {
    print_structs();
    print_return_values();
    print_varargs();
    print_operations();
    return 0;
}

void print_structs(void) {
    printf("Arguments:\n");
    printf("%.1s\n", s1.x);
    printf("%.2s\n", s2.x);
    printf("%.3s\n", s3.x);
    printf("%.4s\n", s4.x);
    printf("%.5s\n", s5.x);
    printf("%.6s\n", s6.x);
    printf("%.7s\n", s7.x);
    printf("%.8s\n", s8.x);
    printf("%.9s\n", s9.x);
    printf("%.10s\n", s10.x);
    printf("%.11s\n", s11.x);
    printf("%.12s\n", s12.x);
    printf("%.13s\n", s13.x);
    printf("%.14s\n", s14.x);
    printf("%.15s\n", s15.x);
    printf("%.16s\n", s16.x);
    printf("%.17s\n", s17.x);
}

void print_return_values(void) {
    printf("Return values:\n");
    printf("%.1s\n", s1.x);
    printf("%.2s\n", s2.x);
    printf("%.3s\n", s3.x);
    printf("%.4s\n", s4.x);
    printf("%.5s\n", s5.x);
    printf("%.6s\n", s6.x);
    printf("%.7s\n", s7.x);
    printf("%.8s\n", s8.x);
    printf("%.9s\n", s9.x);
    printf("%.10s\n", s10.x);
    printf("%.11s\n", s11.x);
    printf("%.12s\n", s12.x);
    printf("%.13s\n", s13.x);
    printf("%.14s\n", s14.x);
    printf("%.15s\n", s15.x);
    printf("%.16s\n", s16.x);
    printf("%.17s\n", s17.x);
    printf("%.1f\n", hfa11.a);
    printf("%.1f %.1f\n", hfa12.a, hfa12.b);
    printf("%.1f %.1f %.1f\n", hfa13.a, hfa13.b, hfa13.c);
    printf("%.1f %.1f %.1f %.1f\n", hfa14.a, hfa14.b, hfa14.c, hfa14.d);
    printf("%.1f\n", hfa21.a);
    printf("%.1f %.1f\n", hfa22.a, hfa22.b);
    printf("%.1f %.1f %.1f\n", hfa23.a, hfa23.b, hfa23.c);
    printf("%.1f %.1f %.1f %.1f\n", hfa24.a, hfa24.b, hfa24.c, hfa24.d);
    printf("%.1Lf\n", hfa31.a);
    printf("%.1Lf %.1Lf\n", hfa32.a, hfa32.b);
    printf("%.1Lf %.1Lf %.1Lf\n", hfa33.a, hfa33.b, hfa33.c);
    printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", hfa34.a, hfa34.b, hfa34.c, hfa34.d);
}

void myprintf(const char *format, ...) {
    const char *s;
    va_list ap;
    va_start(ap, format);
    for (s = format; *s; s++) {
        if (!strncmp(s, "%9s", 3)) {
            struct s9 t9 = va_arg(ap, struct s9);
            printf("%.9s", t9.x);
            s += 2;
        } else if (!strncmp(s, "%hfa12", 6)) {
            struct hfa12 x = va_arg(ap, struct hfa12);
            printf("%.1f,%.1f", x.a, x.b);
            s += 5;
        } else {
            putchar(*s);
        }
    }
    putchar('\n');
    va_end(ap);
}

void print_varargs(void) {
    printf("stdarg:\n");
    myprintf("%9s", s9);
    myprintf("%hfa12", hfa12);
}

void print_operations(void) {
    uint64_t x = 1000;
    printf("Result of operations: 0x%llx\n", (unsigned long long)do_operations(x));
}

static uint64_t do_operations(uint64_t x) {
    return x + 12345;
}