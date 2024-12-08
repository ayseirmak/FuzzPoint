#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Structures with fixed strings
struct s1 { char x[2]; } s1 = { "0" };
struct s2 { char x[3]; } s2 = { "12" };
struct s3 { char x[4]; } s3 = { "345" };
struct s4 { char x[5]; } s4 = { "6789" };
struct s5 { char x[6]; } s5 = { "abcde" };
struct s6 { char x[7]; } s6 = { "fghijk" };
struct s7 { char x[8]; } s7 = { "lmnopqr" };
struct s8 { char x[9]; } s8 = { "stuvwxyz" };
struct s9 { char x[10]; } s9 = { "ABCDEFGHI" };
struct s10 { char x[11]; } s10 = { "JKLMNOPQRS" };
struct s11 { char x[12]; } s11 = { "TUVWXYZ0123" };
struct s12 { char x[13]; } s12 = { "456789abcdef" };
struct s13 { char x[14]; } s13 = { "ghijklmnopqrs" };
struct s14 { char x[15]; } s14 = { "tuvwxyzABCDEFG" };
struct s15 { char x[16]; } s15 = { "HIJKLMNOPQRSTUV" };
struct s16 { char x[17]; } s16 = { "WXYZ0123456789ab" };
struct s17 { char x[18]; } s17 = { "cdefghijklmnopqrs" };

// Structures with floating point values
struct hfa11 { float a; };
struct hfa12 { float a, b; };
struct hfa13 { float a, b, c; };
struct hfa14 { float a, b, c, d; };
struct hfa21 { double a; };
struct hfa24 { double a, b, c, d; };
struct hfa31 { long double a; };
struct hfa32 { long double a, b; };
struct hfa33 { long double a, b, c; };
struct hfa34 { long double a, b, c, d; };

static struct hfa11 hfa11 = { 11.1f };
static struct hfa12 hfa12 = { 12.1f, 12.2f };
static struct hfa13 hfa13 = { 13.1f, 13.2f, 13.3f };
static struct hfa14 hfa14 = { 14.1f, 14.2f, 14.3f, 14.4f };
static struct hfa21 hfa21 = { 21.1 };
static struct hfa24 hfa24 = { 24.1, 24.2, 24.3, 24.4 };
static struct hfa31 hfa31 = { 31.1 };
static struct hfa32 hfa32 = { 32.1, 32.2 };
static struct hfa33 hfa33 = { 33.1, 33.2, 33.3 };
static struct hfa34 hfa34 = { 34.1, 34.2, 34.3, 34.4 };

// Print functions for each structure
void fa_s1(struct s1 a) { printf("%.1s\n", a.x); }
void fa_s2(struct s2 a) { printf("%.2s\n", a.x); }
void fa_s3(struct s3 a) { printf("%.3s\n", a.x); }
void fa_s4(struct s4 a) { printf("%.4s\n", a.x); }
void fa_s5(struct s5 a) { printf("%.5s\n", a.x); }
void fa_s6(struct s6 a) { printf("%.6s\n", a.x); }
void fa_s7(struct s7 a) { printf("%.7s\n", a.x); }
void fa_s8(struct s8 a) { printf("%.8s\n", a.x); }
void fa_s9(struct s9 a) { printf("%.9s\n", a.x); }

void stdarg(void) {
    printf("stdarg:\n");
    printf("%9s %9s %9s %9s %9s %9s\n", s9.x, s9.x, s9.x, s9.x, s9.x, s9.x);
    printf("%7s %9s %9s %9s %9s %9s\n", s7.x, s9.x, s9.x, s9.x, s9.x, s9.x);
}

void pll(unsigned long long x) {
    printf("%llx\n", x);
}

void movi(void) {
    printf("MOVI:\n");
    pll(0xabcdef0123456789);
    pll(0xffffef0123456789);
}

static uint32_t addip0(uint32_t x) { return x + 0; }
static uint64_t sublp0(uint64_t x) { return x - 0; }
static uint32_t addip123(uint32_t x) { return x + 123; }
// More functions simplified for brevity

void opi(void) {
    int x = 1000;
    pll(addip0(x));
    pll(sublp0(x));
    pll(addip123(x));
    // More function calls as needed
}

void pcs(void) {
    stdarg();
    movi();
    opi();
}

int main(void) {
    pcs();
    return 0;
}