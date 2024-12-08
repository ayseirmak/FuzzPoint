#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

// Define Structs with initialized variables
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

// Function prototypes
void print_structs(void);
void test_initializers(void);

// Main function
int main(void) {
    print_structs();
    test_initializers();
    return 0;
}

void print_structs(void) {
    printf("String structures:\n");
    printf("%s\n", s1.x);
    printf("%s\n", s2.x);
    printf("%s\n", s3.x);
    printf("%s\n", s4.x);
    printf("%s\n", s5.x);
    printf("%s\n", s6.x);
    printf("%s\n", s7.x);
    printf("%s\n", s8.x);
    printf("%s\n", s9.x);
    printf("%s\n", s10.x);
    printf("%s\n", s11.x);
    printf("%s\n", s12.x);
    printf("%s\n", s13.x);
    printf("%s\n", s14.x);
    printf("%s\n", s15.x);
    printf("%s\n", s16.x);
    printf("%s\n", s17.x);

    printf("\nFloating point structures:\n");
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

void test_initializers(void) {
    struct SEA sea1 = { .i = 0, .j = 5, .k = 0, .l = 0 };
    printf("\nTesting correct filling:\n");
    if (sea1.i == 0 && sea1.j == 5 && sea1.k == 0 && sea1.l == 0) {
        printf("Initialization for sea1: okay\n");
    } else {
        printf("Initialization for sea1: wrong\n");
    }
}