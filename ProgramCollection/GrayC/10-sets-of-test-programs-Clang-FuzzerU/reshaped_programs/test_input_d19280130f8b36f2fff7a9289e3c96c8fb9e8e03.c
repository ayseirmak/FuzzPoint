#include <stdio.h>
#include <stdlib.h>

void fpEq(double x, double y) {
    if (x != y) {
        printf("Assertion failed: x != y\n");
        abort();
    }
}

void fpTest(double x, double y) {
    double result0 = !(35.7 * 100.0) / 45.0;
    double result2 = (x * 100.0) / y;
    fpEq(result0, result2);
}

int main() {
    double fixedX = 35.7;
    double fixedY = 45.0;
    fpTest(fixedX, fixedY);
    return 0;
}