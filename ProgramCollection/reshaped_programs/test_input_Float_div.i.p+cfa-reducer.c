#include <assert.h>
#include <stdio.h>

// Replacing reach_error() with a simple call to assert(0)
void reach_error() {
    assert(0);
}

int main() {
    float x = 1.0f;
    float x1 = x / 2.5f;

    while (x1 != x) {
        x = x1;
        x1 = x / 2.5f;
    }

    // The assert replaces the custom verification
    if (x != 0) {
        reach_error();
        printf("Error: x is not zero.\n");
        return 1;
    }
    
    printf("Success: The calculation reached zero.\n");
    return 0;
}