#include <stdio.h>
#include <stdarg.h>

// Structures with initialized data
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

struct hfa11 { float a; } hfa11 = { 11.1 };
struct hfa12 { float a, b; } hfa12 = { 12.1, 12.2 };
struct hfa13 { float a, b, c; } hfa13 = { 13.1, 13.2, 13.3 };
struct hfa14 { float a, b, c, d; } hfa14 = { 14.1, 14.2, 14.3, 14.4 };

struct hfa21 { double a; } hfa21 = { 21.1 };
struct hfa22 { double a, b; } hfa22 = { 22.1, 22.2 };
struct hfa23 { double a, b, c; } hfa23 = { 23.1, 23.2, 23.3 };
struct hfa24 { double a, b, c, d; } hfa24 = { 24.1, 24.2, 24.3, 24.4 };

struct hfa31 { long double a; } hfa31 = { 31.1 };
struct hfa32 { long double a, b; } hfa32 = { 32.1, 32.2 };
struct hfa33 { long double a, b, c; } hfa33 = { 33.1, 33.2, 33.3 };
struct hfa34 { long double a, b, c, d; } hfa34 = { 34.1, 34.2, 34.3, 34.4 };

// Function to simulate custom printf
void myprintf(const char* fmt, ...)
{
    va_list ap;
    const char *s;

    va_start(ap, fmt);
    
    for (s = fmt; *s; ++s) {
        if (*s == '%' && *(s + 1) == 'h') {
            switch (*(s + 2)) {
                case 'f':
                    switch (*(s + 3)) {
                        case 'a':
                            if (*(s + 4) == '3' && *(s + 5) == '2') {
                                struct hfa32 x = va_arg(ap, struct hfa32);
                                printf("%.1Lf,%.1Lf\n", x.a, x.b);
                                s += 5;
                            } else if (*(s + 4) == '3' && *(s + 5) == '3') {
                                struct hfa33 x = va_arg(ap, struct hfa33);
                                printf("%.1Lf,%.1Lf\n", x.a, x.c);
                                s += 5;
                            } else if (*(s + 4) == '3' && *(s + 5) == '4') {
                                struct hfa34 x = va_arg(ap, struct hfa34);
                                printf("%.1Lf,%.1Lf\n", x.a, x.d);
                                s += 5;
                            }
                            break;
                        default:
                            putchar(*s);
                            break;
                    }
                    break;
                default:
                    putchar(*s);
                    break;
            }
        } else {
            putchar(*s);
        }
    }
    putchar('\n');
    va_end(ap);
}

// Arithmetic and logical operations functions
static uint32_t addip0(uint32_t x) { return x + 0; }
static uint64_t sublp0(uint64_t x) { return x - 0; }
static uint32_t addip123(uint32_t x) { return x + 123; }
static uint64_t addlm123(uint64_t x) { return x + (-123); }
static uint64_t sublp4095(uint64_t x) { return x - 4095; }
static uint32_t subim503808(uint32_t x) { return x - (-503808); }
static uint64_t addp12345(uint64_t x) { return x + 12345; }
static uint32_t subp12345(uint32_t x) { return x - 12345; }

void pll(uint64_t x)
{
    printf("%llx\n", x);
}

// Example of using the defined functions
void exampleFunctions(void)
{
    pll(addip0(1000));
    pll(sublp0(1000));
    pll(addip123(1000));
    pll(addlm123(1000));
    pll(sublp4095(1000));
    pll(subim503808(1000));
    pll(addp12345(1000));
    pll(subp12345(1000));
}

int main(void)
{
    exampleFunctions();
    
    myprintf("%hfa32 %hfa33 %hfa34", hfa32, hfa33, hfa34);
    
    return 0;
}