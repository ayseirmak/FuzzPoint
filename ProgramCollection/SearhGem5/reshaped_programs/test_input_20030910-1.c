#include <stdio.h>
#include <complex.h>
#include <assert.h>

int main() {
    // Initialize complex double and assign a constant value
    double complex dc = 3.14 + 0.0 * I;
    
    // Extract the real part of the complex number
    double real_part = creal(dc);
    
    // Assert to verify the real part is as expected
    assert(real_part == 3.14);
    
    // Print the real part to ensure the program performs some output
    printf("The real part of the complex number is: %.2f\n", real_part);
    
    return 0;
}