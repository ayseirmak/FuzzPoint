#include <stdio.h>
#include <string.h>  // To use memcpy
#include <stdlib.h>  // To use exit()

struct S {
    double a, b, *c;
    unsigned long d;
};

void foo(struct S *x, const struct S *y) {
    const unsigned long n = y->d + 1;
    const double m = 0.25 * (y->b - y->a);
    x->a = y->a;
    x->b = y->b;

    if (n == 1) {
        x->c[0] = 0.0;
    } else if (n == 2) {
        x->c[1] = m * y->c[0];
        x->c[0] = 2.0 * x->c[1];
    } else {
        double o = 0.0, p = 1.0;
        unsigned long i;

        for (i = 1; i <= n - 2; i++) {
            x->c[i] = m * (y->c[i - 1] - y->c[i + 1]) / (double)i;
            o += p * x->c[i];
            p = -p;
        }
        x->c[n - 1] = m * y->c[n - 2] / (n - 1.0);
    }
}

int main(void) {
    double c_array[4] = {0};  // Initialize c array with deterministic values
    struct S x = {0, 0, c_array, 0};
    struct S y = {0.0, 0.0, (double[]){60, 20, -10, 118}, 2};

    foo(&x, &y);

    double expected[4] = {60, 20, -10, 118};
    if (memcmp(c_array, expected, sizeof(c_array)) != 0) {
        printf("Test failed for y.d = 2\n");
        exit(EXIT_FAILURE);
    }

    y.d = 1;
    memcpy(c_array, (double[]){-20, -10, 118, 118}, sizeof(c_array));
    foo(&x, &y);

    if (memcmp(c_array, (double[]){-20, -10, 118, 118}, sizeof(c_array)) != 0) {
        printf("Test failed for y.d = 1\n");
        exit(EXIT_FAILURE);
    }

    y.d = 0;
    memcpy(c_array, (double[]){0, 118, 118, 118}, sizeof(c_array));
    foo(&x, &y);

    if (memcmp(c_array, (double[]){0, 118, 118, 118}, sizeof(c_array)) != 0) {
        printf("Test failed for y.d = 0\n");
        exit(EXIT_FAILURE);
    }

    printf("All tests passed.\n");
    return 0;
}