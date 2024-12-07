#include <stdio.h>
#include <assert.h>

int main() {
    double x = 1.0;
    double x1 = x / 1.6;

    while (x1 != x) {
        x = x1;
        x1 = x / 1.6;
    }

    // Use assert to replace __VERIFIER_assert
    assert(x == 0);

    printf("Program completed without errors.\n");

    return 0;
}