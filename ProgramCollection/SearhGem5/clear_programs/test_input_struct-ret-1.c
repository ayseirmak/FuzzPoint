#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define output buffer
char out[100];

// Declare structs
typedef struct { 
    double d; 
    int i[3]; 
} B;

typedef struct { 
    char c[50], c1; 
} X;

// Initialize variables with predetermined values
char c1 = 'A';
char c2 = 5;  // Example integer value
char c3 = 7;
char c4 = 3;
char c5 = 9;

double d1 = 1.23;
double d2 = 2.34;
double d3 = 3.45;
double d4 = 4.56;
double d5 = 5.67;
double d6 = 6.78;
double d7 = 7.89;
double d8 = 8.90;
double d9 = 9.01;

B B1 = {6.123, {1, 2, 3}};
B B2 = {4.567, {4, 5, 6}};

X X1 = {"Test1", 'X'};
X X2 = {"Test2", 'Y'};
X X3 = {"Test3", 'Z'};

X f (B a, char b, double c, B d) {
    static X xr = {"return val", 'R'};
    X r = xr;
    r.c1 = b;
    sprintf(out, "X f(B,char,double,B):({%g,{%d,%d,%d}},'%c',%g,{%g,{%d,%d,%d}})",
            a.d, a.i[0], a.i[1], a.i[2], b, c, d.d, d.i[0], d.i[1], d.i[2]);
    return r;
}

X (*fp) (B, char, double, B) = &f;

int main(void) {
    X Xr;
    char tmp[100];

    Xr = f(B1, c2, d3, B2);
    strcpy(tmp, out);
    Xr.c[0] = Xr.c1 = '\0';
    Xr = (*fp)(B1, c2, d3, B2);
    if (strcmp(tmp, out) != 0) {
        printf("Function results differ!\n");
        return 1;  // Non-zero return indicates failure
    }

    printf("The function executed successfully with expected results.\n");
    return 0;
}