#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reach_error() {
    assert(0 && "reach_error");
}

void func_to_recursive_line_0_to_32_0(double *a, double *x, int *r) {
    while ((*x) > (*r)) {
        assert(((int)((((*r) * (*r)) - (*a)) - (*r)) + (2 * (*x))) == 0);
        *x = (*x) - (*r);
        *r = (*r) + 1;
    }
}

int main() {
    int r = 0;
    double a = 4.0;  // Deterministic input
    double x = a / 2.0;

    func_to_recursive_line_0_to_32_0(&a, &x, &r);

    assert(((int)((((r * r) - a) - r) + (2 * x))) == 0);

    printf("Program finished successfully with r: %d\n", r);
    return 0;
}