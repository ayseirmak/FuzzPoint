#include <stdio.h>
#include <assert.h>

#define X 2.5

int main() {
    double x = 1.0;
    double x1 = x / X;

    while (x1 != x) {
        x = x1;
        x1 = x / X;
    }

    assert(x == 0);

    printf("The while loop has terminated. x: %f\n", x);

    return 0;
}