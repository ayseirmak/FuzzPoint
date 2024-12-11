#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double test(const double le, const double ri) {
    double val = (ri - le) / (ri * (le + 1.0));
    return val;
}

int main() {
    // Initialize variables with fixed values
    double le = 1.0;  // Example value for le
    double ri = 2.0;  // Example value for ri

    // Perform the computation
    double retval = test(le, ri);

    // Use assert to the same check instead of abort
    assert(retval >= 0.24 && retval <= 0.26);

    // Indicate successful execution
    printf("Function returned a valid result within the expected range.\n");
    return 0;
}