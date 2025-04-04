#include <stdio.h>

// Define string structures
struct s1 { char x[1]; } s1 = { "0" };
struct s2 { char x[2]; } s2 = { "12" };
struct s3 { char x[3]; } s3 = { "345" };
struct s4 { char x[4]; } s4 = { "6789" };
struct s5 { char x[5]; } s5 = { "abcde" };
// Ensure no illegal escape or unexpected character sequences
struct s6 { char x[6]; } s6 = { "fghijk" };
struct s7 { char x[7]; } s7 = { "lmnopqr" };
struct s8 { char x[8]; } s8 = { "stuvwxyz" };

// Define float structures
struct hfa11 { float a; } hfa11 = { 11.1f };
struct hfa12 { float a, b; } hfa12 = { 12.1f, 12.2f };

// Define double structures
struct hfa21 { double a; } hfa21 = { 21.1 };
struct hfa22 { double a, b; } hfa22 = { 22.1, 22.2 };

// Define long double structures
struct hfa31 { long double a; } hfa31 = { 31.1 };
struct hfa32 { long double a, b; } hfa32 = { 32.1, 32.2 };

// Print functions for testing structure handling
void fa_s1(struct s1 a) { printf("fa_s1: %.1s\n", a.x); }
void fa_s2(struct s2 a) { printf("fa_s2: %.2s\n", a.x); }
void fa_s3(struct s3 a) { printf("fa_s3: %.3s\n", a.x); }

void fa_hfa11(struct hfa11 a) {
    printf("fa_hfa11: %.1f\n", a.a);
}

void fa_hfa12(struct hfa12 a) {
    printf("fa_hfa12: %.1f %.1f\n", a.a, a.b);
}

void fa_hfa21(struct hfa21 a) {
    printf("fa_hfa21: %.1f\n", a.a);
}

void fa_hfa22(struct hfa22 a) {
    printf("fa_hfa22: %.1f %.1f\n", a.a, a.b);
}

void fa_hfa31(struct hfa31 a) {
    printf("fa_hfa31: %.1Lf\n", a.a);
}

// Test function calling other print functions
void test_structs(void)
{
    printf("Testing:\n");
    fa_s1(s1);
    fa_s2(s2);
    fa_s3(s3);
    fa_hfa11(hfa11);
    fa_hfa12(hfa12);
    fa_hfa21(hfa21);
    fa_hfa22(hfa22);
    fa_hfa31(hfa31);
}

int main()
{
    test_structs();
    return 0;
}