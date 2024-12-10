#include <assert.h>
#include <stdio.h>

int main() {
    // Initialize x with a specific value within the given range
    float x = 1.0f;  // Example value between 0.95 and 128.0
    unsigned int y;
    
    // Convert floating-point to unsigned int, which truncates the fractional part
    y = (unsigned int)x;
    
    if (y == 0) {
        printf("y is zero\n");
    } else {
        printf("y non zero\n");
    }
    
    // Ensure y is less than 128
    assert(y < 128);

    return 0;
}