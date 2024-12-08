#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

long long foo(long long t) {
    while (t > -4) {
        t -= 2;
    }
    return t;
}

int main(void) {
    if (foo(0) != -4) {
        abort();
    }
    return 0;
}

// Struct definitions
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

// HFA struct definitions
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

// Function to print structure content
void printStructContent() {
    // Showing exemplary prints for some structs
    printf("%.1s %.2s %.3s %.4s %.5s\n", s3.x, s4.x, s5.x, s6.x, s7.x);
}

void printHfaContent() {
    // Showing exemplary prints for HFA structs
    printf("%.1f %.1f %.1Lf %.1Lf\n", hfa11.a, hfa12.a, hfa31.a, hfa32.a);
}

int main() {
    printStructContent();
    printHfaContent();
    return 0;
}