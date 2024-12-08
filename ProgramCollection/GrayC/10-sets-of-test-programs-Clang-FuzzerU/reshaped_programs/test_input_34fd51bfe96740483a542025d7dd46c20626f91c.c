#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

// Corrected struct definition
typedef struct {
    _Complex double a;
    _Complex double b;
} Scf10;

// Global variable initialization
Scf10 g1s = {{0.0, 0.0}, {0.0, 0.0}};

// Function to check if the complex numbers match
void check(Scf10 x, _Complex double y) {
    if (x.a != y) {
        printf("Verification failed: x.a (%f, %f) != y (%f, %f)\n",
               creal(x.a), cimag(x.a), creal(y), cimag(y));
        abort();
    }
}

// Function to initialize the complex number in the struct
void init(Scf10 *p, _Complex double y) {
    p->a = y;
}

int main() {
    _Complex double testVal = 1.0 + 0.0*I;
    init(&g1s, testVal);
    check(g1s, testVal);
    printf("Verification succeeded\n");
    return 0;
}