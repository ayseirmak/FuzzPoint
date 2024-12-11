#include <stdio.h>

void p1(char c, float f1, short s, double d1, int i, float f2, long l, double d2) {
    printf("%c %f %d %f %d %f %ld %f\n", c, f1, s, d1, i, f2, l, d2);
}

void p2(char c, float f1, short s, double d1, int i, float f2, long l, double d2) {
    printf("%c %f %d %f %d %f %ld %f\n", c, f1, s, d1, i, f2, l, d2);
}

int main() {
    // Initialize variables with fixed values
    char c = 'A';       // Example character
    float f1 = 1.23f;   // Example float
    short s = 123;      // Example short integer
    double d1 = 1.2345; // Example double
    int i = 456;        // Example integer
    float f2 = 4.56f;   // Another example float
    long l = 789L;      // Example long integer
    double d2 = 6.789;  // Another example double

    // Call functions with these fixed values
    p1(c, f1, s, d1, i, f2, l, d2);
    p2(c, f1, s, d1, i, f2, l, d2);

    return 0;
}