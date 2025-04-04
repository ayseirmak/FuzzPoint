#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

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

struct hfa31 { long double a; } hfa31 = { 31.1L };
struct hfa32 { long double a, b; } hfa32 = { 32.1L, 32.2L };
struct hfa33 { long double a, b, c; } hfa33 = { 33.1L, 33.2L, 33.3L };
struct hfa34 { long double a, b, c, d; } hfa34 = { 34.1L, 34.2L, 34.3L, 34.4L };

void fa_s1(struct s1 a) { printf("%.1s\n", a.x); }
void fa_s2(struct s2 a) { printf("%.2s\n", a.x); }
void fa_s3(struct s3 a) { printf("%.3s\n", a.x); }
void fa_s4(struct s4 a) { printf("%.4s\n", a.x); }
void fa_s5(struct s5 a) { printf("%.5s\n", a.x); }
void fa_s6(struct s6 a) { printf("%.6s\n", a.x); }
void fa_s7(struct s7 a) { printf("%.7s\n", a.x); }
void fa_s8(struct s8 a) { printf("%.8s\n", a.x); }
void fa_s9(struct s9 a) { printf("%.9s\n", a.x); }
void fa_s10(struct s10 a) { printf("%.10s\n", a.x); }
void fa_s11(struct s11 a) { printf("%.11s\n", a.x); }
void fa_s12(struct s12 a) { printf("%.12s\n", a.x); }
void fa_s13(struct s13 a) { printf("%.13s\n", a.x); }
void fa_s14(struct s14 a) { printf("%.14s\n", a.x); }
void fa_s15(struct s15 a) { printf("%.15s\n", a.x); }
void fa_s16(struct s16 a) { printf("%.16s\n", a.x); }
void fa_s17(struct s17 a) { printf("%.17s\n", a.x); }

void fa_hfa11(struct hfa11 a) { printf("%.1f\n", a.a); }
void fa_hfa12(struct hfa12 a) { printf("%.1f %.1f\n", a.a, a.b); }
void fa_hfa13(struct hfa13 a) { printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
void fa_hfa14(struct hfa14 a) { printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

void fa_hfa21(struct hfa21 a) { printf("%.1f\n", a.a); }
void fa_hfa22(struct hfa22 a) { printf("%.1f %.1f\n", a.a, a.b); }
void fa_hfa23(struct hfa23 a) { printf("%.1f %.1f %.1f\n", a.a, a.b, a.c); }
void fa_hfa24(struct hfa24 a) { printf("%.1f %.1f %.1f %.1f\n", a.a, a.b, a.c, a.d); }

void fa_hfa31(struct hfa31 a) { printf("%.1Lf\n", a.a); }
void fa_hfa32(struct hfa32 a) { printf("%.1Lf %.1Lf\n", a.a, a.b); }
void fa_hfa33(struct hfa33 a) { printf("%.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c); }
void fa_hfa34(struct hfa34 a) { printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", a.a, a.b, a.c, a.d); }

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
    fa_s2(s2);
    fa_s3(s3);
    fa_s4(s4);
    fa_s5(s5);
    fa_s6(s6);
    fa_s7(s7);
    fa_s8(s8);
    fa_s9(s9);
    fa_s10(s10);
    fa_s11(s11);
    fa_s12(s12);
    fa_s13(s13);
    fa_s14(s14);
    fa_s15(s15);
    fa_s16(s16);
    fa_s17(s17);
    fa_hfa11(hfa11);
    fa_hfa12(hfa12);
    fa_hfa13(hfa13);
    fa_hfa14(hfa14);
    fa_hfa21(hfa21);
    fa_hfa22(hfa22);
    fa_hfa23(hfa23);
    fa_hfa24(hfa24);
    fa_hfa31(hfa31);
    fa_hfa32(hfa32);
    fa_hfa33(hfa33);
    fa_hfa34(hfa34);
    fa1(s8, s9, s10, s11, s12, s13);
    fa2(s9, s10, s11, s12, s13, s14);
    fa3(hfa14, hfa23, hfa32);
    fa4(s1, hfa14, s2, hfa24, s3, hfa34);
}

struct s1 fr_s1(void) { return s1; }
struct s2 fr_s2(void) { return s2; }
struct s3 fr_s3(void) { return s3; }
struct s4 fr_s4(void) { return s4; }
struct s5 fr_s5(void) { return s5; }
struct s6 fr_s6(void) { return s6; }
struct s7 fr_s7(void) { return s7; }
struct s8 fr_s8(void) { return s8; }
struct s9 fr_s9(void) { return s9; }
struct s10 fr_s10(void) { return s10; }
struct s11 fr_s11(void) { return s11; }
struct s12 fr_s12(void) { return s12; }
struct s13 fr_s13(void) { return s13; }
struct s14 fr_s14(void) { return s14; }
struct s15 fr_s15(void) { return s15; }
struct s16 fr_s16(void) { return s16; }
struct s17 fr_s17(void) { return s17; }

struct hfa11 fr_hfa11(void) { return hfa11; }
struct hfa12 fr_hfa12(void) { return hfa12; }
struct hfa13 fr_hfa13(void) { return hfa13; }
struct hfa14 fr_hfa14(void) { return hfa14; }

struct hfa21 fr_hfa21(void) { return hfa21; }
struct hfa22 fr_hfa22(void) { return hfa22; }
struct hfa23 fr_hfa23(void) { return hfa23; }
struct hfa24 fr_hfa24(void) { return hfa24; }

struct hfa31 fr_hfa31(void) { return hfa31; }
struct hfa32 fr_hfa32(void) { return hfa32; }
struct hfa33 fr_hfa33(void) { return hfa33; }
struct hfa34 fr_hfa34(void) { return hfa34; }

void ret(void) {
    struct s1 t1 = fr_s1();
    struct s2 t2 = fr_s2();
    struct s3 t3 = fr_s3();
    struct s4 t4 = fr_s4();
    struct s5 t5 = fr_s5();
    struct s6 t6 = fr_s6();
    struct s7 t7 = fr_s7();
    struct s8 t8 = fr_s8();
    struct s9 t9 = fr_s9();
    struct s10 t10 = fr_s10();
    struct s11 t11 = fr_s11();
    struct s12 t12 = fr_s12();
    struct s13 t13 = fr_s13();
    struct s14 t14 = fr_s14();
    struct s15 t15 = fr_s15();
    struct s16 t16 = fr_s16();
    struct s17 t17 = fr_s17();
    printf("Return values:\n");
    printf("%.1s\n", t1.x);
    printf("%.2s\n", t2.x);
    printf("%.3s\n", t3.x);
    printf("%.4s\n", t4.x);
    printf("%.5s\n", t5.x);
    printf("%.6s\n", t6.x);
    printf("%.7s\n", t7.x);
    printf("%.8s\n", t8.x);
    printf("%.9s\n", t9.x);
    printf("%.10s\n", t10.x);
    printf("%.11s\n", t11.x);
    printf("%.12s\n", t12.x);
    printf("%.13s\n", t13.x);
    printf("%.14s\n", t14.x);
    printf("%.15s\n", t15.x);
    printf("%.16s\n", t16.x);
    printf("%.17s\n", t17.x);
    printf("%.1f\n", fr_hfa11().a);
    printf("%.1f %.1f\n", fr_hfa12().a, fr_hfa12().b);
    printf("%.1f %.1f %.1f\n", fr_hfa13().a, fr_hfa13().b, fr_hfa13().c);
    printf("%.1f %.1f %.1f %.1f\n", fr_hfa14().a, fr_hfa14().b, fr_hfa14().c, fr_hfa14().d);
    printf("%.1f\n", fr_hfa21().a);
    printf("%.1f %.1f\n", fr_hfa22().a, fr_hfa22().b);
    printf("%.1f %.1f %.1f\n", fr_hfa23().a, fr_hfa23().b, fr_hfa23().c);
    printf("%.1f %.1f %.1f %.1f\n", fr_hfa24().a, fr_hfa24().b, fr_hfa24().c, fr_hfa24().d);
    printf("%.1Lf\n", fr_hfa31().a);
    printf("%.1Lf %.1Lf\n", fr_hfa32().a, fr_hfa32().b);
    printf("%.1Lf %.1Lf %.1Lf\n", fr_hfa33().a, fr_hfa33().b, fr_hfa33().c);
    printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", fr_hfa34().a, fr_hfa34().b, fr_hfa34().c, fr_hfa34().d);
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
        if (match(&s, "%7s")) {
            struct s7 t7 = va_arg(ap, struct s7);
            printf("%.7s", t7.x);
        }
        else if (match(&s, "%9s")) {
            struct s9 t9 = va_arg(ap, struct s9);
            printf("%.9s", t9.x);
        }
        else if (match(&s, "%hfa11")) {
            struct hfa11 x = va_arg(ap, struct hfa11);
            printf("%.1f,%.1f", x.a, x.a);
        }
        else if (match(&s, "%hfa12")) {
            struct hfa12 x = va_arg(ap, struct hfa12);
            printf("%.1f,%.1f", x.a, x.b);
        }
        else if (match(&s, "%hfa13")) {
            struct hfa13 x = va_arg(ap, struct hfa13);
            printf("%.1f,%.1f %.1f", x.a, x.b, x.c);
        }
        else if (match(&s, "%hfa14")) {
            struct hfa14 x = va_arg(ap, struct hfa14);
            printf("%.1f,%.1f", x.a, x.d);
        }
        else if (match(&s, "%hfa21")) {
            struct hfa21 x = va_arg(ap, struct hfa21);
            printf("%.1f,%.1f", x.a, x.a);
        }
        else if (match(&s, "%hfa22")) {
            struct hfa22 x = va_arg(ap, struct hfa22);
            printf("%.1f,%.1f", x.a, x.b);
        }
        else if (match(&s, "%hfa23")) {
            struct hfa23 x = va_arg(ap, struct hfa23);
            printf("%.1f,%.1f %.1f", x.a, x.b, x.c);
        }
        else if (match(&s, "%hfa24")) {
            struct hfa24 x = va_arg(ap, struct hfa24);
            printf("%.1f,%.1f", x.a, x.d);
        }
        else if (match(&s, "%hfa31")) {
            struct hfa31 x = va_arg(ap, struct hfa31);
            printf("%.1Lf,%.1Lf", x.a, x.a);
        }
        else if (match(&s, "%hfa32")) {
            struct hfa32 x = va_arg(ap, struct hfa32);
            printf("%.1Lf,%.1Lf", x.a, x.b);
        }
        else if (match(&s, "%hfa33")) {
            struct hfa33 x = va_arg(ap, struct hfa33);
            printf("%.1Lf,%.1Lf %.1Lf", x.a, x.b, x.c);
        }
        else if (match(&s, "%hfa34")) {
            struct hfa34 x = va_arg(ap, struct hfa34);
            printf("%.1Lf,%.1Lf", x.a, x.d);
        }
        else
            putchar(*s);
    }
    putchar('\n');
    va_end(ap);
}

void stdarg(void) {
    printf("stdarg:\n");
    myprintf("%9s %9s %9s %9s %9s %9s", s9, s9, s9, s9, s9, s9);
    myprintf("%7s %9s %9s %9s %9s %9s", s7, s9, s9, s9, s9, s9);

    myprintf("HFA long double:");
    myprintf("%hfa34 %hfa34 %hfa34 %hfa34", hfa34, hfa34, hfa34, hfa34);
    myprintf("%hfa33 %hfa34 %hfa13 %hfa13", hfa33, hfa34, hfa13, hfa13);
    myprintf("%hfa11 %hfa13 %hfa13 %hfa13 %hfa13", hfa11, hfa13, hfa13, hfa13, hfa13);
    myprintf("%hfa13 %hfa13 %hfa13 %hfa13", hfa13, hfa13, hfa13, hfa13);

    myprintf("%hfa14 %hfa12 %hfa12 %hfa12 %hfa12", hfa14, hfa12, hfa12, hfa12, hfa12);
    myprintf("%hfa13 %hfa12 %hfa12 %hfa12 %hfa12", hfa13, hfa12, hfa12, hfa12, hfa12);
    myprintf("%hfa14 %hfa12 %hfa11 %hfa11 %hfa11 %hfa11", hfa14, hfa12, hfa11, hfa11, hfa11, hfa11);
}

void pll(unsigned long long x) {
    printf("%llx\n", x);
}

void movi(void) {
    printf("MOVI:\n");
    pll(0);
    pll(0xabcd);
    pll(0xabcd0000);
    pll(0xabcd00000000);
    pll(0xabcd000000000000);
    pll(0xffffabcd);
    pll(0xabcdffff);
    pll(0xffffffffffffabcd);
    pll(0xffffffffabcdffff);
    pll(0xffffabcdffffffff);
    pll(0xabcdffffffffffff);
    pll(0xaaaaaaaa);
    pll(0x5555555555555555);
    pll(0x77777777);
    pll(0x3333333333333333);
    pll(0xf8f8f8f8);
    pll(0x1e1e1e1e1e1e1e1e);
    pll(0x3f803f80);
    pll(0x01ff01ff01ff01ff);
    pll(0x007fffc0);
    pll(0x03fff80003fff800);
    pll(0x0007fffffffffe00);
    pll(0xabcd1234);
    pll(0xabcd00001234);
    pll(0xabcd000000001234);
    pll(0xabcd12340000);
    pll(0xabcd000012340000);
    pll(0xabcd123400000000);
    pll(0xffffffffabcd1234);
    pll(0xffffabcdffff1234);
    pll(0xabcdffffffff1234);
    pll(0xffffabcd1234ffff);
    pll(0xabcdffff1234ffff);
    pll(0xabcd1234ffffffff);

    pll(0xffffef0123456789);
    pll(0xabcdef012345ffff);
    pll(0xabcdef0123456789);
}

static uint32_t addip0(uint32_t x) { return x + 0; }
static uint64_t sublp0(uint64_t x) { return x - 0; }
static uint32_t addip123(uint32_t x) { return x + 123; }
static uint64_t addlm123(uint64_t x) { return x + -123; }
static uint64_t sublp4095(uint64_t x) { return x - 4095; }
static uint32_t subim503808(uint32_t x) { return x - -503808; }
static uint64_t addp12345(uint64_t x) { return x + 12345; }
static uint32_t subp12345(uint32_t x) { return x - 12345; }

static uint32_t mvni(uint32_t x) { return 0xffffffff - x; }
static uint64_t negl(uint64_t x) { return 0 - x; }
static uint32_t rsbi123(uint32_t x) { return 123 - x; }
static uint64_t rsbl123(uint64_t x) { return 123 - x; }

static uint32_t andi0(uint32_t x) { return x & 0; }
static uint64_t andlm1(uint64_t x) { return x & -1; }
static uint64_t orrl0(uint64_t x) { return x | 0; }
static uint32_t orrim1(uint32_t x) { return x | -1; }
static uint32_t eori0(uint32_t x) { return x ^ 0; }
static uint64_t eorlm1(uint64_t x) { return x ^ -1; }
static uint32_t and0xf0(uint32_t x) { return x & 0xf0; }
static uint64_t orr0xf0(uint64_t x) { return x | 0xf0; }
static uint64_t eor0xf0(uint64_t x) { return x ^ 0xf0; }

static uint32_t lsli0(uint32_t x) { return x << 0; }
static uint32_t lsri0(uint32_t x) { return x >> 0; }
static int64_t asrl0(int64_t x) { return x >> 0; }
static uint32_t lsli1(uint32_t x) { return x << 1; }
static uint32_t lsli31(uint32_t x) { return x << 31; }
static uint64_t lsll1(uint64_t x) { return x << 1; }
static uint64_t lsll63(uint64_t x) { return x << 63; }
static uint32_t lsri1(uint32_t x) { return x >> 1; }
static uint32_t lsri31(uint32_t x) { return x >> 31; }
static uint64_t lsrl1(uint64_t x) { return x >> 1; }
static uint64_t lsrl63(uint64_t x) { return x >> 63; }
static int32_t asri1(int32_t x) { return x >> 1; }
static int32_t asri31(int32_t x) { return x >> 31; }
static int64_t asrl1(int64_t x) { return x >> 1; }
static int64_t asrl63(int64_t x) { return x >> 63; }

void opi(void) {
    unsigned long long x;
    
    x = addip0(1000);
    pll(x);
    x = sublp0(x);
    pll(x);
    x = addip123(x);
    pll(x);
    x = addlm123(x);
    pll(x);
    x = sublp4095(x);
    pll(x);
    x = subim503808(x);
    pll(x);
    x = addp12345(x);
    pll(x);
    x = subp12345(x);
    pll(x);
    x = mvni(x);
    pll(x);
    x = negl(x);
    pll(x);
    x = rsbi123(x);
    pll(x);
    x = rsbl123(x);
    pll(x);
    x = andi0(x);
    pll(x);
    x = andlm1(x);
    pll(x);
    x = orrl0(x);
    pll(x);
    x = orrim1(x);
    pll(x);
    x = eori0(x);
    pll(x);
    x = eorlm1(x);
    pll(x);
    x = and0xf0(x);
    pll(x);
    x = orr0xf0(x);
    pll(x);
    x = eor0xf0(x);
    pll(x);
    x = lsli0(x);
    pll(x);
    x = lsri0(x);
    pll(x);
    x = asrl0(x);
    pll(x);
    x = lsli1(x);
    pll(x);
    x = lsli31(x);
    pll(x);
    x = lsll1(x);
    pll(x);
    x = lsll63(x);
    pll(x);
    x = lsri1(x);
    pll(x);
    x = lsri31(x);
    pll(x);
    x = lsrl1(x);
    pll(x);
    x = lsrl63(x);
    pll(x);
    x = asri1(x);
    pll(x);
    x = asri31(x);
    pll(x);
    x = asrl1(x);
    pll(x);
    x = asrl63(x);
    pll(x);
}

void pcs(void) {
    arg();
    ret();
    stdarg();
    movi();
    opi();
}

int main() {
    pcs();
    return 0;
}