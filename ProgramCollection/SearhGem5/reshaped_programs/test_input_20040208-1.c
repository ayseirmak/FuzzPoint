#include <stdio.h>
#include <stdlib.h>

int main() {
    long double x;

    // Fixed values for demonstration purposes
    long double value1 = 2.5;
    long double value2 = 4.0;
    long double expected_result = 10.0; // Expected to be the result of 2.5 * 4.0

    x = value1;
    x *= value2;

    if (x != expected_result) {
        printf("Test failed! Expected: %Lf, but got: %Lf\n", expected_result, x);
        return 1; // Indicating failed condition
    }

    printf("Test passed! Computed result: %Lf\n", x);
    return 0; // Successful execution
}