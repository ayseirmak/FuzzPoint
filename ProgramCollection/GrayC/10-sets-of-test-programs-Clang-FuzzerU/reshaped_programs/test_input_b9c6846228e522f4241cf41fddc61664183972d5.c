/* Taken from: https://github.com/c-testsuite/c-testsuite */

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

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

struct hfa11 { float a; } hfa11 = { 11.1f };
struct hfa12 { float a, b; } hfa12 = { 12.1f, 12.2f };
struct hfa13 { float a, b, c; } hfa13 = { 13.1f, 13.2f, 13.3f };
struct hfa14 { float a, b, c, d; } hfa14 = { 14.1f, 14.2f, 14.3f, 14.4f };

struct hfa21 { double a; } hfa21 = { 21.1 };
struct hfa22 { double a, b; } hfa22 = { 22.1, 22.2 };
struct hfa23 { double a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
struct hfa24 { double a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

struct hfa31 { long double a; } hfa31 = { 31.1 };
struct hfa32 { long double a, b; } hfa32 = { 32.1, 32.2 };
struct hfa33 { long double a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
struct hfa34 { long double a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

// Functions for printing fixed-size character structs
void fa_s1(struct s1 a) { printf("%.1s\n", a.x); }
// Similar functions for other structs (fa_s2 to fa_s17) omitted for brevity

// Functions for floating point structs
void fa_hfa11(struct hfa11 a) { printf("%.1f\n", a.a); }
// Similar functions for other HFA structs (fa_hfa12 to fa_hfa34) omitted for brevity

void fa1(struct s8 a, struct s9 b, struct s10 c, struct s11 d, struct s12 e, struct s13 f) {
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

void fa2(struct s9 a, struct s10 b, struct s11 c, struct s12 d, struct s13 e, struct s14 f) {
    printf("%.3s %.3s %.3s %.3s %.3s %.3s\n", a.x, b.x, c.x, d.x, e.x, f.x);
}

void fa3(struct hfa14 a, struct hfa23 b, struct hfa32 c) {
    printf("%.1f %.1f %.1f %.1f %.1Lf %.1Lf\n", a.a, a.d, b.a, b.c, c.a, c.b);
}

void fa4(struct s1 a, struct hfa14 b, struct s2 c, struct hfa24 d, struct s3 e, struct hfa34 f) {
    printf("%.1s %.1f %.1f %.2s %.1f %.1f %.3s %.1Lf %.1Lf\n", a.x, b.a, b.d, c.x, d.a, d.d, e.x, f.a, f.d);
}

void arg(void) {
    printf("Arguments:\n");
    fa_s1(s1);
    // Similar function calls omitted for brevity
}

struct s1 fr_s1(void) { return s1; }
// Similar functions for other struct returners (fr_s2 to fr_s17, fr_hfa11 to fr_hfa34) omitted for brevity

void ret(void) {
    struct s1 t1 = fr_s1();
    struct s2 t2 = fr_s2();
    // Similar assignments and printf statements omitted for brevity
}

int match(const char **s, const char *f) {
    const char *p = *s;
    while (*f && *f == *p) {
        f++;
        p++;
    }
    if (!*f) {
        *s = p - 1;
        return 1;
    }
    return 0;
}

void myprintf(const char *format, ...) {
    const char *s;
    va_list ap;
    va_start(ap, format);
    for (s = format; *s; s++) {
        // Dynamic content printing omitted for brevity
    }
    va_end(ap);
    putchar('\n');
}

void stdarg(void) {
    printf("stdarg:\n");
    myprintf("%9s %9s %9s %9s %9s %9s", s9, s9, s9, s9, s9, s9);
    // Similar function calls omitted for brevity
}

void pll(unsigned long long x) {
    printf("%llx\n", x);
}

void movi(void) {
    printf("MOVI:\n");
    pll(0);
    // Similar printf calls with pll omitted for brevity
}

void opi(void) {
    int x = 1000;
    pll(addip0(x));
    // Similar calls to pll with operations omitted for brevity
}

void pcs(void) {
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

int main(void) {
    pcs();
    return 0;
}