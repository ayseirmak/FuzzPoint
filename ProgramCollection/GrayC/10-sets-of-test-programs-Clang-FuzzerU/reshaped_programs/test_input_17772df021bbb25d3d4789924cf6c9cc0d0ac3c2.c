#include <stdio.h>

void foo(float *x);

int main() {
    // Initialize the array with zeros
    float x[4] = {0.0, 0.0, 0.0, 0.0};
    
    foo(x);

    // Print the results for verification
    printf("Results:\n");
    printf("x[0] = %.2f\n", x[0]);
    printf("x[1] = %.2f\n", x[1]);
    printf("x[2] = %.2f\n", x[2]);
    printf("x[3] = %.2f\n", x[3]);

    return 0;
}

void foo (float *x) {
    int i, j, k;
    float temp; 
    // Initialize static arrays
    static float t16[16] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
                             10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
    static float tmp[4] = {0.0, 0.0, 0.0, 0.0};  // Ensure size matches usage in the function

    // Perform computations
    for (i = 0; i < 4; i++) {
        k = 3 - i;
        temp = t16[5 * k];
        for (j = k + 1; j < 4; j++) {
            tmp[k] = t16[k + j * 4] * temp;
        }
    }

    // Store results in the output array
    for (i = 0; i < 4; i++) {
        x[i] = tmp[i];
    }
}