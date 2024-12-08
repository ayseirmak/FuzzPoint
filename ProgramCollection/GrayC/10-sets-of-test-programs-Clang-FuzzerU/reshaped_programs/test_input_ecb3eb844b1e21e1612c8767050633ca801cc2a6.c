#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

// Structure definitions with initialized data
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

// Define functions
static uint32_t addip123(uint32_t x) { return x + 123; }
static uint64_t addlm123(uint64_t x) { return x - 123; }
static uint32_t mvni(uint32_t x) { return ~x; }
static uint64_t negl(uint64_t x) { return -x; }
static uint32_t rsbi123(uint32_t x) { return 123 - x; }
static uint64_t rsbl123(uint64_t x) { return 123 - x; }

void pll(unsigned long long x) {
    printf("%llx\n", x);
}

// An operation method to process all arithmetic commands
void opi(void) {
    int x = 1000;
    pll(addip123(x));
    pll(addlm123(x));
    pll(mvni(x));
    pll(negl(x));
    pll(rsbi123(x));
    pll(rsbl123(x));
}

// Further functions like fa1, fa2, fa3, etc., following the method template
void pcs(void) {
    opi();
}

int main() {
    pcs();
    return 0;
}