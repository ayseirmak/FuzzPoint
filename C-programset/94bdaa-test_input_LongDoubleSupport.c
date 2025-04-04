#include <stdio.h>
#include <assert.h>

int main() {
    // Initialize variables explicitly
    unsigned N0 = 0, N1 = 0, N2 = 0;  // Counter variables

    // Initialize floating-point numbers
    float V0 = 0.1f;
    while (V0 != 0) {
        V0 *= V0;
        N0++;
    }

    double V1 = 0.1;
    while (V1 != 0) {
        V1 *= V1;
        N1++;
    }

    long double V2 = 0.1L;
    while (V2 != 0) {
        V2 *= V2;
        N2++;
    }

    // Print the counts
    printf("counts: %u, %u, %u\n", N0, N1, N2);

    // Assertions ensure behavior consistency
    assert(N0 == 6);
    assert(N1 == 9);
    assert(N2 == 13);

    return 0;
}