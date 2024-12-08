#include <stdio.h>
#include <stdint.h>

// Define structures with character arrays
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

// Define structures with floating-point numbers
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

void print_structs(void) {
    printf("Struct data:\n");
    printf("%.1s %.2s %.3s %.4s %.5s %.6s %.7s %.8s %.9s %.10s %.11s %.12s %.13s %.14s %.15s %.16s %.17s\n",
           s1.x, s2.x, s3.x, s4.x, s5.x, s6.x, s7.x, s8.x, s9.x, s10.x, s11.x, 
           s12.x, s13.x, s14.x, s15.x, s16.x, s17.x);

    printf("Floating point data:\n");
    printf("%.1f %.1f %.1f %.1f\n", hfa11.a, hfa12.a, hfa13.a, hfa14.a);
    printf("%.1lf %.1lf %.1lf %.1lf\n", hfa21.a, hfa22.a, hfa23.a, hfa24.a);
    printf("%.1Lf %.1Lf %.1Lf %.1Lf\n", hfa31.a, hfa32.a, hfa33.a, hfa34.a);
}

int main() {
    print_structs();
    return 0;
}