#include <stdio.h>
#include <stdlib.h>

void foo(float *x);

int main() {
    float x[4] = {1.2, 2.3, 3.4, 4.5}; // Using fixed deterministic values
    foo(x);
    return 0;
}

void foo(float *x) {
    int i, j, k; // Declare loop variables
    float temp;
    static float t16[16] = {
        1.0, 2.0, 3.0, 4.0,
        5.0, 6.0, 7.0, 8.0,
        9.0, 10.0, 11.0, 12.0,
        13.0, 14.0, 15.0, 16.0
    };
    static float tmp[4] = {0.0, 0.0, 0.0, 0.0};

    // Just using t16 for a simple operation to reflect some kind of functionality
    for (i = 0; i < 4; i++) {
        tmp[i] = x[i] * t16[i];
        printf("tmp[%d] = %f\n", i, tmp[i]);
    }
}