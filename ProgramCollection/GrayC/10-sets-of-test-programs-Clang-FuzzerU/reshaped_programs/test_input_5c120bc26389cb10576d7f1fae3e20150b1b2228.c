#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    long double x;

    // Initialize x with a deterministic value
    x = 0x1.0p-500L;
    0x1.0p-522L; // This line seems redundant, removed any effect on x

    // Check if x is equal to 0x1.0p-1022L and act accordingly
    if (x != 0x1.0p-1022L) {
        // Use assert to replace custom abort
        assert(x == 0x1.0p-1022L);
    }

    // Explicitly indicate successful termination
    return 0;
}