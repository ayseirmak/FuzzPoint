#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#include <assert.h>

// Define the structure with complex doubles
typedef struct {
    _Complex double a;
    _Complex double b;
} Scf10;

Scf10 g1s;

// Function to check if the complex number in the structure matches the given value
void check(Scf10 x, _Complex double y) {
    if (x.a != y) {
        fprintf(stderr, "Mismatch: Expected %lf + %lfi but got %lf + %lfi\n",
                creal(y), cimag(y), creal(x.a), cimag(x.a));
        abort();
    }
}

// Function to initialize the structure with a given complex double value
void init(Scf10 *p, _Complex double y) {
    p->a = y;
}

int main() {
    // Initialize and check with deterministic values
    _Complex double fixed_value = 1.0 + 0.0 * I;  // equivalent to (_Complex double)1
    init(&g1s, fixed_value);
    check(g1s, fixed_value);

    return 0;
}