#include <stdio.h>
#include <assert.h>

#define X 2.5f

int main() {
    float x = 1.0f;
    float x1 = x / X;

    // Output values to debug and understand computation
    printf("Initial values:\n");
    printf("x = %.2f, x1 = %.2f\n", x, x1);

    while(x1 != x) {
        x = x1;
        x1 = x / X;
        
        // Log updates every step to ensure the loop's behavior is clear
        printf("Updated values:\n");
        printf("x = %.2f, x1 = %.2f\n", x, x1);
    }

    // Replace custom assert function with standard assert
    assert(x == 0.0f);

    return 0;
}