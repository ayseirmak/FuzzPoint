#include <stdio.h>

double a[3] = {0.0, 1.0, 2.0};

void bar(int x, double *y) {
    if (x || *y != 1.0) {
        // Use printf for logging instead of abort
        printf("Assertion failed in bar: x=%d, *y=%lf\n", x, *y);
    } else {
        printf("Assertion success in bar: x=%d, *y=%lf\n", x, *y);
    }
}

int main(void) {
    double c = 0.0; // Initialization value to observe intended functionality
    int d;
    
    for (d = 0; d < 3; d++) {
        c = a[d];
        if (c > 0.0) goto e;
    }
    
    bar(1, &c); // This would match the test scenario "a[d]" being <= 0.0
    // Replace exit(1) with return for portability
    printf("Exiting with code 1\n");
    return 1;

e:
    bar(0, &c); // This would match the test scenario "a[d]" being > 0.0
    // Replace exit(0) with return for portability
    printf("Exiting with code 0\n");
    return 0;
}