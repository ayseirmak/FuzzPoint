#include <stdio.h>
#include <stdarg.h>

// Define the structures
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

void myprintf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    const char *s = fmt;
    while (*s) {
        if (*s == '%') {
            s++;
            if (*s == '9') {
                struct s9 x = va_arg(ap, struct s9);
                printf("%.9s", x.x);
            } else if (*s == '7') {
                struct s7 x = va_arg(ap, struct s7);
                printf("%.7s", x.x);
            } else if (*s == 'h' && *(s + 1) == 'f' && *(s + 2) == 'a') {
                s += 3;
                switch (*s) {
                    case '3':
                        switch (*(s + 1)) {
                            case '4': {
                                struct hfa34 x = va_arg(ap, struct hfa34);
                                printf("%.1Lf,%.1Lf", x.a, x.d);
                                s += 2;
                                break;
                            }
                            case '3': {
                                struct hfa33 x = va_arg(ap, struct hfa33);
                                printf("%.1Lf,%.1Lf", x.a, x.c);
                                s += 2;
                                break;
                            }
                            case '2': {
                                struct hfa32 x = va_arg(ap, struct hfa32);
                                printf("%.1Lf,%.1Lf", x.a, x.b);
                                s += 2;
                                break;
                            }
                            case '1': {
                                struct hfa31 x = va_arg(ap, struct hfa31);
                                printf("%.1Lf,%.1Lf", x.a, x.a);
                                s += 2;
                                break;
                            }
                        }
                        break;
                    case '2':
                        switch (*(s + 1)) {
                            case '4': {
                                struct hfa24 x = va_arg(ap, struct hfa24);
                                printf("%.1f,%.1f", x.a, x.d);
                                s += 2;
                                break;
                            }
                            case '3': {
                                struct hfa23 x = va_arg(ap, struct hfa23);
                                printf("%.1f,%.1f", x.a, x.c);
                                s += 2;
                                break;
                            }
                            case '2': {
                                struct hfa22 x = va_arg(ap, struct hfa22);
                                printf("%.1f,%.1f", x.a, x.b);
                                s += 2;
                                break;
                            }
                            case '1': {
                                struct hfa21 x = va_arg(ap, struct hfa21);
                                printf("%.1f,%.1f", x.a, x.a);
                                s += 2;
                                break;
                            }
                        }
                        break;
                    case '1':
                        switch (*(s + 1)) {
                            case '4': {
                                struct hfa14 x = va_arg(ap, struct hfa14);
                                printf("%.1f,%.1f", x.a, x.d);
                                s += 2;
                                break;
                            }
                            case '3': {
                                struct hfa13 x = va_arg(ap, struct hfa13);
                                printf("%.1f,%.1f", x.a, x.c);
                                s += 2;
                                break;
                            }
                            case '2': {
                                struct hfa12 x = va_arg(ap, struct hfa12);
                                printf("%.1f,%.1f", x.a, x.b);
                                s += 2;
                                break;
                            }
                            case '1': {
                                struct hfa11 x = va_arg(ap, struct hfa11);
                                printf("%.1f,%.1f", x.a, x.a);
                                s += 2;
                                break;
                            }
                        }
                        break;
                }
            } else {
                putchar('%');
                putchar(*s);
            }
        } else {
            putchar(*s);
        }
        s++;
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
    myprintf("%hfa33 %hfa34 %hfa34 %hfa34", hfa33, hfa34, hfa34, hfa34);
    myprintf("%hfa32 %hfa34 %hfa34 %hfa34", hfa32, hfa34, hfa34, hfa34);
    myprintf("%hfa31 %hfa34 %hfa34 %hfa34", hfa31, hfa34, hfa34, hfa34);

    myprintf("%hfa32 %hfa33 %hfa33 %hfa33 %hfa33",
             hfa32, hfa33, hfa33, hfa33, hfa33);
    myprintf("%hfa31 %hfa33 %hfa33 %hfa33 %hfa33",
             hfa31, hfa33, hfa33, hfa33, hfa33);
    myprintf("%hfa33 %hfa33 %hfa33 %hfa33",
             hfa33, hfa33, hfa33, hfa33);

    myprintf("%hfa34 %hfa32 %hfa32 %hfa32 %hfa32",
             hfa34, hfa32, hfa32, hfa32, hfa32);
    myprintf("%hfa33 %hfa32 %hfa32 %hfa32 %hfa32",
             hfa33, hfa32, hfa32, hfa32, hfa32);

    myprintf("%hfa34 %hfa32 %hfa31 %hfa31 %hfa31 %hfa31",
             hfa34, hfa32, hfa31, hfa31, hfa31, hfa31);

    myprintf("HFA double:");
    myprintf("%hfa24 %hfa24 %hfa24 %hfa24", hfa24, hfa24, hfa24, hfa24);
    myprintf("%hfa23 %hfa24 %hfa24 %hfa24", hfa23, hfa24, hfa24, hfa24);
    myprintf("%hfa22 %hfa24 %hfa24 %hfa24", hfa22, hfa24, hfa24, hfa24);
    myprintf("%hfa21 %hfa24 %hfa24 %hfa24", hfa21, hfa24, hfa24, hfa24);

    myprintf("%hfa22 %hfa23 %hfa23 %hfa23 %hfa23",
             hfa22, hfa23, hfa23, hfa23, hfa23);
    myprintf("%hfa21 %hfa23 %hfa23 %hfa23 %hfa23",
             hfa21, hfa23, hfa23, hfa23, hfa23);
    myprintf("%hfa23 %hfa23 %hfa23 %hfa23",
             hfa23, hfa23, hfa23, hfa23);

    myprintf("%hfa24 %hfa22 %hfa22 %hfa22 %hfa22",
             hfa24, hfa22, hfa22, hfa22, hfa22);
    myprintf("%hfa23 %hfa22 %hfa22 %hfa22 %hfa22",
             hfa23, hfa22, hfa22, hfa22, hfa22);

    myprintf("%hfa24 %hfa22 %hfa21 %hfa21 %hfa21 %hfa21",
             hfa24, hfa22, hfa21, hfa21, hfa21, hfa21);

    myprintf("HFA float:");
    myprintf("%hfa14 %hfa14 %hfa14 %hfa14", hfa14, hfa14, hfa14, hfa14);
    myprintf("%hfa13 %hfa14 %hfa14 %hfa14", hfa13, hfa14, hfa14, hfa14);
    myprintf("%hfa12 %hfa14 %hfa14 %hfa14", hfa12, hfa14, hfa14, hfa14);
    myprintf("%hfa11 %hfa14 %hfa14 %hfa14", hfa11, hfa14, hfa14, hfa14);

    myprintf("%hfa12 %hfa13 %hfa13 %hfa13 %hfa13",
             hfa12, hfa13, hfa13, hfa13, hfa13);
    myprintf("%hfa11 %hfa13 %hfa13 %hfa13 %hfa13",
             hfa11, hfa13, hfa13, hfa13, hfa13);
    myprintf("%hfa13 %hfa13 %hfa13 %hfa13",
             hfa13, hfa13, hfa13, hfa13);

    myprintf("%hfa14 %hfa12 %hfa12 %hfa12 %hfa12",
             hfa14, hfa12, hfa12, hfa12, hfa12);
    myprintf("%hfa13 %hfa12 %hfa12 %hfa12 %hfa12",
             hfa13, hfa12, hfa12, hfa12, hfa12);

    myprintf("%hfa14 %hfa12 %hfa11 %hfa11 %hfa11 %hfa11",
             hfa14, hfa12, hfa11, hfa11, hfa11, hfa11);
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
    pll(-0x1234);
    pll(-0x12340000);
    pll(-0x123400000000);
    pll(-0x1234000000000000);
}

void pcs(void) {
    stdarg();
    movi();
}

int main() {
    pcs();
    return 0;
}