#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Constants
#define X 2.5f  // As per the suggestion to make verification successful

// Function to trigger an error if a condition is false
void reach_error() { 
    assert(0); 
}

// Verifier assert function
void custom_assert(int cond) { 
    if (!cond) { 
        reach_error(); 
        abort(); 
    } 
    return; 
}

// Main function
int main() {
    // Initialize variables
    float x = 1.0f;
    float x1 = x / X;
  
    // Loop to adjust x until it stabilizes
    while (x1 != x) {
        x = x1;
        x1 = x / X;
    }
  
    // Assert to check the final condition
    custom_assert(x == 0);
    return 0;
}