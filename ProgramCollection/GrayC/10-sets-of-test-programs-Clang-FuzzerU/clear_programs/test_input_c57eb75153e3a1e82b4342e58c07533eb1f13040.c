#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define X  5

int y = 0;

long double x = X + X;
long double foo_y = 2.0L * X;

int foo(int x) {
    return (x ? 3 : foo_y++);
}

int main() {
    int z = 4;

    // Check assertions based on the original logic
    if (y || z != 4 || foo(4) != 3) {
        abort();
    }

    printf("Program executed successfully.\n");
    return 0;
}