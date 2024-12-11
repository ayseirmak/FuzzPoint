#include <stdio.h>
#include <math.h> // For copysign

int copysign_bug(double x) {
    if (x != 0.0 && (x * 0.5 == x)) 
        return 1;
    if (copysign(1.0, x) < 0.0) 
        return 2;
    else
        return 3;
}

int main() {
    // Initialized to a value for testing
    double x = -1.0; // Example value which should make the copysign_bug return 2

    if (copysign_bug(x) != 2) {
        printf("Error: copysign_bug() did not return 2 for x = %f\n", x);
        return 1;
    } else {
        printf("Success: copysign_bug() returned 2 for x = %f\n", x);
    }

    return 0;
}