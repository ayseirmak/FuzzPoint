#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

// Define all structures
struct s1 { char x[1]; } s1 = { "a" };
struct s2 { char x[2]; } s2 = { "ab" };
struct s3 { char x[3]; } s3 = { "abc" };
struct s4 { char x[4]; } s4 = { "abcd" };
struct s5 { char x[5]; } s5 = { "abcde" };
struct s6 { char x[6]; } s6 = { "abcdef" };
struct s7 { char x[7]; } s7 = { "abcdefg" };
struct s8 { char x[8]; } s8 = { "abcdefgh" };
struct s9 { char x[9]; } s9 = { "abcdefghi" };
struct s10 { char x[10]; } s10 = { "abcdefghij" };
struct s11 { char x[11]; } s11 = { "abcdefghijk" };
struct s12 { char x[12]; } s12 = { "abcdefghijkl" };
struct s13 { char x[13]; } s13 = { "abcdefghijklm" };
struct s14 { char x[14]; } s14 = { "abcdefghijklmn" };
struct s15 { char x[15]; } s15 = { "abcdefghijklmno" };
struct s16 { char x[16]; } s16 = { "abcdefghijklmnop" };
struct s17 { char x[17]; } s17 = { "abcdefghijklmnopq" };

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

// Function declarations
void fa_s1(struct s1 a) { printf("%.1s\n", a.x); }
// ... similar declarations for fa_s2 to fa_s17 ...
void fa_s17(struct s17 a) { printf("%.17s\n", a.x); }

void fa_hfa11(struct hfa11 a) { printf("%.1f\n", a.a); }
void fa_hfa12(struct hfa12 a) { printf("%.1f %.1f\n", a.a, a.b); }
void fa_hfa13(struct hfa13 a) { printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
void fa_hfa14(struct hfa14 a) { printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

void fa_hfa21(struct hfa21 a) { printf("%.1f\n", a.a); }
// ... similar declarations for fa_hfa22, fa_hfa23, fa_hfa24 ...
void fa_hfa24(struct hfa24 a) { printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

void fa_hfa31(struct hfa31 a) { printf("%.1Lf\n", a.a); }
// ... similar declarations for fa_hfa32 to fa_hfa34 ...
void fa_hfa34(struct hfa34 a) { printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }

void arg(void)
{
    printf("Arguments:\n");
    fa_s1(s1); fa_s2(s2); fa_s3(s3); fa_s4(s4); fa_s5(s5);
    fa_s6(s6); fa_s7(s7); fa_s8(s8); fa_s9(s9); fa_s10(s10);
    fa_s11(s11); fa_s12(s12); fa_s13(s13); fa_s14(s14); fa_s15(s15);
    fa_s16(s16); fa_s17(s17);

    fa_hfa11(hfa11); fa_hfa12(hfa12); fa_hfa13(hfa13); fa_hfa14(hfa14);
    fa_hfa21(hfa21); fa_hfa22(hfa22); fa_hfa23(hfa23); fa_hfa24(hfa24);
    fa_hfa31(hfa31); fa_hfa32(hfa32); fa_hfa33(hfa33); fa_hfa34(hfa34);
}

// Structure return functions will remain similar

int match(const char **s, const char *f)
{
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

void myprintf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    for (const char *s = format; *s; s++) {
        if (match(&s, "%7s")) {
            struct s7 t7 = va_arg(ap, struct s7);
            printf("%.7s", t7.x);
        } 
        else if (match(&s, "%9s")) {
            struct s9 t9 = va_arg(ap, struct s9);
            printf("%.9s", t9.x);
        } 
        else {
            putchar(*s);
        }
    }
    va_end(ap);
    putchar('\n');
}

void stdarg(void)
{
    printf("stdarg:\n");
    myprintf("%9s %9s %9s %9s %9s %9s", s9, s9, s9, s9, s9, s9);
    myprintf("%7s %9s %9s %9s %9s %9s", s7, s9, s9, s9, s9, s9);
    // Add more calls as required
}

void pll(unsigned long long x)
{
    printf("%llx\n", x);
}

void movi(void)
{
    printf("MOVI:\n");
    pll(0xabcd);
    // Add more calls as required
}

static uint32_t addip0(uint32_t x) { return x + 0; }

void opi(void)
{
    int x = 1000;
    pll(addip0(x));
    // Add more calls as required
}

void pcs(void)
{
    arg();
    // Add more calls if required
}

int main(void)
{
    pcs();
    return 0;
}