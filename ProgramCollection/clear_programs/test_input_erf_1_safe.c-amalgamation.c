#include <stdio.h>
#include <math.h>
#include <assert.h>

int main() {
    // Initialized with a fixed value for the demonstration
    float x = 0.5f;  // Replace 0.5f with any desired test value

    // Assume x is not NaN for the purpose of this program
    assert(!isnan(x));

    float y = erff(x);

    // Use assert from the standard library to ensure the condition is met
    assert(islessequal(y, 1.0f));
    printf("The value of y: %f\n", y);

    return 0;
}