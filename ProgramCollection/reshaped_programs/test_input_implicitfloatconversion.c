#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void reach_error() { 
    assert(0 && "reach_error"); 
}

int main() {
    // Initialize a float with a deterministic value
    float f = 1.0f;
    
    // Explicit conversion to int
    int i = (int)f;
    
    // Check the condition and use an assertion for errors
    if (i == 1) {
        reach_error();
        abort();  // Exit the program abnormally
    }
    
    return 0;
}