#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

// Define structures with specific sizes
struct s1 { char x[1]; };
struct s2 { char x[2]; };
struct s3 { char x[3]; };
struct s4 { char x[4]; };
struct s5 { char x[5]; };
struct s6 { char x[6]; };
struct s7 { char x[7]; };
struct s8 { char x[8]; };
struct s9 { char x[9]; };
struct s10 { char x[10]; };
struct s11 { char x[11]; };
struct s12 { char x[12]; };
struct s13 { char x[13]; };
struct s14 { char x[14]; };
struct s15 { char x[15]; };
struct s16 { char x[16]; };
struct s17 { char x[17]; };

// Define structures with float, double and long double
struct hfa11 { float a; };
struct hfa12 { float a, b; };
struct hfa13 { float a, b, c; };
struct hfa14 { float a, b, c, d; };

struct hfa21 { double a; };
struct hfa22 { double a, b; };
struct hfa23 { double a, b, c; };
struct hfa24 { double a, b, c, d; };

struct hfa31 { long double a; };
struct hfa32 { long double a, b; };
struct hfa33 { long double a, b, c; };
struct hfa34 { long double a, b, c, d; };

// Initialize all data
struct s1 s1 = { "0" };
struct s2 s2 = { "12" };
struct s3 s3 = { "345" };
struct s4 s4 = { "6789" };
struct s5 s5 = { "abcde" };
struct s6 s6 = { "fghijk" };
struct s7 s7 = { "lmnopqr" };
struct s8 s8 = { "stuvwxyz" };
struct s9 s9 = { "ABCDEFGHI" };
struct s10 s10 = { "JKLMNOPQRS" };
struct s11 s11 = { "TUVWXYZ0123" };
struct s12 s12 = { "456789abcdef" };
struct s13 s13 = { "ghijklmnopqrs" };
struct s14 s14 = { "tuvwxyzABCDEFG" };
struct s15 s15 = { "HIJKLMNOPQRSTU" };
struct s16 s16 = { "WXYZ0123456789ab" };
struct s17 s17 = { "cdefghijklmnopqrs" };

struct hfa11 hfa11 = { 11.1 };
struct hfa12 hfa12 = { 12.1, 12.2 };
struct hfa13 hfa13 = { 13.1, 13.2, 13.3 };
struct hfa14 hfa14 = { 14.1, 14.2, 14.3, 14.4 };

struct hfa21 hfa21 = { 21.1 };
struct hfa22 hfa22 = { 22.1, 22.2 };
struct hfa23 hfa23 = { 23.1, 23.2, 23.3 };
struct hfa24 hfa24 = { 24.1, 24.2, 24.3, 24.4 };

struct hfa31 hfa31 = { 31.1 };
struct hfa32 hfa32 = { 32.1, 32.2 };
struct hfa33 hfa33 = { 33.1, 33.2, 33.3 };
struct hfa34 hfa34 = { 34.1, 34.2, 34.3, 34.4 };

// Function definitions for printing
void print_structure_data(void) {
    printf("String struct values:\n");
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

    printf("\nHFA float struct values:\n");
    printf("%.1f\n", hfa11.a);
    printf("%.1f %.1f\n", hfa12.a, hfa12.b);
    printf("%.1f %.1f %.1f\n", hfa13.a, hfa13.b, hfa13.c);
    printf("%.1f %.1f %.1f %.1f\n", hfa14.a, hfa14.b, hfa14.c, hfa14.d);

    printf("\nHFA double struct values:\n");
    printf("%.1f\n", hfa21.a);
    printf("%.1f %.1f\n", hfa22.a, hfa22.b);
    printf("%.1f %.1f %.1f\n", hfa23.a, hfa23.b, hfa23.c);
    printf("%.1f %.1f %.1f %.1f\n", hfa24.a, hfa24.b, hfa24.c, hfa24.d);

    printf("\nHFA long double struct values:\n");
    printf("%.1Lf\n", hfa31.a);
    printf("%.1Lf %.1Lf\n", hfa32.a, hfa32.b);
    printf("%.1Lf %.1Lf %.1Lf\n", hfa33.a, hfa33.b, hfa33.c);
    printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", hfa34.a, hfa34.b, hfa34.c, hfa34.d);
}

int main() {
    printf("Printing Structures:\n");
    print_structure_data();
    
    return 0;
}