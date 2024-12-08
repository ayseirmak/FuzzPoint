#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct s1 { double d; };
struct s2 { double d; };
union u {
    struct s1 x; // Rename the struct ss to x
    struct s2 y;
};

double f(struct s1 *a, struct s2 *b) {
    a->d = 1.0;
    return b->d + 1.0;
}

int main() {
    union u a;
    a.x.d = 0.0;
    a.y.d = 0.0; // Initialize y's double as well

    double result = f(&a.x, &a.y);
    assert(result == 2.0); // Use assert to ensure the result is as expected

    if (result != 2.0) {
        fprintf(stderr, "Calculation did not yield the expected result.\n");
        abort();
    }

    return 0;
}