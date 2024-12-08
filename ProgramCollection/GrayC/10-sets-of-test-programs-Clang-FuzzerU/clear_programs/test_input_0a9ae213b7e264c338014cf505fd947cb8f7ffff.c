#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

typedef struct {
    _Complex double a;
} Scf10;

Scf10 g1s;

void check(Scf10 x, _Complex double y) {
    if (x.a != y) {
        printf("Check failed: x.a != y\n");
        exit(1);
    }
}

void init(Scf10* p, _Complex double y) {
    p->a = y;
}

int main() {
    _Complex double initial_value = 1.0 + 0.0 * I;
    init(&g1s, initial_value);
    check(g1s, initial_value);

    printf("Check passed: g1s.a == initial_value\n");
    return 0;
}