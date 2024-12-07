#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FIXED_ITERATIONS 10

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
    double count = 0.0;

    // Using a fixed set of deterministic degrees for demonstration purposes
    int fixedDegrees[FIXED_ITERATIONS] = {30, -45, 60, -90, 120, -135, 150, 170, 0, -15};

    for (int i = 0; i < FIXED_ITERATIONS; ++i) {
        x = fixedDegrees[i];

        // Ensure degree is within the allowed range
        if (x <= -180 || x >= 180) continue;

        angleInRadian = radianMeasure(x);
        sum2 = sum2 + sin(angleInRadian + 2 * phaseLead);
        sum1 = sum1 + cos(angleInRadian + phaseLag);

        count++;
    }

    // Assertion that diff(sum1, sum2) should be <= count
    assert(diff(sum1, sum2) <= count);

    return 0;
}