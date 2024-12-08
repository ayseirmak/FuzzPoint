#include <stdio.h>
#include <complex.h>
#include <assert.h>

typedef struct {
    _Complex double a;
    _Complex double b;
} Scf10;

Scf10 g1s;

void check(Scf10 x, _Complex double y) {
    assert(x.a == y);
}

void init(Scf10 *p, _Complex double y) {
    p->a = y;
    p->b = 0.0;  // Ensure all struct fields are initialized
}

int main() {
    init(&g1s, 1.0 + 0.0*I);
    check(g1s, 1.0 + 0.0*I);

    return 0;
}