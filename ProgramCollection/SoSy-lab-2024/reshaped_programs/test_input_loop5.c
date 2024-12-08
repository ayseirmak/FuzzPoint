#include <stdio.h>
#include <math.h>
#include <assert.h>

float pi = 3.14159;

double diff(double x1, double x2) {
    if (x1 > x2)
        return (x1 - x2);
    else
        return (x2 - x1);
}

double radianMeasure(int degrees) {
    return (degrees * (pi / 180));
}

int main() {
    int x;
    float angleInRadian;
    float phaseLag = pi / 2, phaseLead = pi;
    double sum1 = 0.0, sum2 = 0.0;
    int temp;
    double count = 0.0;

    // Fixed array of values to replace nondeterministic input
    int testValues[] = {30, -45, 60, 90, -120, 135, 0}; 
    size_t n = sizeof(testValues) / sizeof(testValues[0]);

    for (size_t i = 0; i < n; i++) {
        x = testValues[i];
        
        if (x > -180 && x < 180) {
            angleInRadian = radianMeasure(x);
            sum2 = sum2 + sin(angleInRadian + 2 * phaseLead);
            sum1 = sum1 + cos(angleInRadian + 3 * phaseLag);

            count++;
        }
    }

    assert(diff(sum1, sum2) <= count * 2);

    printf("Assertions passed.\n");
    return 0;
}