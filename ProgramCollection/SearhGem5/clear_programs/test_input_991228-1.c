#include <stdio.h>
#include <stdlib.h>

// Union to facilitate accessing the underlying bit representation of a double.
union {
    double d;
    int i[2];
} u = { -0.25 };  // Initialize the union with a floating-point value.

long long endianness_test = 1;
#define MSW (*(int*)&endianness_test)  // Macro to determine which part of the union to check for the sign bit.

int signbit(double x) {
    // Local union to check the sign bit of the provided double.
    union {
        double d;
        int i[2];
    } u_local = { x };

    // Returns true if the MSB (most significant bit) of the double is set, indicating a negative number.
    return u_local.i[MSW] < 0;
}

int main() {
    // Check if the size assumptions for the union and double hold true for this platform.
    // Ensure that MSW points to the correct part of the double that contains the sign.
    if (2 * sizeof(int) != sizeof(double) || u.i[MSW] >= 0) {
        return 0;  // Exit successfully if assumptions don't hold, securing against erroneous cases.
    }

    // Verify the sign bit of -0.25. If incorrect, the test fails.
    if (!signbit(-0.25)) {
        // If signbit does not return true, something is incorrect.
        printf("Error: signbit check failed.\n");
        return 1;  // Indicate the test did not pass.
    }

    return 0;  // Indicate successful execution.
}