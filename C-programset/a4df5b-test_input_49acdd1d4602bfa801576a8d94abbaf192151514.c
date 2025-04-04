#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

// Define structures with initial values
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

    struct hfa11 hf1 = fr_hfa11();
    struct hfa12 hf2 = fr_hfa12();
    struct hfa13 hf3 = fr_hfa13();
    struct hfa14 hf4 = fr_hfa14();

    struct hfa21 hf5 = fr_hfa21();
    struct hfa22 hf6 = fr_hfa22();
    struct hfa23 hf7 = fr_hfa23();
    struct hfa24 hf8 = fr_hfa24();

    struct hfa31 hf9 = fr_hfa31();
    struct hfa32 hf10 = fr_hfa32();
    struct hfa33 hf11 = fr_hfa33();
    struct hfa34 hf12 = fr_hfa34();
}

void stdarg(void) {
    printf("stdarg:\n");
    printf("%.9s %.9s %.9s %.9s %.9s\n", s9.x, s9.x, s9.x, s9.x, s9.x);
    printf("%.7s %.9s %.9s %.9s %.9s\n", s7.x, s9.x, s9.x, s9.x, s9.x);

    printf("HFA long double:\n");
    printf("%.1Lf,%.1Lf\n", hfa34.a, hfa34.d);
    printf("%.1Lf,%.1Lf\n", hfa33.a, hfa34.b);
    printf("%.1Lf,%.1Lf\n", hfa32.a, hfa34.c);
    printf("%.1Lf,%.1Lf\n", hfa31.a, hfa34.d);
    
    printf("HFA double:\n");
    printf("%.1lf,%.1lf\n", hfa24.a, hfa24.d);
    printf("%.1lf,%.1lf\n", hfa23.a, hfa24.b);
    printf("%.1lf,%.1lf\n", hfa22.a, hfa24.c);
    printf("%.1lf,%.1lf\n", hfa21.a, hfa24.d);
    
    printf("HFA float:\n");
    printf("%.1f,%.1f\n", hfa14.a, hfa14.d);
    printf("%.1f,%.1f\n", hfa13.a, hfa14.b);
    printf("%.1f,%.1f\n", hfa12.a, hfa14.c);
    printf("%.1f,%.1f\n", hfa11.a, hfa14.d);
}

void pll(unsigned long long x) {
    printf("%llx\n", x);
}

void movi(void) {
    printf("MOVI:\n");
    pll(0);
    pll(0xabcd);
    pll(0xabcd0000);
    pll(0xffffabcd);
    pll(0xabcdffff);
    pll(0xffffffffabcdffff);
}

void opi(void) {
    uint32_t x = 1000;
    printf("OPI:\n");
    pll(x + 0);
    pll(x - 0);
    pll(x + 123);
    pll(x + (-123));
    pll(x - 4095);
    pll(x - (-503808));
    pll(x + 12345);
    pll(x - 12345);
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