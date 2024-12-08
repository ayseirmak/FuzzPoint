#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main() {
    // Declare and initialize variables
    double d = FLT_MIN / 2.0;
    double x = FLT_MIN / 2.7;

    // Check if the values are not equal and abort if true
    if (x != d) {
        abort();
    }
    
    // Return 0 to indicate successful execution
    return 0;
}