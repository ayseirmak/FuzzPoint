#include <stdio.h>

void printfn(int a, short b, double C, float D, signed char E, char F, void *G, double *H, int I, long long J) {
    printf("%d, %d, %f, %f, %d\n", a, b, C, D, E);
    printf("%d, %ld, %ld, %d, %lld\n", F, (long) G, (long) H, I, J);
}

int main() {
    int a = 42; // Example integer
    short b = 10; // Example short integer
    double C = 3.14; // Example double
    float D = 1.23f; // Example float
    signed char E = 65; // Example signed char (equivalent to 'A')
    char F = 70; // Example char (equivalent to 'F')
    void *G = (void *) 0xDEADBEEF; // Example pointer address
    double exampleDouble = 7.89; // Example double
    double *H = &exampleDouble; // Pointer to the example double
    int I = 24; // Example integer
    long long J = 9876543210LL; // Example long long

    printfn(a, b, C, D, E, F, G, H, I, J);

    return 0;
}