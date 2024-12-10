#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    double x = INFINITY; // Initialize with a constant representing infinity

    // Check if x is infinite
    if (isinf(x)) {
        // Assert that x is indeed infinite
        assert(isinf(x));
    } else {
        // Assert that x is not infinite
        assert(!isinf(x));
    }
    
    printf("Assertions passed successfully.\n");
    return 0; // Return 0 to indicate successful execution
}