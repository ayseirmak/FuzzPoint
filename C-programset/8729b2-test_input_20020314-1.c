#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void f(void *a, double y) {
    // Function body remains empty, as per original code
}

double g(double a, double b, double c, double d) {
    double x, y, z;
    void* p;

    x = a + b;
    y = c * d;

    // Local variable instead of alloca
    void* localMemory[16];
    p = localMemory;

    f(p, y);
    z = x * y * a;

    return z + b;
}

int main(void) {
    double a = 1.0, b = 0.0, c = 10.0, d = 0.0;

    // Assert conditions in place of abort
    assert(g(a, b, c, d) == 0.0);
    assert(a == 1.0 && b == 0.0 && c == 10.0 && d == 0.0);

    return 0;
}